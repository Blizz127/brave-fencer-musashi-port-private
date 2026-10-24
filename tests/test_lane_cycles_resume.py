"""D-011 / IRQ-GAP-D011 F2: the ledger instrumentation clears
musashi_lane_resume_pc after every guest call that stored it
(tools/lane_cycles.py instrument). Without the clear, a direct native call
whose callee makes no guest call left the value set, and a later guest call
from a non-storing body consumed it (P1: kind=stale).

Hand-written -O0 IR and hand-assembled MIPS words (owner test data)."""
from pathlib import Path
import re
import shutil
import subprocess
import sys
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))
import lane_cycles as lc  # noqa: E402

BASE = 0x80100000
NOP = 0
JR_RA = 0x03E00008
SEGS = "lane_segs_func_80100000"
STORE_RESUME = re.compile(r"^\s*store i32 (\S+), ptr @musashi_lane_resume_pc, align 4$")


def jal(t): return (3 << 26) | ((t >> 2) & 0x3FFFFFF)
def addiu(rt, rs, imm): return (9 << 26) | (rs << 21) | (rt << 16) | (imm & 0xFFFF)


def fn(body, params=""):
    return f"define dso_local void @lane_func_80100000({params}) #0 {{\n{body}\n}}\n"


# a direct native call (an admitted callee: the stub calls it natively) and a
# guest call (the stub thunks to the interpreter): the IR cannot tell them
# apart, both are lane_call_func_* and both store the resume pc
CALLS_IR = fn("""  call void @lane_call_func_80200000() #1
  %2 = call i32 @lane_call_func_80300000(i32 noundef 7) #1
  store i32 %2, ptr inttoptr (i64 2148532224 to ptr), align 4
  ret void""")
CALLS_WORDS = [jal(0x80200000), NOP, jal(0x80300000), addiu(4, 0, 7), JR_RA, NOP]

NOCALL_IR = fn("""  store i32 1, ptr inttoptr (i64 2148532224 to ptr), align 4
  ret void""")
NOCALL_WORDS = [addiu(2, 0, 1), JR_RA, NOP]


def instrumented(ir, words, guard=True):
    c, r, m = lc.map_ir(ir, "lane_func_80100000", BASE, words)
    return lc.instrument(c, r, m, guard=guard, segs_symbol=SEGS)


class ResumeClear(unittest.TestCase):
    def test_clear_after_each_call(self):
        text, _ = instrumented(CALLS_IR, CALLS_WORDS)
        lines = text.splitlines()
        calls = [i for i, l in enumerate(lines) if re.search(r"call [^@]*@lane_call_func_", l)]
        self.assertEqual(len(calls), 2)
        for i in calls:
            # the line before the call (after the charge) stores the resume pc,
            # the line right after the call clears it
            before = [STORE_RESUME.match(l) for l in lines[:i]]
            last = next(m for m in reversed(before) if m)
            self.assertNotEqual(last.group(1), "0")
            self.assertEqual(lines[i + 1].strip(), "store i32 0, ptr @musashi_lane_resume_pc, align 4")
        stores = [STORE_RESUME.match(l).group(1) for l in lines if STORE_RESUME.match(l)]
        # set, clear, set, clear: no value outlives its own call
        self.assertEqual([s == "0" for s in stores], [False, True, False, True])
        # the call's result is still used after the clear
        self.assertRegex(text, r"(?m)^\s*store i32 0, ptr @musashi_lane_resume_pc, align 4\n\s*(?:%\S+ = .*\n\s*)*store i32 %2, ptr inttoptr")

    def test_no_calls_unchanged(self):
        text, rows = instrumented(NOCALL_IR, NOCALL_WORDS)
        self.assertNotRegex(text, r"store i32 [^,]+, ptr @musashi_lane_resume_pc")
        # the declaration stays (guard modules declare the ledger symbols)
        self.assertIn("@musashi_lane_resume_pc = external global i32", text)
        self.assertEqual(len(rows), 1)

    def test_no_guard_no_resume(self):
        text, _ = instrumented(CALLS_IR, CALLS_WORDS, guard=False)
        self.assertNotIn("musashi_lane_resume_pc", text)

    def test_only_the_clears_are_added(self):
        # one clear per call, nothing else: the segment tables (rows) are the
        # retail costs as before (call 4, call 4, return 4)
        text, rows = instrumented(CALLS_IR, CALLS_WORDS)
        clears = text.count("  store i32 0, ptr @musashi_lane_resume_pc, align 4\n")
        self.assertEqual(clears, 2)
        self.assertEqual([sum(c for _, c, _ in insns) for _, _, insns in rows], [4, 4, 4])

    def test_optimizes(self):
        clang = shutil.which("clang")
        if not clang:
            raise unittest.SkipTest("needs clang")
        text, _ = instrumented(CALLS_IR, CALLS_WORDS)
        text += ("declare void @lane_call_func_80200000()\n"
                 "declare i32 @lane_call_func_80300000(i32 noundef)\n")
        with tempfile.TemporaryDirectory() as d:
            src = Path(d) / "x.ll"
            src.write_text(text)
            out = subprocess.run([clang, "--target=x86_64-unknown-linux-gnu", "-O2", "-S", "-emit-llvm",
                                  "-w", str(src), "-o", str(Path(d) / "y.ll")], capture_output=True, text=True)
            self.assertEqual(out.returncode, 0, out.stderr[-1500:])
            opt = (Path(d) / "y.ll").read_text()
        # -O2 keeps a clear after each call (the global is visible to callees)
        body = opt[opt.index("@lane_func_80100000("):]
        body = body[:body.index("\n}\n")]
        seq = re.findall(r"call [^@]*@(lane_call_func_\w+)|store i32 (\S+), ptr @musashi_lane_resume_pc", body)
        flat = [a or ("clear" if b == "0" else "set") for a, b in seq]
        self.assertEqual(flat, ["set", "lane_call_func_80200000", "clear", "set", "lane_call_func_80300000", "clear"])


if __name__ == "__main__":
    unittest.main()
