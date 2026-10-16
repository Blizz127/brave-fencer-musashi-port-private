#!/usr/bin/env python3
"""Static regression test (no build): the native lane generator must keep the PsyQ VSync entry native.

tools/native_lane_gen.py hooked_pcs() reads pc_port/*.c as TEXT, without the preprocessor, so a pc / ra / case
comparison with a guest address is a hook in every build, whatever #if surrounds it. A hook inside VSync's body
[0x8004239C, 0x800424E4) other than its two HLE_REPLACED_GATES makes psyq_hooked() hold VSync back, the default lane
(pure+vsync+pad) loses the native VSync(mode < 0), and tests/psyq_vsync_probe.c fails with "VSync in table=0 want 1".
At 7c970b2f0f the M6a other_ra diagnostic (cpu->r[31] against VSync's two call-return PCs) did exactly that.
Run: python3 -I -B tests/test_native_lane_vsync_hooks.py -v"""
import importlib.util
import sys
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
VSYNC = 0x8004239C
VSYNC_BODY_END = 0x800424E4     # psyq_hooked() ends VSync (no registry size) at the next function start


def generator():
    sys.path.insert(0, str(ROOT / "tools"))
    try:
        spec = importlib.util.spec_from_file_location("native_lane_gen_under_test", ROOT / "tools/native_lane_gen.py")
        module = importlib.util.module_from_spec(spec)
        spec.loader.exec_module(module)
    finally:
        sys.path.pop(0)
    return module


class VSyncStaysNative(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.gen = generator()
        cls.hooks = cls.gen.hooked_pcs()

    def test_no_port_hook_inside_the_vsync_body(self):
        inside = sorted(hex(pc) for pc in self.hooks if VSYNC <= pc < VSYNC_BODY_END)
        self.assertEqual(inside, [], "port code compares a PC inside VSync's body, so the lane would interpret VSync")

    def test_vsync_is_not_held_back_from_the_psyq_lane(self):
        self.assertNotIn(VSYNC, self.gen.psyq_hooked(self.hooks))

    def test_the_vsync_gates_stay_hle_replaced(self):
        self.assertLessEqual({0x8004239C, 0x800424CC}, self.gen.HLE_REPLACED_GATES)


if __name__ == "__main__":
    unittest.main()
