"""M6a T1: the native VSync wait's segment model equals the interpreter's per-instruction sequence (pure Python).

For every scenario the reference (checkpoint before every instruction), the HLE stepping skipped slots one by one and
the HLE jumping whole iterations must give the same result kind, exit cycle, CPU state, RAM and delivery log (pc,
cycle, kind, CPU state and RAM at each delivery)."""
import copy
import random
import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "tools"))
import vsync_wait_model as m  # noqa: E402

S = 0x801FFE00
RA = 0x80042434
T0 = 1_000_000
FRAME = 564_398


def run_all(tick, a0, a1, events, unknown=(), extra_ram=None, ra=RA):
    out = []
    for kind in ("ref", "hle_step", "hle_fast"):
        cpu = m.Cpu(pc=m.ENTRY, npc=m.ENTRY + 4, sp=S, ra=ra, a0=a0 & m.M32, a1=a1 & m.M32)
        ram = {m.TICK: tick & m.M32, S - 0x10: 0xDEADBEEF, S - 0x08: 0xCAFEF00D}
        if extra_ram:
            ram.update(extra_ram)
        env = m.Env(copy.deepcopy(events), unknown)
        if kind == "ref":
            res, now, cpu, ram = m.reference(cpu, ram, env, T0)
            stats = None
        else:
            res, now, cpu, ram, stats = m.hle(cpu, ram, env, T0, fast=(kind == "hle_fast"))
        out.append(((res, now, cpu.regs(), tuple(sorted(ram.items())), env.log), stats))
    return out


class Model(unittest.TestCase):
    def same(self, *args, **kw):
        (ref, _), (step, s1), (fast, s2) = run_all(*args, **kw)
        self.assertEqual(ref[:4], step[:4])
        self.assertEqual(ref[4], step[4])
        self.assertEqual(ref[:4], fast[:4])
        self.assertEqual(ref[4], fast[4])
        return ref, s1, s2

    def test_not_entered_cost_30(self):
        for tick, a0 in ((5, 5), (6, 5), (0x7FFFFFFF, -0x80000000)):
            ref, _, _ = self.same(tick, a0, 1, [])
            self.assertEqual(ref[0], "done")
            self.assertEqual(ref[1], T0 + 30)

    def test_entered_m_iterations_cost_32_m_plus_1(self):
        # VBlank whose handler ends at the start of iteration m's tick read -> exit after m iterations
        for m_iter in (1, 2, 3, 10):
            ev = [(T0 + 23 + 32 * (m_iter - 1) + 21 - 50, "vblank", 50, 0)]
            ref, _, _ = self.same(4, 5, 1, ev)
            self.assertEqual(ref[0], "done")

    def test_signed_compare(self):
        ref, _, _ = self.same(-5, 3, 1, [(T0 + 5000, "settick", 7, 3)])
        self.assertEqual(ref[0], "done")

    def test_timeout_handover(self):
        for a1 in (0, 1, 2):
            ref, _, s = self.same(0, 5, a1, [(T0 + k * 768, "noop", 0, 0) for k in range(1, 5000)])
            self.assertEqual(ref[0], "handover")
            self.assertEqual(ref[1], T0 + 23 + 32 * ((a1 << 15) & m.M32))

    def test_delivery_at_every_boundary(self):
        # one VBlank due at every cycle offset through the prologue, 4 iterations and the exit; plus mid-loop IRQs
        for off in range(0, 23 + 32 * 4 + 40):
            for a0 in (1, 3):
                ev = [(T0 + off, "vblank", 37, 0)]
                if a0 == 3:
                    ev.append((T0 + off + 400, "vblank", 41, 0))
                self.same(1 if a0 == 3 else 0, a0, 1, ev)

    def test_irq_kinds_and_handler_writes(self):
        rng = random.Random(1)
        for trial in range(300):
            a1 = rng.choice([0, 1, 2, 7, 0xFFFF, 0x10000, 0x1FFFF])
            tick = rng.choice([0, 5, -3, 0x7FFFFFF0])
            a0 = tick + rng.choice([-1, 0, 1, 2, 3])
            ev = []
            t = T0
            for _ in range(rng.randint(0, 12)):
                t += rng.randint(0, 3000)
                kind = rng.choice(["vblank", "irq", "irq", "noop", "settick", "cell"])
                arg = rng.choice([0, 1, 5, a0, a0 + 1, (1 << 31), m.M32])
                ev.append((t, kind, rng.randint(0, 200), arg))
            ev.append((t + rng.randint(1, 6000), "vblank", 60, 0))
            ev.append((t + 9000, "vblank", 60, 0))
            ev.append((t + 20000, "settick", 60, a0 + 10))
            unk = []
            if rng.random() < 0.4:
                lo = T0 + rng.randint(0, 4000)
                unk.append((lo, lo + rng.randint(1, 3000)))
            self.same(tick, a0, a1, ev, unk)

    def test_frame_long_wait_spu_grid(self):
        ev = [(T0 + k * 768, "noop", 0, 0) for k in range(1, FRAME // 768 + 2)]
        ev.append((T0 + FRAME, "vblank", 1500, 0))
        ref, s_step, s_fast = self.same(10, 11, 1, ev)
        self.assertEqual(ref[0], "done")
        self.assertLess(s_fast["checkpoints"], 800)            # ~735 SPU boundaries + the VBlank
        self.assertGreater(s_fast["jumped_iters"], 15000)       # the loop itself is not stepped
        self.assertLess(s_fast["slots"], 30000)

    def test_handler_steers_into_timeout_path(self):
        # a handler stores -1 into the counter cell between the store (offset 7) and the reload (offset 10) of
        # iteration 3: bne falls through to 8004252C, which the model hands to the interpreter
        it3 = T0 + 23 + 32 * 2
        ref, _, _ = self.same(0, 5, 1, [(it3 + 8, "cell", 11, m.M32)])
        self.assertEqual(ref[0], "handover")
        self.assertEqual(ref[2][0], m.TIMEOUT_PC)

    def test_ra_inside_the_wait_range(self):
        ref, _, _ = self.same(5, 5, 1, [], ra=0x80042508)
        self.assertEqual(ref[0], "done")
        self.assertEqual(ref[2][0], 0x80042508)


if __name__ == "__main__":
    unittest.main(verbosity=2)
