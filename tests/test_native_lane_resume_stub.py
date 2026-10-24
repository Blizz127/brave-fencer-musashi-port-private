"""IRQ-GAP-D011 3.2, decided against (r61 review F2): a direct native call
into an admitted callee that is not cycle-mapped (no ledger) keeps the
caller's musashi_lane_resume_pc. The callee's first guest call takes it, so
an IRQ due by then is delivered right after that call returns, where retail
takes it, under the caller's resume pc. Clearing it in the stub only
deferred that delivery to the caller's next charge under the same pc. The
caller's own instrumentation clears the value after this call returns
(lane_cycles F2, tests/test_lane_cycles_resume.py). A mapped callee stores
its own before each of its calls. Synthetic rows only."""
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
    def test_unmapped_callee_keeps_the_callers_resume_pc(self):
        body = stub_body(ledger=False)
        # the fixed charge is still added, and the resume pc is left alone
        self.assertIn("++musashi_lane_fixed;", body)
        self.assertNotIn("musashi_lane_resume_pc", body)

    def test_mapped_callee_untouched(self):
        self.assertNotIn("musashi_lane_resume_pc", stub_body(ledger=True))


if __name__ == "__main__":
    unittest.main()
