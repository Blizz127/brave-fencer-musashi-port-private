#!/usr/bin/env python3
"""Retail cycle model for native-lane functions (D-011, phase 2a: report only).

The interpreter charges guest time per retail instruction (pc_port/
mips_formatter.c formatter_step): 2 cycles, +1 for a data load or store
(LB/LH/LW/LBU/LHU/SB/SH/SW/LWC2/SWC2), LWL/LWR 3, SWL/SWR 4. Delay slots count.
A native-lane call today charges a fixed 2 * words at return instead.

This module does two things, both from the user's own retail words:

G1  retail control flow and cost. `retail_cfg` decodes a function's words
    into segments: straight runs that end in a guest-visible or branching
    event (conditional branch, call, return, trap). Each segment carries the
    exact interpreter cost of its instructions, delay slots included, so the
    cost of any retail path is the sum of its segments.

G2  the product walk. To charge that cost from native code, every edge of
    the host IR must be tied to the retail instructions it stands for.
    `map_function` walks the clang -O0 CFG of the same C (before
    optimisation, so its shape follows the source) together with the retail
    CFG. Calls (callee and order) and returns are anchors; a clang
    conditional branch is paired with the next retail conditional branch,
    with the polarity taken from the two predicates (relation family,
    direction, constant) when both are recognisable. A clang branch the
    retail code does not have (gcc's branch-free set/compare idioms) is
    "transparent": both arms continue against the same retail position.
    The result is a product graph whose states are (clang position, retail
    pc); a clang block reached at several retail pcs (gcc loop inversion,
    for instance) would be node-split in phase 2b so that every edge carries
    one constant cost.

    The mapping is heuristic, not translation validation. It is accepted
    only when it is complete and consistent: every reachable clang event and
    every reachable retail branch is covered, every product cycle consumes
    retail time, and among the consistent solutions the ones that best agree
    with the predicates (pairings against a recognised, contradicting
    predicate rank last) all charge the same costs. Anything else
    is refused with a named reason (rule `cycles` in phase 2b). Phase 2a only
    reports; admission and the runtime charge are unchanged.
"""
import re

# ---------------------------------------------------------------- G1: retail

LOADS = {32, 33, 35, 36, 37}          # lb lh lw lbu lhu
STORES = {40, 41, 43}                 # sb sh sw
LWLR = {34, 38}
SWLR = {42, 46}
COP2_MEM = {50, 58}                   # lwc2 swc2
AT = 1


def insn_cost(word):
    """Interpreter cycles for one retail instruction (formatter_step)."""
    op = word >> 26
    if op in LOADS or op in STORES or op in COP2_MEM:
        return 3
    if op in LWLR:
        return 3
    if op in SWLR:
        return 4
    return 2


def sext16(x):
    x &= 0xFFFF
    return x - 0x10000 if x & 0x8000 else x


class Refuse(Exception):
    def __init__(self, reason):
        super().__init__(reason)
        self.reason = reason


def decode(word, pc):
    """(kind, info) for control-flow relevant instructions; ('op', None) else."""
    op = word >> 26
    rs, rt = (word >> 21) & 31, (word >> 16) & 31
    if op == 0:
        fn = word & 63
        if fn == 8:
            return ("jr", rs)
        if fn == 9:
            return ("jalr", rs)
        if fn == 12:
            return ("syscall", None)
        if fn == 13:
            return ("break", (word >> 6) & 0xFFFFF)
        return ("op", None)
    if op == 1:
        target = pc + 4 + (sext16(word) << 2)
        if rt in (16, 17):
            return ("bal", target)
        if rt == 1 and rs == 0:                  # bgez $0: always
            return ("j", target)
        if rt in (0, 1):
            return ("cond", target)
        return ("bad", None)
    if op == 2:
        return ("j", (pc & 0xF0000000) | ((word & 0x3FFFFFF) << 2))
    if op == 3:
        return ("jal", (pc & 0xF0000000) | ((word & 0x3FFFFFF) << 2))
    if op in (4, 5, 6, 7):
        target = pc + 4 + (sext16(word) << 2)
        if op == 4 and rs == 0 and rt == 0:      # b
            return ("j", target)
        if op == 5 and rs == 0 and rt == 0:      # never taken
            return ("op", None)
        return ("cond", target)
    if op in (20, 21, 22, 23):                   # branch-likely: not R3000
        return ("bad", None)
    return ("op", None)


class Retail:
    """A function's retail words with their segment structure."""

    def __init__(self, vram, words):
        self.vram = vram
        self.words = list(words)
        self.end = vram + 4 * len(self.words)
        self._seg = {}

    def targets(self):
        """Branch and jump targets inside the extent (block starts)."""
        if not hasattr(self, "_targets"):
            t = set()
            for i, w in enumerate(self.words):
                pc = self.vram + 4 * i
                kind, info = decode(w, pc)
                if kind in ("cond", "j") and info is not None:
                    t.add(info)
            self._targets = t
        return self._targets

    def word(self, pc):
        if not self.vram <= pc < self.end:
            raise Refuse(f"retail pc {pc:08x} outside the extent")
        return self.words[(pc - self.vram) // 4]

    def cost(self, pc):
        return insn_cost(self.word(pc))

    def trap_fallthrough(self, pc):
        """A conditional branch whose fall-through is a `break` (gcc's
        divide-by-zero / overflow checks): taken on every non-trapping path."""
        nxt = pc + 8
        return self.vram <= nxt < self.end and decode(self.word(nxt), nxt)[0] == "break"

    def divm1_check(self, pc):
        """`li $at,-1; bne rt,$at,L` of gcc's signed-division overflow check.
        Taken unless the divisor is -1; returns the extra cost of the
        divisor == -1 path (it rejoins L, or traps)."""
        if pc - 4 < self.vram:
            return None
        w, prev = self.word(pc), self.word(pc - 4)
        if prev != 0x2401FFFF or w >> 26 != 5 or (w >> 16) & 31 != AT:
            return None
        target = pc + 4 + (sext16(w) << 2)
        # not taken: pc+8 (`bne rs,$at,L`), pc+12 (its delay slot), then L
        w2 = self.word(pc + 8)
        if w2 >> 26 != 5 or (w2 >> 16) & 31 != AT or pc + 12 + (sext16(w2) << 2) != target:
            return None
        return self.cost(pc + 8) + self.cost(pc + 12)

    def pow2_adjust(self, pc):
        """gcc's signed division by 2^k: `bgez x,L; <slot>; addiu x,x,2^k-1;
        L:`. Taken unless the dividend is negative; returns the extra cost
        of the negative path (the addiu), or None."""
        w = self.word(pc)
        if w >> 26 != 1 or (w >> 16) & 31 != 1:
            return None
        reg = (w >> 21) & 31
        if pc + 4 + (sext16(w) << 2) != pc + 12 or pc + 8 >= self.end:
            return None
        a = self.word(pc + 8)
        imm = a & 0xFFFF
        if a >> 26 != 9 or (a >> 21) & 31 != reg or (a >> 16) & 31 != reg or \
                imm == 0 or (imm + 1) & imm:
            return None
        return self.cost(pc + 8)

    def segment(self, start):
        """Walk from `start` to the next event. Returns a dict:
        pcs: retail pcs executed in order (delay slots included), cost,
        kind: cond|call|ret|trap, and per kind: pc/taken/fall, target/resume.
        Unconditional jumps are followed; gcc's trap checks are folded in
        (taken), and a divisor == -1 check is folded in with its extra cost
        recorded under `div_m1`."""
        if start in self._seg:
            return self._seg[start]
        pcs, cost, divs, seen = [], 0, [], set()
        pc = start
        while True:
            if pc in seen:
                raise Refuse(f"retail loop without an event at {pc:08x}")
            seen.add(pc)
            kind, info = decode(self.word(pc), pc)
            if kind == "op":
                pcs.append(pc); cost += self.cost(pc); pc += 4
                continue
            if kind in ("bad", "syscall", "bal"):
                raise Refuse(f"retail {kind} at {pc:08x}")
            if kind == "break":
                pcs.append(pc); cost += self.cost(pc)
                seg = dict(pcs=pcs, cost=cost, kind="trap", pc=pc, divs=divs)
                break
            slot = pc + 4
            sk, _ = decode(self.word(slot), slot)
            if sk not in ("op",):
                raise Refuse(f"control transfer in a delay slot at {slot:08x}")
            pcs += [pc, slot]; cost += self.cost(pc) + self.cost(slot)
            if kind == "j":
                pc = info
                continue
            if kind == "cond":
                if self.trap_fallthrough(pc):
                    pc = info
                    continue
                m1 = self.divm1_check(pc)
                if m1 is not None:
                    divs.append(dict(pc=pc, kind="div_m1", extra=m1))
                    pc = info
                    continue
                p2 = self.pow2_adjust(pc)
                if p2 is not None:
                    divs.append(dict(pc=pc, kind="sdiv_pow2", extra=p2))
                    pc = info
                    continue
                seg = dict(pcs=pcs, cost=cost, kind="cond", pc=pc, taken=info, fall=pc + 8,
                           divs=divs)
                break
            if kind == "jal":
                seg = dict(pcs=pcs, cost=cost, kind="call", pc=pc, target=info,
                           resume=pc + 8, divs=divs)
                break
            if kind == "jalr":
                seg = dict(pcs=pcs, cost=cost, kind="call", pc=pc, target=None,
                           resume=pc + 8, divs=divs)
                break
            if kind == "jr":
                if info != 31:
                    raise Refuse(f"jr ${info} at {pc:08x} (jump table)")
                seg = dict(pcs=pcs, cost=cost, kind="ret", pc=pc, divs=divs)
                break
            raise Refuse(f"unhandled {kind} at {pc:08x}")
        self._seg[start] = seg
        return seg

    def branch_pred(self, pc):
        """The retail branch at `pc` as a predicate on the compared value:
        (family, direction, const, taken_when_true) or None when it cannot be
        recognised. family: eq | s | u (signed / unsigned order); for eq,
        taken_when_true means taken iff equal; for order, direction is '<' or
        '>' with a strict constant (x < K / x > K), const None for a register
        operand."""
        w = self.word(pc)
        op = w >> 26
        rs, rt = (w >> 21) & 31, (w >> 16) & 31
        if op == 1:
            # bltz: x < 0, bgez: x >= 0 == x > -1
            return ("s", "<", 0, True) if rt == 0 else ("s", ">", -1, True)
        if op == 6:
            return ("s", "<", 1, True)       # blez: x <= 0 == x < 1
        if op == 7:
            return ("s", ">", 0, True)       # bgtz
        if op not in (4, 5):
            return None
        eq_taken = op == 4
        if rt != 0 and rs != 0:
            return ("eq", None, None, eq_taken)
        reg = rs or rt
        d = self.definer(pc, reg)
        if d is None:
            return ("eq", None, 0, eq_taken)
        dop, dfn, dimm, d_rs, d_rt = d
        # set-on-less-than: branch on (x < y) != 0
        nonzero_taken = not eq_taken        # bne t,$0: taken iff t != 0
        if dop == 0 and dfn in (42, 43):     # slt / sltu
            fam = "s" if dfn == 42 else "u"
            if d_rs == 0 and fam == "u":     # sltu t,$0,x: x != 0
                return ("eq", None, 0, not nonzero_taken)
            return (fam, "<", None, nonzero_taken)
        if dop in (10, 11):                  # slti / sltiu
            fam = "s" if dop == 10 else "u"
            if fam == "u" and dimm == 1:     # sltiu t,x,1: x == 0
                return ("eq", None, 0, nonzero_taken)
            return (fam, "<", dimm, nonzero_taken)
        return ("eq", None, 0, eq_taken)

    def preds(self, start):
        """Predecessor edges of the block starting at `start`, as the pc of
        the last instruction executed before it: a branch's delay slot, or
        the fall-through instruction."""
        out = []
        for i, w in enumerate(self.words):
            src = self.vram + 4 * i
            kind, info = decode(w, src)
            if kind in ("cond", "j") and info == start:
                out.append(src + 4)              # its delay slot ran last
        prev = start - 4
        if prev >= self.vram:
            k2 = decode(self.word(prev - 4), prev - 4)[0] if prev - 4 >= self.vram else "op"
            k1 = decode(self.word(prev), prev)[0]
            # falls through unless prev is a jump's delay slot, a jump, or a
            # trap/return
            if k1 not in ("j", "jr", "break") and k2 not in ("j", "jr"):
                out.append(prev)
        return out

    def _writes(self, w, reg):
        """(op, fn, imm, rs, rt) when `w` writes GPR `reg`; 'unknown' when it
        may (COP2 moves); None otherwise."""
        op = w >> 26
        if op == 0:
            if (w >> 11) & 31 == reg and (w & 63) not in (8, 12, 13, 24, 25, 26, 27, 17, 19):
                return (0, w & 63, None, (w >> 21) & 31, (w >> 16) & 31)
            return None
        if op == 18:
            return "unknown" if (w >> 16) & 31 == reg else None
        if op in (1, 2, 3, 4, 5, 6, 7) or op in (40, 41, 42, 43, 46, 58):
            return None
        if (w >> 16) & 31 == reg:
            return (op, None, sext16(w), (w >> 21) & 31, (w >> 16) & 31)
        return None

    def definer(self, pc, reg, depth=0):
        """The instruction that last wrote `reg` before the branch at `pc`,
        following straight code and single-predecessor block starts (a
        predecessor branch's delay slot included), as (op, fn, imm, rs, rt),
        or None when unknown or path-dependent."""
        p = pc - 4
        seen = 0
        while p >= self.vram and seen < 64:
            seen += 1
            if p + 4 in self.targets() or p + 4 == self.vram:
                break
            w = self.word(p)
            kind, _ = decode(w, p)
            if kind != "op":
                return None      # p is a control op: p+4 would be its slot
            r = self._writes(w, reg)
            if r == "unknown":
                return None
            if r:
                return r
            p -= 4
        start = p + 4
        if depth > 4 or start == self.vram:
            return None
        preds = self.preds(start)
        if len(preds) != 1:
            return None
        last = preds[0]
        w = self.word(last)
        r = self._writes(w, reg)
        if r == "unknown":
            return None
        if r:
            return r
        # continue above the predecessor (skip its branch if `last` is a slot)
        prev = last - 4
        if prev >= self.vram and decode(self.word(prev), prev)[0] != "op":
            return self.definer(prev, reg, depth + 1)
        return self.definer(last, reg, depth + 1)


def path_cost(retail, start, end_pc):
    """Cost of the straight-line retail range start..end_pc inclusive."""
    return sum(retail.cost(pc) for pc in range(start, end_pc + 4, 4))


def walk(retail, decisions, start=None):
    """Cost of one retail path from `start` (default: entry) to its return,
    taking each conditional branch as `decisions` says in order (True =
    taken). Returns (total cost, [cost up to each call, then the return])."""
    pc, costs, total, it = start or retail.vram, [], 0, iter(decisions)
    acc = 0
    while True:
        seg = retail.segment(pc)
        acc += seg["cost"]
        if seg["kind"] == "cond":
            pc = seg["taken"] if next(it) else seg["fall"]
        elif seg["kind"] == "call":
            costs.append(acc); total += acc; acc = 0
            pc = seg["resume"]
        elif seg["kind"] == "ret":
            costs.append(acc); total += acc
            return total, costs
        else:
            raise Refuse(f"path ends in {seg['kind']} at {seg['pc']:08x}")


def single_path_cost(retail):
    """Cost of a function with no conditional branch (straight-line) from
    entry to its return, plus the cost up to and including each call's delay
    slot: [(call target, cost since the previous boundary)], return cost."""
    calls, pc = [], retail.vram
    while True:
        seg = retail.segment(pc)
        if seg["kind"] == "call":
            calls.append((seg["target"], seg["cost"]))
            pc = seg["resume"]
        elif seg["kind"] == "ret":
            return calls, seg["cost"]
        else:
            raise Refuse(f"not straight-line ({seg['kind']} at {seg['pc']:08x})")


def shape(retail):
    """straight | straight+call | acyclic | acyclic+call | loop | loop+call
    over the reachable retail segments (None when the CFG is refused)."""
    seen, stack, calls, conds = set(), [retail.vram], 0, 0
    edges = {}
    while stack:
        pc = stack.pop()
        if pc in seen:
            continue
        seen.add(pc)
        seg = retail.segment(pc)
        succ = []
        if seg["kind"] == "cond":
            conds += 1
            succ = [seg["taken"], seg["fall"]]
        elif seg["kind"] == "call":
            calls += 1
            succ = [seg["resume"]]
        edges[pc] = succ
        stack.extend(succ)
    # cycle detection over segment starts
    color = {}

    def cyclic(n):
        color[n] = 1
        for s in edges.get(n, []):
            if color.get(s) == 1 or (s not in color and cyclic(s)):
                return True
        color[n] = 2
        return False

    loop = cyclic(retail.vram)
    base = "loop" if loop else ("acyclic" if conds else "straight")
    return base + ("+call" if calls else "")


# --------------------------------------------------------------- clang -O0

SWITCH_END = re.compile(r"^\s*\]")
LABEL = re.compile(r"^([\w.$-]+):")
CALL = re.compile(r"\bcall\b[^@%]*?(?:@([\w.$]+)|(%[\w.$-]+))\(")
BR_COND = re.compile(r"^\s*br i1 (\S+), label %([\w.$-]+), label %([\w.$-]+)")
BR = re.compile(r"^\s*br label %([\w.$-]+)")
DEF = re.compile(r"^\s*(%[\w.$-]+) = (.*)$")
GUEST_CALL = re.compile(r"^lane_(?:call_)?(?:[a-z]+\d*_\d{4}__)?func_([0-9A-Fa-f]{8})$")
DIV_HELPERS = ("lane_sdiv32", "lane_srem32", "lane_udiv32", "lane_urem32")
# N-GTE COP2 helpers (pc_port/mips_formatter.c lane_gte_*): each call stands
# for one retail COP2 move, command, LWC2 or SWC2, whose interpreter cost the
# retail segments already include (insn_cost), so a call is no event: no
# anchor, no charge of its own and no change to the CFG.
GTE_HELPERS = ("lane_gte_mtc2", "lane_gte_lwc2", "lane_gte_mfc2", "lane_gte_swc2",
               "lane_gte_ctc2", "lane_gte_cfc2", "lane_gte_cmd")


class Clang:
    """The entry function of a clang -O0 module: blocks, their events (calls
    in order, then the terminator) and the SSA definitions for predicates."""

    def __init__(self, ir, fname):
        m = re.search(r"^define [^@]*@" + re.escape(fname) + r"\(([^)]*)\)[^{]*\{\n(.*?)^\}",
                      ir, flags=re.M | re.S)
        if not m:
            raise Refuse(f"{fname} not in the module")
        self.blocks, self.order, self.defs, self.lines = {}, [], {}, {}
        self.text, self.span = ir, (m.start(2), m.end(2))
        params = re.findall(r"(%[\w.$-]+)", m.group(1))
        # The entry block is unnamed: its number is the next free one.
        cur = "%entry"
        nums = [int(p[1:]) for p in params if p[1:].isdigit()]
        if nums or not params:
            cur = str((max(nums) + 1) if nums else 0)
        lines = []
        for line in m.group(2).splitlines():
            lm = LABEL.match(line)
            if lm:
                self._close(cur, lines)
                cur, lines = lm.group(1), []
                continue
            if line.strip() and not line.strip().startswith(";"):
                lines.append(line)
        self._close(cur, lines)
        self.entry = self.order[0]
        self.loops = self._natural_loops()

    def succ(self, b):
        term = self.blocks[b][1]
        return [term[1]] if term[0] == "br" else list(term[2:4]) if term[0] == "cond" else []

    def _natural_loops(self):
        """header -> set of blocks of its natural loop(s)."""
        order, seen, onstack, back = [], set(), set(), []

        def dfs(n):
            seen.add(n); onstack.add(n)
            for s in self.succ(n):
                if s in onstack:
                    back.append((n, s))
                elif s not in seen:
                    dfs(s)
            onstack.discard(n)
        import sys
        sys.setrecursionlimit(max(10000, sys.getrecursionlimit()))
        dfs(self.entry)
        pred = {}
        for b in self.blocks:
            for s in self.succ(b):
                pred.setdefault(s, []).append(b)
        loops = {}
        for tail, head in back:
            body, stack = {head}, [tail]
            while stack:
                n = stack.pop()
                if n not in body:
                    body.add(n)
                    stack.extend(pred.get(n, []))
            loops.setdefault(head, set()).update(body)
        return loops

    def _close(self, name, lines):
        if not lines:
            return
        events = []
        for li, line in enumerate(lines):
            d = DEF.match(line)
            if d:
                self.defs[d.group(1)] = d.group(2)
            c = CALL.search(line)
            if c and not re.match(r"^\s*(%[\w.$-]+ = )?(tail )?call\b", line):
                c = None
            if c:
                callee = c.group(1)
                if callee is None:
                    events.append(("call", None, li))
                elif callee.startswith("llvm."):
                    if not re.match(r"llvm\.(memcpy|memset|memmove|dbg|lifetime)", callee):
                        raise Refuse(f"intrinsic {callee}")
                elif callee in DIV_HELPERS:
                    events.append(("div", callee, li))
                elif callee in GTE_HELPERS:
                    pass
                else:
                    g = GUEST_CALL.match(callee)
                    if not g:
                        raise Refuse(f"call to {callee}")
                    events.append(("call", int(g.group(1), 16), li))
        t = lines[-1]
        if SWITCH_END.match(t):
            raise Refuse("switch")
        b = BR_COND.match(t)
        if b:
            term = ("cond", b.group(1), b.group(2).lstrip("%"), b.group(3).lstrip("%"))
        elif BR.match(t):
            term = ("br", BR.match(t).group(1).lstrip("%"))
        elif re.match(r"^\s*ret\b", t):
            term = ("ret",)
        elif re.match(r"^\s*unreachable", t):
            term = ("unreachable",)
        elif re.match(r"^\s*switch\b", t):
            raise Refuse("switch")
        else:
            raise Refuse(f"terminator {t.strip()[:40]}")
        self.blocks[name] = (events, term)
        self.lines[name] = lines
        self.order.append(name)

    # Predicate of `br i1 %c`: (family, direction, const, negated) with the
    # same conventions as Retail.branch_pred (true means the condition holds).
    def pred(self, val, depth=0):
        if depth > 8 or val not in self.defs:
            return None
        rhs = self.defs[val]
        m = re.match(r"icmp (\w+) i\d+ ([^,]+), (.+)$", rhs)
        if m:
            p, a, b = m.group(1), m.group(2).strip(), m.group(3).strip()
            ca = int(a) if re.fullmatch(r"-?\d+", a) else None
            cb = int(b) if re.fullmatch(r"-?\d+", b) else None
            if ca is not None and cb is None:      # const on the left: swap
                swap = {"slt": "sgt", "sgt": "slt", "sle": "sge", "sge": "sle",
                        "ult": "ugt", "ugt": "ult", "ule": "uge", "uge": "ule"}
                p, cb = swap.get(p, p), ca
            if p in ("eq", "ne"):
                return ("eq", None, cb, p == "eq")
            fam = "s" if p[0] == "s" else "u"
            # a zero-extended operand compared with a non-negative constant:
            # signed and unsigned order agree, so either retail form fits
            if fam == "s" and re.match(r"zext ", self.defs.get(a, "")) and (cb is None or cb >= 0):
                fam = "su"
            rel = p[1:]
            if cb is not None:
                if fam == "u":
                    if (rel == "gt" and cb == 0) or (rel == "ge" and cb == 1):
                        return ("eq", None, 0, False)
                    if (rel == "lt" and cb == 1) or (rel == "le" and cb == 0):
                        return ("eq", None, 0, True)
                if rel == "le":
                    return (fam, "<", cb + 1, True)
                if rel == "ge":
                    return (fam, ">", cb - 1, True)
                return (fam, "<" if rel == "lt" else ">", cb, True)
            return (fam, {"lt": "<", "gt": ">", "le": "<=", "ge": ">="}[rel], None, True)
        m = re.match(r"xor i1 (%[\w.$-]+), true$", rhs)
        if m:
            q = self.pred(m.group(1), depth + 1)
            return None if q is None else negate(q)
        m = re.match(r"trunc i\d+ (%[\w.$-]+) to i1$", rhs)
        if m:
            return ("eq", None, 0, False)
        return None


def negate(p):
    fam, d, k, t = p
    return (fam, d, k, not t)


def polarity(cp, rp):
    """'direct' (retail taken <=> clang true), 'inverted', 'mismatch' (the
    two predicates are both recognised and cannot be the same condition) or
    None (not decidable: try both)."""
    if cp is None or rp is None:
        return None
    cfam, cd, ck, ct = cp
    rfam, rd, rk, rt = rp
    if cfam == "eq" or rfam == "eq":
        if cfam != rfam:
            return "mismatch"
        if ck is not None and rk is not None and ck != rk and rk != 0:
            return None
        return "direct" if ct == rt else "inverted"
    if cfam != rfam and not (cfam == "su" and rfam in ("s", "u")):
        return "mismatch"
    # register-register order compares: strictness decides (a<b vs a>=b).
    if ck is None or rk is None:
        if ck is None and rk is None:
            cstrict = cd in ("<", ">")
            # retail slt is strict when taken on true, non-strict otherwise
            rstrict = rt
            want = cstrict if ct else not cstrict
            return "direct" if want == rstrict else "inverted"
        return None
    # x < K or x > K, strict constants: x < K == not (x > K-1)
    same = (cd == rd and ck == rk)
    neg = (cd == "<" and rd == ">" and rk == ck - 1) or (cd == ">" and rd == "<" and rk == ck + 1)
    if same:
        return "direct" if ct == rt else "inverted"
    if neg:
        return "inverted" if ct == rt else "direct"
    return "mismatch"


# --------------------------------------------------------- G2: product walk

SEARCH_LIMIT = 200000


class _Fail(Exception):
    pass


def map_function(clang, retail):
    """Product walk; returns a summary dict or raises Refuse.

    Each pairing of a clang branch with a retail branch has candidate
    options: the polarity the predicates give, or, where they are not
    recognisable or disagree (strength-reduced induction variables, for
    instance), direct / inverted / transparent in turn, plus "fold" at a
    loop header entered from outside. Chronological backtracking over those
    choices enumerates every complete, consistent product graph (up to 64).
    Solutions are ranked by how much they lean on pairings the predicates do
    not support (score); the best-ranked ones must all charge the same
    costs (clang-side projection), else the function is refused as
    ambiguous."""
    steps = [0]

    def clang_event(block, idx):
        """Next clang event from (block, idx), following plain branches."""
        seen = set()
        while True:
            events, term = clang.blocks[block]
            while idx < len(events) and events[idx][0] == "div":
                idx += 1
            if idx < len(events):
                return ("call", events[idx][1], block, idx)
            if term[0] == "br":
                if block in seen:
                    raise _Fail(f"clang loop without an event at {block}")
                seen.add(block)
                block, idx = term[1], 0
                continue
            if term[0] == "cond":
                return ("cond", term, block, idx)
            return (term[0], None, block, idx)

    def solve(path):
        """One DFS with the choices in `path` (list of [key, options, i]);
        new choice points are appended with option 0."""
        forced = {e[0]: e[1][e[2]] for e in path}
        states, evat = {}, {}
        stack = [(clang.entry, 0, retail.vram)]
        while stack:
            steps[0] += 1
            if steps[0] > SEARCH_LIMIT:
                raise Refuse("search limit")
            cb, ci, rpc = stack.pop()
            key = (cb, ci, rpc)
            if key in states:
                continue
            ev = clang_event(cb, ci)
            seg = retail.segment(rpc)
            kind = ev[0]
            evat[key] = (ev[2], ev[3], kind)
            if kind == "call":
                if seg["kind"] != "call":
                    raise _Fail(f"clang call at {cb} vs retail {seg['kind']} at {seg['pc']:08x}")
                if (ev[1] is None) != (seg["target"] is None) or (ev[1] is not None and ev[1] != seg["target"]):
                    raise _Fail(f"call order at {seg['pc']:08x}")
                nxt = (ev[2], ev[3] + 1, seg["resume"])
                states[key] = [("call", seg["cost"], nxt)]
                stack.append(nxt)
            elif kind == "ret":
                if seg["kind"] != "ret":
                    raise _Fail(f"clang return at {cb} vs retail {seg['kind']} at {seg['pc']:08x}")
                states[key] = [("ret", seg["cost"], None)]
            elif kind == "unreachable":
                states[key] = [("dead", 0, None)]
            elif kind == "cond":
                _, val, t, f = ev[1]
                b = ev[2]
                trans = [(t, 0, rpc), (f, 0, rpc)]
                header = b in clang.loops and cb not in clang.loops[b]
                inner = seg["kind"] == "cond" and (seg["taken"] in seg["pcs"] or seg["fall"] in seg["pcs"])
                if header and (seg["kind"] != "cond" or inner):
                    fold_only = True
                elif seg["kind"] != "cond":
                    states[key] = [("transparent", 0, x) for x in trans]
                    stack.extend(trans)
                    continue
                else:
                    fold_only = False
                ck = (b, rpc) if fold_only else (b, seg["pc"])
                if ck in forced:
                    pol = forced[ck]
                else:
                    if fold_only:
                        opts = ["fold"]
                    else:
                        verdict = polarity(clang.pred(val), retail.branch_pred(seg["pc"]))
                        opts = [verdict] if verdict in ("direct", "inverted") else \
                            ["direct", "inverted", "transparent"]
                        if header:
                            opts = opts + ["fold"]
                    path.append([ck, opts, 0, None if fold_only else verdict])
                    forced[ck] = pol = opts[0]
                if pol == "fold":
                    # gcc dropped the loop's first test (a bottom-tested
                    # loop entered at its body): clang's first evaluation
                    # is transparent and its exit arm cannot run then (gcc
                    # proved the test true, which is why there is none);
                    # the evaluations after the body pair with the test.
                    body = clang.loops[b]
                    if (t in body) == (f in body):
                        raise _Fail(f"folded test at {b}: no single loop arm")
                    cont = (t, 0, rpc) if t in body else (f, 0, rpc)
                    arms = [("transparent", 0, cont), ("dead", 0, None)]
                    states[key] = arms if t in body else arms[::-1]
                    stack.append(cont)
                    continue
                if pol == "transparent":
                    states[key] = [("transparent", 0, x) for x in trans]
                    stack.extend(trans)
                    continue
                rt, rf = (seg["taken"], seg["fall"]) if pol == "direct" else (seg["fall"], seg["taken"])
                succ = [(t, 0, rt), (f, 0, rf)]
                states[key] = [("cond", seg["cost"], succ[0]), ("cond", seg["cost"], succ[1])]
                stack.extend(succ)
            else:
                raise _Fail(f"clang {kind}")
        check(clang, retail, states)
        return states, evat

    def solutions():
        path = []
        while True:
            trial = [list(x) for x in path]
            try:
                states, evat = solve(trial)
                yield (states, evat), trial
            except (_Fail, Refuse) as e:
                if isinstance(e, Refuse) and e.reason == "search limit":
                    raise
                last_fail[0] = e.args[0] if e.args else str(e)
            # backtrack: advance the deepest choice that has options left
            while trial and trial[-1][2] + 1 >= len(trial[-1][1]):
                trial.pop()
            if not trial:
                return
            trial[-1][2] += 1
            path = trial

    last_fail = ["no solution"]
    found = []
    for (states, evat), chosen in solutions():
        found.append((score(chosen), states, chosen, evat))
        if len(found) > 64:
            raise Refuse("search limit (solutions)")
    if not found:
        raise Refuse(last_fail[0])
    best = min(f[0] for f in found)
    top = [f for f in found if f[0] == best]
    proj = projection(top[0][1])
    if any(projection(f[1]) != proj for f in top[1:]):
        raise Refuse("ambiguous mapping")
    _, states, chosen, evat = top[0]
    blocks_at = {}
    for (cb, ci, rpc) in states:
        blocks_at.setdefault(cb, set()).add(rpc)
    heuristic = sum(1 for e in chosen if len(e[1]) > 1)
    return dict(
        states=len(states),
        paired=sum(1 for e in states.values() if e and e[0][0] == "cond"),
        transparent=sum(1 for e in states.values() if e and e[0][0] == "transparent"),
        structural=heuristic,
        split_blocks=sum(1 for v in blocks_at.values() if len(v) > 1),
        div_adjust=sorted({d["kind"] for (_, _, rpc) in states for d in retail.segment(rpc)["divs"]}),
        graph=states,
        events=evat,
    )


def score(chosen):
    """How much a solution leans on pairings the predicates do not support:
    a pairing against a recognised, contradicting predicate costs 2, one
    against an unrecognised predicate or a transparent choice 1."""
    total = 0
    for _, opts, i, verdict in chosen:
        pick = opts[i]
        if pick in ("direct", "inverted"):
            total += 2 if verdict == "mismatch" else (1 if verdict is None else 0)
        elif pick == "transparent":
            total += 1
    return total


def projection(states):
    """Clang-side view of a mapping: for every clang position, the set of
    costs its outgoing events carry."""
    out = {}
    for (cb, ci, rpc), edges in states.items():
        out.setdefault((cb, ci), set()).add(tuple((k, c) for k, c, _ in edges))
    return {k: frozenset(v) for k, v in out.items()}


def check(clang, retail, states):
    """Completeness and consistency of a product graph."""
    # every retail conditional branch reachable on the retail CFG is paired
    reach, stack = set(), [retail.vram]
    while stack:
        pc = stack.pop()
        if pc in reach:
            continue
        reach.add(pc)
        seg = retail.segment(pc)
        if seg["kind"] == "cond":
            stack += [seg["taken"], seg["fall"]]
        elif seg["kind"] == "call":
            stack.append(seg["resume"])
    used = {rpc for (_, _, rpc) in states}
    for pc in reach:
        seg = retail.segment(pc)
        if seg["kind"] in ("cond", "call", "ret") and pc not in used:
            raise _Fail(f"retail path at {pc:08x} not covered by the C")
        if seg["kind"] == "cond":
            ok = any(e[0] == "cond" for (_, _, r), es in states.items() if r == pc for e in es)
            if not ok:
                raise _Fail(f"retail branch at {seg['pc']:08x} has no clang branch")
    # every product cycle must consume retail time
    zero = {}
    for key, edges in states.items():
        zero[key] = [n for k, c, n in edges if n is not None and c == 0]
    color = {}

    def visit(n):
        color[n] = 1
        for s in zero.get(n, []):
            if color.get(s) == 1:
                raise _Fail(f"product cycle with no retail cost at {s[0]}")
            if s not in color:
                visit(s)
        color[n] = 2

    import sys
    sys.setrecursionlimit(max(10000, sys.getrecursionlimit()))
    for n in list(zero):
        if n not in color:
            visit(n)


def analyse(ir, fname, vram, words):
    """Shape, mapping status and summary for one function (report only)."""
    out = dict(shape=None, status="refused", reason=None)
    try:
        retail = Retail(vram, words)
        out["shape"] = shape(retail)
        if out["shape"].startswith("straight"):
            calls, ret = single_path_cost(retail)
            out["return_cost"] = ret
            out["call_costs"] = [c for _, c in calls]
            out["path_cost"] = sum(c for _, c in calls) + ret
        clang = Clang(ir, fname)
        m = map_function(clang, retail)
        division_adjusts(clang, retail, m["graph"])
        out["_mapping"] = (clang, retail, m)
        out.update({k: v for k, v in m.items() if k not in ("graph", "events")})
        out["status"] = "mapped"
    except Refuse as e:
        out["reason"] = e.reason
    return out


def charge_path(graph, start, picks):
    """Follow a product graph from `start`, taking the arm `picks` names
    (0 = clang true arm, 1 = false arm) at every two-way state; a folded
    loop test's dead arm is never taken. Returns the cycles charged at each
    boundary (each guest call, then the return), as phase 2b would flush
    them."""
    out, acc, key, it = [], 0, start, iter(picks)
    while True:
        edges = graph[key]
        live = [e for e in edges if e[0] != "dead"]
        if len(live) == 1:
            kind, cost, nxt = live[0]
        else:
            kind, cost, nxt = edges[next(it)]
        acc += cost
        if kind in ("call", "ret"):
            out.append(acc)
            acc = 0
        if kind in ("ret", "dead"):
            return out
        key = nxt


def map_ir(ir, fname, vram, words):
    """(Clang, Retail, mapping dict with its graph) for tests and tools."""
    clang = Clang(ir, fname)
    retail = Retail(vram, words)
    return clang, retail, map_function(clang, retail)


# ------------------------------------------- phase 2b: ledger instrumentation

LEDGER = "musashi_lane_ledger"          # i64: cycles charged, not yet flushed
LEDGER_LOST = "musashi_lane_ledger_lost"  # i32: a mapped body left its graph
RESUME = "musashi_lane_resume_pc"      # i32: retail pc a guest call returns to
SEG_EXTRA = "musashi_lane_seg_extra"   # i64: data-dependent division cycles in the open segment
BUDGET = "musashi_lane_budget"          # i64: ledger value at the next device deadline
TICK = "musashi_native_lane_tick"       # (segment table, state): mid-native checkpoint
POW2_SDIV = re.compile(r"^\s*(%[\w.$-]+) = sdiv(?: exact)? i32 ([^,]+), (\d+)\s*$")
HELPER_CALL = re.compile(r"call i32 @(lane_sdiv32|lane_srem32)\(i32 (?:noundef )?([^,]+), "
                         r"i32 (?:noundef )?([^)]+)\)")


def _biased_pow2(d):
    """gcc 2.7.2 divides by 2^k (k >= 2) with a `bgez` around the bias add;
    by 2 it is branch-free (srl 31, addu, sra), so its cost is fixed."""
    return d >= 4 and not d & (d - 1)


def division_adjusts(clang, retail, states):
    """Check that the clang divisions with a data-dependent retail cost match
    the retail idioms one for one, and return their extra costs:
    (signed helper extra for divisor -1, power-of-two extra for a negative
    dividend). Raises Refuse on a mismatch."""
    retail_divs = {}
    for (_, _, rpc) in states:
        for d in retail.segment(rpc)["divs"]:
            retail_divs[d["pc"]] = d
    m1 = [d["extra"] for d in retail_divs.values() if d["kind"] == "div_m1"]
    p2 = [d["extra"] for d in retail_divs.values() if d["kind"] == "sdiv_pow2"]
    n_helpers = n_pow2 = 0
    for b in clang.order:
        for line in clang.lines[b]:
            if HELPER_CALL.search(line):
                n_helpers += 1
            pm = POW2_SDIV.match(line)
            if pm and _biased_pow2(int(pm.group(3))):
                n_pow2 += 1
    if n_helpers != len(m1) or len(set(m1)) > 1:
        raise Refuse(f"division mismatch: {n_helpers} signed helper(s), {len(m1)} retail -1 check(s)")
    if n_pow2 != len(p2) or len(set(p2)) > 1:
        raise Refuse(f"division mismatch: {n_pow2} sdiv by 2^k, {len(p2)} retail bias branch(es)")
    return (m1[0] if m1 else 0), (p2[0] if p2 else 0)


def instrument(clang, retail, mapping, guard=False, segs_symbol=None):
    """Rewrite the entry function of `clang` (its -O0 module text) so that it
    charges the mapped retail cost into @musashi_lane_ledger as it runs.

    A local %lane.st holds the current product state (1..n; 0 = lost). At
    every event (guest call, paired or transparent branch, return) the cost
    of that state's retail segment is added to the ledger and the successor
    state is selected, arithmetically (select chains: no new control flow),
    so -O2 folds the states wherever they are static. Division helpers and
    power-of-two signed divisions add their data-dependent retail extra.
    A state with no expected successor sets @musashi_lane_ledger_lost.
    With `guard`, each charge that reaches @musashi_lane_budget calls
    musashi_native_lane_tick(segment table, state) first (phase 2b step d).
    Returns (new module text, per-state segment rows for the runtime table:
    [(state id, retail pc of the segment, [(pc, cost, delay_slot)...])])."""
    states, evat = mapping["graph"], mapping["events"]
    m1_extra, p2_extra = division_adjusts(clang, retail, states)
    ids = {k: i + 1 for i, k in enumerate(sorted(states, key=lambda k: (str(k[0]), k[1], k[2])))}
    by_event = {}
    for key, (b, idx, kind) in evat.items():
        by_event.setdefault((b, idx, kind), []).append(key)
    n = [0]

    def tmp(tag):
        n[0] += 1
        return f"%lane.{tag}.{n[0]}"

    def chain(out, st, pairs, ty, default):
        """select chain: value of `pairs[state]`, else default."""
        cur = default
        for k, v in pairs:
            e = tmp("e")
            out.append(f"  {e} = icmp eq i32 {st}, {k}")
            nv = tmp("v")
            out.append(f"  {nv} = select i1 {e}, {ty} {v}, {ty} {cur}")
            cur = nv
        return cur

    def add_ledger(out, amount):
        a, b2 = tmp("l"), tmp("l")
        out.append(f"  {a} = load i64, ptr @{LEDGER}, align 8")
        out.append(f"  {b2} = add i64 {a}, {amount}")
        out.append(f"  store i64 {b2}, ptr @{LEDGER}, align 8")
        return b2

    def add_extra(out, amount):
        if not guard:
            return
        a, b2 = tmp("x"), tmp("x")
        out.append(f"  {a} = load i64, ptr @{SEG_EXTRA}, align 8")
        out.append(f"  {b2} = add i64 {a}, {amount}")
        out.append(f"  store i64 {b2}, ptr @{SEG_EXTRA}, align 8")

    def mark_lost(out, nxt):
        e, z, a, o = tmp("lost"), tmp("lost"), tmp("lost"), tmp("lost")
        out.append(f"  {e} = icmp eq i32 {nxt}, 0")
        out.append(f"  {z} = zext i1 {e} to i32")
        out.append(f"  {a} = load i32, ptr @{LEDGER_LOST}, align 4")
        out.append(f"  {o} = or i32 {a}, {z}")
        out.append(f"  store i32 {o}, ptr @{LEDGER_LOST}, align 4")

    splits = {}

    def charge(out, keys, nexts_t, nexts_f=None, cond=None):
        st = tmp("s")
        out.append(f"  {st} = load i32, ptr %lane.st, align 4")
        cost = chain(out, st, [(ids[k], states[k][0][1]) for k in keys], "i64", "0")
        total = add_ledger(out, cost)
        if guard:
            # the charge reached the deadline budget: the tick finds the
            # retail instruction where a device event falls due and runs the
            # interpreter's checkpoint there (IRQ delivery included)
            bud, over = tmp("b"), tmp("b")
            n[0] += 1
            tick, go = f"lane.tick.{n[0]}", f"lane.go.{n[0]}"
            out.append(f"  {bud} = load i64, ptr @{BUDGET}, align 8")
            out.append(f"  {over} = icmp uge i64 {total}, {bud}")
            out.append(f"  br i1 {over}, label %{tick}, label %{go}")
            out.append(f"{tick}:")
            out.append(f"  call void @{TICK}(ptr @{segs_symbol}, i32 {st})")
            out.append(f"  br label %{go}")
            out.append(f"{go}:")
            if m1_extra or p2_extra:
                out.append(f"  store i64 0, ptr @{SEG_EXTRA}, align 8")
            splits[cur_block[0]] = go
        nt = chain(out, st, [(ids[k], nexts_t[k]) for k in keys], "i32", "0")
        if cond is not None:
            nf = chain(out, st, [(ids[k], nexts_f[k]) for k in keys], "i32", "0")
            nx = tmp("n")
            out.append(f"  {nx} = select i1 {cond}, i32 {nt}, i32 {nf}")
            nt = nx
        mark_lost(out, nt)
        out.append(f"  store i32 {nt}, ptr %lane.st, align 4")

    def next_id(edge):
        kind, _, nxt = edge
        return 0 if kind == "dead" or nxt is None else ids[nxt]

    blocks_out = []
    cur_block = [None]
    for b in clang.order:
        cur_block[0] = b
        events, term = clang.blocks[b]
        lines = list(clang.lines[b])
        inserts = {}                     # line index -> lines inserted before
        for idx, ev in enumerate(events):
            li = ev[2]
            if ev[0] == "div":
                hm = HELPER_CALL.search(lines[li])
                if hm and m1_extra:
                    out = []
                    e, x = tmp("m1"), tmp("m1")
                    out.append(f"  {e} = icmp eq i32 {hm.group(3).strip()}, -1")
                    out.append(f"  {x} = select i1 {e}, i64 {m1_extra}, i64 0")
                    add_ledger(out, x)
                    add_extra(out, x)
                    inserts.setdefault(li, []).extend(out)
                continue
            keys = by_event.get((b, idx, "call"), [])
            if keys:
                out = []
                charge(out, keys, {k: next_id(states[k][0]) for k in keys})
                if guard:
                    # where the retail caller resumes: an IRQ the callee's
                    # return left pending is delivered there, before any
                    # native code after the call runs
                    st2 = tmp("s")
                    out.append(f"  {st2} = load i32, ptr %lane.st, align 4")
                    rp = chain(out, st2, [(next_id(states[k][0]), states[k][0][2][2]) for k in keys],
                               "i32", "0")
                    out.append(f"  store i32 {rp}, ptr @{RESUME}, align 4")
                inserts.setdefault(li, []).extend(out)
        if p2_extra:
            for li, line in enumerate(lines):
                pm = POW2_SDIV.match(line)
                if pm and _biased_pow2(int(pm.group(3))):
                    out = []
                    e, x = tmp("p2"), tmp("p2")
                    out.append(f"  {e} = icmp slt i32 {pm.group(2).strip()}, 0")
                    out.append(f"  {x} = select i1 {e}, i64 {p2_extra}, i64 0")
                    add_ledger(out, x)
                    add_extra(out, x)
                    inserts.setdefault(li, []).extend(out)
        tl = len(lines) - 1
        idx = len(events)
        if term[0] == "cond":
            keys = by_event.get((b, idx, "cond"), [])
            if keys:
                out = []
                charge(out, keys, {k: next_id(states[k][0]) for k in keys},
                       {k: next_id(states[k][1]) for k in keys}, cond=term[1])
                inserts.setdefault(tl, []).extend(out)
        elif term[0] == "ret":
            keys = by_event.get((b, idx, "ret"), [])
            if keys:
                out = []
                charge(out, keys, {k: ids[k] for k in keys})
                inserts.setdefault(tl, []).extend(out)
        body = []
        for li, line in enumerate(lines):
            body.extend(inserts.get(li, []))
            body.append(line)
        if b == clang.entry:
            body = ["  %lane.st = alloca i32, align 4",
                    f"  store i32 {ids[(clang.entry, 0, retail.vram)]}, ptr %lane.st, align 4"] + body
            blocks_out.append("\n".join(body))
        else:
            blocks_out.append(f"{b}:\n" + "\n".join(body))
    if splits:
        # a split block's terminator now sits in its last continuation:
        # successors' phi nodes name that block as the predecessor
        fixed = []
        for text_block in blocks_out:
            lines_b = text_block.split("\n")
            for i, line in enumerate(lines_b):
                if re.match(r"^\s*%[\w.$-]+ = phi ", line):
                    for old, new in splits.items():
                        line = re.sub(r"(\[[^\[\]]*,\s*)%" + re.escape(old) + r"(\s*\])", r"\g<1>%" + new + r"\2", line)
                    lines_b[i] = line
            fixed.append("\n".join(lines_b))
        blocks_out = fixed
    a, z = clang.span
    text = clang.text[:a] + "\n\n".join(blocks_out) + "\n" + clang.text[z:]
    decls = [f"@{LEDGER} = external global i64, align 8",
             f"@{LEDGER_LOST} = external global i32, align 4"]
    if guard:
        decls += [f"@{BUDGET} = external global i64, align 8",
                  f"@{SEG_EXTRA} = external global i64, align 8",
                  f"@{RESUME} = external global i32, align 4",
                  f"@{segs_symbol} = external constant i8",
                  f"declare void @{TICK}(ptr, i32)"]
    text = text.rstrip("\n") + "\n\n" + "\n".join(decls) + "\n"
    rows = []
    for key, i in sorted(ids.items(), key=lambda kv: kv[1]):
        # what this state charges: its segment, or nothing (transparent,
        # folded and dead states)
        if states[key] and states[key][0][0] in ("cond", "call", "ret"):
            seg = retail.segment(key[2])
            insns = [(pc, retail.cost(pc), 1 if _in_delay_slot(retail, pc) else 0) for pc in seg["pcs"]]
            if sum(c for _, c, _ in insns) != states[key][0][1]:
                raise Refuse(f"segment table cost mismatch at {key[2]:08x}")
            # a division idiom's data-dependent instructions (flag 2): they
            # run after the check's delay slot when its extra is charged. The
            # tick attributes the segment's charged extra to them in order,
            # which is exact for one idiom per segment (all of them today).
            if len(seg["divs"]) > 1:
                raise Refuse(f"two division idioms in the segment at {key[2]:08x}")
            for d in seg["divs"]:
                cond_pcs = [d["pc"] + 8, d["pc"] + 12] if d["kind"] == "div_m1" else [d["pc"] + 8]
                at = next(i for i, x in enumerate(insns) if x[0] == d["pc"] + 4) + 1
                insns[at:at] = [(pc, retail.cost(pc), 2) for pc in cond_pcs]
        else:
            insns = []
        rows.append((i, key[2], insns))
    return text, rows


def _in_delay_slot(retail, pc):
    if pc - 4 < retail.vram:
        return False
    return decode(retail.word(pc - 4), pc - 4)[0] in ("cond", "j", "jal", "jalr", "jr")
