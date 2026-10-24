"""IRQ-GAP-D011 3.2: a direct native call into an admitted callee that is
not cycle-mapped (no ledger) clears musashi_lane_resume_pc before the call,
so the callee's guest calls do not consume the caller's resume pc
(P1 kind=stale via 80034314 / 80148648 / 80029ED4). A mapped callee stores
its own before each of its calls and is left alone. Synthetic rows only."""
from pathlib import Path
import sys
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))
import native_lane_gen as g  # noqa: E402

F, C = 0x80100000, 0x80100300


def row(qname, vram, stubs=(), ledger=True, size=40):
    return dict(qname=qname, vram=vram, size=size, member=None, admitted=True, ledger=ledger,
                defs={"lane_" + qname: ("void", (False, False), [])},
                stubs=dict(stubs), icalls={})


def stub_body(ledger):
    callee = row("func_80100000", F, ledger=ledger)
    caller = row("func_80100300", C, [("lane_call_func_80100000__rvoid",
                                       ("func_80100000", ("void", (False, False), []), 0, None))])
    with tempfile.TemporaryDirectory() as d:
        direct, thunk, _, _ = g.emit_table([callee, caller], Path(d))
        table = (Path(d) / "native_lane_table.c").read_text()
    assert (direct, thunk) == (1, 0)
    return table.split("lane_call_func_80100000__rvoid(", 1)[1].split("\n}", 1)[0]


class ResumeStub(unittest.TestCase):
    def test_unmapped_callee_clears_before_the_call(self):
        body = stub_body(ledger=False)
        self.assertIn("musashi_lane_resume_pc = 0u;", body)
        self.assertLess(body.index("musashi_lane_resume_pc = 0u;"), body.index("lane_func_80100000()"))

    def test_mapped_callee_untouched(self):
        self.assertNotIn("musashi_lane_resume_pc", stub_body(ledger=True))


if __name__ == "__main__":
    unittest.main()
