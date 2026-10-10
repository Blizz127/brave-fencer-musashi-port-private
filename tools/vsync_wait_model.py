#!/usr/bin/env python3
"""M6a T1: offline model of the native VSync wait 800424E4..8004257C (pure Python, no build).

Reference = the interpreter: before every instruction a checkpoint (deliver every event due at or before `now`; each
delivery runs its handler, which charges its own cycles and may change guest RAM), then the instruction's cost, then its
effect. HLE = the M6 design (M6-VSYNC-NATIVE-DESIGN.md section 2.4): query the deadline, run to the first slot boundary
whose start time is at or after now + until (per-step when unknown), checkpoint there with the materialized state, run
that slot, repeat. `hle(fast=True)` jumps whole loop iterations arithmetically (what the C does); `fast=False` walks
the same skipped slots one by one. Both must give the reference's delivery log and exit state."""
import dataclasses

M32 = 0xFFFFFFFF
TICK = 0x8006CBB8
ENTRY, LOOP, EXIT_PC, TIMEOUT_PC = 0x800424E4, 0x8004250C, 0x80042570, 0x8004252C

# (pc, cost) in path order; cost = interpreter BIAS 2, +1 per load/store
PROLOGUE = [(0x800424E4, 2), (0x800424E8, 2), (0x800424EC, 3), (0x800424F0, 2), (0x800424F4, 3),
            (0x800424F8, 2), (0x800424FC, 2), (0x80042500, 2), (0x80042504, 3), (0x80042508, 2)]
LOOPS = [(0x8004250C, 3), (0x80042510, 2), (0x80042514, 2), (0x80042518, 3), (0x8004251C, 3), (0x80042520, 2),
         (0x80042524, 2), (0x80042528, 2), (0x80042558, 2), (0x8004255C, 3), (0x80042560, 2), (0x80042564, 2),
         (0x80042568, 2), (0x8004256C, 2)]
EXITS = [(0x80042570, 3), (0x80042574, 2), (0x80042578, 2), (0x8004257C, 2)]
LOOP_OFF = [0, 3, 5, 7, 10, 13, 15, 17, 19, 21, 24, 26, 28, 30]
ITER = 32


def s32(x):
    x &= M32
    return x - (1 << 32) if x & 0x80000000 else x


@dataclasses.dataclass
class Cpu:
    pc: int
    npc: int
    sp: int
    ra: int
    a0: int
    a1: int
    v0: int = 0
    v1: int = 0
    delay: int = 0
    branch_pc: int = 0

    def regs(self):
        return (self.pc, self.npc, self.sp, self.ra, self.a0, self.a1, self.v0, self.v1, self.delay, self.branch_pc)


class Env:
    """Deterministic device/IRQ environment shared by both models.
    events: list of (due, kind, cost, arg). kind 'vblank' increments the tick, 'irq' only charges its handler,
    'settick' stores arg into the tick, 'cell' stores arg into the counter cell, 'noop' is a deadline-only point
    (an SPU sample boundary: bounds `until`, delivers nothing). unknown: list of [lo, hi) times when the deadline
    query answers unknown (host clock, device frame, lag)."""

    def __init__(self, events, unknown=()):
        self.pending = sorted(events)
        self.unknown = list(unknown)
        self.log = []

    def deadline(self, now):
        if any(lo <= now < hi for lo, hi in self.unknown):
            return None
        dues = [e[0] for e in self.pending]
        return max(0, min(dues) - now) if dues else 1 << 40

    def checkpoint(self, cpu, ram, now, who):
        """Deliver everything due at or before now, in due order; returns the new now."""
        while self.pending and self.pending[0][0] <= now:
            due, kind, cost, arg = self.pending.pop(0)
            if kind == 'noop':
                continue
            self.log.append((cpu.pc, now, kind, cpu.regs(), dict(ram)))
            if kind == 'vblank':
                ram[TICK] = (ram[TICK] + 1) & M32
            elif kind == 'settick':
                ram[TICK] = arg & M32
            elif kind == 'cell':
                ram[cpu.sp + 0x10 if cpu.pc != ENTRY else cpu.sp - 0x10] = arg & M32
            now += cost
        return now


def execute(cpu, ram, S):
    """Retail effect of the instruction at cpu.pc (interpreter semantics: loads land at once, branches resolve npc)."""
    pc = cpu.pc
    nxt = cpu.npc
    delay, branch = 0, 0
    target = nxt + 4
    if pc == 0x800424E4: cpu.sp = (cpu.sp - 0x20) & M32
    elif pc == 0x800424E8: cpu.a1 = (cpu.a1 << 15) & M32
    elif pc == 0x800424EC: ram[S - 0x10] = cpu.a1
    elif pc in (0x800424F0, 0x80042558): cpu.v0 = 0x80070000
    elif pc in (0x800424F4, 0x8004255C): cpu.v0 = ram[TICK]
    elif pc in (0x800424FC, 0x80042564): cpu.v0 = 1 if s32(cpu.v0) < s32(cpu.a0) else 0
    elif pc == 0x80042500:
        delay, branch = 1, pc
        target = 0x80042570 if cpu.v0 == 0 else nxt + 4
    elif pc == 0x80042504: ram[S - 0x08] = cpu.ra
    elif pc == 0x80042508: cpu.v1 = M32
    elif pc in (0x8004250C, 0x8004251C): cpu.v0 = ram[S - 0x10]
    elif pc == 0x80042514: cpu.v0 = (cpu.v0 - 1) & M32
    elif pc == 0x80042518: ram[S - 0x10] = cpu.v0
    elif pc == 0x80042524:
        delay, branch = 1, pc
        target = 0x80042558 if cpu.v0 != cpu.v1 else nxt + 4
    elif pc == 0x80042568:
        delay, branch = 1, pc
        target = 0x8004250C if cpu.v0 != 0 else nxt + 4
    elif pc == 0x80042570: cpu.ra = ram[S - 0x08]
    elif pc == 0x80042574: cpu.sp = (cpu.sp + 0x20) & M32
    elif pc == 0x80042578:
        delay, branch = 1, pc
        target = cpu.ra
    elif pc in (0x800424F8, 0x80042510, 0x80042520, 0x80042528, 0x80042560, 0x8004256C, 0x8004257C): pass
    else:
        raise AssertionError(f"pc {pc:08x} outside the modeled wait")
    cpu.pc, cpu.npc = nxt, target
    cpu.delay, cpu.branch_pc = delay, branch


COST = dict(PROLOGUE + LOOPS + EXITS)


def reference(cpu, ram, env, now, max_steps=10**7):
    """The interpreter, checkpoint before every instruction. The caller already ran the checkpoint before 800424E4.
    Returns ('done'|'handover', now, cpu, ram). 'done' = back at ra (the run loop checkpoints there next);
    'handover' = the start of the timeout iteration (counter cell 0, so this iteration's decrement gives -1)."""
    S = cpu.sp
    first = True
    ran = None
    for _ in range(max_steps):
        if ran == 0x8004257C:
            return 'done', now, cpu, ram
        if cpu.pc not in COST or (cpu.pc == LOOP and ram[S - 0x10] == 0):
            return 'handover', now, cpu, ram
        if not first:
            now = env.checkpoint(cpu, ram, now, 'ref')
        first = False
        ran = cpu.pc
        now += COST[cpu.pc]
        execute(cpu, ram, S)
    raise AssertionError('reference did not finish')


def hle(cpu, ram, env, now, fast=True, max_iter=10**7):
    """The design's segment model, with the C's exit rule: done only after 8004257C ran; any other pc the model does
    not cover (the timeout iteration's start, or the timeout path a handler steered into) is handed over."""
    S = cpu.sp
    stats = {'checkpoints': 0, 'slots': 0, 'jumped_iters': 0}

    def stop():
        if ran == 0x8004257C:
            return 'done'
        if cpu.pc not in COST or (cpu.pc == LOOP and ram[S - 0x10] == 0):
            return 'handover'
        return None
    ran = cpu.pc                     # slot 800424E4: its checkpoint was the run loop's
    now += COST[cpu.pc]
    execute(cpu, ram, S)
    stats['slots'] += 1
    for _ in range(max_iter):
        if stop():
            return stop(), now, cpu, ram, stats
        until = env.deadline(now)
        target = now + (until if until is not None else 0)
        while now < target and not stop():
            if fast and cpu.pc == LOOP and s32(ram[TICK]) < s32(cpu.a0):
                w = min((target - now) // ITER, ram[S - 0x10])   # stop at the timeout iteration's start
                if w > 0:
                    ram[S - 0x10] = (ram[S - 0x10] - w) & M32
                    now += ITER * w
                    cpu.v0 = 1
                    ran = 0x8004256C
                    stats['jumped_iters'] += w
                    continue
            ran = cpu.pc
            now += COST[cpu.pc]
            execute(cpu, ram, S)
            stats['slots'] += 1
        if stop():
            continue
        now = env.checkpoint(cpu, ram, now, 'hle')
        stats['checkpoints'] += 1
        ran = cpu.pc
        now += COST[cpu.pc]
        execute(cpu, ram, S)
        stats['slots'] += 1
    raise AssertionError('hle did not finish')
