"""Native-vs-deny route proof rule (tools/devobs_route_compare.py).

Pins the one explained DEVOBS difference, the thunk-return IRQ hold (B18,
docs/B18-TIMING-2026-10-03.md), and that everything else stays DIFFER.
Synthetic code words and records only.
"""
from pathlib import Path
import struct
import sys
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "tools"))
import devobs_route_compare as drc  # noqa: E402

VRAM = 0x80140000
CALLER_JAL = 0x80140010      # jal callee; resume pc = +8
RESUME = CALLER_JAL + 8
CALLEE_JR = 0x80140100       # jr ra; slot at +4
SLOT = CALLEE_JR + 4


def code(slot_word=0x00000000):
    words = [0] * 0x80
    words[(CALLER_JAL - VRAM) // 4] = 0x0C000000 | ((0x80140080 >> 2) & 0x3FFFFFF)
    words[(CALLEE_JR - VRAM) // 4] = drc.JR_RA
    words[(SLOT - VRAM) // 4] = slot_word
    c = drc.Code()
    c.add_member(struct.pack("<%dI" % len(words), *words), VRAM, 0)
    return c


def rec(kind, cycle, pc, a=0, b=8, c=0xD):
    return [kind, str(cycle), f"{pc:08x}", f"{a:08x}", f"{b:08x}", f"{c:08x}"]


def streams(shift=2, native_pc=SLOT, deny_pc=RESUME, tamper=None):
    common = [rec("R", 100, 0x8005BAA4), rec("W", 110, 0x8004270C)]
    hunk_n = [rec("I", 200, 0), rec("R", 213, 0x8005BAA4), rec("D", 200, native_pc, 0x55D8)]
    hunk_d = [rec("I", 200 + shift, 0), rec("R", 213 + shift, 0x8005BAA4), rec("D", 200 + shift, deny_pc, 0x55D8)]
    if tamper:
        tamper(hunk_n, hunk_d)
    tail = [rec("W", 900, 0x8004270C)]
    return common + hunk_n + tail, common + hunk_d + tail


class RouteCompare(unittest.TestCase):
    def verdict(self, nat, deny, c=None):
        return drc.compare(iter(nat), iter(deny), c or code())[0]

    def test_identical(self):
        nat, _ = streams()
        self.assertEqual(self.verdict(nat, list(nat)), "IDENTICAL")

    def test_thunk_return_hold_explained(self):
        self.assertEqual(self.verdict(*streams()), "EXPLAINED")

    def test_shift_must_be_the_slot_cost(self):
        self.assertEqual(self.verdict(*streams(shift=3)), "DIFFER")
        # a load in the slot costs 3
        self.assertEqual(self.verdict(*streams(shift=3), c=code(0x8E040198)), "EXPLAINED")

    def test_native_leg_later_is_not_the_hold(self):
        self.assertEqual(self.verdict(*streams(shift=-2)), "DIFFER")

    def test_delivery_pcs_must_be_slot_and_resume(self):
        self.assertEqual(self.verdict(*streams(native_pc=SLOT + 4)), "DIFFER")
        self.assertEqual(self.verdict(*streams(deny_pc=RESUME + 4)), "DIFFER")

    def test_fields_and_shift_must_agree(self):
        def field(n, d): d[1][3] = "00000401"
        def shift(n, d): d[1][1] = str(int(d[1][1]) + 1)
        def pc(n, d): d[1][2] = "8005baec"
        for t in (field, shift, pc):
            self.assertEqual(self.verdict(*streams(tamper=t)), "DIFFER", t.__name__)

    def test_hunk_without_delivery_or_unknown_code(self):
        def drop(n, d): del n[2], d[2]
        self.assertEqual(self.verdict(*streams(tamper=drop)), "DIFFER")
        self.assertEqual(self.verdict(*streams(), c=drc.Code()), "DIFFER")

    def test_length_and_reconvergence(self):
        nat, deny = streams()
        self.assertEqual(self.verdict(nat, deny[:-1]), "DIFFER")
        self.assertEqual(self.verdict(nat[:-1], deny[:-1]), "DIFFER")


if __name__ == "__main__":
    unittest.main()
