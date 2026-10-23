"""Native lane: checker decisions and generated-table shape.

Only tracked decomp sources are needed (no retail data); skipped without
clang. The differential check against the interpreter is the CTest
native_lane_differential (MUSASHI_NATIVE_LANE=ON)."""
from pathlib import Path
import json
import shutil
import subprocess
import sys
import tempfile

import unittest

ROOT = Path(__file__).resolve().parents[1]
GEN = ROOT / "tools/native_lane_gen.py"

# Each decision is pinned to the rule that must make it.
EXPECT = {
    0x80019064: (True, None),        # guest globals, absolute addresses
    0x8001C044: (True, None),        # calls a bespoke-binding callee (thunk)
    0x800141F0: (False, "hooks"),    # STARTUP_ENTRY: host-sequenced (enum-named PC)
    0x8001903C: (True, None),        # STARTUP_RECORD_CLEAR: a host intrinsic the lane may run
    0x80015498: (False, "deny"),     # admissible, held out on DENY until a targeted probe covers it
    0x80015208: (True, None),        # register-pinned, only tied empty asm
    0x80015B6C: (False, "calls"),    # empty asm with an untied output
    0x80014CF8: (True, None),        # tied empty asm ("" : "=r"(x) : "0"(x)) is an identity
    0x80015310: (False, "memory"),   # volatile device access
    0x8002A088: (False, "abi"),      # passes 0 of 1 arguments to func_8002A108
    0x8001CFDC: (True, None),        # bounded read-only table search (walks memory)
    0x80018384: (False, "irq"),      # for (;;); : a loop that reads nothing new
}
# Sony PsyQ entry points never enter the lane (config/psyq_ranges.txt).
PSYQ = (0x800425B0, 0x8003B08C, 0x80046ABC)
CALLEES = (0x8002A108,)  # the arity rule needs the admitted callee present



class NativeLaneGeneratorTest(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.clang = shutil.which("clang")
        if not cls.clang:
            raise unittest.SkipTest("clang unavailable")
        cls._tmp = tempfile.TemporaryDirectory(prefix="musashi-lane-")
        cls.out = Path(cls._tmp.name)
        only = cls.out / "only.txt"
        only.write_text("".join(f"{pc:08x}\n" for pc in (*EXPECT, *PSYQ, *CALLEES)))
        subprocess.run([sys.executable, str(GEN), "--out", str(cls.out), "--clang", cls.clang,
                        "--jobs", "2", "--only", str(only)], check=True, timeout=300,
                       capture_output=True)
        cls.report = json.loads((cls.out / "report.json").read_text())
        cls.table = (cls.out / "native_lane_table.c").read_text()

    @classmethod
    def tearDownClass(cls):
        cls._tmp.cleanup()

    def test_decisions(self):
        got = {f["vram"]: f for f in self.report["functions"]}
        for pc, (admitted, rule) in EXPECT.items():
            entry = got[pc]
            self.assertEqual(entry["admitted"], admitted, (hex(pc), entry))
            if not admitted:
                self.assertEqual(entry["rule"], rule, (hex(pc), entry))
        for pc in PSYQ:
            self.assertNotIn(pc, got)
        self.assertGreaterEqual(self.report["psyq_excluded"], 1)

    def test_table_shape(self):
        # Admitted entry, marshalled through the register ABI.
        # The last field is the D-011 ledger flag (1: the body charges its
        # mapped retail cost; cost_cycles is then not charged).
        self.assertIn('{0x80019064u, 36u, wrap_80019064, "func_80019064", 1u, 0u, 1u},', self.table)
        # func_80016714 has a bespoke binding, so natively compiled callers
        # reach its guest words through the interpreter thunk.
        self.assertIn("musashi_native_guest_call(0x80016714u, 2u, args, NULL)", self.table)
        # Guest symbols are absolute guest addresses, never host relocations.
        lane_ir = (self.out / "ir" / "80019064.lane.ll").read_text()
        self.assertIn("inttoptr (i64 2147960768 to ptr)", lane_ir)  # D_800747C0
        self.assertNotIn("@D_800747C0", lane_ir)

    def test_table_compiles(self):
        cc = shutil.which("cc")
        if not cc:
            self.skipTest("cc unavailable")
        subprocess.run([cc, "-std=c99", "-Wall", "-Wextra", "-Werror",
                        "-I", str(ROOT / "pc_port/include"), "-c",
                        str(self.out / "native_lane_table.c"), "-o", str(self.out / "table.o")],
                       check=True, timeout=60)


class EmptyAsmTest(unittest.TestCase):
    def test_only_identity_empty_asm_is_dropped(self):
        sys.path.insert(0, str(ROOT / "tools"))
        import native_lane_gen as g
        for text in ('__asm__("" : : "r"(i), "r"(c));', '__asm__("" : "=r"(p) : "0"(p));',
                     '__asm__("" : "=r"(a), "=r"(b) : "0"(a), "1"(b));',
                     '__asm__ __volatile__("" ::: "memory");'):
            self.assertEqual(g.strip_empty_asm(text)[1], 1, text)
        self.assertIsNone(g.strip_empty_asm('__asm__("" : "=r"(a));'))        # untied output
        self.assertIsNone(g.strip_empty_asm('__asm__("" : "=r"(a) : "0"(b));'))  # tied to another value
        self.assertEqual(g.strip_empty_asm('__asm__("mtc2 $1, $2");')[1], 0)


class PollingLoopTest(unittest.TestCase):
    """The irq rule follows the control-flow graph, not the text layout (801379FC)."""

    def check(self, ir):
        sys.path.insert(0, str(ROOT / "tools"))
        import native_lane_gen as g
        g.check_polling_loops(ir)

    def refused(self, ir):
        sys.path.insert(0, str(ROOT / "tools"))
        import native_lane_gen as g
        with self.assertRaises(g.Reject) as cm:
            g.check_polling_loops(ir)
        self.assertIn("irq", str(cm.exception.args))

    def test_real_poll_refused(self):
        self.refused("define void @f(ptr %p) {\n  br label %1\n1:\n  %v = load i32, ptr %p, align 4\n"
                     "  %c = icmp eq i32 %v, 0\n  br i1 %c, label %1, label %2\n2:\n  ret void\n}\n")

    def test_earlier_block_on_a_forward_path_is_no_loop(self):
        # 801379FC: %2 branches to .preheader, laid out earlier but not on any cycle
        self.check("define void @f(ptr %p, i1 %c) {\n  br i1 %c, label %pre, label %2\npre:\n  br label %3\n"
                   "2:\n  %v = load i32, ptr %p, align 4\n  %d = icmp eq i32 %v, 0\n  br i1 %d, label %pre, label %3\n"
                   "3:\n  ret void\n}\n")

    def test_call_block_after_the_latch_counts(self):
        self.check("declare void @g()\ndefine void @f(ptr %p) {\n  br label %h\nh:\n  %v = load i32, ptr %p, align 4\n"
                   "  %z = icmp eq i32 %v, 0\n  br i1 %z, label %c, label %l\nl:\n  %w = load i32, ptr %p, align 4\n"
                   "  %y = icmp eq i32 %w, 7\n  br i1 %y, label %h, label %x\nc:\n  call void @g()\n  br label %l\n"
                   "x:\n  ret void\n}\n")

    def test_nested_poll_inside_a_calling_loop_refused(self):
        # outer loop calls g(); the inner loop spins on *p with no store or call of its own
        self.refused("declare void @g()\ndefine void @f(ptr %p) {\n  br label %o\no:\n  call void @g()\n  br label %i\n"
                     "i:\n  %v = load i32, ptr %p, align 4\n  %z = icmp eq i32 %v, 0\n  br i1 %z, label %i, label %e\n"
                     "e:\n  %w = load i32, ptr %p, align 4\n  %y = icmp eq i32 %w, 9\n  br i1 %y, label %x, label %o\n"
                     "x:\n  ret void\n}\n")

    def test_call_outside_the_loop_cannot_hide_a_poll(self):
        # the old text-range body (h .. h2) took in %side's call, which is not on the loop
        self.refused("declare void @g()\ndefine void @f(ptr %p, i1 %k) {\n  br i1 %k, label %h, label %side\n"
                     "h:\n  %v = load i32, ptr %p, align 4\n  %z = icmp eq i32 %v, 0\n  br i1 %z, label %h2, label %x\n"
                     "side:\n  call void @g()\n  br label %x\nh2:\n  br label %h\nx:\n  ret void\n}\n")


class GuestLocalSlotTest(unittest.TestCase):
    """escape: a C pointer variable that holds the same local's address on every path (MB-0003 800D27A0)."""
    VRAM = 0x80100000
    # addiu sp,-32; sw ra,24(sp); addiu a0,sp,16; jal 80059888; nop; lw ra,24(sp); jr ra; addiu sp,32
    WORDS = [0x27BDFFE0, 0xAFBF0018, 0x27A40010, 0x0C016622, 0x00000000, 0x8FBF0018, 0x03E00008, 0x27BD0020]

    def ir(self, a_store, b_store, extra=""):
        return ("define void @lane_func_80100000(i32 %c, ptr %q) {\n"
                "  %r = alloca [8 x i8], align 2\n  %s = alloca [8 x i8], align 2\n  %p = alloca ptr, align 8\n"
                "  %t = icmp ne i32 %c, 0\n  br i1 %t, label %a, label %b\n"
                f"a:\n  store ptr {a_store}, ptr %p, align 8\n  br label %j\n"
                f"b:\n  store ptr {b_store}, ptr %p, align 8\n  br label %j\n"
                f"j:\n{extra}  %x = load ptr, ptr %p, align 8\n  call void @lane_func_80059888(ptr %x)\n  ret void\n}}\n")

    def place(self, ir):
        sys.path.insert(0, str(ROOT / "tools"))
        import native_lane_gen as g
        return g, g.place_guest_locals(ir, "lane_func_80100000", self.WORDS, self.VRAM, 32)

    def test_same_local_on_every_path_is_placed(self):
        _, (out, placed) = self.place(self.ir("%r", "%r"))
        self.assertEqual(placed, [("%r", 16, 8)])
        self.assertIn("%r = inttoptr i64", out)

    def test_auto_init_null_store_is_ignored(self):
        # -ftrivial-auto-var-init's annotated null store (host-only) does not count as a stored value.
        ir = self.ir("%r", "%r").replace("  %t = icmp", "  store ptr null, ptr %p, align 8, !annotation !5\n  %t = icmp")
        ir += '!5 = !{!"auto-init"}\n'
        _, (_, placed) = self.place(ir)
        self.assertEqual(placed, [("%r", 16, 8)])
        # an unannotated null store is a real value: nothing is placed
        _, (_, placed) = self.place(self.ir("%r", "%r").replace("  %t = icmp", "  store ptr null, ptr %p, align 8\n  %t = icmp"))
        self.assertEqual(placed, [])

    def test_moved_scalar_keeps_retail_bytes(self):
        # A guest-placed scalar's host-only auto-init zero store is dropped (retail leaves the slot as it was);
        # an ordinary zero store stays.
        ir = ("define void @lane_func_80100000(i32 %c) {\n  %v = alloca i32, align 4\n"
              "  store i32 0, ptr %v, align 4, !annotation !5\n  call void @lane_func_80059888(ptr %v)\n"
              "  store i32 0, ptr %v, align 4\n  ret void\n}\n!5 = !{!\"auto-init\"}\n")
        _, (out, placed) = self.place(ir)
        self.assertEqual(placed, [("%v", 16, 4)])
        self.assertNotIn("!annotation !5", out.split("!5 = ")[0])
        self.assertIn("store i32 0, ptr %v, align 4\n", out)

    def test_different_values_are_not_placed(self):
        # Nothing moves into the guest frame; the later host-address check refuses the call.
        sys.path.insert(0, str(ROOT / "tools"))
        import native_lane_gen as g
        for a, b in (("%r", "%s"), ("%r", "%q")):
            try:
                _, placed = g.place_guest_locals(self.ir(a, b), "lane_func_80100000", self.WORDS, self.VRAM, 32)
            except g.Reject as e:
                self.assertIn("escape", str(e.args))
            else:
                self.assertEqual(placed, [])

    def test_slot_with_another_use_stays_refused(self):
        sys.path.insert(0, str(ROOT / "tools"))
        import native_lane_gen as g
        with self.assertRaises(g.Reject):
            g.place_guest_locals(self.ir("%r", "%r", "  call void @lane_func_80059000(ptr %p)\n"),
                                 "lane_func_80100000", self.WORDS, self.VRAM, 32)


class NativeLaneSourceTest(unittest.TestCase):
    def test_formatter_consults_lane_before_fetch(self):
        source = (ROOT / "pc_port/mips_formatter.c").read_text()
        step = source[source.index(
            "static int formatter_step(MusashiBootMemory *memory, FormatterCpu *cpu) {"):]
        self.assertLess(step.index("lane_try(memory, cpu)"),
                        step.index("formatter_fetch(memory, cpu, &instruction)"))
        # Tracing is opt-in and only observes.
        self.assertIn('getenv("MUSASHI_TRACE_FUNCS")', source)

    def test_no_retail_words_compiled_into_the_formatter(self):
        """Run off the disc: word arrays carry only their shape."""
        import re
        source = (ROOT / "pc_port/mips_formatter.c").read_text()
        self.assertNotRegex(source, r'#include "[^"]*_words\.inc"')
        for m in re.finditer(r"^static const uint32_t (k\w*Words)(\[[^\]]*\])+(.*)$",
                             source, flags=re.M):
            self.assertTrue(m.group(3).startswith(";"), m.group(0)[:100])
        self.assertFalse((ROOT / "pc_port/800cf02c_overlay_words.inc").exists())
        cmake = (ROOT / "CMakeLists.txt").read_text()
        self.assertNotIn("extract_asm_words.py", cmake)


if __name__ == "__main__":
    unittest.main()
