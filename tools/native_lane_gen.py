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
            constants inside game RAM
  calls   : only direct calls to prototyped guest functions (lane_func_*),
            module-internal functions and memory intrinsics; no inline asm
  arith   : no variable or trapping divisors (x86 traps where MIPS does not),
            variable shift counts must be masked to 5 bits
  ub      : no undef/poison operands and no unreachable (UB the host
            optimizer could exploit differently from gcc-2.7.2)
  abi     : parameters/returns limited to 8/16/32-bit integers and pointers;
            no direct call passing fewer arguments than the callee reads
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
RAM_LO, RAM_HI = 0x80010000, 0x80200000
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


def strip_empty_asm(text):
    """Drop empty-template asm statements that are identities on the host:
    no outputs, or every output tied to an input ("N") with the same
    expression; clobbers (incl. "memory") only steer MIPS scheduling. Returns
    (text, dropped) or None when an empty asm has an untied output (its value
    would be whatever the MIPS register held)."""
    pat = re.compile(r'\b(?:__asm__|__asm|asm)\s*(?:__volatile__|volatile)?\s*\(\s*""\s*')
    pos, pieces, dropped = 0, [], 0
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
        for k, (cons, expr) in enumerate(outs):
            if not any(c == str(k) and e == expr for c, e in ins):
                return None
        pieces.append(text[pos:m.start()])
        pieces.append("/* empty asm removed for the host */")
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
    context = re.compile(r"\bpc\b|->pc|\.pc|r\[31\]|raw_cpu|_caller|\bcase ")
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
            if m.group(2).startswith("alloca "):
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
                            re.match(r"and i64 .*, 4294967295$", d)):
                        raise Reject("inttoptr", f"integer->pointer from '{d[:40]}'")
                elif re.fullmatch(r"-?\d+", val) and not RAM_LO <= int(val) < RAM_HI:
                    raise Reject("inttoptr", f"constant address {int(val):x}")
            for const in re.findall(r"inttoptr \(i64 (-?\d+) to ptr\)", rhs):
                if not RAM_LO <= int(const) < RAM_HI:
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
                if name in ("memset", "memcpy", "memmove") or name in LANE_HELPERS:
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


def host_source(text):
    return REG_PIN_RE.sub(r"\1", text)


# Admissible by every rule, but held out until a differential covers them:
# with the probe's generic inputs none of their cases was comparable.
DENY = {
    0x80015498: "no comparable differential case yet (mirror faults on generic inputs)",
    0x80016638: "no comparable differential case yet (not comparable / mirror faults)",
    0x800167F0: "no comparable differential case yet (mirror faults on generic inputs)",
    0x8002FF0C: "no comparable differential case yet (interpreter refused every case)",
}


def build_one(entry, out, symbols, hooks, clang, info=None):
    vram, size, src = entry["vram"], entry["size"], ROOT / entry["source"]
    name = entry["name"]
    member = info["member"] if info else None
    tag = f"{member}_{vram:08x}" if member else f"{vram:08x}"
    work = out / "ir"
    try:
        if vram in DENY:
            raise Reject("deny", DENY[vram])
        for pc, kind in hooks.items():
            if not vram <= pc < vram + size:
                continue
            if pc == vram and (vram in INTRINSIC_PCS or kind == "entry"):
                continue
            raise Reject("hooks", f"port references {pc:08x}")
        if info:
            jt = guest_jump_table(info, vram, size)
            if jt:
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
        stripped = strip_empty_asm(host)
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
        check_layout(ir)
        rewritten = lower_arith(narrow_pointer_cells(rewrite_symbols(
            ir, symbols, member, info["code"] if info else ())))
        sub = work / f"{tag}.sub.ll"
        sub.write_text(rewritten)
        opt = work / f"{tag}.opt.ll"
        # No auto-vectorisation or unrolling: their splat and remainder idioms
        # (insertelement poison, phi poison) trip
        # the undef/poison check, and lane functions gain nothing from it.
        r = run([clang, f"--target={HOST_TARGET}", "-O2", "-fno-vectorize", "-fno-slp-vectorize", "-fno-unroll-loops",
                 "-S", "-emit-llvm", "-w", str(sub), "-o", str(opt)])
        if r.returncode:
            raise Reject("compile", "optimize: " + (r.stderr.strip().splitlines() or ["?"])[0][:160])
        optir, icalls = rewrite_indirect_calls(opt.read_text())
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
                    and u not in MEMORY_FNS and u not in LANE_HELPERS:
                raise Reject("symbols", f"object still references {u}")
        digest = member_digest(info, vram, size) if info else None
        if info and digest is None:
            raise Reject("overlay", "extent outside the member file")
        return dict(name=name, qname=qualify(member, name), member=member, vram=vram, size=size,
                    source=entry["source"], admitted=True, obj=str(obj), defs=sigs, stubs=stubs,
                    icalls=icalls, digest=digest)
    except Reject as e:
        return dict(name=name, qname=qualify(member, name), member=member, vram=vram, size=size,
                    source=entry["source"], admitted=False, rule=e.rule, detail=e.detail,
                    digest=member_digest(info, vram, size) if info else None)


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


def emit_table(admitted, out, entry_sites=frozenset()):
    """Write native_lane_table.c. Returns (direct, thunk, hooked): direct
    native calls, interpreter thunks, and admitted callees reached through
    the thunk because they are platform entry-hook sites."""
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
    direct = thunk = hooked = 0
    ovl = {"lane_" + a["qname"]: a for a in admitted if a.get("member")}
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
        native = target in defs and int(addr, 16) not in entry_sites
        hooked += target in defs and not native
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
               f"{len(params)}u, {0 if ret == 'void' else 1}u}}")
        if a.get("member"):
            ovl_entries.append(f"    {{{row}, {a['size']}u, 0x{a['digest']:016x}ull, \"{a['member']}\"}},")
        else:
            entries.append(f"    {row},")
    lines.append("")
    lines.append("const MusashiNativeLaneEntry musashi_native_lane_generated[] = {")
    lines.extend(entries or ["    {0u, 0u, NULL, NULL, 0u, 0u},"])
    lines.append("};")
    lines.append(f"const size_t musashi_native_lane_generated_count = {len(entries)}u;")
    lines.append("")
    lines.append("/* Overlay members: run only while guest RAM over the extent hashes to the")
    lines.append(" * member's digest (FNV-1a 64 of the user's own extracted member file). */")
    lines.append("const MusashiNativeLaneOverlayEntry musashi_native_lane_overlay[] = {")
    lines.extend(ovl_entries or ["    {{0u, 0u, NULL, NULL, 0u, 0u}, 0u, 0u, NULL},"])
    lines.append("};")
    lines.append(f"const size_t musashi_native_lane_overlay_count = {len(ovl_entries)}u;")
    (out / "native_lane_table.c").write_text("\n".join(lines) + "\n")
    return direct, thunk, hooked


# --own-code-only: a registry entry is third-party-derived when its origin or
# its source's header names the upstream decomp (Druthulu/BFM-decomp, whose
# src/ carries no license) or another project's PsyQ C. Such functions stay
# interpreted from the player's disc, so the binary compiles none of them.
THIRD_PARTY_MARK = re.compile(r"vendor|Druthulu|BFM-decomp|psyq|Sony|parasite|xenogears", re.I)


def third_party_derived(m):
    if THIRD_PARTY_MARK.search(m.get("origin") or ""):
        return True
    src = ROOT / m["source"]
    return src.exists() and bool(THIRD_PARTY_MARK.search(src.read_text(errors="replace")[:2000]))


def candidates(only=None, excluded=None):
    """Game-code candidates. Sony PsyQ library ranges (config/psyq_ranges.txt)
    never enter the lane: their entry points belong to PsyCross/HLE."""
    sys.path.insert(0, str(ROOT / "tools"))
    import psyq_manifest
    psyq = psyq_manifest.ranges()
    registry = json.loads((ROOT / "provenance/matches.json").read_text())["matches"]
    picked = []
    for m in registry:
        if m["region"] != "main" or m.get("recovery") != "c":
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
        if other and not (m["vram"] in INTRINSIC_PCS and
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
    ap.add_argument("--only", help="file of guest PCs (hex, one per line) to consider, e.g. a trace")
    ap.add_argument("--exclude", help="file of guest PCs (hex) never to admit")
    ap.add_argument("--own-code-only", action="store_true",
                    help="compile only owner-authored matched C (see third_party_derived)")
    ap.add_argument("--overlay-allow", type=Path,
                    help="file of '<member> <vram>' overlay functions to compile (release); "
                         "the overlay candidates are exactly these, checked strictly")
    ap.add_argument("--overlay-members", default="",
                    help="comma-separated overlay members to compile (e.g. main_0003); each needs "
                         "config/overlay_<m>.yaml and its extracted member file for the digests")
    args = ap.parse_args()
    out = args.out
    (out / "ir").mkdir(parents=True, exist_ok=True)
    def pcs(path):
        return {int(t.split()[0], 16) for t in Path(path).read_text().splitlines()
                if t.strip() and not t.startswith("#")}
    only = pcs(args.only) if args.only else None
    exclude = pcs(args.exclude) if args.exclude else set()
    symbols = load_symbol_addrs()
    hooks = hooked_pcs()
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
    # A native caller of an admitted callee links to it directly; otherwise
    # the thunk runs the guest words. Duplicate definitions cannot occur:
    # each TU defines only its own registry function under lane_func_*.
    direct, thunk, hook_thunk = emit_table(admitted, out, frozenset(plat_hook_sites()))
    blocked = psyq_hooked(hooks)
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
    report = dict(candidates=len(results), admitted=len(admitted), rejected_by_rule=rules,
                  psyq_excluded=len(psyq_excluded),
                  psyq_hooked=[f"{pc:08x}" for pc in blocked],
                  call_stubs=dict(direct=direct, interpreter_thunk=thunk,
                                  hook_site_thunk=hook_thunk),
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
                              for k, v in r.items() if k not in ("obj", "defs", "stubs")}
                             for r in sorted(results, key=lambda r: (r["vram"], r.get("member") or ""))])
    (out / "report.json").write_text(json.dumps(report, indent=1) + "\n")
    print(f"native lane: {len(admitted)}/{len(results)} game functions admitted "
          f"({len(psyq_excluded)} PsyQ-range candidates excluded); rejected {rules}; "
          f"call stubs direct={direct} thunk={thunk} (hook-site thunks {hook_thunk})")
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
