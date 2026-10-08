#!/usr/bin/env python3
"""Build the native-lane table from byte-matched decomp C (docs/PC-PORT.md,
"Native lane").

For each main-executable registry entry with recovery "c" whose source has
a native word export (so the interpreter can always run it as a fallback),
compile the decomp C branch with clang for the 64-bit host, rewrite every
guest symbol to its guest address, and admit the function only when an
IR-level checker proves it pointer-width safe under the "guest RAM mapped
at host 0x80000000" model. Admitted functions become lane_func_<ADDR> in an
archive; a generated C file holds the register-ABI wrappers, interpreter
thunks for every unported callee, and the MusashiNativeLaneEntry table.

Rules (each rejection names the first rule that failed, in report.json):
  source  : no 'long' or 'sizeof' tokens (their widths differ on the host)
  compile : clang must accept the source (implicit declarations are fatal)
  symbols : guest data/function symbols must resolve into game RAM
            [0x80010000, 0x80200000); mutable data defined by the TU is
            refused (it would be a host copy, not the guest's)
  layout  : no struct/union/array type containing a pointer is used, and no
            pointer-element indexing (checked before optimization)
  memory  : no pointer-typed load/store to non-local memory; no atomics
  escape  : no host stack or host data address reaches guest memory, a
            guest callee, an integer, or the return value
  inttoptr: integer->pointer only from zero-extended 32-bit values or
            constants inside game RAM or the scratchpad (host alias)
  calls   : only direct calls to prototyped guest functions (lane_func_*),
            module-internal functions and memory intrinsics; no inline asm
  arith   : no variable or trapping divisors (x86 traps where MIPS does not),
            variable shift counts must be masked to 5 bits
  ub      : no undef/poison operands and no unreachable (UB the host
            optimizer could exploit differently from gcc-2.7.2)
  abi     : parameters/returns limited to 8/16/32-bit integers and pointers;
            no direct call passing fewer arguments than the callee reads;
            no void-typed function whose retail caller reads v0/v1 after
            the jal (the retail words return a value the C does not);
            no caller that passes a pass-through function (below) fewer
            arguments than it reads unless the caller passes them through
  (pass-through, not a rejection): a function whose retail words read an
            argument register past its C prototype's (a0/a1 left untouched
            before `jal callee`) is never called directly; native callers
            reach it through the guest-call thunk and lane_try runs it
  memory  : (also) no volatile access, which in decomp C means a device
  irq     : no loop that neither stores nor calls (a native call runs
            without IRQ delivery, so a polling loop could spin forever)
  hooks   : the function's guest range contains no PC the port observes or
            intercepts (0x80xxxxxx literals on pc/ra/continuation/case lines
            in pc_port/*.c, plus the platform entry-hook sites in
            pc_port/platform/bfm_plat_hook_sites.c), since native execution
            would bypass the hook
  jumptable: (overlays) no guest `jr` to a register other than ra: the
            residency digest covers the code extent, not a jump table in the
            member's .rodata, so identical code bytes do not prove the same
            switch targets

Overlay members (--overlay-members, or --overlay-allow in release builds):
every entry carries the FNV-1a 64 of its member's bytes over the function's
extent and runs only while guest RAM there hashes to it. Entries with the same
(vram, digest) from several members are compiled once and record the members
they cover. With --overlay-allow FILE ("<member> <vram>" lines) the overlay
candidates are exactly those pairs; a missing member config or file, a member
SHA-1 that differs from the yaml's, a missing registry row or an extent that
does not fit the member is a build error, never a silent 0. Under
--own-code-only each pair must also carry a clean-room or owner origin.
"""
import argparse
import concurrent.futures
import json
import os
import re
import shutil
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(Path(__file__).resolve().parent))
import lane_cycles  # noqa: E402  (D-011 retail cycle model, report only)
RAM_LO, RAM_HI = 0x80010000, 0x80200000
# The 1 KiB scratchpad. musashi_native_lane_map_guest maps it a second time at
# host 0x1F800000 (the same page as MusashiBootMemory.scratchpad), so constant
# scratchpad addresses are admitted. Such functions are listed in
# musashi_native_lane_scratchpad_pcs[] and native_boot drops them when that
# alias could not be mapped.
SCRATCH_LO, SCRATCH_HI = 0x1F800000, 0x1F800400


GAME_RAM = (0x80010000, 0x80200000)


_SCEV_CACHE = {}


def scev_unsigned_ranges(ir):
    """Strict only (B28): {function: {value: (lo, hi)}} from LLVM's
    scalar-evolution printer (`opt -passes=print<scalar-evolution>`): the
    unsigned range `U: [lo,hi)` LLVM proves for each integer value. Empty
    when opt is unavailable or fails."""
    import hashlib
    import tempfile
    key = hashlib.sha1(ir.encode()).hexdigest()
    if key in _SCEV_CACHE:
        return _SCEV_CACHE[key]
    res = {}
    opt_bin = shutil.which("opt-19") or shutil.which("opt")
    if opt_bin:
        with tempfile.NamedTemporaryFile("w", suffix=".ll", delete=False) as f:
            f.write(ir)
            path = f.name
        try:
            r = subprocess.run([opt_bin, "-disable-output", "-passes=print<scalar-evolution>", path],
                               capture_output=True, text=True, timeout=120)
            text = r.stdout + r.stderr if r.returncode == 0 else ""
        except (OSError, subprocess.SubprocessError):
            text = ""
        finally:
            os.unlink(path)
        fn, var = None, None
        for line in text.splitlines():
            m = re.match(r"Classifying expressions for: @([\w.$]+)", line)
            if m:
                fn, var = m.group(1), None
                res.setdefault(fn, {})
                continue
            m = re.match(r"^  (%[\w.\"$]+) = ", line)
            if m:
                var = m.group(1)
                continue
            m = re.search(r"-->.*?\bU: \[(-?\d+),(-?\d+)\)", line)
            if m and fn and var:
                lo, hi = int(m.group(1)), int(m.group(2))
                if 0 <= lo < hi:
                    res[fn][var] = (lo, hi)
                var = None
    _SCEV_CACHE[key] = res
    return res


def scev_in_game_ram(ir, header, val):
    """Strict only (B28): LLVM proves val's unsigned range inside game RAM
    (with the same 16-byte slack as bounded_guest_affine), so the host
    pointer equals the guest address (a struct walk over a fixed table with
    a bounded trip count, 8012944C)."""
    m = re.search(r"@([\w.$]+)\(", header)
    if not m:
        return False
    rng = scev_unsigned_ranges(ir).get(m.group(1), {}).get(val)
    return bool(rng) and GAME_RAM[0] <= rng[0] and rng[1] - 1 + 16 < GAME_RAM[1]


def bounded_guest_affine(val, defs):
    """Strict only (B28): an inttoptr from `add nuw nsw i64 X, C` where C is a
    game-RAM address and X is provably small: a counted induction variable
    (phi from 0, +1 step, exit at `icmp eq next, N`) or a zext from i8/i16,
    scaled by a constant (mul/shl nuw nsw). The guest's 32-bit sum then
    never wraps and stays inside game RAM, so the host pointer equals the
    guest address (an array of structs indexed by a loop counter)."""
    d = defs.get(val, "")
    m = re.fullmatch(r"(?:add|or)(?: nuw| nsw| disjoint)* i64 (%[\w.]+), (\d+)", d) or \
        re.fullmatch(r"(?:add|or)(?: nuw| nsw| disjoint)* i64 (\d+), (%[\w.]+)", d)
    if not m:
        return False
    x, c = (m.group(1), int(m.group(2))) if m.group(1).startswith("%") else \
           (m.group(2), int(m.group(1)))
    if not GAME_RAM[0] <= c < GAME_RAM[1]:
        return False

    def bound(v):
        """Largest value v can take (inclusive), or None."""
        dv = defs.get(v, "")
        z = re.fullmatch(r"zext(?: nneg)? i(8|16) %[\w.]+ to i64", dv)
        if z:
            return (1 << int(z.group(1))) - 1
        ph = re.fullmatch(r"phi i64 \[ 0, %[\w.]+ \], \[ (%[\w.]+), %[\w.]+ \]", dv) or \
            re.fullmatch(r"phi i64 \[ (%[\w.]+), %[\w.]+ \], \[ 0, %[\w.]+ \]", dv)
        if ph:
            nxt = ph.group(1)
            if not re.fullmatch(r"add nuw nsw i64 " + re.escape(v) + r", 1", defs.get(nxt, "")):
                return None
            ns = [int(e.group(1)) for e in (re.fullmatch(
                r"icmp eq i64 " + re.escape(nxt) + r", (\d+)", r) for r in defs.values()) if e]
            return max(ns) - 1 if len(ns) == 1 and ns[0] > 0 else None
        return None

    dx = defs.get(x, "")
    sc = re.fullmatch(r"mul nuw nsw i64 (%[\w.]+), (\d+)", dx)
    sh = re.fullmatch(r"shl nuw nsw i64 (%[\w.]+), (\d+)", dx)
    if sc:
        b, k = bound(sc.group(1)), int(sc.group(2))
    elif sh:
        b, k = bound(sh.group(1)), 1 << min(int(sh.group(2)), 40)
    else:
        b, k = bound(x), 1
    return b is not None and c + b * k + 16 < GAME_RAM[1]



def const_addr_ok(val):
    return RAM_LO <= val < RAM_HI or SCRATCH_LO <= val < SCRATCH_HI


def uses_scratchpad(ir):
    for v in re.findall(r"inttoptr \(i64 (-?\d+) to ptr\)|inttoptr i64 (-?\d+) to ptr", ir):
        n = int(v[0] or v[1])
        if SCRATCH_LO <= n < SCRATCH_HI:
            return True
    return False
HOST_TARGET = "x86_64-unknown-linux-gnu"
def host_long(text):
    """PS1 `long` is 32-bit: rewrite lone `long` / `long int` to `int` for the
    LP64 host, keeping `long long` (64-bit on both)."""
    text = re.sub(r"\blong\s+long\b", "\0LL\0", text)
    text = re.sub(r"\blong(\s+int)?\b", "int", text)
    return text.replace("\0LL\0", "long long")


def lower_arith(ir):
    """MIPS semantics for i32 shifts and divisions with a variable operand:
    shift counts are masked to 5 bits (SLLV/SRLV/SRAV use the low 5 bits;
    LLVM makes >= 32 poison), and sdiv/udiv/srem/urem call the guarded
    helpers (a trapping divisor aborts the native call instead of faulting
    the host or inventing a quotient). Constant operands are left alone."""
    out, n = [], 0
    used = set()
    for line in ir.splitlines():
        m = re.match(r"^(\s*)(%[\w.$-]+) = (shl|lshr|ashr)((?: nuw| nsw| exact)*) i32 (.+)$", line)
        if m:
            a, b = split_top(m.group(5))
            if not re.fullmatch(r"-?\d+", b.strip()):
                n += 1
                amt = f"%lane.amt{n}"
                out.append(f"{m.group(1)}{amt} = and i32 {b.strip()}, 31")
                line = f"{m.group(1)}{m.group(2)} = {m.group(3)} i32 {a.strip()}, {amt}"
        m = re.match(r"^(\s*)(%[\w.$-]+) = (sdiv|udiv|srem|urem)(?: exact)? i32 (.+)$", line)
        if m:
            a, b = split_top(m.group(4))
            if not re.fullmatch(r"-?\d+", b.strip()) or int(b) in (0, -1):
                fn = {"sdiv": "lane_sdiv32", "srem": "lane_srem32",
                      "udiv": "lane_udiv32", "urem": "lane_urem32"}[m.group(3)]
                used.add(fn)
                line = f"{m.group(1)}{m.group(2)} = call i32 @{fn}(i32 {a.strip()}, i32 {b.strip()})"
        out.append(line)
    for fn in sorted(used):
        out.append(f"declare i32 @{fn}(i32, i32)")
    return "\n".join(out) + "\n"


def split_operands(text):
    """'"=r"(a), "=r"(b)' -> [('=r', 'a'), ('=r', 'b')]"""
    out = []
    for part in split_top(text, ","):
        m = re.match(r'\s*"([^"]*)"\s*\((.*)\)\s*$', part, flags=re.S)
        if not part.strip():
            continue
        if not m:
            return None
        out.append((m.group(1), re.sub(r"\s+", "", m.group(2))))
    return out


def strip_empty_asm(text, orig=None):
    """Drop empty-template asm statements that are identities on the host:
    no outputs, or every output tied to an input ("N") with the same
    expression; clobbers (incl. "memory") only steer MIPS scheduling. Returns
    (text, dropped) or None when an empty asm has an untied output (its value
    would be whatever the MIPS register held)."""
    pat = re.compile(r'\b(?:__asm__|__asm|asm)\s*(?:__volatile__|volatile)?\s*\(\s*""\s*')
    pos, pieces, dropped = 0, [], 0
    # Strict (B28): an untied output naming a register-pinned local is an
    # identity too. The template emits no instruction, so the pinned MIPS
    # register (the variable itself) keeps its value.
    pinned = set(re.findall(r'\bregister\b[^;={}]*?\b(\w+)\s*(?:__asm__|asm)\s*\(\s*"\$\w+"\s*\)',
                            orig or text)) if STRICT else set()
    for m in pat.finditer(text):
        if m.start() < pos:
            continue
        depth, i = 1, text.index("(", m.start()) + 1
        while i < len(text) and depth:
            depth += {"(": 1, ")": -1}.get(text[i], 0)
            i += 1
        j = i
        while j < len(text) and text[j] in " \t\n":
            j += 1
        if j >= len(text) or text[j] != ";":
            return None
        inner = text[m.end():i - 1]
        sections = split_top(inner, ":")
        outs = split_operands(sections[1]) if len(sections) > 1 else []
        ins = split_operands(sections[2]) if len(sections) > 2 else []
        if outs is None or ins is None:
            return None
        moves = []
        for k, (cons, expr) in enumerate(outs):
            if any(c == str(k) and e == expr for c, e in ins):
                continue
            tied = [e for c, e in ins if c == str(k)]
            if STRICT and len(tied) == 1:
                # Strict: an output tied to a different input expression
                # receives that input's value (the template emits nothing,
                # so the shared register carries it): `out = (in);`.
                moves.append((expr.strip(), tied[0].strip()))
                continue
            if not (STRICT and not tied and expr.strip() in pinned):
                return None
        pieces.append(text[pos:m.start()])
        # A comment marker breaks when the asm text sits inside a comment
        # (80030F80 quotes it in its notes): strict uses a no-op expression,
        # non-strict keeps the old text so its lane stays byte-identical.
        if moves:
            pieces.append(" ".join(f"{o} = ({i});" for o, i in moves))
        else:
            pieces.append("((void)0);" if STRICT else "/* empty asm removed for the host */")
        pos = j + 1
        dropped += 1
    pieces.append(text[pos:])
    return "".join(pieces), dropped


# Host intrinsics (mips_formatter.c formatter_call) whose matched C may run
# in the lane instead of the bespoke host implementation: their only port
# reference is the entry PC the intrinsic dispatch compares, and their file's
# only bespoke macro is a *_BINDING for that host implementation (compiled
# here without it, i.e. the matched body).
INTRINSIC_PCS = {0x80016714, 0x8001903C, 0x80029044, 0x8002906C, 0x80029094, 0x80029218}

CFLAGS = [
    f"--target={HOST_TARGET}", "-std=gnu89", "-fPIE", "-fwrapv",
    "-fno-strict-aliasing", "-fno-builtin", "-ffreestanding",
    "-ftrivial-auto-var-init=zero", "-fno-delete-null-pointer-checks",
    "-w", "-Werror=implicit-function-declaration", "-Werror=implicit-int",
    "-Wno-error=int-conversion", "-Wno-int-conversion",
    "-Wno-error=incompatible-pointer-types",
]
SYM_RE = re.compile(r'@(?:"([^"]+)"|([A-Za-z_.$][\w.$]*))')
GLOBAL_DECL_RE = re.compile(r'^@(?:"([^"]+)"|([\w.$]+)) = (.*)$', re.M)
DEF_RE = re.compile(r"^\s*(%[\w.\"$]+) = (.*)$")


class Reject(Exception):
    def __init__(self, rule, detail):
        super().__init__(f"{rule}: {detail}")
        self.rule, self.detail = rule, detail


class BuildError(Exception):
    """A release input is missing or inconsistent: the build must fail rather
    than ship a lane that silently compiled fewer functions."""


# Overlay members (MAIN.CD main_NNNN, scene scNN_NNNN) share load addresses,
# so their lane symbols carry the member: lane_main_0003__func_800D27A0.
QFUNC = r"(?:[a-z]+\d*_\d{4}__)?func_[0-9A-Fa-f]{8}"


def qualify(member, name):
    return f"{member}__{name}" if member else name


def fnv1a64(data):
    h = 0xCBF29CE484222325
    for b in data:
        h = ((h ^ b) * 0x100000001B3) & 0xFFFFFFFFFFFFFFFF
    return h


def member_info(member, strict=False):
    """From config/overlay_<member>.yaml: the member file (the user's local
    extract), its vram/start mapping, and code ranges (asm/c subsegments).
    When the yaml records a sha1, the file must match it. None when the
    config or the file is missing or the SHA-1 differs; with strict, a
    BuildError naming the problem instead."""
    import hashlib

    def fail(why):
        if strict:
            raise BuildError(f"overlay member {member}: {why}")
        print(f"native_lane_gen: overlay member {member} stays interpreted: {why}")
        return None

    cfg = ROOT / "config" / f"overlay_{member}.yaml"
    if not cfg.exists():
        return fail(f"no {cfg.relative_to(ROOT)}")
    text = cfg.read_text(errors="replace")
    seg = re.search(r"-\s*name:\s*(\w+)\s*\n\s*type:\s*code\s*\n\s*start:\s*(0x[0-9A-Fa-f]+)"
                    r"\s*\n\s*vram:\s*(0x[0-9A-Fa-f]+)", text)
    tp = re.search(r"target_path:\s*(\S+)", text)
    if not seg or not tp:
        return fail(f"{cfg.name} has no code segment or target_path")
    start, vram = int(seg.group(2), 16), int(seg.group(3), 16)
    subs = [(int(m.group(1), 16), m.group(2)) for m in
            re.finditer(r"^\s*-\s*\[\s*(0x[0-9A-Fa-f]+)\s*(?:,\s*(\w+))?", text, flags=re.M)]
    code = [(vram + o - start, vram + n[0] - start) for (o, k), n in zip(subs, subs[1:])
            if k in ("asm", "c", "hasm")]
    path = ROOT / tp.group(1)
    if not code:
        return fail(f"{cfg.name} has no code subsegments")
    if not path.exists():
        return fail(f"member file {tp.group(1)} is not extracted")
    data = path.read_bytes()
    want = re.search(r"^sha1:\s*([0-9A-Fa-f]{40})\s*$", text, flags=re.M)
    if strict and not want:
        return fail(f"{cfg.name} records no sha1 to check the member file against")
    if want and hashlib.sha1(data).hexdigest() != want.group(1).lower():
        return fail(f"member file {tp.group(1)} SHA-1 {hashlib.sha1(data).hexdigest()} "
                    f"!= {want.group(1).lower()} in {cfg.name}")
    return dict(member=member, path=path, vram=vram, start=start, code=code, data=data)


def parse_strict_overlay_allow(path):
    """Like parse_overlay_allow, plus '<member> all': every registry row of
    matched C (recovery "c", source present) in that member, in vram order."""
    registry = json.loads((ROOT / "provenance/matches.json").read_text())["matches"]
    pairs, seen = [], set()
    for n, line in enumerate(Path(path).read_text().splitlines(), 1):
        text = line.split("#", 1)[0].strip()
        if not text:
            continue
        m = re.fullmatch(r"([a-z]+\d*_\d{4})\s+all", text)
        if m:
            starts = sorted({r["vram"] for r in registry if r["region"] == m.group(1)})
            nxt = {a: b for a, b in zip(starts, starts[1:])}
            # 'all' skips rows whose recorded size runs into the next
            # registry function (a registry inconsistency, e.g. main_0012
            # 8012ACE0/801457A4); naming one explicitly still reports it.
            got = sorted(r["vram"] for r in registry if r["region"] == m.group(1)
                         and r.get("recovery") == "c" and (ROOT / r["source"]).exists()
                         and not (r.get("size") and r["vram"] in nxt
                                  and r["vram"] + r["size"] > nxt[r["vram"]]))
            if not got:
                raise BuildError(f"{path}:{n}: {m.group(1)} has no matched C")
            new = [(m.group(1), v) for v in got]
        else:
            m = re.fullmatch(r"([a-z]+\d*_\d{4})\s+(?:0x)?([0-9A-Fa-f]{8})", text)
            if not m:
                raise BuildError(f"{path}:{n}: expected '<member> <vram>' or '<member> all'")
            new = [(m.group(1), int(m.group(2), 16))]
        for pair in new:
            if pair not in seen:
                seen.add(pair)
                pairs.append(pair)
    return pairs


def parse_overlay_allow(path):
    """'<member> <vram>' lines ('#' comments, blank lines ignored) ->
    ordered list of (member, vram). Malformed or repeated lines are errors."""
    pairs, seen = [], set()
    for n, line in enumerate(Path(path).read_text().splitlines(), 1):
        text = line.split("#", 1)[0].strip()
        if not text:
            continue
        m = re.fullmatch(r"([a-z]+\d*_\d{4})\s+(?:0x)?([0-9A-Fa-f]{8})", text)
        if not m:
            raise BuildError(f"{path}:{n}: expected '<member> <vram>', got {line.strip()!r}")
        pair = (m.group(1), int(m.group(2), 16))
        if pair[1] & 3:
            raise BuildError(f"{path}:{n}: unaligned vram {pair[1]:08x}")
        if pair in seen:
            raise BuildError(f"{path}:{n}: duplicate {pair[0]} {pair[1]:08x}")
        seen.add(pair)
        pairs.append(pair)
    return pairs


# Positive origin check for overlay own code: the registry must say who wrote
# the C (a clean-room re-derivation or the owner), and neither the origin nor
# the source header may name third-party code. Untagged C fails.
OWN_ORIGIN = re.compile(r"\bclean[ -]room\b|\bowner\b", re.I)


def overlay_origin_problem(m):
    origin = m.get("origin") or ""
    if provenance_allowed(m):
        return None  # strict + --strict-provenance-allow (B28)
    if not origin.strip():
        return "registry origin is untagged"
    if not OWN_ORIGIN.search(origin):
        return f"registry origin {origin[:60]!r} is not clean-room or owner"
    if third_party_derived(m):
        return f"origin or source header names third-party code ({origin[:60]!r})"
    return None


def overlay_size_problem(m, info, registry_starts):
    """The registry extent must be word-sized, fit one code subsegment of the
    member file and end at or before the member's next registry function."""
    vram, size = m["vram"], m.get("size") or 0
    if size <= 0 or size % 4:
        return f"registry size {size} is not a positive word multiple"
    if not any(lo <= vram and vram + size <= hi for lo, hi in info["code"]):
        return f"extent {vram:08x}+{size} is outside the member's code subsegments"
    if member_digest(info, vram, size) is None:
        return f"extent {vram:08x}+{size} is outside the member file"
    later = [s for s in registry_starts if vram < s < vram + size]
    if later:
        return f"extent {vram:08x}+{size} overlaps the next registry function {later[0]:08x}"
    return None


def guest_jump_table(info, vram, size):
    """First `jr rs` with rs != ra in the member's bytes over the extent (a
    switch through a jump table), or None."""
    off = vram - info["vram"] + info["start"]
    for i in range(0, size, 4):
        word = int.from_bytes(info["data"][off + i:off + i + 4], "little")
        if word >> 26 == 0 and word & 0x3F == 0x08 and (word >> 21) & 31 != 31:
            return vram + i, (word >> 21) & 31
    return None


def switch_tables_internal(info, vram, size):
    """Strict only: every `jr rs` (rs != ra) in the extent is the gcc switch
    idiom `sltiu rB, rI, N; beqz rB, ...; sll rT, rI, 2; lui at, hi;
    addu at, at, rT; lw rs, lo(at); jr rs`, and all N table words (read
    from the member file) are instruction addresses inside the extent. The
    native body compiles the switch from the matched C and never reads the
    guest table. The table only maps cases onto this function's own code,
    which the per-call digest already pins, so leaving it out of the digest
    cannot change the behaviour. Returns False on any doubt."""
    off = vram - info["vram"] + info["start"]
    words = [int.from_bytes(info["data"][off + i:off + i + 4], "little") for i in range(0, size, 4)]
    found = False
    for k, w in enumerate(words):
        if not (w >> 26 == 0 and w & 0x3F == 0x08 and (w >> 21) & 31 != 31):
            continue
        rs = (w >> 21) & 31
        # lw rs, lo(at) within the 3 words before the jr (a nop may sit between)
        lw = next((j for j in range(k - 1, max(k - 4, -1), -1)
                   if words[j] >> 26 == 0x23 and (words[j] >> 16) & 31 == rs), None)
        if lw is None or lw < 2:
            return False
        base = (words[lw] >> 21) & 31
        lo = words[lw] & 0xFFFF
        lo = lo - 0x10000 if lo & 0x8000 else lo
        addu, lui = words[lw - 1], words[lw - 2]
        if not (addu >> 26 == 0 and addu & 0x3F == 0x21 and (addu >> 11) & 31 == base):
            return False
        if lui >> 26 == 0x0F and (lui >> 16) & 31 == base:
            table = (((lui & 0xFFFF) << 16) + lo) & 0xFFFFFFFF
        else:
            # -O0 form: `lui rB, hi; addiu rB, rB, lo; addu rX, rT, rB;
            # lw rs, 0(rX)` (8013B83C)
            addiu = words[lw - 2]
            lui = words[lw - 3] if lw >= 3 else 0
            rb = (addiu >> 16) & 31
            if not (lo == 0 and addiu >> 26 == 0x09 and (addiu >> 21) & 31 == rb and
                    rb in ((addu >> 21) & 31, (addu >> 16) & 31) and
                    lui >> 26 == 0x0F and (lui >> 16) & 31 == rb):
                return False
            alo = addiu & 0xFFFF
            alo = alo - 0x10000 if alo & 0x8000 else alo
            table = (((lui & 0xFFFF) << 16) + alo) & 0xFFFFFFFF
        bound = None
        for j in range(lw - 3, max(lw - 12, -1), -1):
            if words[j] >> 26 == 0x0B:  # sltiu
                bound = words[j] & 0xFFFF
                break
        if not bound or bound > 256:
            return False
        for n in range(bound):
            t = guest_word(table + 4 * n, info)
            if t is None or t & 3 or not vram <= t < vram + size:
                return False
        found = True
    return found


MAIN_EXE = ROOT / "extracted/disc/files/SLUS_007.26"
_MAIN_EXE_BYTES = None
IO_LO, IO_HI = 0x1F801000, 0x1F803000


def guest_word(addr, info=None):
    """Initial 32-bit word at a guest address, from the user's own local
    extract: the member file for overlay data, else the main EXE (loaded at
    0x80010000 after its 0x800-byte header). None when unknown."""
    global _MAIN_EXE_BYTES
    if info:
        off = addr - info["vram"] + info["start"]
        if 0 <= off <= len(info["data"]) - 4:
            return int.from_bytes(info["data"][off:off + 4], "little")
    if _MAIN_EXE_BYTES is None:
        _MAIN_EXE_BYTES = MAIN_EXE.read_bytes() if MAIN_EXE.exists() else b""
    off = addr - 0x80010000 + 0x800
    if 0x800 <= off <= len(_MAIN_EXE_BYTES) - 4:
        return int.from_bytes(_MAIN_EXE_BYTES[off:off + 4], "little")
    return None


def check_device_pointers(ir, info=None):
    """The decompiled C often keeps device-register pointers in plain globals
    (`extern s32 *D_800DB674`, holding 1F8010F0) that no volatile marks. A
    native body dereferencing them would touch host memory at the MMIO
    address. Refuse a function that loads a guest global whose initial word
    (in the user's EXE or member file) is an I/O register address."""
    for m in re.finditer(r"load (?:i32|ptr), ptr inttoptr \(i64 (\d+) to ptr\)", ir):
        addr = int(m.group(1))
        word = guest_word(addr, info)
        if word is not None and IO_LO <= word < IO_HI:
            raise Reject("memory", f"device pointer {addr:08x} -> {word:08x}")


def member_digest(info, pc, size):
    off = pc - info["vram"] + info["start"]
    if off < 0 or off + size > len(info["data"]):
        return None
    return fnv1a64(info["data"][off:off + size])


def run(cmd, **kw):
    return subprocess.run(cmd, capture_output=True, text=True, **kw)


def load_symbol_addrs(member=None):
    """name -> address from tracked config/*syms*.txt / symbol_addrs*.txt.
    With a member, that member's own symbol files come first."""
    table = {}
    paths = sorted((ROOT / "config").glob("*.txt"))
    if member:
        own = [p for p in paths if f".{member}." in p.name]
        paths = own + [p for p in paths if p not in own]
    for path in paths:
        if "sym" not in path.name:
            continue
        for line in path.read_text(errors="replace").splitlines():
            m = re.match(r"\s*([A-Za-z_]\w*)\s*=\s*(0x[0-9A-Fa-f]+)\s*;", line)
            if m:
                table.setdefault(m.group(1), int(m.group(2), 16))
    return table


# Where a port reference to a guest PC sits decides what it means for a native
# body starting at that PC:
#  - formatter_admitted: the interpreter's word-source map, not a hook;
#  - cd_irq_call: CD IRQ frame call-edge checks; the lane is suspended in that
#    frame (musashi_boot_execute_cd_irq_with_services), so not a hook;
#  - the startup loop's observer list, native_boot's observe_entry and
#    spu_source_guard run at the top of the stepping loop, before formatter_step
#    tries the lane: a function's own entry PC stays observed. A body PC in
#    them would be skipped, so it is still a hook.
# Anything else (formatter_step intercepts, formatter_call, stops) is a hook.
IGNORED_HOOK_FUNCS = {"formatter_admitted", "cd_irq_call"}
ENTRY_OK_HOOK_FUNCS = {"run_startup_cpu_loop", "observe_entry", "spu_source_guard"}
# Host-sequenced whatever the context: main never returns (the game loop),
# and STARTUP_ENTRY is driven step by step by native_boot's startup.
ALWAYS_HOOKED = {0x80010178, 0x800141F0}
# PCs the interpreter (formatter_step) compares only to admit a COP2 transfer
# site inside a function whose whole body the lane replaces with an HLE: the
# MTC2 LZCS / MFC2 LZCR pair of func_80049440 (bfm_psyq_LZC). They sequence
# nothing, so a native entry that skips them is exact; interpreted retail code
# still goes through the same admission. Not hooks.
#
# 0x8004239C and 0x800424CC (VSync, bfm_psyq_VSync; 800424CC is VSync's own
# shared epilogue, inside its body because VSync has no registry size and
# psyq_hooked() ends it at the next function start, 800424E4): the formatter
# compares them (TICK_QUERY_ENTRY / TICK_QUERY_RETURN and the
# source-validated call edges that target the entry with a0 == -1 or 1) only
# to accept those interpreted calls. The lane completes
# VSync(mode < 0) natively and REFUSES every other mode before any write, so
# the retail words still run for the waiting modes and mode 1: every
# interpreted path those whitelists guard is unchanged, and they stay valid.
# Why skipping the PC checks is exact (audited, see docs/NATIVE-LANE-RUNTIME):
# every action keyed to these two PCs is an admission or a whitelist for
# INTERPRETED execution: the CD IRQ frame's word table and call edges
# (cd_irq_admitted / cd_irq_call; the lane is suspended in that frame and in
# every IRQ callback, so a VSync called there still runs the retail words and
# reaches both PCs), formatter_admitted's range table, and the
# musashi_boot_run_8004239c_minus_one / 80044124 prefix runners, which
# nothing in the production boot calls. Nothing at either PC advances guest
# time, delivers an IRQ, counts or fast-forwards: the lane charges the
# interpreter's own cost for the path (64 cycles).
# 800424E4 (the wait loop), 800426D4 and 800426FC remain hooked: they are not
# part of the native path.
HLE_REPLACED_GATES = {0x80049440, 0x8004944C, 0x8004239C, 0x800424CC}


def hooked_pcs():
    """{guest PC: "hard" | "entry"} for PCs the port compares against (CPU pc /
    ra / checkpoint continuation tests and case lists, including enum names).
    "entry" PCs are observed only before the lane runs (see above). Word-table
    range bounds and data addresses are not hooks."""
    kinds = {}
    # `ra == 0x...` lines are caller pins (a GTE site admitted only for an
    # audited jal return address): a native caller reaches the callee through
    # the thunk with the sentinel ra, so a body holding the pinned jal would
    # abort there.
    context = re.compile(r"\bpc\b|->pc|\.pc|r\[31\]|raw_cpu|_caller|\bcase |\bra\s*[!=]=")
    named = re.compile(r"\b([A-Z][A-Z0-9_]*)\s*=\s*0x(80[0-9a-fA-F]{6})u?\b")
    func_head = re.compile(r"^(?:static\s+)?(?:inline\s+)?[A-Za-z_][\w\s\*]*?\b(\w+)\s*\([^;]*$")
    texts = [path.read_text(errors="replace") for path in (ROOT / "pc_port").glob("*.c")]
    enums = {}
    for text in texts:
        for m in named.finditer(text):
            enums.setdefault(m.group(1), int(m.group(2), 16))

    def add(pc, kind):
        if kinds.get(pc) != "hard":
            kinds[pc] = kind

    for text in texts:
        func = None
        for line in text.splitlines():
            fm = func_head.match(line)
            if fm and not line.startswith((" ", "\t")) and fm.group(1) not in ("if", "while", "for", "switch"):
                func = fm.group(1)
            if not context.search(line) or "Words" in line:
                continue
            if func in IGNORED_HOOK_FUNCS:
                continue
            kind = "entry" if func in ENTRY_OK_HOOK_FUNCS else "hard"
            pcs = [int(m.group(1), 16) for m in re.finditer(r"0x(80[0-9a-fA-F]{6})u?\b", line)]
            if not named.search(line):
                pcs += [enums[i] for i in re.findall(r"\b[A-Z][A-Z0-9_]*\b", line) if i in enums]
            for pc in pcs:
                add(pc, kind)
    for pc in HLE_REPLACED_GATES:
        kinds.pop(pc, None)
    # bfm_plat entry hooks fire in formatter_step before the lane runs, so a
    # function's own entry PC may stay native ("entry"); a site inside a body
    # would be skipped ("hooks" rule). Native callers reach the sites only
    # through the interpreter thunk (emit_table), which arms the hook.
    for pc in plat_hook_sites():
        add(pc, "entry")
    for pc in ALWAYS_HOOKED:
        kinds[pc] = "hard"
    return kinds


_PINNED_ENTRIES = None
# --strict (MUSASHI_STRICT_NATIVE): no interpreter observes any guest PC.
# Carried in the environment so worker processes see it whatever the start method.
STRICT = os.environ.get("MUSASHI_LANE_STRICT") == "1"


def caller_pinned_entries():
    """Guest entries whose COP2 sites the formatter admits only for a jal
    caller (jal_caller_of(ra, kGteEntryXXXXXXXX), mips_formatter.c). A native
    body reaching one through the interpreter thunk (sentinel ra) would abort
    at the first such site, so a body that calls one is refused (rule hooks)."""
    global _PINNED_ENTRIES
    if _PINNED_ENTRIES is None:
        text = "\n".join(p.read_text(errors="replace") for p in (ROOT / "pc_port").glob("*.c"))
        consts = {m.group(1): int(m.group(2), 16) for m in re.finditer(
            r"\b(kGteEntry[0-9A-Fa-f]{8})\s*=\s*0x([0-9A-Fa-f]{8})u?", text)}
        _PINNED_ENTRIES = {consts[n] for n in re.findall(r"jal_caller_of\([^,()]+,\s*(kGteEntry[0-9A-Fa-f]{8})\)",
                                                         text) if n in consts}
    return _PINNED_ENTRIES


PLAT_HOOK_SITES = ROOT / "pc_port/platform/bfm_plat_hook_sites.c"


def plat_hook_sites():
    """Guest entry PCs of the platform hook table (bfm_plat_hook_sites.c rows
    `{0x8xxxxxxxu, <overlay filter>, BFM_EVENT_..., ...}`)."""
    if not PLAT_HOOK_SITES.exists():
        return set()
    return {int(m.group(1), 16) for m in re.finditer(
        r"^\s*\{\s*0x(80[0-9A-Fa-f]{6})u?\s*,\s*[^,]+,\s*BFM_EVENT_",
        PLAT_HOOK_SITES.read_text(errors="replace"), flags=re.M)}

def guest_address(name, symbols):
    plus = re.fullmatch(r"(.+?)\+(\d+|0x[0-9A-Fa-f]+)", name)
    if plus:  # asm-label aliases such as "D_80078E7C+1"
        base = guest_address(plus.group(1), symbols)
        return None if base is None else base + int(plus.group(2), 0)
    m = re.fullmatch(r"(?:D|func|jtbl|jpt)_([0-9A-Fa-f]{8})", name)
    if m:
        return int(m.group(1), 16)
    return symbols.get(name)


def strip_comments(text):
    text = re.sub(r"/\*.*?\*/", " ", text, flags=re.S)
    return re.sub(r"//[^\n]*", " ", text)


# ---- IR helpers ----------------------------------------------------------

def split_top(text, sep=","):
    parts, depth, cur = [], 0, []
    for ch in text:
        if ch in "([{<":
            depth += 1
        elif ch in ")]}>":
            depth -= 1
        if ch == sep and depth == 0:
            parts.append("".join(cur).strip())
            cur = []
        else:
            cur.append(ch)
    if cur and "".join(cur).strip():
        parts.append("".join(cur).strip())
    return parts


def named_types(ir):
    types = {}
    for m in re.finditer(r"^(%[\w.\"$]+) = type (.*)$", ir, flags=re.M):
        types[m.group(1)] = m.group(2)
    return types


def type_has_ptr(ty, types, seen=None):
    seen = seen or set()
    if re.search(r"\bptr\b", ty):
        return True
    for name in re.findall(r"%[\w.\"$]+", ty):
        if name in types and name not in seen:
            seen.add(name)
            if type_has_ptr(types[name], types, seen):
                return True
    return False


def functions(ir):
    """Yield (header, [body lines]) for every define."""
    lines = ir.splitlines()
    i = 0
    while i < len(lines):
        if lines[i].startswith("define "):
            header, body = lines[i], []
            i += 1
            while i < len(lines) and lines[i] != "}":
                body.append(lines[i])
                i += 1
            yield header, body
        i += 1


INT_TYPES = {"i8", "i16", "i32"}


def parse_params(text):
    """'(i32 noundef signext %0, ptr %1)' -> [(type, attrs)]"""
    inner = text.strip()
    assert inner[0] == "(" and inner[-1] == ")"
    inner = inner[1:-1].strip()
    if not inner:
        return [], False
    params, variadic = [], False
    for part in split_top(inner):
        if part == "...":
            variadic = True
            continue
        tokens = part.split()
        params.append((tokens[0], set(tokens[1:])))
    return params, variadic


def abi_type(ty, attrs, what):
    if ty == "ptr" or ty in INT_TYPES:
        if attrs & {"byval", "sret", "inalloca", "preallocated"}:
            raise Reject("abi", f"{what} passes {ty} by value")
        return ty, ("signext" in attrs, "zeroext" in attrs)
    raise Reject("abi", f"{what} type {ty}")


def parse_signature(header_or_decl, name):
    """-> (ret_type, ret_ext, [(type, ext)])"""
    m = re.search(r"^(?:define|declare)\s+(.*?)@" + re.escape(name) + r"(\(.*\))", header_or_decl)
    if not m:
        raise Reject("abi", f"cannot parse signature of {name}")
    pre = m.group(1).split()
    # Return type is the last token that is a type; attributes precede it.
    ret = next((t for t in reversed(pre) if t == "void" or t == "ptr" or re.fullmatch(r"i\d+", t)), None)
    if ret is None:
        raise Reject("abi", f"return type of {name}")
    ret_attrs = set(pre)
    # Trim trailing function attributes / section after the parameter list.
    params_text = m.group(2)
    depth = 0
    for idx, ch in enumerate(params_text):
        depth += ch == "("
        depth -= ch == ")"
        if depth == 0:
            params_text = params_text[: idx + 1]
            break
    params, variadic = parse_params(params_text)
    if variadic:
        raise Reject("calls", f"{name} is variadic or unprototyped")
    if ret != "void":
        abi_type(ret, set(), f"{name} return")
    return (ret, ("signext" in ret_attrs, "zeroext" in ret_attrs),
            [abi_type(t, a, f"{name} param") for t, a in params])


# ---- Compile + check one source -------------------------------------------

MEMORY_FNS = ("memset", "memcpy", "memmove")
# Guarded division helpers (mips_formatter.c) that lower_arith() calls.
LANE_HELPERS = ("lane_sdiv32", "lane_srem32", "lane_udiv32", "lane_urem32")
# D-011 ledger (pc_port/mips_formatter.c): the cycles a mapped native body
# has charged, a lost-state flag, the deadline budget and the guard's tick.
LEDGER_SYMBOLS = ("musashi_lane_ledger", "musashi_lane_ledger_lost", "musashi_lane_budget",
                  "musashi_lane_seg_extra", "musashi_lane_resume_pc", "musashi_lane_sp_adj",
                  "musashi_lane_entry_sp", "musashi_native_lane_tick")
LEDGER_SEGS = re.compile(r"lane_segs_" + QFUNC)


def rewrite_symbols(ir, symbols, member=None, member_code=()):
    """Replace guest data symbols with absolute guest addresses. Functions
    this TU defines become lane_func_*; calls to guest functions it only
    declares become lane_call_func_* (resolved per signature later); any
    other use of a guest function is its guest code address."""
    decl_globals = {}
    for m in GLOBAL_DECL_RE.finditer(ir):
        decl_globals[m.group(1) or m.group(2)] = m.group(3)
    replace = {}
    for name, rest in decl_globals.items():
        if rest.startswith("external "):
            addr = guest_address(name, symbols)
            if addr is None:
                raise Reject("symbols", f"unresolved data symbol {name}")
            if not RAM_LO <= addr < RAM_HI:
                raise Reject("symbols", f"{name} at {addr:08x} is outside game RAM")
            replace[name] = f"inttoptr (i64 {addr} to ptr)"
        elif not rest.startswith(("private unnamed_addr constant", "internal unnamed_addr constant",
                                  "private constant", "internal constant")):
            raise Reject("symbols", f"TU defines data {name}")
    internal = set(re.findall(r"^define internal [^@]*@([\w.$]+)\(", ir, flags=re.M))
    defined = set(re.findall(r"^define [^@]*@([\w.$]+)\(", ir, flags=re.M)) - internal
    declared = set(re.findall(r"^declare [^@]*@([\w.$]+)\(", ir, flags=re.M))
    guest = set()
    for fname in defined | declared:
        if fname.startswith("llvm.") or fname in MEMORY_FNS:
            continue
        addr = guest_address(fname, symbols)
        if addr is None:
            raise Reject("symbols", f"unresolved function {fname}")
        if not RAM_LO <= addr < RAM_HI:
            raise Reject("symbols", f"function {fname} at {addr:08x} outside game RAM")
        guest.add(fname)
    out_lines = []
    for line in ir.splitlines():
        m = GLOBAL_DECL_RE.match(line)
        if m and (m.group(1) or m.group(2)) in replace:
            continue
        def sub(mm, line=line):
            name = mm.group(1) or mm.group(2)
            if name in replace:
                return replace[name]
            if name in guest:
                after = line[mm.end(): mm.end() + 1]
                is_def_or_decl = line.startswith(("define ", "declare "))
                is_call_target = after == "(" and re.search(r"\bcall\b", line[:mm.start()]) is not None
                if is_def_or_decl or is_call_target:
                    addr = guest_address(name, symbols)
                    local = member and any(lo <= addr < hi for lo, hi in member_code)
                    q = qualify(member, name) if (name in defined or local) else name
                    return ("@lane_" if name in defined else "@lane_call_") + q
                # Address taken: the guest sees its guest code address.
                return f"inttoptr (i64 {guest_address(name, symbols)} to ptr)"
            return mm.group(0)
        out_lines.append(SYM_RE.sub(sub, line))
    return "\n".join(out_lines) + "\n"


def narrow_pointer_cells(ir):
    """Guest memory holds 32-bit pointers. Before optimization, every
    pointer-typed load/store whose address is not a host local slot becomes
    a 32-bit access with zero extension / truncation, and every int->pointer
    conversion goes through the value's 32-bit guest form (C sign-extends an
    int converted to a pointer; the MIPS register is already the address).
    Aggregates holding pointers are refused by check_layout, so no offset or
    size baked into the IR depends on the pointer width."""
    out, counter = [], [0]

    def fresh(tag):
        counter[0] += 1
        return f"%lane.{tag}{counter[0]}"

    allocas = set()
    sext_defs = {}
    for line in ir.splitlines():
        if line.startswith("define "):
            allocas, sext_defs = set(), {}
        m = DEF_RE.match(line)
        if m:
            # strict: an aggregate slot (narrow_aggregate_pointers gave it
            # guest layout) holds 32-bit pointers, so only scalar slots are
            # host-width (B28)
            if m.group(2).startswith("alloca ") and not (
                    STRICT and re.match(r"alloca (%|\[|\{)", m.group(2))):
                allocas.add(m.group(1))
            sm = re.match(r"sext (i\d+) (%[\w.\"$]+) to i64", m.group(2))
            if sm:
                sext_defs[m.group(1)] = (sm.group(1), sm.group(2))
        lm = re.match(r"^(\s*)(%[\w.\"$]+) = load (volatile )?ptr, (.*)$", line)
        if lm:
            parts = split_top(lm.group(4))
            addr = parts[0][len("ptr "):] if parts[0].startswith("ptr ") else None
            if addr is not None and addr not in allocas:
                ind, dst, vol = lm.group(1), lm.group(2), lm.group(3) or ""
                narrow, wide = fresh("n"), fresh("z")
                out.append(f"{ind}{narrow} = load {vol}i32, ptr {addr}, align 1")
                out.append(f"{ind}{wide} = zext i32 {narrow} to i64")
                out.append(f"{ind}{dst} = inttoptr i64 {wide} to ptr")
                continue
        st = re.match(r"^(\s*)store (volatile )?ptr (.*)$", line)
        if st:
            parts = split_top(st.group(3))
            addr = parts[1][len("ptr "):] if len(parts) > 1 and parts[1].startswith("ptr ") else None
            if addr is not None and addr not in allocas:
                ind, vol, value = st.group(1), st.group(2) or "", parts[0]
                narrow = fresh("t")
                out.append(f"{ind}{narrow} = ptrtoint ptr {value} to i32")
                out.append(f"{ind}store {vol}i32 {narrow}, ptr {addr}, align 1")
                continue
        im = re.match(r"^(\s*)(%[\w.\"$]+) = inttoptr i64 (%[\w.\"$]+) to ptr(.*)$", line)
        if im and im.group(3) in sext_defs:
            ind = im.group(1)
            width, src = sext_defs[im.group(3)]
            value = src
            if width != "i32":
                value = fresh("s")
                out.append(f"{ind}{value} = sext {width} {src} to i32")
            wide = fresh("z")
            out.append(f"{ind}{wide} = zext i32 {value} to i64")
            out.append(f"{ind}{im.group(2)} = inttoptr i64 {wide} to ptr{im.group(4)}")
            continue
        out.append(line)
    return "\n".join(out) + "\n"



def llvm_type_layout(ty, types, ptr_bytes):
    """(size, align) of an LLVM type under the x86-64 data layout, with
    `ptr` taken as ptr_bytes wide (8 on the host, 4 for guest layout).
    None when the type is not understood."""
    ty = ty.strip()
    if ty == "ptr":
        return ptr_bytes, ptr_bytes
    m = re.fullmatch(r"i(\d+)", ty)
    if m:
        bits = int(m.group(1))
        size = {1: 1, 8: 1, 16: 2, 32: 4, 64: 8}.get(bits)
        return (size, size) if size else None
    if ty in ("float", "double"):
        return (4, 4) if ty == "float" else (8, 8)
    m = re.fullmatch(r"\[(\d+) x (.*)\]", ty)
    if m:
        el = llvm_type_layout(m.group(2), types, ptr_bytes)
        return (int(m.group(1)) * el[0], el[1]) if el else None
    if ty in types:
        return llvm_type_layout(types[ty], types, ptr_bytes)
    packed = ty.startswith("<{") and ty.endswith("}>")
    if packed or (ty.startswith("{") and ty.endswith("}")):
        inner = ty[2:-2] if packed else ty[1:-1]
        off, align = 0, 1
        for field in split_top(inner):
            fl = llvm_type_layout(field, types, ptr_bytes)
            if fl is None:
                return None
            fa = 1 if packed else fl[1]
            off = (off + fa - 1) // fa * fa + fl[0]
            align = max(align, fa)
        return (off + align - 1) // align * align, align
    return None


def entry_arg_at_calls(words, vram, k):
    """Strict only (B28): {call target: True when a(k) still holds the
    function's entry value at every jal to it}, by a forward must-analysis
    over the retail words (a write to a(k) or any earlier call kills it; a
    jal's delay slot runs before the call). None when the control flow
    cannot be followed (jr through a register other than ra)."""
    n = len(words)
    bit = 1 << k
    state = [None] * (n + 1)
    state[0] = True
    sites = {}
    work = [0]
    while work:
        i = work.pop()
        if i >= n:
            continue
        cur = state[i]
        x = _xfer(words[i], vram + 4 * i)
        if x is None:
            succ = [(i + 1, cur and not (_a_writes(words[i]) & bit))]
        else:
            kind, target = x
            if kind == "jr":
                return None
            after = cur and not (_a_writes(words[i]) & bit)
            if i + 1 >= n:
                return None
            slot = after and not (_a_writes(words[i + 1]) & bit)
            succ = []
            if kind in ("call", "icall"):
                if kind == "call":
                    sites[target] = sites.get(target, True) and slot
                succ.append((i + 2, False))
            elif kind == "b":
                t = (target - vram) // 4
                succ += [(i + 2, slot)] + ([(t, slot)] if 0 <= t < n else [])
            elif kind == "j":
                t = (target - vram) // 4
                if 0 <= t < n:
                    succ.append((t, slot))
        for j, v in succ:
            if j > n:
                continue
            old = state[j]
            new = v if old is None else (old and v)
            if new != old:
                state[j] = new
                work.append(j)
    return sites


def fix_short_calls(ir, words, vram):
    """Strict only (B28): a direct call that passes fewer arguments than the
    callee's declaration takes (`((void (*)(void))f)()` on an `f(s32)`).
    The retail jal hands the callee whatever a0-a3 still hold; the optimizer
    would fill the missing native argument with a constant (80136BC4 got
    a0 = 0 from 801336E8 and faulted). When the retail words leave the
    missing a(k) untouched on every path to every jal of that callee
    (entry_arg_at_calls), the register still holds the caller's own k-th
    argument there: the call gets the caller's parameter k. Any other short
    call is refused (abi)."""
    decls = {}
    for m in re.finditer(r"^declare\b[^@]*@([\w.$]+)\((.*)\)[^(]*$", ir, flags=re.M):
        if "..." not in m.group(2):
            decls[m.group(1)] = [p.split()[0] for p in split_top(m.group(2)) if p]
    dm = re.search(r"^define\b[^@]*@([\w.$]+)\((.*)\)[^(]*\{$", ir, flags=re.M)
    own = []
    if dm and "..." not in dm.group(2):
        for p in split_top(dm.group(2)):
            toks = p.split()
            if toks and toks[-1].startswith("%"):
                own.append((toks[0], toks[-1]))
    out, n = [], 0
    for line in ir.splitlines():
        cm = re.search(r"\bcall ([^@]*)@([\w.$]+)\((.*)\)", line)
        if not cm or cm.group(2) not in decls or cm.group(2).startswith("llvm."):
            out.append(line)
            continue
        args = [a for a in split_top(cm.group(3)) if a]
        want = decls[cm.group(2)]
        if len(args) >= len(want):
            out.append(line)
            continue
        why = None
        if words is None:
            why = "retail words unavailable"
        elif not re.fullmatch(r"func_[0-9A-Fa-f]{8}", cm.group(2)):
            why = "the callee has no retail address"
        elif len(want) > 4 or len(own) < len(want):
            why = "the caller does not receive the missing arguments"
        if why is None:
            ind = re.match(r"^\s*", line).group(0) or "  "
            for k in range(len(args), len(want)):
                live = entry_arg_at_calls(words, vram, k)
                if not live or not live.get(int(cm.group(2)[5:], 16)):
                    why = f"a{k} is not the caller's argument at every retail jal"
                    break
                (oty, oval), cty = own[k], want[k]
                if oty == cty:
                    args.append(f"{cty} {oval}")
                elif oty == "ptr" and cty == "i32":
                    out.append(f"{ind}%lane.ar{n} = ptrtoint ptr {oval} to i32")
                    args.append(f"i32 %lane.ar{n}")
                    n += 1
                elif oty == "i32" and cty == "ptr":
                    out.append(f"{ind}%lane.ar{n}.z = zext i32 {oval} to i64")
                    out.append(f"{ind}%lane.ar{n} = inttoptr i64 %lane.ar{n}.z to ptr")
                    args.append(f"ptr %lane.ar{n}")
                    n += 1
                else:
                    why = f"argument {k} is {oty} in the caller, {cty} in the callee"
                    break
        if why is not None:
            raise Reject("abi", f"calls {cm.group(2)} with {len([a for a in split_top(cm.group(3)) if a])} "
                                f"of {len(want)} declared arguments ({why})")
        out.append(line[:cm.start(3)] + ", ".join(args) + line[cm.end(3):])
    return "\n".join(out) + "\n"


def strip_symbol_binding_asm(ir):
    """Strict only (B28): drop file-scope asm that only binds a symbol to a
    retail address (`.globl memcpy` / `.set memcpy, 0x8005C324`). The vendor
    C uses it so gcc-2.7.2's struct-copy library call lands on the retail
    memcpy; the lane's struct copy is an llvm.memcpy intrinsic, and an
    absolute host `memcpy` would break the link. Any other module asm, or a
    direct call to the bound symbol, is refused."""
    names = set()
    out = []
    for line in ir.splitlines():
        m = re.match(r'^module asm "(.*)"$', line)
        if not m:
            out.append(line)
            continue
        text = m.group(1).strip()
        g = re.fullmatch(r"\.globl\s+([A-Za-z_][\w$]*)", text)
        st = re.fullmatch(r"\.set\s+([A-Za-z_][\w$]*)\s*,\s*0x[0-9A-Fa-f]+", text)
        if not (g or st) and text:
            raise Reject("symbols", f"module asm {text[:60]}")
        if g or st:
            names.add((g or st).group(1))
    body = "\n".join(out)
    for n in names:
        if re.search(r"@" + re.escape(n) + r"\b", body):
            raise Reject("symbols", f"direct use of asm-bound symbol {n}")
    return body + "\n"


def narrow_aggregate_pointers(ir):
    """Strict only (B28): give pointer-bearing aggregates their guest layout.
    Guest pointers are 32-bit, so in every named type and array type a `ptr`
    member becomes `i32`, and pointer-element indexing (`p[i]` on a `T **`)
    strides by 4. Field and element addresses then match the guest's, and
    narrow_pointer_cells turns each pointer load/store through them into the
    32-bit access it already uses for scalar guest pointer cells. Copies and
    fills whose byte count the front end sized with host pointers cannot be
    fixed up and are refused. -> (ir, changed)."""
    types = named_types(ir)
    if not any(type_has_ptr(t, types) for t in types.values()) and \
            not re.search(r"\[\d+ x ptr\]|getelementptr (?:inbounds |nuw |nusw )*ptr,", ir):
        return ir, False
    # allocas whose type holds no pointer: a memset of one (the zero
    # auto-init of a local) is sized the same on host and guest
    alloca_types = dict(re.findall(r"^\s*(%[\w.\"$]+) = alloca (.*?), align \d+", ir, flags=re.M))
    plain = {n for n, t in alloca_types.items() if not type_has_ptr(t, types)}
    plain_sizes, ptr_sizes = set(), set()
    for tn in types:
        lay = llvm_type_layout(tn, types, 8)
        if lay is None:
            ptr_sizes.add(-1)
            continue
        (ptr_sizes if type_has_ptr(tn, types) else plain_sizes).add(lay[0])
    if -1 in ptr_sizes:
        plain_sizes = set()
    # a copy whose end is a global or local of one named pointer-bearing
    # type and whose constant length is that type's host size is a whole
    # struct assignment: it gets the guest-layout size (B28)
    typed = dict(alloca_types)
    typed.update(re.findall(r"^(@[\w.$\"]+) = (?:external |internal |private |dso_local |common )*global (%[\w.\"$]+)\b", ir, flags=re.M))
    copy_lines = []
    for line in ir.splitlines():
        cm = re.search(r"call void @llvm\.mem(?:cpy|move)[\w.]*\(ptr (?:align \d+ )?([%@][\w.\"$]+), "
                       r"ptr (?:align \d+ )?([%@][\w.\"$]+), i64 (\d+), i1 false\)", line)
        if not cm:
            copy_lines.append(line)
            continue
        ends = {typed[n] for n in (cm.group(1), cm.group(2)) if n in typed}
        ty = next(iter(ends)) if len(ends) == 1 else None
        if ty and ty in types and type_has_ptr(ty, types):
            host = llvm_type_layout(ty, types, 8)
            guest = llvm_type_layout(ty, types, 4)
            if host and guest and host[0] == int(cm.group(3)):
                line = (line[:cm.start()] +
                        f"call void @llvm.memcpy.p0.p0.i64(ptr align 1 {cm.group(1)}, "
                        f"ptr align 1 {cm.group(2)}, i64 {guest[0]}, i1 false)" + line[cm.end():])
                if "memmove" in cm.group(0):
                    line = line.replace("@llvm.memcpy.p0.p0.i64", "@llvm.memmove.p0.p0.i64", 1)
                line += " ; strict-struct-assign"
        copy_lines.append(line)
    ir = "\n".join(copy_lines) + "\n"
    out = []
    for line in ir.splitlines():
        if re.match(r"^%[\w.\"$]+ = type ", line):
            head, body = line.split(" = type ", 1)
            line = head + " = type " + re.sub(r"\bptr\b", "i32", body)
        else:
            prev = None
            while prev != line:
                prev = line
                line = re.sub(r"\[(\d+) x ptr\]", r"[\1 x i32]", line)
            line = re.sub(r"getelementptr ((?:inbounds |nuw |nusw )*)ptr,", r"getelementptr \1i32,", line)
        out.append(line)
    ir = "\n".join(out) + "\n"
    for line in ir.splitlines():
        if re.search(r"call .*@llvm\.mem(?:cpy|move|set)", line):
            ms = re.search(r"@llvm\.memset[\w.]*\(ptr (?:align \d+ )?(%[\w.\"$]+),", line)
            if ms and ms.group(1) in plain:
                continue
            if line.endswith("; strict-struct-assign"):
                continue
            # a constant-length copy the size of a pointer-free struct and of
            # no pointer-bearing type is a plain struct assignment (the same
            # size on host and guest; 8013D53C copies a 9-byte record)
            cl = re.search(r"@llvm\.mem(?:cpy|move)[\w.]*\(.*, i64 (\d+), i1 false\)", line)
            if cl and int(cl.group(1)) in plain_sizes and int(cl.group(1)) not in ptr_sizes:
                continue
            raise Reject("layout", "aggregate copy/fill sized with host pointer width")
    return ir, True


def check_layout(ir):
    types = named_types(ir)
    ptr_types = {n for n, t in types.items() if type_has_ptr(t, types)}
    body = re.sub(r"^%[\w.\"$]+ = type .*$", "", ir, flags=re.M)
    for name in ptr_types:
        if re.search(re.escape(name) + r"\b", body):
            raise Reject("layout", f"uses pointer-bearing type {name}")
    if re.search(r"\[\d+ x ptr\]", body):
        raise Reject("layout", "array of pointers")
    for header, lines in functions(ir):
        for line in lines:
            if re.search(r"getelementptr (?:inbounds |nuw |nusw )*ptr,", line):
                raise Reject("layout", "pointer-element indexing")


def check_optimized(ir, module_internal):
    types = named_types(ir)
    private_globals = set(re.findall(r"^@([\w.$]+) = (?:private|internal)", ir, flags=re.M))
    for header, lines in functions(ir):
        defs = {}
        for line in lines:
            m = DEF_RE.match(line)
            if m:
                defs[m.group(1)] = m.group(2)
        tainted = set()
        for name, rhs in defs.items():
            if rhs.startswith("alloca "):
                tainted.add(name)
        changed = True
        while changed:
            changed = False
            for name, rhs in defs.items():
                if name in tainted:
                    continue
                op = rhs.split()[0] if rhs.split() else ""
                if op in ("getelementptr", "bitcast", "phi", "select", "addrspacecast", "freeze"):
                    if any(t in re.findall(r"%[\w.\"$]+", rhs) for t in tainted) or \
                            any("@" + g in rhs for g in private_globals):
                        tainted.add(name)
                        changed = True

        def refs_host(text):
            return any(re.search(re.escape(t) + r"\b", text) for t in tainted) or \
                any(re.search("@" + re.escape(g) + r"\b", text) for g in private_globals)

        # Strict builds: a volatile access whose address provably derives from
        # a constant guest RAM or scratchpad address (inttoptr bases through
        # getelementptr/phi/select/bitcast only), or is a local, is ordinary
        # memory. Matched C
        # uses volatile on RAM fields to pin gcc 2.7.2's store order; device
        # registers stay refused (their addresses are MMIO or pointer cells).
        def const_ram(text):
            nums = [int(n) for n in re.findall(r"inttoptr \(i\d+ (-?\d+) to ptr\)", text)]
            return bool(nums) and all(0x80000000 <= (n & 0xFFFFFFFF) < 0x80200000 or
                                      0x1F800000 <= (n & 0xFFFFFFFF) < 0x1F800400
                                      for n in nums)
        def ram_value(v, ram):
            v = v.strip()
            if v.startswith("ptr "):
                v = v[4:].strip()
            if v.startswith("%"):
                return v in ram
            return const_ram(v) and "%" not in v

        ram_ptr = set()
        if STRICT:
            # greatest fixpoint: loop phis are RAM-derived unless some
            # incoming pointer is not
            ram_ptr = {n for n, r in defs.items()
                       if r.split()[0] in ("getelementptr", "phi", "select", "bitcast")
                       and (r.startswith("phi ptr") or r.startswith("select") or
                            r.startswith("bitcast ptr") or r.startswith("getelementptr"))}
            changed = True
            while changed:
                changed = False
                for name in sorted(ram_ptr):
                    r = defs[name]
                    op = r.split()[0]
                    if op == "getelementptr":
                        body = re.sub(r"^getelementptr (?:inbounds |nuw |nusw )*", "", r)
                        parts = split_top(body)
                        ok = len(parts) > 1 and ram_value(parts[1], ram_ptr)
                    elif op == "phi":
                        vals = re.findall(r"\[\s*(.+?),\s*%[\w.\"$]+\s*\]", r)
                        ok = bool(vals) and all(ram_value(v, ram_ptr) for v in vals)
                    elif op == "select":
                        parts = split_top(r[len("select"):])
                        ok = len(parts) == 3 and all(ram_value(v, ram_ptr) for v in parts[1:])
                    else:
                        ok = ram_value(r[len("bitcast"):].split(" to ")[0], ram_ptr)
                    if not ok:
                        ram_ptr.discard(name)
                        changed = True

        def ram_address(addr):
            # a local (alloca: host stack frame, e.g. gcc frame padding) is
            # ordinary memory too
            a = addr.strip()
            a = a[4:].strip() if a.startswith("ptr ") else a
            return ram_value(addr, ram_ptr) or defs.get(a, "").startswith("alloca ")

        for line in lines:
            s = line.strip()
            if not s or s.endswith(":") or s.startswith(";"):
                continue
            if re.search(r"\b(undef|poison)\b", s):
                raise Reject("ub", "undef/poison operand")
            if s == "unreachable":
                raise Reject("ub", "unreachable")
            m = DEF_RE.match(line)
            rhs = m.group(2) if m else s
            if re.search(r"\basm\b", rhs) and not empty_asm_identity(rhs):
                raise Reject("calls", "inline asm")
            if rhs.startswith(("atomicrmw", "cmpxchg", "fence")) or " atomic " in rhs:
                raise Reject("memory", "atomic operation")
            if re.match(r"(load|store) volatile ", rhs) or "i1 true)" in rhs and "llvm.mem" in rhs:
                # Decomp C marks device access volatile; a pointer cell such
                # as D_8006B560 holds an MMIO address the host cannot map.
                vol_ok = False
                if STRICT and re.match(r"(load|store) volatile ", rhs):
                    parts = split_top(re.sub(r"^(load|store) volatile ", "", rhs))
                    vol_ok = len(parts) > 1 and ram_address(parts[1])
                if not vol_ok:
                    raise Reject("memory", "volatile access (device register)")
            if re.match(r"load (volatile )?", rhs):
                ty = split_top(re.sub(r"^load (volatile )?", "", rhs))[0]
                addr = split_top(re.sub(r"^load (volatile )?", "", rhs))[1]
                if type_has_ptr(ty, types) and not refs_host(addr):
                    raise Reject("memory", "pointer load from guest memory")
            if re.match(r"store (volatile )?", rhs):
                parts = split_top(re.sub(r"^store (volatile )?", "", rhs))
                value, addr = parts[0], parts[1]
                if type_has_ptr(value.split()[0], types) and not refs_host(addr):
                    raise Reject("memory", "pointer store to guest memory")
                if refs_host(value):
                    raise Reject("escape", "host address stored")
            if rhs.startswith("ptrtoint") and refs_host(rhs):
                raise Reject("escape", "host address converted to integer")
            if rhs.startswith("ret ") and refs_host(rhs):
                raise Reject("escape", "host address returned")
            if re.match(r"inttoptr ", rhs):
                src = split_top(rhs[len("inttoptr "):].split(" to ")[0])[0].split()
                val = src[-1]
                if val.startswith("%"):
                    d = defs.get(val, "")
                    if not (d.startswith("zext i32") or d.startswith("zext nneg i32") or
                            re.match(r"and i64 .*, 4294967295$", d) or
                            (STRICT and bounded_guest_affine(val, defs)) or
                            (STRICT and scev_in_game_ram(ir, header, val))):
                        raise Reject("inttoptr", f"integer->pointer from '{d[:40]}'")
                elif re.fullmatch(r"-?\d+", val) and not const_addr_ok(int(val)):
                    raise Reject("inttoptr", f"constant address {int(val):x}")
            for const in re.findall(r"inttoptr \(i64 (-?\d+) to ptr\)", rhs):
                if not const_addr_ok(int(const)):
                    raise Reject("inttoptr", f"constant address {int(const) & 0xffffffffffffffff:x}")
            dm = re.match(r"(sdiv|udiv|srem|urem)(?: exact)? (i\d+) (.*)$", rhs)
            if dm:
                divisor = split_top(dm.group(3))[1]
                if not re.fullmatch(r"-?\d+", divisor) or int(divisor) in (0, -1):
                    raise Reject("arith", f"{dm.group(1)} by {divisor}")
            sm = re.match(r"(shl|lshr|ashr)(?: nuw| nsw| exact)* (i\d+) (.*)$", rhs)
            if sm:
                amount = split_top(sm.group(3))[1]
                if not re.fullmatch(r"\d+", amount):
                    d = defs.get(amount, "")
                    mm = re.match(r"and i\d+ (?:%[\w.\"$]+, (\d+)|(\d+), %[\w.\"$]+)$", d)
                    mask = int(mm.group(1) or mm.group(2)) if mm else None
                    if mask is None or mask > 31:
                        raise Reject("arith", "unmasked variable shift")
                elif int(amount) >= int(sm.group(2)[1:]):
                    raise Reject("arith", "oversized constant shift")
            cm = re.search(r"\b(?:tail |musttail |notail )?call\b(.*)$", rhs)
            if cm and empty_asm_identity(rhs):
                continue  # emits nothing; outputs are the tied inputs
            if cm:
                call = cm.group(1)
                target = re.search(r"(@[\w.$]+|%[\w.\"$]+)\(", call)
                if not target or target.group(1).startswith("%"):
                    raise Reject("calls", "indirect call")
                if "inttoptr" in call.split("(")[0]:
                    raise Reject("calls", "call through a guest address")
                name = target.group(1)[1:]
                args = call[target.end():]
                if name.startswith("llvm."):
                    if not re.match(r"llvm\.(lifetime|memset|memcpy|memmove|smax|smin|umax|umin|abs|"
                                    r"ctlz|cttz|ctpop|fshl|fshr|bswap|assume|experimental\.noalias|"
                                    r"sadd|uadd|ssub|usub|vector\.reduce)", name):
                        raise Reject("calls", f"intrinsic {name}")
                    continue
                if name in ("memset", "memcpy", "memmove") or name in LANE_HELPERS or name in LEDGER_SYMBOLS:
                    continue
                if name in module_internal:
                    continue
                if not (re.fullmatch(r"lane_(?:call_)?" + QFUNC + r"(?:__\w+)?", name) or
                        name.startswith("lane_icall__")):
                    raise Reject("calls", f"call to {name}")
                if refs_host(args):
                    raise Reject("escape", f"host address passed to {name}")


def loop_walks_memory(body):
    """True when some load in the loop reads an address that changes each
    iteration: its pointer derives (transitively, within the loop) from a phi
    defined in the loop. Such a loop (a table search, a string scan) ends on
    the data it reads; a polling loop re-reads the same address."""
    tainted = set()
    for l in body:
        m = re.match(r"\s*(%[\w.$-]+)\s*=\s*phi\b", l)
        if m:
            tainted.add(m.group(1))
    changed = True
    while changed:
        changed = False
        for l in body:
            m = re.match(r"\s*(%[\w.$-]+)\s*=\s*(.*)", l)
            if not m or m.group(1) in tainted:
                continue
            if any(re.search(re.escape(t) + r"\b", m.group(2)) for t in tainted):
                tainted.add(m.group(1))
                changed = True
    for l in body:
        m = re.search(r"=\s*load\b[^,]*,\s*ptr\s+(%[\w.$-]+)", l)
        if m and m.group(1) in tainted:
            return True
    return False


ICALL_RE = re.compile(r"^(\s*(?:%[\w.\"$]+ = )?)((?:tail |musttail |notail )?call )"
                      r"((?:[\w]+ )*?)(void|i8|i16|i32|ptr) (%[\w.\"$]+)\((.*)\)(\s*#\d+)?\s*$")
ARG_TYPES = ("i8", "i16", "i32", "ptr")


def rewrite_indirect_calls(ir):
    """Route calls through function pointers to the interpreter, as jalr does.

    A guest function pointer holds a guest address (a zero-extended 32-bit
    value). `call T %fp(args)` becomes `call T @lane_icall__<sig>(i32 addr,
    args)`, whose generated stub runs musashi_native_guest_call(addr, ...);
    the interpreter then dispatches the target (natively again when the lane
    admits it). Returns (ir, {symbol: (ret, rext, params)}). A call with an
    argument type the guest ABI cannot carry is left alone, and the checker
    refuses it as before."""
    out, icalls, n = [], {}, 0
    for line in ir.splitlines():
        m = ICALL_RE.match(line)
        if not m or " asm " in line:
            out.append(line)
            continue
        lead, call, rattrs, ret, fp, args, attrs = m.groups()
        params = []
        ok = True
        for a in split_top(args):
            toks = a.split()
            if not toks or toks[0] not in ARG_TYPES:
                ok = False
                break
            params.append((toks[0], ("signext" in toks[1:-1], "zeroext" in toks[1:-1])))
        if not ok or len(params) > 8:
            out.append(line)
            continue
        rext = ("signext" in rattrs.split(), "zeroext" in rattrs.split())
        sig = (ret, rext, tuple(params))
        sym = "lane_icall__" + sig_code((ret, rext, params))
        icalls[sym] = sig
        indent = re.match(r"^\s*", line).group(0) or "  "
        out.append(f"{indent}%icall.{n} = ptrtoint ptr {fp} to i64")
        out.append(f"{indent}%icall.{n}.t = trunc i64 %icall.{n} to i32")
        new_args = ", ".join([f"i32 %icall.{n}.t"] + split_top(args))
        out.append(f"{lead}{call}{rattrs}{ret} @{sym}({new_args}){attrs or ''}")
        n += 1
    for sym, (ret, rext, params) in sorted(icalls.items()):
        def t(ty, e):
            return ty + (" signext" if e[0] else " zeroext" if e[1] else "")
        plist = ", ".join(["i32"] + [t(ty, e) for ty, e in params])
        rdecl = ("signext " if rext[0] else "zeroext " if rext[1] else "") + ret
        out.append(f"declare {rdecl} @{sym}({plist})")
    return "\n".join(out) + "\n", icalls


def check_polling_loops(ir):
    """A native call runs to completion without IRQ delivery. A loop that
    neither stores nor calls can only make progress through state an IRQ or
    device changes (a VSync counter, a DMA flag), so it could spin forever
    natively. Refuse any such loop; counting loops that also store or call
    are unaffected."""
    for header, lines in functions(ir):
        labels = {}
        for idx, line in enumerate(lines):
            m = re.match(r"^([\w.$-]+):", line)
            if m:
                labels["%" + m.group(1)] = idx
        # The entry block is unlabeled; numbered blocks still get "N:" lines.
        for idx, line in enumerate(lines):
            if not line.strip().startswith("br "):
                continue
            for target in re.findall(r"label (%[\w.$\"-]+)", line):
                start = labels.get(target)
                if start is None or start > idx:
                    continue
                body = lines[start: idx + 1]
                if not any(re.search(r"\bstore\b", l) or
                           (re.search(r"\bcall\b", l) and "@llvm." not in l) for l in body) \
                        and not loop_walks_memory(body):
                    raise Reject("irq", "loop with no store or call (polling)")


def lane_names(ir):
    return set(re.findall(r"^define [^@]*@(lane_" + QFUNC + r")\(", ir, flags=re.M))


def sig_code(sig):
    ret, rext, params = sig
    def tok(t, e):
        return t + ("s" if e[0] else "z" if e[1] else "")
    return "r" + tok(ret, rext) + "".join("_" + tok(t, e) for t, e in params)


def resolve_calls(optir):
    """Give each lane_call_func_* a signature-specific symbol. Returns
    (ir, {symbol: (callee, sig or None, argc)}); sig None = unprototyped,
    called with at most argc register-width arguments."""
    stubs, renames = {}, {}
    for decl in [l for l in optir.splitlines() if l.startswith("declare ")]:
        m = re.search(r"@(lane_call_(" + QFUNC + r"))\(", decl)
        if not m:
            continue
        sym, callee = m.group(1), m.group(2)
        if re.search(r"\(\s*\.\.\.\s*\)", decl) or ", ...)" in decl:
            argc = 0
            ret = parse_return(decl, sym)
            for line in optir.splitlines():
                if line.startswith("declare ") or "@" + sym + "(" not in line:
                    continue
                inner = line.split("@" + sym + "(", 1)[1]
                depth, end = 1, 0
                for end, ch in enumerate(inner):
                    depth += ch == "("
                    depth -= ch == ")"
                    if depth == 0:
                        break
                args = split_top(inner[:end])
                for a in args:
                    ty = a.split()[0]
                    if ty not in ("i32", "ptr", "i8", "i16"):
                        raise Reject("abi", f"unprototyped {callee} gets {ty}")
                argc = max(argc, len(args))
            if argc > 6:
                raise Reject("abi", f"unprototyped {callee} with {argc} arguments")
            new = f"{sym}__va{argc}_{ret[0]}{'s' if ret[1][0] else ''}"
            stubs[new] = (callee, None, argc, ret)
        else:
            sig = parse_signature(decl, sym)
            new = f"{sym}__{sig_code(sig)}"
            stubs[new] = (callee, sig, len(sig[2]), None)
        renames[sym] = new
    for old, new in renames.items():
        optir = re.sub(r"@" + re.escape(old) + r"\b", "@" + new, optir)
    return optir, stubs


def parse_return(decl, name):
    m = re.search(r"^declare\s+(.*?)@" + re.escape(name) + r"\(", decl)
    pre = m.group(1).split() if m else []
    ret = next((t for t in reversed(pre) if t in ("void", "ptr") or re.fullmatch(r"i\d+", t)), None)
    if ret is None or (ret != "void" and ret not in ("ptr", "i8", "i16", "i32")):
        raise Reject("abi", f"return type of {name}")
    return ret, ("signext" in pre, "zeroext" in pre)


ASM_CALL_RE = re.compile(r'\basm\s+(?:sideeffect\s+)?(?:alignstack\s+)?(?:inteldialect\s+)?"([^"]*)",\s*"([^"]*)"')


def empty_asm_identity(rhs):
    """An empty asm template ("") emits no instruction. It is an identity
    when each output is tied to an input ("=r,0"); decomp C uses these as
    scheduling barriers for gcc-2.7.2 matching. An untied output would be
    an undefined value, so it is still refused."""
    m = ASM_CALL_RE.search(rhs)
    if not m or m.group(1).strip():
        return False
    cons = [c for c in m.group(2).split(",") if c]
    outs = [c for c in cons if c.startswith("=")]
    ins = [c for c in cons if not c.startswith(("=", "~"))]
    tied = {int(c) for c in ins if c.isdigit()}
    return all(i in tied for i in range(len(outs)))


# `register int x asm("$5")` pins a MIPS register for matching; C semantics
# are unchanged, and the host compiler rejects the MIPS name.
REG_PIN_RE = re.compile(r'(\bregister\b[^;={}]*?)\s*(?:__asm__|asm)\s*\(\s*"\$\w+"\s*\)')


GLOBAL_PIN_RE = re.compile(r'^register\s+([^;{}=]*?)\s*(?:__asm__|asm)\s*\(\s*"\$\w+"\s*\)\s*;', re.M)


def host_source(text):
    if STRICT:
        # Strict (B28): a file-scope register variable (GCC global register
        # binding, 800118AC) only pins a caller-saved MIPS register for the
        # byte match; no value survives a call or return in it. On the host
        # it becomes a plain local of every function body.
        decls = GLOBAL_PIN_RE.findall(text)
        if decls:
            text = GLOBAL_PIN_RE.sub("", text)
            local = "".join(f" {d};" for d in decls)
            text = re.sub(r"^(\w[^;{}()]*\([^;{}]*\)\s*\{)", lambda m: m.group(1) + local,
                          text, flags=re.M)
    return REG_PIN_RE.sub(r"\1", text)


# Admissible by every rule, but held out until a differential covers them:
# with the probe's generic inputs none of their cases was comparable.
DENY = {
    0x80015498: "no comparable differential case yet (mirror faults on generic inputs)",
    0x80016638: "no comparable differential case yet (not comparable / mirror faults)",
    0x800167F0: "no comparable differential case yet (mirror faults on generic inputs)",
    0x8002FF0C: "no comparable differential case yet (interpreter refused every case)",
    # Guest-frame locals (place_guest_locals) admit these; held out:
    0x800128EC: "retail cycle mapping ambiguous: would keep the fixed charge (inexact timing)",
    0x80014168: "no comparable differential case yet (the interpreter refuses its own unaligned copy)",
    0x80016D78: "no comparable differential case yet (its allocator callee returns NULL on probe state)",
}


# Overlay functions admissible by every rule but held out, keyed (member, vram).
OVERLAY_DENY = {
    # Empty. main_0003 800D2A24 was held out here as "guest-time sensitive":
    # native under a native 800D2454 it cut the intro FMV to 4 MDEC transfers
    # (1852). The cause was an ABI bug, not timing: 800D2454's C was typed
    # void, but its caller tests v0 after the jal and the retail words leave
    # 800D2A24's result there, which a native 800D2A24 did not put in v0.
    # 800D2454 now returns it, and the abi rule below (void_result_readers)
    # refuses any other void-typed function whose retail caller reads v0/v1.
    #
    # main_0012 8012B608 (B18, an angle step): its retail cycle mapping is
    # ambiguous, so it would run on the fixed charge and change guest time
    # (the B18 route proof's village DEVOBS/RAM/PAD differed with it native).
    # Held out to keep native-vs-interpreted runs exact, like main 800128EC.
    ("main_0012", 0x8012B608): "ambiguous retail cycle mapping (fixed charge would change guest time)",
    # main_0012 8012DEB8 (B18): on the attract route it reads through a null
    # object pointer (+0x12), which retail reads harmlessly from the low-RAM
    # mirror; natively it faults the host (D-013 (4), job
    # 20261002-170002-bfm-b18route2). Held out until the lane normalises
    # KUSEG/null guest pointers.
    ("main_0012", 0x8012DEB8): "reads through a null guest pointer on the attract route (KUSEG gap, host fault)",
}


def retail_words(vram, size, info=None):
    """The function's retail words from the user's own extract, or None."""
    words = [guest_word(vram + i, info) for i in range(0, size, 4)]
    return None if any(w is None for w in words) else words


def retail_frame(words):
    """The retail stack frame a function that makes calls allocates
    (`addiu sp,sp,-F` in its first 8 words), else 0 (leaves need none)."""
    calls = any(w >> 26 == 3 or (w >> 26 == 0 and w & 63 == 9) for w in words)
    if not calls:
        return 0
    for w in words[:8]:
        if w >> 26 == 9 and (w >> 21) & 31 == 29 and (w >> 16) & 31 == 29 and w & 0x8000:
            return 0x10000 - (w & 0xFFFF)
    return 0


SP_ADJ = "musashi_lane_sp_adj"


def add_frame_adjust(ir, fname, frame):
    """D-011 guest stack layout: a native body has no guest frame, so a guest
    call it makes would run the callee higher on the guest stack than retail
    (and an uninitialised local there reads different leftovers). The body
    adds its retail frame size to @musashi_lane_sp_adj at entry and removes
    it before each return; the guest-call thunk puts the callee at the
    retail stack pointer (entry sp minus the adjustment)."""
    if not frame:
        return ir
    m = re.search(r"^define [^@]*@" + re.escape(fname) + r"\([^)]*\)[^{]*\{\n(.*?)^\}", ir,
                  flags=re.M | re.S)
    if not m:
        return ir
    body = m.group(1)
    lines, n = [], 0
    entry = [f"  %lane.spa.e0 = load i32, ptr @{SP_ADJ}, align 4",
             f"  %lane.spa.e1 = add i32 %lane.spa.e0, {frame}",
             f"  store i32 %lane.spa.e1, ptr @{SP_ADJ}, align 4"]
    first = True
    for line in body.splitlines():
        if first and line.strip() and not line.strip().startswith(";"):
            lines += entry
            first = False
        if re.match(r"^\s*ret\b", line):
            n += 1
            lines += [f"  %lane.spa.r{n}a = load i32, ptr @{SP_ADJ}, align 4",
                      f"  %lane.spa.r{n}b = sub i32 %lane.spa.r{n}a, {frame}",
                      f"  store i32 %lane.spa.r{n}b, ptr @{SP_ADJ}, align 4"]
        lines.append(line)
    out = ir[:m.start(1)] + "\n".join(lines) + "\n" + ir[m.end(1):]
    return out.rstrip("\n") + f"\n\n@{SP_ADJ} = external global i32, align 4\n"


# ---- Guest-frame locals (rule "escape") ----------------------------------
#
# A local whose address the C passes to a callee lives, in the retail run, in
# the function's stack frame: guest RAM at (retail sp) + OFF, where the asm
# computes the argument as `addiu aN, sp, OFF`. An interpreted callee (a
# thunk) or a native one writes through that pointer, so the native body
# must hand it the same guest address, not a host stack slot. place_guest_
# locals() moves exactly those allocas into the retail frame: the D-011
# frame adjustment (add_frame_adjust) already reserves it below the entry
# sp, and the body's retail sp is musashi_lane_entry_sp - musashi_lane_sp_adj
# (after its own adjustment), the same sp the guest-call thunk gives a
# callee. OFF is read from the retail words by a forward dataflow over the
# function's CFG; anything not proven from the asm is refused.

GUEST_SP = "musashi_lane_entry_sp"


def merged_call_bases(ir_calls, rsites, known, order=()):
    """Strict only: the compiler cross-jumped identical call tails, so the
    retail words hold fewer jal sites to a target than the C has calls. Find
    the single assignment of a frame offset to each local passed to that
    target such that (1) every C call has a retail site passing exactly those
    sp offsets in exactly those argument slots, and (2) every retail site is
    the image of at least one C call. Locals already placed by other calls
    keep their offset. When the sites alone fit several assignments (two
    same-typed locals swapped), keep the one whose offsets ascend in the
    locals' definition order, which is how this compiler lays out its frame.
    Any non-overlapping choice gives the callees the same values, because
    only the C body and its callees use these addresses. Returns
    {alloca: base}, or None when nothing fits or the tie stays unresolved."""
    import itertools
    sites = [{i: o for i, o in args.items() if i < argc}
             for (_, args) in rsites for argc in [max(a for _, a in ir_calls)]]
    cand = {}
    for tainted, argc in ir_calls:
        for i, (alloca, off) in tainted.items():
            opts = {s[i] - off for s in sites if i in s}
            cand[alloca] = cand.get(alloca, opts) & opts
    if not cand or any(not v for v in cand.values()):
        return None
    for a in list(cand):
        if a in known:
            if known[a] not in cand[a]:
                return None
            cand[a] = {known[a]}
    names = sorted(cand)
    fits = []
    for combo in itertools.product(*(sorted(cand[a]) for a in names)):
        b = dict(zip(names, combo))
        images = []
        for tainted, argc in ir_calls:
            want = {i: b[a] + off for i, (a, off) in tainted.items()}
            hit = [k for k, s in enumerate(sites)
                   if {i: o for i, o in s.items() if i < argc} == want]
            if not hit:
                break
            images += hit
        else:
            if set(images) == set(range(len(sites))):
                fits.append(b)
    if len(fits) > 1:
        rank = {a: n for n, a in enumerate(order)}
        fits = [b for b in fits
                if [b[a] for a in sorted(b, key=lambda a: rank.get(a, 0))] == sorted(b.values())]
    return fits[0] if len(fits) == 1 else None

CALLER_SAVED = frozenset([1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 24, 25, 31])


def _branch_info(w, pc):
    """(kind, target) for a control transfer, else None. kind: 'b' (two-way
    branch), 'j' (jump), 'call', 'ret' (jr ra), 'bad' (anything the
    dataflow cannot follow: jr reg, jalr, branch-and-link)."""
    op = w >> 26
    simm = (w & 0xFFFF) - 0x10000 if w & 0x8000 else w & 0xFFFF
    if op in (4, 5, 6, 7):
        return "b", pc + 4 + (simm << 2)
    if op == 1:
        rt = (w >> 16) & 31
        if rt in (0, 1):
            return "b", pc + 4 + (simm << 2)
        return "bad", None
    if op == 2:
        return "j", ((pc + 4) & 0xF0000000) | ((w & 0x3FFFFFF) << 2)
    if op == 3:
        return "call", ((pc + 4) & 0xF0000000) | ((w & 0x3FFFFFF) << 2)
    if op == 0 and w & 63 == 8:
        return ("ret", None) if (w >> 21) & 31 == 31 else ("bad", None)
    if op == 0 and w & 63 == 9:
        return "bad", None
    if op in (0x10, 0x11, 0x12, 0x13) and (w >> 21) & 31 == 8:
        return "bad", None  # coprocessor branch
    return None


def _gpr_dest(w):
    """The GPR an instruction writes (0: none)."""
    op = w >> 26
    if op == 0:
        f = w & 63
        if f in (0x08, 0x0C, 0x0D, 0x18, 0x19, 0x1A, 0x1B, 0x11, 0x13):
            return 0
        return (w >> 11) & 31
    if op in (8, 9, 10, 11, 12, 13, 14, 15) or 0x20 <= op <= 0x26:
        return (w >> 16) & 31
    if op in (0x10, 0x12) and (w >> 21) & 31 in (0, 2):  # mfc/cfc
        return (w >> 16) & 31
    if op == 3:
        return 31
    return 0


def _step(w, regs, slots):
    """Abstract effect of one non-transfer instruction. regs: {reg: off}
    for registers proven to hold retail sp + off; slots: {sp off: off} for
    stack words proven to hold sp + off. Returns False when the
    instruction moves sp other than in the prologue/epilogue form."""
    op, rs, rt, rd = w >> 26, (w >> 21) & 31, (w >> 16) & 31, (w >> 11) & 31
    simm = (w & 0xFFFF) - 0x10000 if w & 0x8000 else w & 0xFFFF
    if op == 0x2B:  # sw
        if rs == 29:
            if rt in regs:
                slots[simm] = regs[rt]
            else:
                slots.pop(simm, None)
        else:
            slots.clear()  # may alias the frame
        return True
    if op in (0x28, 0x29, 0x2A, 0x2E):  # sb/sh/swl/swr
        if rs == 29:
            for k in [k for k in slots if k - 3 <= simm < k + 4]:
                slots.pop(k)
        else:
            slots.clear()
        return True
    dest = _gpr_dest(w)
    value = None
    if op == 9 and rs in regs:  # addiu
        value = regs[rs] + simm
    elif op == 0 and w & 63 in (0x21, 0x20, 0x25) and rt == 0 and rs in regs:
        value = regs[rs]  # move (addu/add/or rd, rs, zero)
    elif op == 0 and w & 63 in (0x21, 0x20, 0x25) and rs == 0 and rt in regs:
        value = regs[rt]
    elif op == 0x23 and rs == 29 and simm in slots:  # lw from a proven slot
        value = slots[simm]
    if dest == 29:
        if value is None:
            return False
    if dest:
        if value is None:
            regs.pop(dest, None)
        else:
            regs[dest] = value
    return True


def retail_call_args(words, vram, frame):
    """Forward dataflow over the retail words. Returns (sites, saved) where
    sites = [(jal pc, target, {argument index: sp offset})] lists, for every
    jal, the arguments proven to be retail sp + offset (a0-a3, and stack
    arguments 4-7 from the words at sp+0x10..), and saved = the sp offsets
    the function stores a callee-saved register or ra to. Raises Reject when
    the control flow cannot be followed."""
    n = len(words)
    lo, hi = vram, vram + 4 * n
    states = [None] * (n + 1)
    states[0] = ({29: frame}, {})
    work = [0]
    sites = {}
    saved = set()

    def merge(i, regs, slots):
        if not 0 <= i <= n:
            raise Reject("escape", f"retail flow leaves the function at {vram + 4 * i:08x}")
        old = states[i]
        if old is None:
            states[i] = (dict(regs), dict(slots))
        else:
            r = {k: v for k, v in old[0].items() if regs.get(k) == v}
            s = {k: v for k, v in old[1].items() if slots.get(k) == v}
            if r == old[0] and s == old[1]:
                return
            states[i] = (r, s)
        work.append(i)

    def at(i):
        return words[i] if i < n else 0

    guard = 0
    while work:
        guard += 1
        if guard > 20000:
            raise Reject("escape", "retail dataflow does not converge")
        i = work.pop()
        if i >= n:
            continue
        regs, slots = dict(states[i][0]), dict(states[i][1])
        w, pc = words[i], vram + 4 * i
        br = _branch_info(w, pc)
        if br is None:
            if not _step(w, regs, slots):
                raise Reject("escape", f"sp changes at {pc:08x}")
            if w >> 26 == 0x2B and (w >> 21) & 31 == 29 and ((w >> 16) & 31) in \
                    (16, 17, 18, 19, 20, 21, 22, 23, 30, 31):
                saved.add((w & 0xFFFF) - 0x10000 if w & 0x8000 else w & 0xFFFF)
            merge(i + 1, regs, slots)
            continue
        kind, target = br
        if kind == "bad":
            raise Reject("escape", f"retail control flow at {pc:08x} is not followed")
        if _branch_info(at(i + 1), pc + 4) is not None:
            raise Reject("escape", f"transfer in a delay slot at {pc + 4:08x}")
        # The transfer reads its operands, then the delay slot runs.
        if not _step(at(i + 1), regs, slots):
            raise Reject("escape", f"sp changes at {pc + 4:08x}")
        if kind == "call":
            args = {k: regs[4 + k] for k in range(4) if 4 + k in regs}
            for k in range(4, 8):
                if 0x10 + 4 * (k - 4) in slots:
                    args[k] = slots[0x10 + 4 * (k - 4)]
            sites[pc] = (target, args)
            for r in CALLER_SAVED:
                regs.pop(r, None)
            slots.clear()
            merge(i + 2, regs, slots)
        elif kind == "ret":
            continue
        elif kind == "j":
            if not lo <= target < hi:
                raise Reject("escape", f"retail jump out of the function at {pc:08x}")
            merge((target - vram) // 4, regs, slots)
        else:
            if not lo <= target <= hi:
                raise Reject("escape", f"retail branch out of the function at {pc:08x}")
            merge((target - vram) // 4, regs, slots)
            merge(i + 2, regs, slots)
    return [(pc, t, a) for pc, (t, a) in sorted(sites.items())], saved


def ir_type_layout(ty, types, seen=()):
    """(size, align) of an LLVM type under the guest (and host) C layout;
    None for a pointer or anything unrecognised."""
    ty = ty.strip()
    ints = {"i8": (1, 1), "i16": (2, 2), "i32": (4, 4), "i64": (8, 8)}
    if ty in ints:
        return ints[ty]
    m = re.fullmatch(r"\[(\d+) x (.*)\]", ty)
    if m:
        el = ir_type_layout(m.group(2), types, seen)
        return None if el is None else (int(m.group(1)) * el[0], el[1])
    if ty in types:
        if ty in seen:
            return None
        return ir_type_layout(types[ty], types, (*seen, ty))
    packed = ty.startswith("<{") and ty.endswith("}>")
    if packed or (ty.startswith("{") and ty.endswith("}")):
        inner = ty[2:-2] if packed else ty[1:-1]
        off, align = 0, 1
        for f in split_top(inner):
            el = ir_type_layout(f, types, seen)
            if el is None:
                return None
            a = 1 if packed else el[1]
            off = (off + a - 1) // a * a + el[0]
            align = max(align, a)
        return (off + align - 1) // align * align, align
    return None


def _struct_fields(ty, types):
    ty = types.get(ty.strip(), ty.strip())
    packed = ty.startswith("<{")
    inner = ty[2:-2] if packed else ty[1:-1]
    return split_top(inner), packed


def gep_const_offset(src_ty, indices, types):
    """Byte offset of a getelementptr with constant indices, or None."""
    off = 0
    size = ir_type_layout(src_ty, types)
    if size is None or not indices:
        return None
    first = indices[0]
    if not re.fullmatch(r"-?\d+", first):
        return None
    off += int(first) * size[0]
    cur = src_ty.strip()
    for idx in indices[1:]:
        if not re.fullmatch(r"-?\d+", idx):
            return None
        k = int(idx)
        body = types.get(cur, cur)
        am = re.fullmatch(r"\[(\d+) x (.*)\]", body)
        if am:
            el = ir_type_layout(am.group(2), types)
            if el is None:
                return None
            off += k * el[0]
            cur = am.group(2).strip()
            continue
        if body.startswith("{") or body.startswith("<{"):
            fields, packed = _struct_fields(cur, types)
            if not 0 <= k < len(fields):
                return None
            pos = 0
            for j, f in enumerate(fields):
                el = ir_type_layout(f, types)
                if el is None:
                    return None
                a = 1 if packed else el[1]
                pos = (pos + a - 1) // a * a
                if j == k:
                    break
                pos += el[0]
            off += pos
            cur = fields[k].strip()
            continue
        return None
    return off


GEP_RE = re.compile(r"getelementptr (?:inbounds |nuw |nusw |inrange\(\S+\) )*(.*)$")


def _call_args(rhs):
    """(callee name, [arg operand text]) for a direct call, else None."""
    cm = re.search(r"\bcall\b[^@]*@([\w.$]+)\((.*)\)", rhs)
    if not cm:
        return None
    inner, depth, end = cm.group(2), 0, None
    for k, ch in enumerate(inner):
        depth += ch in "([{<"
        depth -= ch in ")]}>"
        if depth < 0:
            end = k
            break
    args = split_top(inner if end is None else inner[:end])
    return cm.group(1), args


_CALL_USE = None


def _call_use_index():
    """func name -> True when some C source (other than its own file) uses it
    other than as an extern declaration or a bare call statement."""
    global _CALL_USE
    if _CALL_USE is not None:
        return _CALL_USE
    used, tok = {}, re.compile(r"\bfunc_[0-9A-Fa-f]{8}\b")
    for path in (ROOT / "src").rglob("*.c"):
        text = re.sub(r"/\*.*?\*/", " ", path.read_text(errors="replace"), flags=re.S)
        text = re.sub(r"//[^\n]*", "", text)
        rel = str(path.relative_to(ROOT))
        for line in text.splitlines():
            names = tok.findall(line)
            if not names:
                continue
            st = line.strip()
            for n in names:
                n = "func_" + n[5:].upper()
                ok = (st.startswith("extern") and st.endswith(";")) or \
                    re.fullmatch(re.escape(n) + r"\s*\(.*\)\s*;", st, flags=re.I) is not None or \
                    (re.match(r"(?:\w+\s+)+\**\s*" + re.escape(n) + r"\s*\([^;=]*(?:\)\s*;|\{|$)",
                              st, flags=re.I) is not None and "=" not in st)
                used.setdefault(n, {}).setdefault(rel, []).append(ok)
    _CALL_USE = used
    return used


def void_result_returns(optir, fname, name, info, own_source):
    """Strict only: a body whose every return is `ret iN undef` (the matched C
    falls off the end of a function declared to return a value) returns 0
    instead, but only when nothing can read the value:
    - every use in every other C source is an extern declaration, a bare
      call statement (`func_X(...);`), a prototype, or another member's
      definition header (comments ignored);
    - no word of the member file or the main EXE equals the function's
      address (no function-pointer table that could call it for a value).
    In retail, v0 holds a leftover there that no caller reads."""
    m = re.search(r"^define [^@]*@" + re.escape(fname) + r"\([^)]*\)[^{]*\{\n(.*?)^\}", optir,
                  flags=re.M | re.S)
    if not m:
        return optir
    body = m.group(1)
    rets = re.findall(r"^\s*ret (i\d+) (\S+)\s*$", body, flags=re.M)
    if not rets or any(v != "undef" for _, v in rets):
        return optir
    uses = _call_use_index().get("func_" + name[5:].upper(), {})
    if any(not all(oks) for src, oks in uses.items() if src != own_source):
        return optir
    vram = int(name[5:], 16)
    word = vram.to_bytes(4, "little")
    blobs = [info["data"]] if info else []
    if MAIN_EXE.exists():
        blobs.append(MAIN_EXE.read_bytes())
    for blob in blobs:
        k = blob.find(word)
        while k >= 0:
            if k % 4 == 0:
                return optir
            k = blob.find(word, k + 1)
    new_body = re.sub(r"^(\s*)ret (i\d+) undef\s*$", r"\1ret \2 0", body, flags=re.M)
    return optir[:m.start(1)] + new_body + optir[m.end(1):]


def pointer_slot_sources(lines):
    """Strict only (O0 IR): {slot: value} for a pointer local (`alloca ptr`)
    that every store fills with the same SSA value and whose address is used
    only as the pointer operand of loads and stores (the auto-init null store
    at the declaration aside). A load from such a slot
    is that value, so a frame local copied through a pinned pointer variable
    (`argp = buf; f(argp)`) still reaches the callee as the local."""
    slots, stores, bad = set(), {}, set()
    for line in lines:
        dm = DEF_RE.match(line)
        if dm and re.fullmatch(r"alloca ptr, align \d+", dm.group(2).strip()):
            slots.add(dm.group(1))
    if not slots:
        return {}
    for line in lines:
        dm = DEF_RE.match(line)
        if dm and dm.group(1) in slots:
            continue
        if re.match(r"\s*store ptr null, ptr %[\w.\"$]+, align \d+, !annotation !\d+\s*$", line):
            continue  # the compiler's auto-init of the declaration, not a value
        sm = re.match(r"\s*store ptr (%[\w.\"$]+), ptr (%[\w.\"$]+)(?:, align \d+)?(?:, ![\w.]+ !\d+)*\s*$", line)
        if sm and sm.group(2) in slots:
            stores.setdefault(sm.group(2), set()).add(sm.group(1))
            rest = [sm.group(1)]
        else:
            lm = re.match(r"\s*%[\w.\"$]+ = load ptr, ptr (%[\w.\"$]+)(?:, align \d+)?(?:, ![\w.]+ !\d+)*\s*$", line)
            rest = [] if lm and lm.group(1) in slots else [line]
        for text in rest:
            for t in re.findall(r"%[\w.\"$]+", text):
                if t in slots:
                    bad.add(t)
    return {s: next(iter(v)) for s, v in stores.items() if len(v) == 1 and s not in bad}


def place_guest_locals(ir, fname, words, vram, frame):
    """Move every alloca of fname whose address reaches a guest callee
    (lane_call_* / lane_* call argument, through constant GEPs) into the
    retail frame. Returns (ir, [(alloca, sp offset, size)]); the IR is
    unchanged when no alloca reaches a call. Raises Reject("escape") when
    the offset cannot be proven from the retail words."""
    m = re.search(r"^define [^@]*@" + re.escape(fname) + r"\([^)]*\)[^{]*\{\n(.*?)^\}", ir,
                  flags=re.M | re.S)
    if not m:
        return ir, []
    types = named_types(ir)
    lines = m.group(1).splitlines()
    allocas, derived, calls = {}, {}, []
    slot_src = pointer_slot_sources(lines) if STRICT else {}
    for k, line in enumerate(lines):
        dm = DEF_RE.match(line)
        if dm:
            name, rhs = dm.group(1), dm.group(2)
            lm = re.fullmatch(r"load ptr, ptr (%[\w.\"$]+)(?:, align \d+)?", rhs.strip())
            if lm and slot_src.get(lm.group(1)) in derived:
                derived[name] = derived[slot_src[lm.group(1)]]
                continue
            pm = re.fullmatch(r"ptrtoint ptr (%[\w.\"$]+) to i32", rhs.strip())
            if STRICT and pm and pm.group(1) in derived:
                # `(s32)&local` passed as an int argument: once the local
                # sits in the retail frame its address is the guest one
                derived[name] = derived[pm.group(1)]
                continue
            am = re.fullmatch(r"alloca ([^,]+), align (\d+)", rhs.strip())
            if am:
                allocas[name] = (am.group(1).strip(), k)
                derived[name] = (name, 0)
                continue
            gm = GEP_RE.match(rhs)
            if gm and rhs.startswith("getelementptr"):
                parts = split_top(gm.group(1))
                if len(parts) >= 2 and parts[1].startswith("ptr "):
                    base = parts[1].split()[-1]
                    if base in derived:
                        idx = [p.split()[-1] for p in parts[2:]]
                        off = gep_const_offset(parts[0], idx, types)
                        if off is None:
                            raise Reject("escape", f"non-constant offset into local {base}")
                        derived[name] = (derived[base][0], derived[base][1] + off)
                continue
        ca = _call_args(line)
        if ca and re.match(r"lane_(?:call_)?" + QFUNC + r"$", ca[0]):
            tainted = {}
            for i, a in enumerate(ca[1]):
                op = a.split()[-1] if a.split() else ""
                if op in derived:
                    tainted[i] = derived[op]
            fm = re.search(r"func_([0-9A-Fa-f]{8})$", ca[0])
            calls.append((int(fm.group(1), 16), tainted, len(ca[1])))
    if not any(t for _, t, _ in calls):
        return ir, []
    if words is None or not frame:
        raise Reject("escape", "local passed to a callee, retail frame unknown")
    sites, saved = retail_call_args(words, vram, frame)
    by_target = {}
    for pc, target, args in sites:
        by_target.setdefault(target, []).append((pc, args))
    ir_by_target = {}
    for target, tainted, argc in calls:
        ir_by_target.setdefault(target, []).append((tainted, argc))
    base = {}
    for target, ir_calls in ir_by_target.items():
        rsites = by_target.get(target, [])
        if len(rsites) != len(ir_calls):
            if not (any(t for t, _ in ir_calls) or any(a for _, a in rsites)):
                continue
            merged = (merged_call_bases(ir_calls, rsites, base,
                                        sorted(allocas, key=lambda a: allocas[a][1]))
                      if STRICT and 0 < len(rsites) < len(ir_calls) else None)
            if merged is None:
                raise Reject("escape", f"{len(ir_calls)} calls to {target:08x} in the C, "
                                       f"{len(rsites)} jal in the retail words")
            base.update(merged)
            continue
        for (tainted, argc), (pc, args) in zip(ir_calls, rsites):
            sp_args = {i: o for i, o in args.items() if i < argc}
            if set(tainted) != set(sp_args):
                raise Reject("escape", f"jal {target:08x} at {pc:08x}: locals at arguments "
                                       f"{sorted(tainted)}, retail sp offsets at {sorted(sp_args)}")
            for i, (alloca, off) in tainted.items():
                b = sp_args[i] - off
                if base.setdefault(alloca, b) != b:
                    raise Reject("escape", f"local {alloca} at sp+{base[alloca]:#x} and sp+{b:#x}")
    for target, rsites in by_target.items():
        if target not in ir_by_target and any(a for _, a in rsites):
            # a frame address the retail words pass where the C passes none
            raise Reject("escape", f"retail jal {target:08x} passes an sp address the C does not")
    placed = []
    max_args = max([argc for _, _, argc in calls] + [4])
    out_area = 0x10 + 4 * (max_args - 4)
    for alloca, off in sorted(base.items(), key=lambda x: x[1]):
        lay = ir_type_layout(allocas[alloca][0], types)
        if lay is None:
            raise Reject("escape", f"local {alloca} has type {allocas[alloca][0]}")
        size = lay[0]
        if off < out_area or off + size > frame:
            raise Reject("escape", f"local {alloca} sp+{off:#x}+{size} outside the frame's locals "
                                   f"[{out_area:#x}, {frame:#x})")
        if off % lay[1]:
            raise Reject("escape", f"local {alloca} sp+{off:#x} misaligned")
        if any(off - 3 <= s < off + size for s in saved):
            raise Reject("escape", f"local {alloca} sp+{off:#x}+{size} overlaps a saved register")
        for _, o2, s2 in placed:
            if off < o2 + s2 and o2 < off + size:
                raise Reject("escape", f"local {alloca} sp+{off:#x} overlaps another local")
        placed.append((alloca, off, size))
    # Rewrite: base computed once, before the first moved alloca (allocas sit
    # at the top of the entry block, after add_frame_adjust's prologue).
    auto_init = set(re.findall(r'^(![\w.]+) = !\{!"auto-init"\}', ir, flags=re.M))
    moved = {a for a, _, _ in placed}
    offs = {a: o for a, o, _ in placed}
    new, first = [], True
    for line in lines:
        dm = DEF_RE.match(line)
        if dm and dm.group(1) in moved:
            a = dm.group(1)
            t = a.lstrip("%").replace('"', "")
            if first:
                new += [f"  %lane.gf.sp = load i32, ptr @{GUEST_SP}, align 4",
                        f"  %lane.gf.base = sub i32 %lane.gf.sp, %lane.spa.e1"]
                first = False
            new += [f"  %lane.gf.a{t} = add i32 %lane.gf.base, {offs[a]}",
                    f"  %lane.gf.z{t} = zext i32 %lane.gf.a{t} to i64",
                    f"  {a} = inttoptr i64 %lane.gf.z{t} to ptr"]
            continue
        im = re.match(r"\s*call void @llvm\.memset\.[\w.]+\(ptr (?:align \d+ )?(%[\w.\"$]+), i8 0, "
                      r"i64 \d+, i1 false\)(?:.*), !annotation (![\w.]+)\s*$", line)
        if im and im.group(1) in moved and im.group(2) in auto_init:
            continue  # -ftrivial-auto-var-init: retail leaves the slot as it was
        lm = re.match(r"\s*call void @llvm\.lifetime\.\w+\.p0\((?:i64 \d+, )?ptr (%[\w.\"$]+)\)", line)
        if lm and lm.group(1) in moved:
            continue
        new.append(line)
    out = ir[:m.start(1)] + "\n".join(new) + "\n" + ir[m.end(1):]
    out = out.rstrip("\n") + f"\n\n@{GUEST_SP} = external global i32, align 4\n"
    return out, placed


def cycle_analysis(ir, entry, vram, size, info):
    """D-011 phase 2a: the retail cycle model and the clang/retail mapping
    for one function. Report only: it changes no admission and no charge."""
    member = info["member"] if info else None
    words = retail_words(vram, size, info)
    if words is None:
        return dict(shape=None, status="refused", reason="retail words unavailable")
    res = lane_cycles.analyse(ir, "lane_" + qualify(member, entry["name"]), vram, words)
    res["today_cost"] = 2 * (size // 4)
    return res


def build_one(entry, out, symbols, hooks, clang, info=None):
    vram, size, src = entry["vram"], entry["size"], ROOT / entry["source"]
    name = entry["name"]
    member = info["member"] if info else None
    tag = f"{member}_{vram:08x}" if member else f"{vram:08x}"
    work = out / "ir"
    cycles = None
    denied = None
    try:
        # Strict builds have no interpreter to compare against or fall back
        # to: a hold-out for missing differential coverage does not apply
        # there (the C is byte-matched and passed every other rule). Cycle
        # and hardware hold-outs still apply in strict (B28).
        if vram in DENY and not info and not (
                STRICT and DENY[vram].startswith("no comparable differential case")):
            denied = DENY[vram]
        if info and (info["member"], vram) in OVERLAY_DENY:
            denied = OVERLAY_DENY[(info["member"], vram)]
        if denied:
            # Still analysed for the cycle report (a held-out function's
            # mapping status is part of D-011); it stays refused.
            try:
                cycles = deny_cycle_analysis(entry, out, symbols, clang, info)
            except Exception as e:  # report only: never fail the build
                cycles = dict(shape=None, status="refused", reason=f"analysis: {e}")
            raise Reject("deny", denied)
        for pc, kind in hooks.items():
            if not vram <= pc < vram + size:
                continue
            if pc == vram and (vram in INTRINSIC_PCS or kind == "entry"):
                continue
            raise Reject("hooks", f"port references {pc:08x}")
        if info:
            jt = guest_jump_table(info, vram, size)
            if jt and not (STRICT and switch_tables_internal(info, vram, size)):
                raise Reject("jumptable", f"jr ${jt[1]} at {jt[0]:08x} (switch table outside the digest)")
        text = strip_comments(src.read_text(errors="replace"))
        body = text.split("#else", 1)[1] if "#else" in text else text
        # `long long` is 64-bit on the PS1 and the host; a lone `long` is
        # 32-bit on the PS1 and becomes `int` in the host copy (host_long).
        if re.search(r"\bsizeof\b", body):
            raise Reject("source", "uses 'sizeof'")
        o0 = work / f"{tag}.O0.ll"
        compile_src = src
        raw = src.read_text(errors="replace")
        host = host_long(host_source(raw))
        # `register T x __asm__("$5")` pins a local to a MIPS register for the
        # byte match only; it has no meaning on the host. Empty asm statements
        # that are identities go too; any other inline asm is still refused
        # (rule "calls").
        stripped = strip_empty_asm(host, raw)
        if stripped is None:
            raise Reject("calls", "empty asm with an untied output")
        host = stripped[0]
        if host != raw:
            compile_src = work / f"{tag}.host.c"
            compile_src.write_text(host)
        r = run([clang, *CFLAGS, "-O0", "-Xclang", "-disable-O0-optnone", "-S", "-emit-llvm",
                 "-I", str(ROOT / "include"), "-I", str(src.parent), str(compile_src), "-o", str(o0)])
        if r.returncode:
            raise Reject("compile", (r.stderr.strip().splitlines() or ["?"])[0][:160])
        ir = o0.read_text()
        if STRICT:
            ir = strip_symbol_binding_asm(ir)
            ir = fix_short_calls(ir, retail_words(vram, size, info), vram)
            ir, _ = narrow_aggregate_pointers(ir)
        check_layout(ir)
        words = retail_words(vram, size, info)
        frame = retail_frame(words) if words is not None else 0
        # Locals whose address reaches a callee move into the retail frame
        # before narrow_pointer_cells, which then treats them as guest memory.
        rewritten, guest_locals = place_guest_locals(
            rewrite_symbols(ir, symbols, member, info["code"] if info else ()),
            "lane_" + qualify(member, name), words, vram, frame)
        rewritten = lower_arith(narrow_pointer_cells(rewritten))
        if words is not None:
            rewritten = add_frame_adjust(rewritten, "lane_" + qualify(member, name), frame)
        if guest_locals and "%lane.spa.e1 =" not in rewritten:
            raise Reject("escape", "guest-frame locals without the frame adjustment")
        sub = work / f"{tag}.sub.ll"
        sub.write_text(rewritten)
        cycles = cycle_analysis(rewritten, entry, vram, size, info)
        opt = work / f"{tag}.opt.ll"
        # No auto-vectorisation or unrolling: their splat and remainder idioms
        # (insertelement poison, phi poison) trip
        # the undef/poison check, and lane functions gain nothing from it.
        r = run([clang, f"--target={HOST_TARGET}", "-O2", "-fno-vectorize", "-fno-slp-vectorize", "-fno-unroll-loops",
                 "-S", "-emit-llvm", "-w", str(sub), "-o", str(opt)])
        if r.returncode:
            raise Reject("compile", "optimize: " + (r.stderr.strip().splitlines() or ["?"])[0][:160])
        optir, icalls = rewrite_indirect_calls(opt.read_text())
        if STRICT:
            optir = void_result_returns(optir, f"lane_{qualify(member, name)}", name, info,
                                        entry["source"])
        internal = set(re.findall(r"^define internal [^@]*@([\w.$]+)\(", optir, flags=re.M))
        check_optimized(optir, internal)
        check_device_pointers(optir, info)
        check_polling_loops(optir)
        defs = lane_names(optir)
        own = f"lane_{qualify(member, name)}"
        if own not in defs:
            raise Reject("symbols", f"{name} not defined by {entry['source']}")
        sigs = {}
        for d in defs:
            header = next(h for h, _ in functions(optir) if re.search("@" + d + r"\(", h))
            sigs[d] = parse_signature(header, d)
        optir, stubs = resolve_calls(optir)
        for callee, _, _, _ in stubs.values():
            addr = int(callee.split("func_")[-1], 16)
            if not STRICT and addr in caller_pinned_entries():
                raise Reject("hooks", f"calls {addr:08x}, whose GTE sites admit only a jal caller")
        mapping = cycles.pop("_mapping", None) if cycles else None
        ledger, ledger_rows = False, None
        if vram in INTRINSIC_PCS and not info:
            # The interpreter answers this PC with a host intrinsic that
            # charges no guest time (mips_formatter.c formatter_call), so the
            # lane-off run spends 0 cycles here; the native body charges the
            # same 0 (no ledger code, no fixed cost).
            ledger, ledger_rows = True, None
            if cycles is not None:
                cycles.update(intrinsic=True)
        elif mapping and cycles["status"] == "mapped":
            # D-011: the object is built from the instrumented -O0 module.
            # Every rule above ran on the uninstrumented one (the ledger's
            # stores must not hide a polling loop from the irq rule); the
            # instrumented one must keep the same calls and definitions.
            try:
                inst, ledger_rows = lane_cycles.instrument(
                    *mapping, guard=True, segs_symbol=f"lane_segs_{qualify(member, name)}")
                lsub = work / f"{tag}.ledger.sub.ll"
                lsub.write_text(inst)
                lopt = work / f"{tag}.ledger.opt.ll"
                r = run([clang, f"--target={HOST_TARGET}", "-O2", "-fno-vectorize", "-fno-slp-vectorize",
                         "-fno-unroll-loops", "-S", "-emit-llvm", "-w", str(lsub), "-o", str(lopt)])
                if r.returncode:
                    raise lane_cycles.Refuse("optimize: " + (r.stderr.strip().splitlines() or ["?"])[0][:120])
                lir, licalls = rewrite_indirect_calls(lopt.read_text())
                check_optimized(lir, set(re.findall(r"^define internal [^@]*@([\w.$]+)\(", lir, flags=re.M)))
                if lane_names(lir) != defs or licalls != icalls:
                    raise lane_cycles.Refuse("instrumented module changed its definitions or calls")
                lir, lstubs = resolve_calls(lir)
                if lstubs != stubs:
                    raise lane_cycles.Refuse("instrumented module changed its guest calls")
                optir, ledger = lir, True
            except (lane_cycles.Refuse, Reject) as e:
                cycles.update(status="refused", reason=f"instrument: {getattr(e, 'reason', None) or e}")
                ledger_rows = None
        final = work / f"{tag}.lane.ll"
        final.write_text(optir)
        obj = work / f"{tag}.o"
        r = run([clang, f"--target={HOST_TARGET}", "-O2", "-fno-vectorize", "-fno-slp-vectorize", "-fno-unroll-loops", "-c", "-fPIE", "-w", str(final), "-o", str(obj)])
        if r.returncode:
            raise Reject("compile", "object: " + (r.stderr.strip().splitlines() or ["?"])[0][:160])
        undefined = run(["nm", "-u", str(obj)]).stdout.split()
        for u in undefined:
            if u != "U" and not re.fullmatch(r"lane_(?:call_)?" + QFUNC + r"(?:__\w+)?", u) \
                    and not u.startswith("lane_icall__") \
                    and u not in MEMORY_FNS and u not in LANE_HELPERS and u not in LEDGER_SYMBOLS \
                    and not LEDGER_SEGS.fullmatch(u):
                raise Reject("symbols", f"object still references {u}")
        digest = member_digest(info, vram, size) if info else None
        if info and digest is None:
            raise Reject("overlay", "extent outside the member file")
        return dict(name=name, qname=qualify(member, name), member=member, vram=vram, size=size,
                    source=entry["source"], admitted=True, obj=str(obj), defs=sigs, stubs=stubs,
                    icalls=icalls, digest=digest, cycles=cycles, ledger=ledger,
                    ledger_rows=ledger_rows, frame=frame, scratchpad=uses_scratchpad(optir),
                    guest_locals=[dict(off=o, size=n) for _, o, n in guest_locals])
    except Reject as e:
        return dict(name=name, qname=qualify(member, name), member=member, vram=vram, size=size,
                    source=entry["source"], admitted=False, rule=e.rule, detail=e.detail,
                    digest=member_digest(info, vram, size) if info else None,
                    cycles=_public(cycles))


def _public(cycles):
    if cycles:
        cycles.pop("_mapping", None)
    return cycles


def deny_cycle_analysis(entry, out, symbols, clang, info):
    """The -O0 compile and symbol rewrite of build_one, for a denied entry,
    feeding only the cycle analysis."""
    vram, size, src = entry["vram"], entry["size"], ROOT / entry["source"]
    member = info["member"] if info else None
    tag = f"{member}_{vram:08x}" if member else f"{vram:08x}"
    work = out / "ir"
    raw = src.read_text(errors="replace")
    stripped = strip_empty_asm(host_long(host_source(raw)))
    if stripped is None:
        return dict(shape=None, status="refused", reason="analysis: empty asm with an untied output")
    compile_src = work / f"{tag}.deny.host.c"
    compile_src.write_text(stripped[0])
    o0 = work / f"{tag}.deny.O0.ll"
    r = run([clang, *CFLAGS, "-O0", "-Xclang", "-disable-O0-optnone", "-S", "-emit-llvm",
             "-I", str(ROOT / "include"), "-I", str(src.parent), str(compile_src), "-o", str(o0)])
    if r.returncode:
        return dict(shape=None, status="refused", reason="analysis: compile failed")
    rewritten = lower_arith(narrow_pointer_cells(rewrite_symbols(
        o0.read_text(), symbols, member, info["code"] if info else ())))
    return cycle_analysis(rewritten, entry, vram, size, info)


CYCLE_CLASSES = (("straight", ("straight",)), ("straight+call", ("straight+call",)),
                 ("acyclic", ("acyclic", "acyclic+call")), ("loop", ("loop", "loop+call")))


def cycle_summary(results):
    """Mapped/refused counts per retail shape over the admitted functions, the
    refusal reasons, and the admitted functions that keep the fixed charge
    (`would_refuse`: unmapped, still admitted, inexact timing; D-011)."""
    by_shape, by_class, reasons, would = {}, {}, {}, []
    for r in results:
        c = r.get("cycles")
        if not r["admitted"] or not c:
            continue
        shape = c.get("shape") or "unknown"
        ok = c["status"] == "mapped"
        d = by_shape.setdefault(shape, dict(mapped=0, refused=0))
        d["mapped" if ok else "refused"] += 1
        cls = next((k for k, v in CYCLE_CLASSES if shape in v), "unknown")
        d = by_class.setdefault(cls, dict(mapped=0, refused=0))
        d["mapped" if ok else "refused"] += 1
        if not ok:
            key = re.split(r" at | \(|:", c.get("reason") or "?")[0]
            reasons[key] = reasons.get(key, 0) + 1
            would.append(dict(vram=f"{r['vram']:08x}", member=r["member"], shape=shape,
                              reason=c.get("reason")))
    order = [k for k, _ in CYCLE_CLASSES] + ["unknown"]
    return dict(by_class={k: by_class[k] for k in order if k in by_class},
                by_shape=dict(sorted(by_shape.items())), refusal_reasons=reasons,
                would_refuse=would)


def _gpr_reads(w):
    """GPRs a MIPS I word reads (conservative)."""
    op, rs, rt = w >> 26, (w >> 21) & 31, (w >> 16) & 31
    if op == 0:
        fn = w & 63
        if fn in (12, 13, 16, 18):          # syscall break mfhi mflo
            return set()
        if fn in (0, 2, 3):                 # sll srl sra
            return {rt}
        if fn in (8, 9, 17, 19):            # jr jalr mthi mtlo
            return {rs}
        return {rs, rt}
    if op in (2, 3, 15):                    # j jal lui
        return set()
    if op == 18:                            # cop2: mtc2/ctc2 read rt
        return {rt} if rs in (4, 6) else set()
    if op in (34, 38, 40, 41, 42, 43, 46, 4, 5):   # lwl lwr stores beq bne
        return {rs, rt}
    return {rs}


def _gpr_writes(w):
    op = w >> 26
    if op == 0:
        fn = w & 63
        return set() if fn in (8, 12, 13, 17, 19, 24, 25, 26, 27) else {(w >> 11) & 31}
    if op == 3:
        return {31}
    if 8 <= op <= 15 or 32 <= op <= 38:
        return {(w >> 16) & 31}
    if op == 18 and (w >> 21) & 31 in (0, 2):   # mfc2 cfc2
        return {(w >> 16) & 31}
    return set()


def _unaligned_pair_target(w, w2):
    """Target register when w, w2 are an lwl/lwr pair (either order) that loads
    one unaligned word into a register: same target rt, same base rs (distinct
    from rt, so the first load does not move the base), and offsets o+3 (lwl)
    / o (lwr). Such a pair fully defines rt whatever the alignment. Otherwise
    None (a lone lwl/lwr keeps its conservative read of rt)."""
    ops = (w >> 26, w2 >> 26)
    if sorted(ops) != [34, 38]:
        return None
    rs, rt = (w >> 21) & 31, (w >> 16) & 31
    if (w2 >> 21) & 31 != rs or (w2 >> 16) & 31 != rt or rs == rt:
        return None
    off = lambda x: x & 0xFFFF
    lwl, lwr = (w, w2) if ops[0] == 34 else (w2, w)
    if off(lwl) != (off(lwr) + 3) & 0xFFFF:
        return None
    return rt


def _is_transfer(w):
    op = w >> 26
    return op in (1, 2, 3, 4, 5, 6, 7) or (op == 0 and w & 63 in (8, 9))


def void_result_readers(target, blobs):
    """Retail callers that read v0 or v1 after `jal target` (past its delay
    slot) before writing it: the callee returns a value there although its C
    is typed void. blobs: [(base vram, bytes)]. Scans straight-line code up to
    the next control transfer (and that transfer's delay slot); jalr callers
    (target unknown statically) are not covered."""
    hits = []
    want = 0x0C000000 | ((target >> 2) & 0x3FFFFFF)
    for base, data in blobs:
        n = len(data) // 4
        words = [int.from_bytes(data[4 * i:4 * i + 4], "little") for i in range(n)]
        for i, w in enumerate(words):
            if w != want or ((base + 4 * i) & 0xF0000000) != (target & 0xF0000000):
                continue
            live = {2, 3}
            j, stop = i + 2, None
            while j < n and j < i + 64 and live:
                if stop is not None and j > stop:
                    break
                x = words[j]
                pair = (_unaligned_pair_target(x, words[j + 1])
                        if j + 1 < n and stop is None and x >> 26 in (34, 38) else None)
                if pair is not None:
                    # lwl+lwr of one word: reads only the base, writes rt fully
                    if (x >> 21) & 31 in live:
                        hits.append(base + 4 * j)
                        break
                    live.discard(pair)
                    j += 2
                    continue
                if _gpr_reads(x) & live:
                    hits.append(base + 4 * j)
                    break
                live -= _gpr_writes(x)
                if x >> 26 == 3 or (x >> 26 == 0 and x & 63 == 9):
                    break              # another call: it writes v0/v1 itself
                if _is_transfer(x):
                    stop = j + 1       # its delay slot still runs
                j += 1
    return hits


def retail_code_blobs(infos):
    """The main EXE text and each configured overlay member's code ranges."""
    blobs = []
    if MAIN_EXE.exists():
        blobs.append((0x80010000, MAIN_EXE.read_bytes()[0x800:]))
    for info in infos.values():
        for lo, hi in info.get("code") or []:
            off = lo - info["vram"] + info["start"]
            if 0 <= off <= len(info["data"]):
                blobs.append((lo, info["data"][off:off + (hi - lo)]))
    return blobs


# ---- Implicit argument pass-through ---------------------------------------
#
# MIPS passes the first four arguments in a0-a3, so a function can hand its
# own arguments to a callee without touching them: `jal f` with a0/a1 still
# holding what its caller put there. Byte-matched C may then declare fewer
# parameters than the retail words pass on (80013328 is `s32 f(void)` around
# `jal 80013350`, which reads a0). Entered from the interpreter (lane_try)
# the native body works by accident: the guest registers still hold the
# caller's arguments when its 0-argument thunk runs the callee. A direct
# native call carries host values only, so the guest a0-a3 are stale there.
#
# ArgLiveness computes, from the retail words alone, which of a0-a3
# each function reads before writing them on some path from its entry
# (upward-exposed), following its control flow (including tail jumps into
# other functions) and using the same summary for every jal it makes
# (interprocedural, to a least fixpoint). A function whose summary names a
# register at or past its C prototype's argument slots under-declares its
# arguments; emit_table() never calls such a function directly: the call
# goes through musashi_native_guest_call, which writes a0-a3 from the
# caller's arguments, and lane_try still runs the body natively with the
# guest registers it reads (apply_passthrough refuses a caller whose own
# arguments do not cover them). Where it keeps the byte match, the better
# fix is the C prototype (80013328 now takes and passes a, b).

A_MASK = 0xF          # bit k: a(k) = GPR 4 + k
LIVE_UNKNOWN = A_MASK  # an unresolvable sink may read any of a0-a3


def _arg_bits(regs):
    return sum(1 << (r - 4) for r in regs if 4 <= r <= 7)


def _a_reads(w):
    """Bits of a0-a3 a MIPS I word reads (conservative)."""
    op, rs = w >> 26, (w >> 21) & 31
    if op in (16, 17, 19):     # cop0/cop1/cop3 moves: mtcN/ctcN read rt
        return _arg_bits({(w >> 16) & 31}) if rs in (4, 6) else 0
    return _arg_bits(_gpr_reads(w))


def _a_writes(w):
    op, rs = w >> 26, (w >> 21) & 31
    if op in (16, 17, 19):
        return _arg_bits({(w >> 16) & 31}) if rs in (0, 2) else 0
    return _arg_bits(_gpr_writes(w))


def _xfer(w, pc):
    """(kind, target) for a control transfer, else None. kind: 'b' (two-way
    branch), 'j', 'call' (jal), 'icall' (jalr, or a branch-and-link), 'ret'
    (jr ra), 'jr' (jr to another register)."""
    op = w >> 26
    simm = (w & 0xFFFF) - 0x10000 if w & 0x8000 else w & 0xFFFF
    if op in (4, 5, 6, 7):
        return "b", pc + 4 + (simm << 2)
    if op == 1:
        rt = (w >> 16) & 31
        if rt in (0, 1):
            return "b", pc + 4 + (simm << 2)
        if rt in (16, 17):
            return "icall", pc + 4 + (simm << 2)
        return None
    if op == 2:
        return "j", ((pc + 4) & 0xF0000000) | ((w & 0x3FFFFFF) << 2)
    if op == 3:
        return "call", ((pc + 4) & 0xF0000000) | ((w & 0x3FFFFFF) << 2)
    if op == 0 and w & 63 == 8:
        return ("ret", None) if (w >> 21) & 31 == 31 else ("jr", None)
    if op == 0 and w & 63 == 9:
        return "icall", None
    if op in (0x10, 0x11, 0x12, 0x13) and (w >> 21) & 31 == 8:
        return "b", pc + 4 + (simm << 2)
    return None


class ArgLiveness:
    """Interprocedural upward-exposed a0-a3 per function entry, from retail
    words. word_at(key, pc) -> word or None; key_of(key, pc) -> the key a
    transfer target from code under `key` is analysed under (its member, or
    None for main); extent_of(key, pc) -> (lo, hi) of the registry function
    holding pc, or None (a `jr reg` switch may reach anything in it).
    Unresolvable sinks (jalr, a `jr reg` outside a known extent, unknown
    words, a walk past `limit` instructions) read LIVE_UNKNOWN when strict,
    nothing otherwise; `unknown` records which functions met one."""

    def __init__(self, word_at, key_of, extent_of, strict=True, limit=8192, varargs=False):
        self.word_at, self.key_of, self.extent_of = word_at, key_of, extent_of
        self.strict, self.limit, self.varargs = strict, limit, varargs
        self.summary = {}      # (key, pc) -> bits
        self.unknown = {}      # (key, pc) -> first unresolvable sink pc
        self.cfg = {}          # (key, pc) -> nodes
        self.callers = {}      # (key, pc) -> {(key, pc) of callers}

    def _walk(self, fn):
        key, entry = fn
        nodes, todo, unk = {}, [entry], None
        extents = {}           # jr pc -> its possible targets
        spills = self._vararg_spills(key, entry) if self.varargs else {}
        while todo:
            pc = todo.pop()
            if pc in nodes:
                continue
            if len(nodes) >= self.limit:
                unk = unk or pc
                nodes[pc] = ("unknown", None, None, None)
                continue
            w = self.word_at(key, pc)
            if w is None:
                unk = unk or pc
                nodes[pc] = ("unknown", None, None, None)
                continue
            x = _xfer(w, pc)
            if x is None:
                nodes[pc] = ("op", w & ~(31 << 16) if pc in spills else w, None, None)
                todo.append(pc + 4)
                continue
            kind, target = x
            d = self.word_at(key, pc + 4)
            if d is not None and pc + 4 in spills:
                d &= ~(31 << 16)
            if d is None or _xfer(d, pc + 4) is not None:
                unk = unk or pc
                nodes[pc] = ("unknown", None, None, None)
                continue
            if kind == "jr":
                ext = self.extent_of(key, pc)
                targets = self._jump_table(key, pc, ext) if ext else None
                if ext is None:
                    unk = unk or pc
                elif targets:
                    extents[pc] = targets
                    todo.extend(targets)
                else:
                    extents[pc] = list(range(ext[0], ext[1], 4))
                    todo.extend(extents[pc])
            if kind == "icall":
                unk = unk or pc
            nodes[pc] = (kind, w, d, target)
            if kind == "b":
                todo += [target, pc + 8]
            elif kind == "j":
                todo.append(target)
            elif kind in ("call", "icall"):
                todo.append(pc + 8)
                if kind == "icall" and target is not None:
                    todo.append(target)
        return nodes, unk, extents

    def _solve(self, fn):
        nodes, extents = self.cfg[fn]
        live = {pc: 0 for pc in nodes}
        order = sorted(nodes, reverse=True)
        changed = True
        while changed:
            changed = False
            for pc in order:
                kind, w, d, target = nodes[pc]
                if kind == "unknown":
                    v = LIVE_UNKNOWN if self.strict else 0
                elif kind == "op":
                    v = (live.get(pc + 4, 0) & ~_a_writes(w)) | _a_reads(w)
                else:
                    v = self._after(fn, pc, kind, target, live, extents)
                    v = (v & ~_a_writes(d)) | _a_reads(d) | _a_reads(w)
                if v != live[pc]:
                    live[pc] = v
                    changed = True
        return live

    def _after(self, fn, pc, kind, target, live, extents):
        """Live a-register bits after the delay slot of the transfer at pc."""
        if kind == "b":
            return live.get(target, 0) | live.get(pc + 8, 0)
        if kind == "j":
            return live.get(target, 0)
        if kind == "call":
            return self.summary.get(self._callee(fn, target), 0)
        if kind == "icall":
            return (LIVE_UNKNOWN if self.strict else 0) | (live.get(target, 0) if target else 0)
        if kind == "ret":
            return 0
        # jr reg: its jump-table targets, else any instruction of the
        # registry function holding it, else anything
        if pc not in extents:
            return LIVE_UNKNOWN if self.strict else 0
        v = 0
        for p in extents[pc]:
            v |= live.get(p, 0)
        return v

    def _vararg_spills(self, key, entry):
        """pcs of a varargs prologue's home-area spills `sw aN, F+4N(sp)`
        (a run aK..a3, before any write to them): with varargs=True these
        count as no read, since a varargs callee reads its unnamed arguments
        only as its named ones (a format) ask, which the caller's C passes.
        Otherwise {}."""
        frame, out, written, last = 0, {}, 0, 12
        for i in range(12):
            if i > last:
                break
            w = self.word_at(key, entry + 4 * i)
            if w is None:
                break
            if _xfer(w, entry + 4 * i) is not None:
                last = i + 1   # its delay slot still runs first
                continue
            op, rs, rt = w >> 26, (w >> 21) & 31, (w >> 16) & 31
            simm = (w & 0xFFFF) - 0x10000 if w & 0x8000 else w & 0xFFFF
            if op == 9 and rs == 29 and rt == 29:
                frame -= simm
            elif op == 0x2B and rs == 29 and 4 <= rt <= 7 and not written >> (rt - 4) & 1 \
                    and simm == frame + 4 * (rt - 4):
                out[entry + 4 * i] = rt
            written |= _a_writes(w)
        regs = sorted(set(out.values()))
        if not regs or regs[-1] != 7 or regs != list(range(regs[0], 8)):
            return {}
        return out

    def _jump_table(self, key, pc, ext):
        """Targets of a gcc switch `lui at,%hi(T); addu at,at,rI; lw rJ,
        %lo(T)(at); jr rJ` (bounded by a preceding `sltiu rX, rK, N` when
        there is one): the table words that land inside the extent. None
        when the pattern is not found."""
        w = self.word_at(key, pc)
        rj = (w >> 21) & 31
        lw = lui = count = None
        for back in range(1, 16):
            x = self.word_at(key, pc - 4 * back)
            if x is None:
                return None
            op, rs, rt = x >> 26, (x >> 21) & 31, (x >> 16) & 31
            if lw is None and op == 0x23 and rt == rj:
                lw = (rs, (x & 0xFFFF) - 0x10000 if x & 0x8000 else x & 0xFFFF)
            elif lw is not None and lui is None and op == 0x0F and rt == lw[0]:
                lui = (x & 0xFFFF) << 16
            elif lui is not None and op == 0x0B:
                count = x & 0xFFFF
                break
        if lw is None or lui is None:
            return None
        table = (lui + lw[1]) & 0xFFFFFFFF
        out = []
        for i in range(count if count else 512):
            t = self.word_at(key, table + 4 * i)
            if t is None or not (ext[0] <= t < ext[1]) or t & 3:
                if count:
                    return None
                break
            out.append(t)
        return sorted(set(out)) or None

    def _callee(self, fn, target):
        return (self.key_of(fn[0], target), target)

    def analyse(self, roots):
        """Summaries for roots and everything they reach by jal."""
        todo = list(roots)
        seen = set()
        while todo:
            fn = todo.pop()
            if fn in seen:
                continue
            seen.add(fn)
            nodes, unk, extents = self._walk(fn)
            self.cfg[fn] = (nodes, extents)
            if unk is not None:
                self.unknown[fn] = unk
            self.summary.setdefault(fn, 0)
            for pc, (kind, _, _, target) in nodes.items():
                if kind == "call":
                    c = self._callee(fn, target)
                    self.callers.setdefault(c, set()).add(fn)
                    todo.append(c)
        work = list(seen)
        while work:
            fn = work.pop()
            live = self._solve(fn)
            v = live.get(fn[1], 0)
            if v != self.summary[fn]:
                self.summary[fn] = v
                work.extend(self.callers.get(fn, ()))
        return self.summary

    def sites(self, fn, bits):
        """[(pc, kind, target, bits)]: where a register of `bits`, still
        holding its entry value on some path, is read (a jal/j whose target
        reads it, a direct read, or an unresolvable sink)."""
        nodes, extents = self.cfg[fn]
        # forward: registers not yet written on some path (may-untouched)
        keep = {fn[1]: A_MASK}
        work = [fn[1]]
        while work:
            pc = work.pop()
            if pc not in nodes:
                continue
            kind, w, d, target = nodes[pc]
            if kind == "unknown":
                continue
            v = keep[pc]
            if kind == "op":
                succ = [(pc + 4, v & ~_a_writes(w))]
            else:
                o = v & ~_a_writes(d)
                if kind == "b":
                    succ = [(target, o), (pc + 8, o)]
                elif kind == "j":
                    succ = [(target, o)] if target in nodes else []
                elif kind in ("call", "icall"):
                    succ = [(pc + 8, 0)]
                elif kind == "jr":
                    succ = [(p, o) for p in extents.get(pc, ())]
                else:
                    succ = []
            for s, o in succ:
                n = keep.get(s, 0) | o
                if n != keep.get(s):
                    keep[s] = n
                    work.append(s)
        out = []
        for pc in sorted(keep):
            if pc not in nodes:
                continue
            kind, w, d, target = nodes[pc]
            v = keep[pc]
            if kind == "unknown":
                use = LIVE_UNKNOWN if self.strict else 0
            elif kind == "op":
                use = _a_reads(w)
            else:
                use = _a_reads(w) | _a_reads(d)
                after = v & ~_a_writes(d)
                if kind == "call":
                    use |= self.summary.get(self._callee(fn, target), 0) & after
                elif kind == "icall" and self.strict:
                    use |= LIVE_UNKNOWN & after
                elif kind == "jr" and self.strict and pc not in extents:
                    use |= LIVE_UNKNOWN & after
            hit = use & v & bits
            if hit:
                out.append((pc, kind, target, hit))
        return out


def arg_slots(params):
    """a0-a3 slots a C parameter list occupies (o32: a 64-bit integer takes
    an aligned register pair)."""
    n = 0
    for ty, _ in params:
        if ty == "i64":
            n = (n + 1) // 2 * 2 + 2
        else:
            n += 1
    return n


def regs_text(bits):
    return ",".join(f"a{k}" for k in range(4) if bits >> k & 1)


def registry_extents():
    """region -> sorted [(lo, hi)] of the registry functions with a size."""
    ext = {}
    for m in json.loads((ROOT / "provenance/matches.json").read_text())["matches"]:
        if m.get("size"):
            ext.setdefault(m["region"], []).append((m["vram"], m["vram"] + m["size"]))
    return {k: sorted(v) for k, v in ext.items()}


def make_arg_liveness(infos, strict=False, varargs=False):
    """An ArgLiveness over the main EXE (key None) and the member files in
    infos (key = member name, for code inside that member's code ranges)."""
    import bisect
    extents = registry_extents()

    def key_of(key, pc):
        info = infos.get(key) if key else None
        return key if info and any(lo <= pc < hi for lo, hi in info["code"]) else None

    def word_at(key, pc):
        return guest_word(pc, infos.get(key) if key else None)

    def extent_of(key, pc):
        rows = extents.get(key or "main", [])
        i = bisect.bisect_right(rows, (pc, 0xFFFFFFFF)) - 1
        return rows[i] if i >= 0 and rows[i][0] <= pc < rows[i][1] else None

    return ArgLiveness(word_at, key_of, extent_of, strict=strict, varargs=varargs)


def passthrough_flags(admitted, infos, strict=False, varargs=True):
    """lane_<qname> -> dict(bits, sites, unknown) for each admitted function
    whose retail words read an argument register at or past the slots its C
    prototype declares (see ArgLiveness). The release policy: reads proven
    through known code only (strict=False: a jalr target or other
    unresolvable sink is not assumed to read a0-a3, and the function records
    it in "unknown"), and a varargs prologue's home-area spills are not reads
    (varargs=True: what a varargs callee reads past its named arguments is
    decided by them, which the caller's C passes)."""
    al = make_arg_liveness(infos, strict, varargs)
    al.analyse([(a.get("member"), a["vram"]) for a in admitted])
    flags = {}
    for a in admitted:
        fn = (a.get("member"), a["vram"])
        d = "lane_" + a["qname"]
        slots = arg_slots(a["defs"][d][2])
        bits = al.summary.get(fn, 0) & ~((1 << slots) - 1) & A_MASK
        if bits:
            flags[d] = dict(bits=bits, slots=slots, sites=al.sites(fn, bits), unknown=al.unknown.get(fn))
    return flags


def passthrough_detail(flag):
    """"implicit argument pass-through: a0,a1 live at jal 80013350" etc."""
    parts = []
    for pc, kind, target, bits in flag["sites"][:3]:
        what = {"call": "jal", "j": "j", "icall": "jalr", "jr": "jr"}.get(kind, "read")
        to = f" {target:08x}" if target is not None and kind in ("call", "j") else ""
        parts.append(f"{regs_text(bits)} live at {what}{to} ({pc:08x})")
    return ("implicit argument pass-through: " + ("; ".join(parts) or regs_text(flag["bits"]))
            + f" (C declares {flag['slots']})")


def apply_passthrough(admitted, flags):
    """Mark each flagged function (a["passthrough"] = detail; emit_table then
    reaches it only through the thunk) and refuse (rule abi) an admitted
    caller that passes it fewer arguments than it reads without passing the
    missing registers through itself: past the arguments the thunk writes,
    the callee reads whatever the guest registers hold at the call, which is
    the caller's own entry value only in that case."""
    for a in admitted:
        f = flags.get("lane_" + a["qname"])
        if f:
            a["passthrough"] = passthrough_detail(f)
    for a in admitted:
        own = flags.get("lane_" + a["qname"], {}).get("bits", 0) | \
            ((1 << arg_slots(a["defs"]["lane_" + a["qname"]][2])) - 1)
        for sym, (callee, sig, argc, _) in sorted(a["stubs"].items()):
            f = flags.get("lane_" + callee)
            if not f:
                continue
            short = f["bits"] & ~((1 << argc) - 1) & ~own & A_MASK
            if short:
                a.update(admitted=False, rule="abi",
                         detail=f"passes {argc} arguments to {callee}, which reads {regs_text(short)} "
                                f"through (implicit argument pass-through)")
                break


def psyq_hooked(hooks):
    """PsyQ compat-table entry points (pc_port/platform/psyq/bfm_psyq_compat.def)
    whose body contains a PC the port sequences or observes: the lane must
    not run those natively either. A body without a registry size ends at
    the next known function start. A platform entry-hook site at the entry
    PC itself (SetGeomScreen/SetGeomOffset) does not block it: the hook fires
    in formatter_step before the lane, and native callers reach the entry
    through the thunk, which arms the hook."""
    plat = plat_hook_sites()
    defs = ROOT / "pc_port/platform/psyq/bfm_psyq_compat.def"
    if not defs.exists():
        return []
    pcs = [int(m.group(1), 16) for m in
           re.finditer(r"^BFM_PSYQ\((0x[0-9A-Fa-f]+),", defs.read_text(), flags=re.M)]
    registry = json.loads((ROOT / "provenance/matches.json").read_text())["matches"]
    sizes = {m["vram"]: m.get("size") for m in registry if m["region"] == "main"}
    starts = sorted(set(sizes) | set(pcs))
    blocked = []
    for pc in sorted(set(pcs)):
        size = sizes.get(pc)
        if size:
            end = pc + size
        else:
            later = [s for s in starts if s > pc]
            end = later[0] if later else pc + 4
        if any(pc <= h < end and not (h == pc and h in plat and hooks[h] == "entry") for h in hooks):
            blocked.append(pc)
    return blocked


# ---- Emit wrappers, stubs and the table ------------------------------------

def c_type(ty, ext):
    if ty == "ptr":
        return "void *"
    signed = ext[0]
    bits = int(ty[1:])
    return f"{'int' if signed else 'uint'}{bits}_t"


def to_guest(expr, ty, ext):
    """Host value -> the 32-bit guest register the MIPS ABI would carry."""
    if ty == "ptr":
        return f"(uint32_t)(uintptr_t)({expr})"
    if ext[0]:
        return f"(uint32_t)(int32_t)({expr})"
    return f"(uint32_t)({expr})"


def from_guest(expr, ty, ext):
    if ty == "ptr":
        return f"(void *)(uintptr_t)(uint32_t)({expr})"
    return f"({c_type(ty, ext)})({expr})"


def emit_table(admitted, out, entry_sites=frozenset(), passthrough=frozenset()):
    """Write native_lane_table.c. Returns (direct, thunk, hooked, passed):
    direct native calls, interpreter thunks, and admitted callees reached
    through the thunk because they are platform entry-hook sites or pass
    arguments through implicitly (passthrough: lane_* names; the thunk
    writes a0-a3 from the caller's arguments, lane_try runs them natively)."""
    defs = {}
    for a in admitted:
        defs.update(a["defs"])
    stubs = {}
    for a in admitted:
        stubs.update(a["stubs"])
    lines = [
        "/* Generated by tools/native_lane_gen.py; do not edit. */",
        "#include <stdint.h>",
        "#include <stddef.h>",
        '#include "musashi_native_lane.h"',
        "",
    ]
    for d, (ret, rext, params) in sorted(defs.items()):
        proto = ", ".join(c_type(t, e) for t, e in params) or "void"
        lines.append(f"extern {'void' if ret == 'void' else c_type(ret, rext)} {d}({proto});")
    lines += ["", "/* Guest calls from native code. Each value crosses as the 32-bit",
              " * register the MIPS ABI carries, so caller and callee prototypes may",
              " * disagree exactly as they can on the PS1. An admitted callee is called",
              " * directly; any other runs on the interpreter (same CPU, same loop). */"]
    direct = thunk = hooked = passed = 0
    ovl = {"lane_" + a["qname"]: a for a in admitted if a.get("member")}
    by_def = {"lane_" + a["qname"]: a for a in admitted}
    for sym, (callee, sig, argc, va_ret) in sorted(stubs.items()):
        addr = callee.split("func_")[-1]
        if sig is None:
            ret, rext = va_ret
            params = [("i32", (False, False))] * argc
        else:
            ret, rext, params = sig
        rtype = "void" if ret == "void" else c_type(ret, rext)
        plist = ", ".join(f"{c_type(t, e)} a{i}" for i, (t, e) in enumerate(params)) or "void"
        regs = [to_guest(f"a{i}", t, e) for i, (t, e) in enumerate(params)]
        lines.append(f"{rtype} {sym}({plist}) {{")
        target = "lane_" + callee
        # A platform entry-hook site is reached through the thunk even when
        # it is admitted: the thunk arms the hook as a jal would, a direct
        # native call would skip it.
        native = target in defs and int(addr, 16) not in entry_sites and target not in passthrough
        hooked += target in defs and int(addr, 16) in entry_sites
        passed += target in defs and int(addr, 16) not in entry_sites and target in passthrough
        ovl_target = ovl.get(target) if native else None
        if ovl_target:
            # Another overlay function: native only while its own bytes are
            # resident too (checked per call), else the interpreter. While it
            # runs it is on the overlay frame stack, so a guest call inside it
            # re-checks its bytes on return (fail closed).
            o = ovl_target
            res = f"0x{o['vram']:08x}u, {o['size']}u, 0x{o['digest']:016x}ull"
            lines.append(f"    if (!musashi_native_lane_overlay_resident({res})) {{")
            if params:
                lines.append(f"        const uint32_t args[{len(params)}] = {{{', '.join(regs)}}};")
                tcall = f"musashi_native_guest_call(0x{addr}u, {len(params)}u, args, NULL)"
            else:
                tcall = f"musashi_native_guest_call(0x{addr}u, 0u, NULL, NULL)"
            lines.append(f"        {'(void)' + tcall if ret == 'void' else 'return ' + from_guest(tcall, ret, rext)};")
            if ret == "void":
                lines.append("        return;")
            lines.append("    }")
        if native:
            direct += 1
            cret, crext, cparams = defs[target]
            if int(addr, 16) in INTRINSIC_PCS and not by_def[target].get("member"):
                # D-011: the interpreter checkpoints at a host intrinsic's
                # entry PC (and then charges nothing for it); so does the
                # deadline guard before a direct native call to one.
                lines.append(f"    if (musashi_lane_ledger >= musashi_lane_budget) "
                             f"musashi_native_lane_tick_entry(0x{addr}u);")
            if not by_def[target].get("ledger"):
                # D-011: an unmapped native callee charges no ledger of its
                # own; a direct call adds its fixed charge, as lane_try does
                # for an interpreted caller (2 * words), and counts it.
                lines.append(f"    musashi_lane_ledger += {2 * (by_def[target]['size'] // 4)}u;")
                lines.append("    ++musashi_lane_fixed;")
            args = ", ".join(from_guest(regs[i] if i < len(regs) else "0u", t, e)
                             for i, (t, e) in enumerate(cparams))
            call = f"{target}({args})"
            for i in range(len(cparams), len(params)):
                lines.append(f"    (void)a{i}; /* the callee takes fewer arguments */")
            if ovl_target:
                lines.append(f"    musashi_native_lane_overlay_enter({res});")
            if ret == "void" or cret == "void":
                lines.append(f"    {call};")
                if ovl_target:
                    lines.append("    musashi_native_lane_overlay_leave();")
                if ret != "void":
                    lines.append(f"    return {from_guest('0u', ret, rext)};")
            elif ovl_target:
                lines.append(f"    {{ const uint32_t v = {to_guest(call, cret, crext)};")
                lines.append("      musashi_native_lane_overlay_leave();")
                lines.append(f"      return {from_guest('v', ret, rext)}; }}")
            else:
                lines.append(f"    return {from_guest(to_guest(call, cret, crext), ret, rext)};")
        else:
            thunk += 1
            if params:
                lines.append(f"    const uint32_t args[{len(params)}] = {{{', '.join(regs)}}};")
                call = f"musashi_native_guest_call(0x{addr}u, {len(params)}u, args, NULL)"
            else:
                call = f"musashi_native_guest_call(0x{addr}u, 0u, NULL, NULL)"
            if ret == "void":
                lines.append(f"    (void){call};")
            else:
                lines.append(f"    return {from_guest(call, ret, rext)};")
        lines.append("}")
    icalls = {}
    for a in admitted:
        icalls.update(a.get("icalls", {}))
    if icalls:
        lines += ["", "/* Calls through guest function pointers: the pointer holds the guest",
                  " * address, and the interpreter dispatches it exactly as jalr does. */"]
    for sym, (ret, rext, params) in sorted(icalls.items()):
        rtype = "void" if ret == "void" else c_type(ret, rext)
        plist = ", ".join(["uint32_t target"] + [f"{c_type(t, e)} a{i}" for i, (t, e) in enumerate(params)])
        regs = [to_guest(f"a{i}", t, e) for i, (t, e) in enumerate(params)]
        lines.append(f"{rtype} {sym}({plist}) {{")
        if params:
            lines.append(f"    const uint32_t args[{len(params)}] = {{{', '.join(regs)}}};")
            call = f"musashi_native_guest_call(target, {len(params)}u, args, NULL)"
        else:
            call = "musashi_native_guest_call(target, 0u, NULL, NULL)"
        if ret == "void":
            lines.append(f"    (void){call};")
        else:
            lines.append(f"    return {from_guest(call, ret, rext)};")
        lines.append("}")
    lines.append("")
    lines += ["/* D-011 segment tables: per product state of a ledger-mapped body, the",
              " * retail instructions its charge stands for (pc, interpreter cost, delay",
              " * slot), so the deadline tick can find the instruction a device event",
              " * falls due at. Row i is state i + 1. */"]
    for a in sorted(admitted, key=lambda a: (a["vram"], a.get("member") or "")):
        rows = a.get("ledger_rows")
        if not rows:
            continue
        q = a["qname"]
        insns, rrows = [], []
        for _, _, ins in rows:
            rrows.append(f"{{{len(insns)}u, {len(ins)}u}}")
            insns += [f"{{0x{pc:08x}u, {c}u, {d}u}}" for pc, c, d in ins]
        lines.append(f"static const MusashiLaneSegInsn lane_segi_{q}[] = {{{', '.join(insns) or '{0u, 0u, 0u}'}}};")
        lines.append(f"static const MusashiLaneSegRow lane_segr_{q}[] = {{{', '.join(rrows)}}};")
        lines.append(f"const MusashiLaneSegTable lane_segs_{q} = {{lane_segr_{q}, {len(rrows)}u, lane_segi_{q}}};")
    lines.append("")
    entries, ovl_entries = [], []
    for a in sorted(admitted, key=lambda a: (a["vram"], a.get("member") or "")):
        d = "lane_" + a["qname"]
        wrap = f"wrap_{a['member']}_{a['vram']:08x}" if a.get("member") else f"wrap_{a['vram']:08x}"
        ret, rext, params = a["defs"][d]
        args = ", ".join(from_guest(f"musashi_native_lane_arg(call, {i}u)", t, e)
                         for i, (t, e) in enumerate(params))
        lines.append(f"static int {wrap}(MusashiNativeLaneCall *call) {{")
        if not params and ret == "void":
            lines.append("    (void)call;")
        if ret == "void":
            lines.append(f"    {d}({args});")
        else:
            lines.append(f"    call->r[2] = {to_guest(f'{d}({args})', ret, rext)};")
        lines.append("    return 1;")
        lines.append("}")
        cost = 2 * (a["size"] // 4)
        row = (f"{{0x{a['vram']:08x}u, {cost}u, {wrap}, \"{a['qname']}\", "
               f"{len(params)}u, {0 if ret == 'void' else 1}u, {1 if a.get('ledger') else 0}u}}")
        if a.get("member"):
            ovl_entries.append(f"    {{{row}, {a['size']}u, 0x{a['digest']:016x}ull, \"{a['member']}\"}},")
        else:
            entries.append(f"    {row},")
    lines.append("")
    lines.append("const MusashiNativeLaneEntry musashi_native_lane_generated[] = {")
    lines.extend(entries or ["    {0u, 0u, NULL, NULL, 0u, 0u, 0u},"])
    lines.append("};")
    lines.append(f"const size_t musashi_native_lane_generated_count = {len(entries)}u;")
    lines.append("")
    lines.append("/* Overlay members: run only while guest RAM over the extent hashes to the")
    lines.append(" * member's digest (FNV-1a 64 of the user's own extracted member file). */")
    lines.append("const MusashiNativeLaneOverlayEntry musashi_native_lane_overlay[] = {")
    lines.extend(ovl_entries or ["    {{0u, 0u, NULL, NULL, 0u, 0u, 0u}, 0u, 0u, NULL},"])
    lines.append("};")
    lines.append(f"const size_t musashi_native_lane_overlay_count = {len(ovl_entries)}u;")
    lines.append("")
    lines.append("/* Main entries that dereference constant scratchpad addresses: they need")
    lines.append(" * the host alias at 1F800000 (musashi_native_lane_map_guest). */")
    sp = sorted(a["vram"] for a in admitted if a.get("scratchpad") and not a.get("member"))
    lines.append("const uint32_t musashi_native_lane_scratchpad_pcs[] = {")
    lines.append("    " + (", ".join(f"0x{v:08x}u" for v in sp) if sp else "0u") + ",")
    lines.append("};")
    lines.append(f"const size_t musashi_native_lane_scratchpad_count = {len(sp)}u;")
    lines.append("")
    lines.append("/* Guest-frame locals (place_guest_locals): guest RAM at the body's retail")
    lines.append(" * sp + off holds them, where the retail code keeps them. The probes compare")
    lines.append(" * these bytes, which sit inside the frame band they otherwise skip. */")
    gl = []
    for a in sorted(admitted, key=lambda a: (a["vram"], a.get("member") or "")):
        member = f'"{a["member"]}"' if a.get("member") else "NULL"
        for g in a.get("guest_locals") or ():
            gl.append(f"    {{0x{a['vram']:08x}u, {a['frame']}u, {g['off']}u, {g['size']}u, {member}}},")
    lines.append("const MusashiNativeLaneGuestLocal musashi_native_lane_guest_locals[] = {")
    lines.extend(gl or ["    {0u, 0u, 0u, 0u, NULL},"])
    lines.append("};")
    lines.append(f"const size_t musashi_native_lane_guest_locals_count = {len(gl)}u;")
    (out / "native_lane_table.c").write_text("\n".join(lines) + "\n")
    return direct, thunk, hooked, passed


# --own-code-only: a registry entry is third-party-derived when its origin or
# its source's header names the upstream decomp (Druthulu/BFM-decomp, whose
# src/ carries no license) or another project's PsyQ C. Such functions stay
# interpreted from the player's disc, so the binary compiles none of them.
THIRD_PARTY_MARK = re.compile(r"vendor|Druthulu|BFM-decomp|psyq|Sony|parasite|xenogears", re.I)


# --strict-provenance-allow FILE (strict builds only): registry origins listed
# verbatim in FILE (config/lane_strict_provenance_allow.txt) are admitted to a
# strict own-code lane even though they name upstream code. The registry keeps
# recording the origin; only the strict lane's own-code filter is widened, and
# every lane rule (hardware registers, cycles, layout, ...) still applies.
# The token "@own-code" admits every clean-room/owner origin (OWN_ORIGIN, no
# third-party mark) without listing each function in an allow list.
STRICT_PROVENANCE_ALLOW = set()


# The token "@untagged" admits matched main C with no registry origin whose
# source header names no third-party code (in-repo decompilation of main.s;
# at most upstream-derived, which Will allowed for strict on 2026-10-07).
# PsyQ library ranges stay excluded by candidates(); hook, cycle and hardware
# rules still apply to every admitted body.
def provenance_allowed(m):
    origin = m.get("origin") or ""
    if not STRICT:
        return False
    if origin in STRICT_PROVENANCE_ALLOW:
        return True
    if ("@own-code" in STRICT_PROVENANCE_ALLOW and OWN_ORIGIN.search(origin)
            and not THIRD_PARTY_MARK.search(origin)):
        return True
    if "@untagged" not in STRICT_PROVENANCE_ALLOW or origin:
        return False
    src = ROOT / m["source"]
    return src.exists() and not THIRD_PARTY_MARK.search(src.read_text(errors="replace")[:2000])


def third_party_derived(m):
    if provenance_allowed(m):
        return False
    if THIRD_PARTY_MARK.search(m.get("origin") or ""):
        return True
    src = ROOT / m["source"]
    return src.exists() and bool(THIRD_PARTY_MARK.search(src.read_text(errors="replace")[:2000]))


def strict_mixed_ok(m):
    """Strict only (B28): a registry row recorded `mixed` only for empty
    compiler barriers and register pins (no instruction asm) is C as far as
    the lane is concerned: host_source/strip_empty_asm drop both, and any
    other asm is still refused (rule calls)."""
    if not STRICT or m.get("recovery") != "mixed":
        return False
    src = ROOT / m["source"]
    if not src.exists():
        return False
    text = REG_PIN_RE.sub(r"\1", src.read_text(errors="replace"))
    asms = re.findall(r'(?:__asm__|\basm)\s*(?:volatile\s*|__volatile__\s*)?\(\s*("[^"]*")', text)
    return all(a == '""' for a in asms)


def lane_recovery(m):
    return m.get("recovery") == "c" or strict_mixed_ok(m)


def candidates(only=None, excluded=None):
    """Game-code candidates. Sony PsyQ library ranges (config/psyq_ranges.txt)
    never enter the lane: their entry points belong to PsyCross/HLE."""
    sys.path.insert(0, str(ROOT / "tools"))
    import psyq_manifest
    psyq = psyq_manifest.ranges()
    registry = json.loads((ROOT / "provenance/matches.json").read_text())["matches"]
    picked = []
    for m in registry:
        if m["region"] != "main" or not lane_recovery(m):
            continue
        if psyq_manifest.psyq_segment(m["vram"], psyq):
            if excluded is not None:
                excluded.append(m["vram"])
            continue
        src = ROOT / m["source"]
        if not src.exists():
            continue
        text = src.read_text(errors="replace")
        other = set(re.findall(r"MUSASHI_NATIVE_[A-Z0-9_]+", text))
        # Strict builds never use the hybrid's bespoke bindings: the lane
        # compiles the file's plain matched body (macros undefined), and the
        # irq/hardware/cycle rules still judge it (B28).
        if other and not STRICT and not (m["vram"] in INTRINSIC_PCS and
                                         all(o.endswith("_BINDING") for o in other)):
            continue  # bespoke binding already owns this file
        if only and m["vram"] not in only:
            continue
        picked.append(m)
    return picked


def overlay_candidates(members, only=None):
    registry = json.loads((ROOT / "provenance/matches.json").read_text())["matches"]
    return [m for m in registry if m["region"] in members and m.get("recovery") == "c"
            and (ROOT / m["source"]).exists() and (not only or m["vram"] in only)]


def allow_candidates(pairs, infos, own_code_only):
    """Registry rows for the --overlay-allow pairs; any inconsistency is a
    BuildError (see the module docstring)."""
    registry = json.loads((ROOT / "provenance/matches.json").read_text())["matches"]
    rows = {(m["region"], m["vram"]): m for m in registry}
    starts = {}
    for m in registry:
        starts.setdefault(m["region"], set()).add(m["vram"])
    picked, problems = [], []
    for member, vram in pairs:
        m = rows.get((member, vram))
        where = f"{member} {vram:08x}"
        if m is None:
            problems.append(f"{where}: no registry row")
            continue
        if m.get("recovery") != "c" or not (ROOT / m["source"]).exists():
            problems.append(f"{where}: registry row is not matched C with a source file")
            continue
        why = overlay_size_problem(m, infos[member], starts[member])
        if why:
            problems.append(f"{where}: size mismatch: {why}")
            continue
        if own_code_only:
            why = overlay_origin_problem(m)
            if why:
                problems.append(f"{where}: origin: {why}")
                continue
        picked.append(m)
    if problems:
        raise BuildError("overlay allow list:\n  " + "\n  ".join(problems))
    return picked


def dedup_overlays(cands, infos):
    """One candidate per (vram, digest): identical bytes over the extent give
    one native entry valid wherever they are resident. A clean-room/owner
    source is preferred, then the member name. Each kept row gets "covers"
    (all members with those bytes); returns (kept, dropped rows)."""
    groups = {}
    for m in cands:
        d = member_digest(infos[m["region"]], m["vram"], m["size"]) if m.get("size") else None
        key = (m["vram"], d) if d is not None else (m["vram"], m["region"])
        groups.setdefault(key, []).append(m)
    kept, dropped = [], []
    for key in sorted(groups, key=lambda k: (k[0], str(k[1]))):
        rows = sorted(groups[key], key=lambda m: (overlay_origin_problem(m) is not None, m["region"]))
        rep = dict(rows[0], covers=sorted(m["region"] for m in rows))
        kept.append(rep)
        dropped += [dict(m, covered_by=rep["region"]) for m in rows[1:]]
    return kept, dropped


def select_overlays(args, only, exclude):
    """-> (candidates with "covers", member infos, missing members, report
    rows of deduplicated candidates)."""
    infos, missing = {}, []
    pairs = parse_overlay_allow(args.overlay_allow) if args.overlay_allow else None
    if getattr(args, "strict_overlay_allow", None):
        if not (STRICT and STRICT_PROVENANCE_ALLOW):
            raise SystemExit("native_lane_gen: --strict-overlay-allow needs --strict and "
                             "--strict-provenance-allow")
        extra = parse_strict_overlay_allow(args.strict_overlay_allow)
        have = set(pairs or [])
        pairs = (pairs or []) + [p for p in extra if p not in have]
        print(f"native_lane_gen: strict overlay allow: {len(extra)} pairs")
    if pairs is not None:
        members = sorted({m for m, _ in pairs})
        for mem in members:
            infos[mem] = member_info(mem, strict=True)
        cands = allow_candidates(pairs, infos, args.own_code_only)
        print(f"native_lane_gen: overlay allow list: {len(pairs)} pairs in {members}")
    elif args.own_code_only:
        # The main --only list is vram-only and names no overlay function:
        # release overlays come from --overlay-allow alone.
        if args.overlay_members:
            print("native_lane_gen: own-code-only without --overlay-allow: overlay members "
                  f"{args.overlay_members} stay interpreted")
        cands = []
    else:
        for mem in [m for m in args.overlay_members.split(",") if m]:
            info = member_info(mem)
            if info is None:
                missing.append(mem)  # no config, no local member file, or another file
            else:
                infos[mem] = info
        cands = overlay_candidates(set(infos), only)
    excluded = [m for m in cands if m["vram"] in exclude]
    if excluded and pairs is not None:
        print(f"native_lane_gen: --exclude drops {len(excluded)} allow-listed overlay functions")
    cands = [m for m in cands if m["vram"] not in exclude]
    kept, dropped = dedup_overlays(cands, infos)
    rows = [dict(member=m["region"], vram=f"{m['vram']:08x}", covered_by=m["covered_by"]) for m in dropped]
    return kept, infos, missing, rows


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--out", required=True, type=Path)
    ap.add_argument("--clang", default=shutil.which("clang") or "clang")
    ap.add_argument("--ar", default=shutil.which("ar") or "ar")
    ap.add_argument("--jobs", type=int, default=4)
    ap.add_argument("--only", action="append",
                    help="file of guest PCs (hex, one per line) to consider, e.g. a trace; "
                         "repeatable (the union is used: strict builds add "
                         "config/lane_strict_allow.txt)")
    ap.add_argument("--exclude", help="file of guest PCs (hex) never to admit")
    ap.add_argument("--own-code-only", action="store_true",
                    help="compile only owner-authored matched C (see third_party_derived)")
    ap.add_argument("--overlay-allow", type=Path,
                    help="file of '<member> <vram>' overlay functions to compile (release); "
                         "the overlay candidates are exactly these, checked strictly")
    ap.add_argument("--strict-overlay-allow", type=Path,
                    help="strict builds with --strict-provenance-allow: extra overlay pairs "
                         "('<member> <vram>' or '<member> all' = every matched C function "
                         "of that member), checked like --overlay-allow")
    ap.add_argument("--strict", action="store_true",
                    help="MUSASHI_STRICT_NATIVE build: there is no interpreter, so no PC is "
                         "observed by formatter_step or a checkpoint; the hooks rule, the "
                         "caller-pinned GTE rule and the PsyQ hooked hold-back do not apply")
    ap.add_argument("--strict-provenance-allow", type=Path,
                    help="with --strict --own-code-only: registry origins (one per line, verbatim) "
                         "whose matched main C is also compiled, e.g. upstream-derived C "
                         "(config/lane_strict_provenance_allow.txt)")
    ap.add_argument("--overlay-members", default="",
                    help="comma-separated overlay members to compile (e.g. main_0003); each needs "
                         "config/overlay_<m>.yaml and its extracted member file for the digests")
    args = ap.parse_args()
    out = args.out
    (out / "ir").mkdir(parents=True, exist_ok=True)
    def pcs(path):
        return {int(t.split()[0], 16) for t in Path(path).read_text().splitlines()
                if t.strip() and not t.startswith("#")}
    only = set().union(*(pcs(f) for f in args.only)) if args.only else None
    exclude = pcs(args.exclude) if args.exclude else set()
    symbols = load_symbol_addrs()
    global STRICT
    STRICT = args.strict
    if STRICT:
        os.environ["MUSASHI_LANE_STRICT"] = "1"
    hooks = {} if STRICT else hooked_pcs()
    if args.strict_provenance_allow:
        if not STRICT:
            raise SystemExit("native_lane_gen: --strict-provenance-allow needs --strict")
        STRICT_PROVENANCE_ALLOW.update(
            t.strip() for t in args.strict_provenance_allow.read_text().splitlines()
            if t.strip() and not t.startswith("#"))
        registry = json.loads((ROOT / "provenance/matches.json").read_text())["matches"]
        extra = {m["vram"] for m in registry
                 if m["region"] == "main" and lane_recovery(m) and provenance_allowed(m)}
        if only is not None:
            only = only | extra
        print(f"native_lane_gen: strict provenance allow: {len(extra)} main functions with origins "
              f"{sorted(STRICT_PROVENANCE_ALLOW)}")
    psyq_excluded = []
    todo = [m for m in candidates(only, psyq_excluded) if m["vram"] not in exclude]
    if args.own_code_only:
        kept = [m for m in todo if not third_party_derived(m)]
        print(f"native_lane_gen: own-code-only: {len(todo) - len(kept)} third-party-derived "
              f"candidates left to the interpreter")
        todo = kept
    ovl_todo, infos, missing, ovl_rows = select_overlays(args, only, exclude)
    msyms = {mem: load_symbol_addrs(mem) for mem in infos}
    with concurrent.futures.ThreadPoolExecutor(max_workers=max(1, args.jobs)) as pool:
        results = list(pool.map(lambda m: build_one(m, out, symbols, hooks, args.clang), todo))
        ovl_results = list(pool.map(lambda m: build_one(m, out, msyms[m["region"]], hooks, args.clang,
                                                        infos[m["region"]]), ovl_todo))
    for m, r in zip(todo, results):
        if provenance_allowed(m):
            r["strict_provenance_allow"] = m.get("origin") or ""
    for m, r in zip(ovl_todo, ovl_results):
        r["covers"] = m["covers"]
        r["origin"] = m.get("origin") or ""
    results += ovl_results
    admitted = [r for r in results if r["admitted"]]
    # A direct native call cannot reproduce a MIPS caller that passes fewer
    # arguments than the callee reads: the callee sees whatever the caller
    # left in a1-a3. Refuse such callers (to a fixpoint, since a refused
    # caller becomes an interpreted callee for others).
    while True:
        arity = {"lane_" + a["qname"]: len(a["defs"]["lane_" + a["qname"]][2]) for a in admitted}
        drop = set()
        for a in admitted:
            for sym, (callee, sig, argc, _) in a["stubs"].items():
                if "lane_" + callee in arity and argc < arity["lane_" + callee]:
                    drop.add(a["qname"])
                    a.update(admitted=False, rule="abi",
                             detail=f"passes {argc} of {arity['lane_' + callee]} arguments to {callee}")
        if not drop:
            break
        admitted = [a for a in admitted if a["qname"] not in drop]
    # A void-typed body cannot return a value, but the retail words of a
    # function the C calls void may still leave one in v0/v1 that a retail
    # caller reads after the jal (800D2454 cut the intro FMV this way). Its
    # native wrapper would leave the register stale: refuse it (rule abi).
    blobs = retail_code_blobs(infos)
    for a in admitted:
        if a["defs"]["lane_" + a["qname"]][0] != "void":
            continue
        readers = void_result_readers(a["vram"], blobs)
        if readers:
            a.update(admitted=False, rule="abi",
                     detail="void callee, caller reads v0/v1 at " + ", ".join(f"{p:08x}" for p in readers[:4]))
    admitted = [a for a in admitted if a["admitted"]]
    # Implicit argument pass-through (ArgLiveness): an admitted function
    # whose retail words read an argument register its C does not declare
    # is never called directly; native callers reach it through the thunk,
    # whose guest registers carry their arguments, and lane_try still runs
    # it natively. Registers past the arguments a caller passes keep the
    # guest value they hold at the call, which is the caller's own entry
    # value only when the caller passes that register through too; a caller
    # that does not is refused (rule abi).
    flags = passthrough_flags(admitted, infos)
    apply_passthrough(admitted, flags)
    admitted = [a for a in admitted if a["admitted"]]
    # A native caller of an admitted callee links to it directly; otherwise
    # the thunk runs the guest words. Duplicate definitions cannot occur:
    # each TU defines only its own registry function under lane_func_*.
    direct, thunk, hook_thunk, pass_thunk = emit_table(
        admitted, out, frozenset(plat_hook_sites()),
        frozenset("lane_" + a["qname"] for a in admitted if a.get("passthrough")))
    blocked = [] if STRICT else psyq_hooked(hooks)
    with open(out / "native_lane_table.c", "a") as table:
        table.write("\n/* PsyQ compat entries whose body holds a port-sequenced PC. */\n")
        table.write("const uint32_t musashi_native_lane_hooked_psyq[] = {\n")
        table.write("".join(f"    0x{pc:08x}u,\n" for pc in blocked) or "    0u,\n")
        table.write("};\n")
        table.write(f"const size_t musashi_native_lane_hooked_psyq_count = {len(blocked)}u;\n")
    lib = out / "libmusashi_native_lane.a"
    if lib.exists():
        lib.unlink()
    objs = [r["obj"] for r in admitted]
    if objs:
        r = run([args.ar, "rcs", str(lib), *objs])
        if r.returncode:
            print(r.stderr, file=sys.stderr)
            return 1
    else:
        stub = out / "ir" / "empty.c"
        stub.write_text("typedef int musashi_native_lane_empty;\n")
        run([args.clang, "-c", str(stub), "-o", str(out / "ir" / "empty.o")])
        run([args.ar, "rcs", str(lib), str(out / "ir" / "empty.o")])
    rules = {}
    for r in results:
        if not r["admitted"]:
            rules[r["rule"]] = rules.get(r["rule"], 0) + 1
    cycles = cycle_summary(results)
    report = dict(candidates=len(results), admitted=len(admitted), rejected_by_rule=rules,
                  cycles=cycles,
                  psyq_excluded=len(psyq_excluded),
                  psyq_hooked=[f"{pc:08x}" for pc in blocked],
                  call_stubs=dict(direct=direct, interpreter_thunk=thunk,
                                  hook_site_thunk=hook_thunk, passthrough_thunk=pass_thunk),
                  passthrough=[dict(member=a.get("member"), vram=f"{a['vram']:08x}", detail=a["passthrough"])
                               for a in sorted(admitted, key=lambda a: (a["vram"], a.get("member") or ""))
                               if a.get("passthrough")],
                  overlay=dict(members=sorted(infos), missing=missing,
                               allow=str(args.overlay_allow) if args.overlay_allow else None,
                               candidates=len(ovl_todo),
                               admitted=sum(1 for a in admitted if a.get("member")),
                               functions=[dict(member=r["member"], vram=f"{r['vram']:08x}", size=r["size"],
                                               digest=f"{r['digest']:016x}" if r.get("digest") is not None
                                               else None,
                                               covers=r["covers"], admitted=r["admitted"],
                                               rule=None if r["admitted"] else r["rule"],
                                               detail=None if r["admitted"] else r["detail"],
                                               origin=r["origin"])
                                          for r in sorted(ovl_results, key=lambda r: (r["vram"], r["member"]))],
                               deduplicated=ovl_rows),
                  functions=[{k: (f"{v:016x}" if k == "digest" and v is not None else v)
                              for k, v in r.items() if k not in ("obj", "defs", "stubs", "ledger_rows")}
                             for r in sorted(results, key=lambda r: (r["vram"], r.get("member") or ""))])
    (out / "report.json").write_text(json.dumps(report, indent=1) + "\n")
    print(f"native lane: {len(admitted)}/{len(results)} game functions admitted "
          f"({len(psyq_excluded)} PsyQ-range candidates excluded); rejected {rules}; "
          f"call stubs direct={direct} thunk={thunk} (hook-site thunks {hook_thunk}, "
          f"pass-through thunks {pass_thunk}; {len(flags)} admitted functions pass arguments through)")
    print("native lane cycles (D-011): mapped " + ", ".join(
        f"{k} {v['mapped']}/{v['mapped'] + v['refused']}" for k, v in cycles["by_class"].items())
          + f"; ledger {sum(1 for a in admitted if a.get('ledger'))} of {len(admitted)} admitted, "
          f"{len(cycles['would_refuse'])} keep the fixed charge (inexact timing, D-011)")
    ovl_admitted = sum(1 for a in admitted if a.get("member"))
    print(f"native lane overlay: {ovl_admitted}/{len(ovl_results)} admitted from {sorted(infos)}"
          + "".join(f"; {r['member']} {r['vram']:08x} {r['rule']}" for r in ovl_results if not r["admitted"]))
    return 0


if __name__ == "__main__":
    try:
        sys.exit(main())
    except BuildError as e:
        print(f"native_lane_gen: ERROR: {e}", file=sys.stderr)
        sys.exit(2)
