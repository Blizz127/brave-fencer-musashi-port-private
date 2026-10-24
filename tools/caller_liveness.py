#!/usr/bin/env python3
"""Exact caller-liveness check for a native function's register leftovers (r61 allowance (a)).

When interpreted retail code calls a native lane function, the lane wrapper sets v0 (for a value-returning
function) and leaves every other caller-saved guest register (at, v1, a0-a3, t0-t9, hi, lo) as it was at the
call, where the retail callee would leave its own values. That is observable only if the retail CALLER reads one
of them before writing it. This walks every path of the caller from the call's return point, over the retail
words, with all those registers tainted:
  - a read of a tainted register by the caller itself is a finding;
  - at a call (jal/jalr), the callee reads the a0-a3 it reads-before-writes on some path of its own retail code
    (computed the same way, recursively, for jal targets; a jalr callee is assumed to read all of a0-a3), and a
    tainted one is a finding; after the call every caller-saved register is the callee's (GCC never reads a
    clobbered register), so the taint ends there;
  - jr ra ends the path (o32: the caller's caller does not read caller-saved registers; v0/v1 are covered by
    the pass-up audit).
Usage: caller_liveness.py EXE CALLER_START CALLER_END RETURN_PC"""
import struct
import sys

EXE = sys.argv[1]
CALLER_LO, CALLER_HI, RET = (int(x, 16) for x in sys.argv[2:5])
data = open(EXE, 'rb').read()
BASE = 0x80010000 - 0x800


def word(a):
    return struct.unpack_from('<I', data, a - BASE)[0]


NAMES = {1: 'at', 3: 'v1', 4: 'a0', 5: 'a1', 6: 'a2', 7: 'a3', 8: 't0', 9: 't1', 10: 't2', 11: 't3', 12: 't4',
         13: 't5', 14: 't6', 15: 't7', 24: 't8', 25: 't9', 32: 'hi', 33: 'lo'}
CALLER_SAVED = set(NAMES)
HI, LO = 32, 33


def rw(w):
    """(reads, writes, kind) for one MIPS I word; kind in {None, 'branch', 'jal', 'jalr', 'jr', 'j'}.
    Unknown encodings read and write nothing (reported separately)."""
    op = w >> 26; rs = (w >> 21) & 31; rt = (w >> 16) & 31; rd = (w >> 11) & 31; fn = w & 63
    R, W, kind = set(), set(), None
    if op == 0:
        if fn in (0, 2, 3): R, W = {rt}, {rd}                    # sll srl sra
        elif fn in (4, 6, 7): R, W = {rs, rt}, {rd}              # sllv srlv srav
        elif fn == 8: R, kind = {rs}, ('jr' if rs == 31 else 'jrx')
        elif fn == 9: R, W, kind = {rs}, {rd}, 'jalr'
        elif fn in (12, 13): pass                                # syscall break
        elif fn == 16: R, W = {HI}, {rd}                         # mfhi
        elif fn == 18: R, W = {LO}, {rd}                         # mflo
        elif fn == 17: R, W = {rs}, {HI}                         # mthi
        elif fn == 19: R, W = {rs}, {LO}                         # mtlo
        elif fn in (24, 25, 26, 27): R, W = {rs, rt}, {HI, LO}   # mult multu div divu
        elif 32 <= fn <= 43: R, W = {rs, rt}, {rd}
        else: return None
    elif op == 1: R, kind = {rs}, 'branch'                       # bltz bgez (bltzal/bgezal not expected)
    elif op == 2: kind = 'j'
    elif op == 3: kind = 'jal'
    elif op in (4, 5): R, kind = {rs, rt}, 'branch'
    elif op in (6, 7): R, kind = {rs}, 'branch'
    elif 8 <= op <= 14: R, W = {rs}, {rt}                       # addi .. xori
    elif op == 15: W = {rt}                                       # lui
    elif op in (32, 33, 35, 36, 37): R, W = {rs}, {rt}          # lb lh lw lbu lhu
    elif op in (34, 38): R, W = {rs, rt}, {rt}                  # lwl lwr (merge: read rt)
    elif op in (40, 41, 43, 42, 46): R = {rs, rt}               # sb sh sw swl swr
    elif op == 18:                                                 # cop2
        sub = rs
        if sub in (0, 2): W = {rt}                                # mfc2 cfc2 write a GPR
        elif sub in (4, 6): R = {rt}                              # mtc2 ctc2 read a GPR
        elif sub >= 16: pass                                      # GTE command
        else: return None
    elif op in (50, 58): R = {rs}                                 # lwc2 swc2 (address base)
    else:
        return None
    R.discard(0); W.discard(0)
    return R, W, kind


def targets(a, w, kind):
    if kind == 'branch':
        off = (w & 0xFFFF) - (0x10000 if w & 0x8000 else 0)
        return [a + 4 + (off << 2), a + 8]
    if kind == 'j':
        return [((a + 4) & 0xF0000000) | ((w & 0x3FFFFFF) << 2)]
    return [a + 8]


_callee_reads = {}


def callee_arg_reads(entry, depth=0):
    """a0-a3 that the function at entry reads before writing on some path (its own code, recursively)."""
    if entry in _callee_reads:
        return _callee_reads[entry]
    _callee_reads[entry] = {4, 5, 6, 7}           # conservative while recursing
    found = set()
    seen = set()
    stack = [(entry, frozenset({4, 5, 6, 7}))]
    steps = 0
    while stack and steps < 200000:
        a, live = stack.pop()
        if (a, live) in seen or not live:
            continue
        seen.add((a, live))
        steps += 1
        d = rw(word(a))
        if d is None:
            found |= live                          # unknown word: fail closed
            continue
        R, W, kind = d
        found |= (R & live)
        if kind in ('branch', 'j', 'jal', 'jalr', 'jr', 'jrx'):
            ds = rw(word(a + 4))
            if ds is None:
                found |= live
                continue
            R2, W2, _ = ds
            found |= (R2 & (live - W))
            live2 = live - W - W2
            if kind == 'jal' and depth < 6:
                t = ((a + 4) & 0xF0000000) | ((word(a) & 0x3FFFFFF) << 2)
                found |= (callee_arg_reads(t, depth + 1) & live2)
                continue                           # after a call the args are clobbered
            if kind in ('jalr', 'jal'):
                found |= live2 & {4, 5, 6, 7}
                continue
            if kind in ('jr', 'jrx'):
                continue
            for t in targets(a, word(a), kind):
                stack.append((t, frozenset(live2)))
            continue
        stack.append((a + 4, frozenset(live - W)))
    _callee_reads[entry] = found
    return found


def walk():
    findings, unknown = [], []
    seen = set()
    stack = [(RET, frozenset(CALLER_SAVED))]
    while stack:
        a, taint = stack.pop()
        if (a, taint) in seen or not taint:
            continue
        seen.add((a, taint))
        if not CALLER_LO <= a < CALLER_HI:
            unknown.append(f'{a:08x} left the caller')
            continue
        d = rw(word(a))
        if d is None:
            unknown.append(f'{a:08x} unknown word {word(a):08x}')
            continue
        R, W, kind = d
        for r in sorted(R & taint):
            findings.append(f'{a:08x} reads {NAMES[r]} (word {word(a):08x})')
        if kind in ('branch', 'j', 'jal', 'jalr', 'jr', 'jrx'):
            ds = rw(word(a + 4))
            if ds is None:
                unknown.append(f'{a + 4:08x} unknown delay-slot word {word(a + 4):08x}')
                continue
            R2, W2, _ = ds
            for r in sorted(R2 & (taint - W)):
                findings.append(f'{a + 4:08x} (delay slot) reads {NAMES[r]}')
            t2 = taint - W - W2
            if kind == 'jal':
                callee = ((a + 4) & 0xF0000000) | ((word(a) & 0x3FFFFFF) << 2)
                for r in sorted(callee_arg_reads(callee) & t2):
                    findings.append(f'{a:08x} jal {callee:08x}: callee reads {NAMES[r]} before writing it')
                continue                           # the callee's registers from here on
            if kind == 'jalr':
                for r in sorted(t2 & {4, 5, 6, 7}):
                    findings.append(f'{a:08x} jalr: callee may read {NAMES[r]}')
                continue
            if kind in ('jr', 'jrx'):
                continue                           # return (jr ra) or tail jump: path ends
            for t in targets(a, word(a), kind):
                stack.append((t, frozenset(t2)))
            continue
        stack.append((a + 4, frozenset(taint - W)))
    return findings, unknown, len(seen)


f, u, n = walk()
print(f'caller {CALLER_LO:08x}..{CALLER_HI:08x} return point {RET:08x}: {n} (pc, taint) states walked')
print(f'findings: {len(f)}')
for x in sorted(set(f)):
    print('  ' + x)
print(f'unknown: {len(u)}')
for x in sorted(set(u))[:20]:
    print('  ' + x)
callees = {k: sorted(NAMES[r] for r in v) for k, v in _callee_reads.items()}
print('callee argument reads (a0-a3 read before written):')
for k in sorted(callees):
    print(f'  {k:08x}: {callees[k]}')
