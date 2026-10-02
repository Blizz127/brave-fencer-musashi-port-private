"""Guest-frame locals (tools/native_lane_gen.py place_guest_locals, rule
"escape"): a local whose address reaches a callee moves into the retail
frame at the sp offset the retail words prove; anything unproven stays
refused. Synthetic MIPS words and IR only; no retail bytes."""
from pathlib import Path
import json
import re
import shutil
import subprocess
import sys
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))
import native_lane_gen as g  # noqa: E402

SP, RA, ZERO, V0, A0, A1, S0, S1, T0 = 29, 31, 0, 2, 4, 5, 16, 17, 8
VRAM = 0x80100000
NOP = 0


def addiu(rt, rs, imm):
    return (9 << 26) | (rs << 21) | (rt << 16) | (imm & 0xFFFF)


def sw(rt, off, base=SP):
    return (0x2B << 26) | (base << 21) | (rt << 16) | (off & 0xFFFF)


def lw(rt, off, base=SP):
    return (0x23 << 26) | (base << 21) | (rt << 16) | (off & 0xFFFF)


def move(rd, rs):
    return (rs << 21) | (rd << 11) | 0x21  # addu rd, rs, zero


def jal(target):
    return (3 << 26) | ((target >> 2) & 0x3FFFFFF)


def jr(rs):
    return (rs << 21) | 8


def beq(rs, rt, words_ahead):
    return (4 << 26) | (rs << 21) | (rt << 16) | ((words_ahead - 1) & 0xFFFF)


F1, F2 = 0x80120000, 0x80120100


def frame(body, size=0x28):
    """Prologue (frame size, ra saved at size-8), body, epilogue."""
    return ([addiu(SP, SP, -size), sw(RA, size - 8)] + body +
            [lw(RA, size - 8), addiu(SP, SP, size), jr(RA), NOP])


class RetailDataflow(unittest.TestCase):
    def test_delay_slot_argument(self):
        words = frame([jal(F1), addiu(A1, SP, 0x10)])
        sites, saved = g.retail_call_args(words, VRAM, 0x28)
        self.assertEqual(sites, [(VRAM + 8, F1, {1: 0x10})])
        self.assertEqual(saved, {0x20})

    def test_callee_saved_register_survives_a_call(self):
        words = frame([addiu(S0, SP, 0x18), jal(F1), move(A0, S0),
                       jal(F2), move(A0, S0)])
        sites, _ = g.retail_call_args(words, VRAM, 0x28)
        self.assertEqual([s[2] for s in sites], [{0: 0x18}, {0: 0x18}])

    def test_caller_saved_register_is_clobbered(self):
        words = frame([addiu(T0, SP, 0x18), jal(F1), move(A0, T0),
                       jal(F2), move(A0, T0)])
        sites, _ = g.retail_call_args(words, VRAM, 0x28)
        self.assertEqual([s[2] for s in sites], [{0: 0x18}, {}])

    def test_stack_argument(self):
        words = frame([addiu(V0, SP, 0x18), sw(V0, 0x10), jal(F1), NOP])
        sites, _ = g.retail_call_args(words, VRAM, 0x28)
        self.assertEqual(sites[0][2], {4: 0x18})

    def test_paths_that_disagree_prove_nothing(self):
        # a0 = sp+0x10 on the fall-through path, sp+0x14 on the taken one
        body = [beq(V0, ZERO, 3), addiu(A0, SP, 0x14), addiu(A0, SP, 0x10),
                jal(F1), NOP]
        sites, _ = g.retail_call_args(frame(body), VRAM, 0x28)
        self.assertEqual(sites[0][2], {})

    def test_paths_that_agree_keep_the_fact(self):
        body = [addiu(A0, SP, 0x10), beq(V0, ZERO, 2), NOP, NOP, jal(F1), NOP]
        sites, _ = g.retail_call_args(frame(body), VRAM, 0x28)
        self.assertEqual(sites[0][2], {0: 0x10})

    def test_indirect_jump_is_refused(self):
        with self.assertRaises(g.Reject) as cm:
            g.retail_call_args(frame([jr(V0), NOP]), VRAM, 0x28)
        self.assertEqual(cm.exception.rule, "escape")


IR = """%struct.V = type {{ i32, i32, i32 }}

define dso_local void @lane_func_80100000(ptr noundef %0) #0 {{
  %2 = alloca ptr, align 8
  %3 = alloca %struct.V, align 4
  %4 = alloca [2 x i32], align 4
  store ptr %0, ptr %2, align 8
  call void @llvm.memset.p0.i64(ptr align 4 %3, i8 0, i64 12, i1 false), !annotation !5
  call void @llvm.memset.p0.i64(ptr align 4 %4, i8 0, i64 8, i1 false), !annotation !5
  %5 = getelementptr inbounds nuw %struct.V, ptr %3, i32 0, i32 1
  store i32 7, ptr %5, align 4
  {calls}
  ret void
}}

declare void @llvm.memset.p0.i64(ptr writeonly captures(none), i8, i64, i1 immarg) #1
declare void @lane_call_func_80120000(...) #2
declare void @lane_call_func_80120100(...) #2
!5 = !{{!"auto-init"}}
"""

CALL_V = "call void (ptr, ...) @lane_call_func_80120000(ptr noundef %3)"
CALL_FIELD = "call void (ptr, ...) @lane_call_func_80120000(ptr noundef %5)"
CALL_ARR = ("%6 = getelementptr inbounds [2 x i32], ptr %4, i64 0, i64 0\n"
            "  call void (ptr, ptr, ...) @lane_call_func_80120100(ptr noundef %0, ptr noundef %6)")


def place(calls, words, size=0x28):
    return g.place_guest_locals(IR.format(calls=calls), "lane_func_80100000", words, VRAM, size)


class PlaceGuestLocals(unittest.TestCase):
    def test_no_escape_leaves_ir_alone(self):
        ir = IR.format(calls="")
        self.assertEqual(g.place_guest_locals(ir, "lane_func_80100000", None, VRAM, 0), (ir, []))

    def test_struct_and_array_move_to_their_retail_offsets(self):
        words = frame([jal(F1), addiu(A0, SP, 0x10),
                       jal(F2), addiu(A1, SP, 0x20)], 0x30)
        out, placed = place(CALL_V + "\n  " + CALL_ARR, words, 0x30)
        self.assertEqual([(o, n) for _, o, n in placed], [(0x10, 12), (0x20, 8)])
        self.assertNotIn("alloca %struct.V", out)
        self.assertNotIn("alloca [2 x i32]", out)
        self.assertIn("alloca ptr, align 8", out)  # the parameter slot stays on the host
        self.assertIn("%lane.gf.base = sub i32 %lane.gf.sp, %lane.spa.e1", out)
        self.assertIn("%lane.gf.a3 = add i32 %lane.gf.base, 16", out)
        self.assertIn("%lane.gf.a4 = add i32 %lane.gf.base, 32", out)
        self.assertIn("%3 = inttoptr i64 %lane.gf.z3 to ptr", out)
        # the host auto-init of a moved local is dropped: retail leaves it as is
        self.assertEqual(len(re.findall(r"call void @llvm\.memset", out)), 0)
        self.assertIn("@musashi_lane_entry_sp = external global i32", out)

    def test_field_address_gives_the_local_base(self):
        words = frame([jal(F1), addiu(A0, SP, 0x14)], 0x30)
        _, placed = place(CALL_FIELD, words, 0x30)
        self.assertEqual([(o, n) for _, o, n in placed], [(0x10, 12)])

    def test_inconsistent_offsets_refused(self):
        words = frame([jal(F1), addiu(A0, SP, 0x10), jal(F1), addiu(A0, SP, 0x14)], 0x30)
        with self.assertRaisesRegex(g.Reject, "sp\\+0x10 and sp\\+0x14"):
            place(CALL_V + "\n  " + CALL_V, words, 0x30)

    def test_call_count_mismatch_refused(self):
        words = frame([jal(F1), addiu(A0, SP, 0x10)], 0x30)
        with self.assertRaisesRegex(g.Reject, "2 calls to 80120000 in the C, 1 jal"):
            place(CALL_V + "\n  " + CALL_V, words, 0x30)

    def test_argument_not_sp_relative_refused(self):
        words = frame([jal(F1), move(A0, V0)], 0x30)
        with self.assertRaisesRegex(g.Reject, "retail sp offsets at \\[\\]"):
            place(CALL_V, words, 0x30)

    def test_overlapping_saved_register_refused(self):
        words = frame([sw(S0, 0x14), jal(F1), addiu(A0, SP, 0x10)], 0x30)
        with self.assertRaisesRegex(g.Reject, "overlaps a saved register"):
            place(CALL_V, words, 0x30)

    def test_outgoing_argument_area_refused(self):
        words = frame([jal(F1), addiu(A0, SP, 0x8)], 0x30)
        with self.assertRaisesRegex(g.Reject, "outside the frame's locals"):
            place(CALL_V, words, 0x30)

    def test_beyond_frame_refused(self):
        words = frame([jal(F1), addiu(A0, SP, 0x28)], 0x30)
        with self.assertRaisesRegex(g.Reject, "outside the frame's locals"):
            place(CALL_V, words, 0x30)

    def test_unknown_frame_refused(self):
        with self.assertRaisesRegex(g.Reject, "retail frame unknown"):
            place(CALL_V, None, 0)

    def test_variable_index_refused(self):
        calls = ("%6 = getelementptr inbounds [2 x i32], ptr %4, i64 0, i64 %0\n"
                 "  call void (ptr, ...) @lane_call_func_80120000(ptr noundef %6)")
        with self.assertRaisesRegex(g.Reject, "non-constant offset"):
            place(calls, frame([jal(F1), addiu(A0, SP, 0x10)], 0x30), 0x30)


class Layout(unittest.TestCase):
    def test_sizes(self):
        types = {"%s": "{ i16, i32, i8 }", "%p": "<{ i16, i32 }>"}
        self.assertEqual(g.ir_type_layout("%s", types), (12, 4))
        self.assertEqual(g.ir_type_layout("%p", types), (6, 1))
        self.assertEqual(g.ir_type_layout("[3 x %s]", types), (36, 4))
        self.assertIsNone(g.ir_type_layout("ptr", types))
        self.assertEqual(g.gep_const_offset("%s", ["0", "2"], types), 8)
        self.assertEqual(g.gep_const_offset("[3 x %s]", ["0", "1", "1"], types), 16)


class CallerPins(unittest.TestCase):
    """A native caller reaches a guest callee through the thunk with the
    sentinel ra, so GTE sites the formatter admits only for an audited jal
    return address would abort it. Read from the port's sources."""

    def test_ra_literal_pins_are_hooks(self):
        hooks = g.hooked_pcs()
        # gte_49324_caller: `return ra == 0x80013274u || ...` (Square0 callers)
        self.assertIn(0x80013274, hooks)
        self.assertIn(0x8002C710, hooks)

    def test_jal_caller_pins(self):
        pinned = g.caller_pinned_entries()
        self.assertIn(0x80049324, pinned)  # Square0
        self.assertIn(0x80048D9C, pinned)
        self.assertNotIn(0x80049440, pinned)  # LZC leaf: pinned by PC/word only


class EndToEnd(unittest.TestCase):
    """The generator on real decomp sources; needs clang and the user's own
    extract (the offsets come from its retail words, never committed)."""

    EXPECT = {
        0x8001C1E4: (True, None),        # tmp[8] at sp+0x10, passed to GsGetLw
        0x8002E5BC: (True, None),        # buf[4] at sp+0x10, passed to CdMix
        0x80013228: (False, "hooks"),    # its Square0 jal is a caller pin (ra 80013274)
        0x80016B60: (False, "abi"),      # locals placed, but an 8-argument unprototyped callee
    }

    @classmethod
    def setUpClass(cls):
        cls.clang = shutil.which("clang")
        if not cls.clang or not g.MAIN_EXE.exists():
            raise unittest.SkipTest("needs clang and extracted/disc/files/SLUS_007.26")
        cls._tmp = tempfile.TemporaryDirectory(prefix="musashi-lane-gf-")
        out = Path(cls._tmp.name)
        only = out / "only.txt"
        only.write_text("".join(f"{pc:08x}\n" for pc in cls.EXPECT))
        subprocess.run([sys.executable, str(ROOT / "tools/native_lane_gen.py"), "--out", str(out),
                        "--clang", cls.clang, "--jobs", "2", "--only", str(only)],
                       check=True, timeout=300, capture_output=True)
        cls.report = {f["vram"]: f for f in json.loads((out / "report.json").read_text())["functions"]}
        cls.table = (out / "native_lane_table.c").read_text()
        cls.out = out

    @classmethod
    def tearDownClass(cls):
        cls._tmp.cleanup()

    def test_decisions(self):
        for pc, (admitted, rule) in self.EXPECT.items():
            f = self.report[pc]
            self.assertEqual(f["admitted"], admitted, (hex(pc), f))
            if not admitted:
                self.assertEqual(f["rule"], rule, (hex(pc), f))

    def test_guest_local_rows(self):
        self.assertEqual(self.report[0x8001C1E4]["guest_locals"], [dict(off=16, size=32)])
        self.assertIn("{0x8001c1e4u, 56u, 16u, 32u, NULL},", self.table)
        ir = (self.out / "ir" / "8001c1e4.lane.ll").read_text()
        self.assertIn("@musashi_lane_entry_sp", ir)
        self.assertNotIn("alloca [8 x i32]", ir)


if __name__ == "__main__":
    unittest.main()
