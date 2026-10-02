"""D-011 phase 2a: the retail cycle model and the clang/retail product walk
(tools/lane_cycles.py) and their report in tools/native_lane_gen.py.

The synthetic cases use hand-assembled MIPS words and hand-written -O0 IR
(owner test data, not retail). The retail checks (VSync's 64-cycle path,
800D2A24's 25/21) read the user's own extract and are skipped without it."""
import json
from pathlib import Path
import shutil
import subprocess
import sys
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))
import lane_cycles as lc  # noqa: E402
import native_lane_gen as g  # noqa: E402

BASE = 0x80100000
NOP = 0
JR_RA = 0x03E00008


def i_type(op, rs, rt, imm):
    return (op << 26) | (rs << 21) | (rt << 16) | (imm & 0xFFFF)


def addiu(rt, rs, imm): return i_type(9, rs, rt, imm)
def slti(rt, rs, imm): return i_type(10, rs, rt, imm)
def sw(rt, off, base): return i_type(43, base, rt, off)
def lw(rt, off, base): return i_type(35, base, rt, off)
def lwl(rt, off, base): return i_type(34, base, rt, off)
def swr(rt, off, base): return i_type(46, base, rt, off)
def jal(t): return (3 << 26) | ((t >> 2) & 0x3FFFFFF)
def j(t): return (2 << 26) | ((t >> 2) & 0x3FFFFFF)
def jr(rs): return (rs << 21) | 8
def brk(code): return (code << 6) | 13


def branch(op, rs, rt, pc, target, regimm_rt=None):
    off = (target - (pc + 4)) >> 2
    return i_type(op, rs, regimm_rt if regimm_rt is not None else rt, off)


def fn(body, params="", name="lane_func_80100000"):
    return f"define dso_local void @{name}({params}) #0 {{\n{body}\n}}\n"


class CostRule(unittest.TestCase):
    """formatter_step: 2 per instruction, +1 load/store, LWL/LWR 3, SWL/SWR 4."""

    def test_costs(self):
        self.assertEqual(lc.insn_cost(NOP), 2)
        self.assertEqual(lc.insn_cost(addiu(2, 0, 1)), 2)
        self.assertEqual(lc.insn_cost(lw(2, 0, 4)), 3)
        self.assertEqual(lc.insn_cost(sw(2, 0, 4)), 3)
        self.assertEqual(lc.insn_cost(lwl(2, 3, 4)), 3)
        self.assertEqual(lc.insn_cost(swr(2, 0, 4)), 4)
        self.assertEqual(lc.insn_cost(i_type(50, 4, 0, 0)), 3)   # lwc2
        self.assertEqual(lc.insn_cost(jal(BASE)), 2)

    def test_straight_call_costs(self):
        # call cost includes the jal and its delay slot; the rest is the return
        words = [addiu(29, 29, -24), sw(31, 16, 29), jal(0x80200000), addiu(4, 0, 1),
                 lw(31, 16, 29), addiu(29, 29, 24), JR_RA, NOP]
        r = lc.Retail(BASE, words)
        calls, ret = lc.single_path_cost(r)
        self.assertEqual(calls, [(0x80200000, 2 + 3 + 2 + 2)])
        self.assertEqual(ret, 3 + 2 + 2 + 2)
        self.assertEqual(lc.shape(r), "straight+call")


FOLDED_IR = fn("""  %1 = alloca i32, align 4
  store i32 0, ptr %1, align 4
  br label %2

2:
  %3 = load i32, ptr %1, align 4
  %4 = icmp slt i32 %3, 4
  br i1 %4, label %5, label %9

5:
  store i32 1, ptr inttoptr (i64 2148532224 to ptr), align 4
  br label %6

6:
  %7 = load i32, ptr %1, align 4
  %8 = add nsw i32 %7, 1
  store i32 %8, ptr %1, align 4
  br label %2

9:
  ret void""")


def folded_words():
    """for (i = 0; i < 4; i++) store, with gcc's first test folded: the
    loop is entered at its body and tested at the bottom."""
    w = [addiu(2, 0, 0), addiu(3, 0, 1), sw(3, 0, 4), addiu(2, 2, 1), slti(8, 2, 4)]
    w.append(branch(5, 8, 0, BASE + 0x14, BASE + 0x8))  # bnez t0, body
    w += [NOP, JR_RA, NOP]
    return w


class Mapping(unittest.TestCase):
    def test_folded_loop_exact(self):
        clang, retail, m = lc.map_ir(FOLDED_IR, "lane_func_80100000", BASE, folded_words())
        self.assertEqual(lc.shape(retail), "loop")
        start = (clang.entry, 0, BASE)
        # 4 iterations: entry+body+test 15, body+test 11 three times, return 4
        self.assertEqual(lc.charge_path(m["graph"], start, [0, 0, 0, 1]), [15 + 3 * 11 + 4])
        # the walk reproduces the retail path cost exactly
        total, _ = lc.walk(retail, [True, True, True, False])
        self.assertEqual(total, 52)

    def test_call_order_refused(self):
        ir = fn("""  call void @lane_call_func_80200000() #1
  call void @lane_call_func_80300000() #1
  ret void""")
        words = [jal(0x80300000), NOP, jal(0x80200000), NOP, JR_RA, NOP]
        with self.assertRaises(lc.Refuse) as e:
            lc.map_ir(ir, "lane_func_80100000", BASE, words)
        self.assertIn("call order", e.exception.reason)

    def test_retail_only_branch_refused(self):
        ir = fn("  ret void")
        words = [branch(4, 4, 0, BASE, BASE + 0x10), NOP, sw(3, 0, 4), NOP, JR_RA, NOP]
        with self.assertRaises(lc.Refuse):
            lc.map_ir(ir, "lane_func_80100000", BASE, words)

    def test_ambiguous_refused(self):
        # an unrecognisable clang condition: both polarities are consistent
        # and charge different arms
        ir = fn("""  %2 = alloca i1, align 1
  %3 = load i1, ptr %2, align 1
  br i1 %3, label %4, label %5

4:
  br label %6

5:
  store i32 1, ptr inttoptr (i64 2148532224 to ptr), align 4
  br label %6

6:
  ret void""", params="i32 noundef %0")
        words = [branch(4, 4, 0, BASE, BASE + 0x10), NOP, sw(3, 0, 4), NOP, JR_RA, NOP]
        with self.assertRaises(lc.Refuse) as e:
            lc.map_ir(ir, "lane_func_80100000", BASE, words)
        self.assertEqual(e.exception.reason, "ambiguous mapping")

    def test_predicate_decides(self):
        # if (x == 0) store: gcc's bne skips the store (inverted polarity)
        ir = fn("""  %2 = icmp eq i32 %0, 0
  br i1 %2, label %3, label %4

3:
  store i32 1, ptr inttoptr (i64 2148532224 to ptr), align 4
  br label %4

4:
  ret void""", params="i32 noundef %0")
        words = [branch(5, 4, 0, BASE, BASE + 0x10), NOP, sw(3, 0, 4), NOP, JR_RA, NOP]
        clang, retail, m = lc.map_ir(ir, "lane_func_80100000", BASE, words)
        start = (clang.entry, 0, BASE)
        self.assertEqual(lc.charge_path(m["graph"], start, [0]), [4 + 3 + 2 + 4])  # x == 0
        self.assertEqual(lc.charge_path(m["graph"], start, [1]), [4 + 4])          # x != 0
        self.assertEqual(m["structural"], 0)

    def test_switch_and_jump_table_refused(self):
        ir = fn("""  switch i32 %0, label %3 [
    i32 1, label %2
  ]

2:
  br label %3

3:
  ret void""", params="i32 noundef %0")
        with self.assertRaises(lc.Refuse) as e:
            lc.map_ir(ir, "lane_func_80100000", BASE, [JR_RA, NOP])
        self.assertEqual(e.exception.reason, "switch")
        out = lc.analyse(fn("  ret void"), "lane_func_80100000", BASE, [jr(2), NOP])
        self.assertEqual(out["status"], "refused")
        self.assertIn("jump table", out["reason"])

    def test_division_checks_folded(self):
        # div with gcc's divide-by-zero and overflow checks, then mflo
        div = (4 << 21) | (5 << 16) | 0x1A
        words = [div, branch(5, 5, 0, BASE + 4, BASE + 0x10), NOP, brk(7),
                 0x2401FFFF, branch(5, 5, 1, BASE + 0x14, BASE + 0x28), 0x3C018000,
                 branch(5, 4, 1, BASE + 0x1C, BASE + 0x28), NOP, brk(6),
                 0x00001012, JR_RA, NOP]
        ir = fn("""  %3 = call i32 @lane_sdiv32(i32 %0, i32 %1)
  ret void""", params="i32 noundef %0, i32 noundef %1")
        clang, retail, m = lc.map_ir(ir, "lane_func_80100000", BASE, words)
        self.assertEqual(m["div_adjust"], ["div_m1"])
        seg = retail.segment(BASE)
        self.assertEqual(seg["divs"][0]["extra"], 4)       # divisor == -1: bne + nop
        # divisor != -1: div, bnez, nop, li, bne, lui, mflo, jr, nop
        self.assertEqual(seg["cost"], 9 * 2)

    def test_pow2_adjust(self):
        # (x + 3) / 4: bgez skips the +3 bias for non-negative dividends
        words = [addiu(2, 4, 3), branch(1, 2, 0, BASE + 4, BASE + 0x10, regimm_rt=1), NOP,
                 addiu(2, 2, 3), (2 << 16) | (2 << 11) | (2 << 6) | 3, JR_RA, NOP]
        r = lc.Retail(BASE, words)
        seg = r.segment(BASE)
        self.assertEqual(seg["kind"], "ret")
        self.assertEqual([d["kind"] for d in seg["divs"]], ["sdiv_pow2"])
        self.assertEqual(seg["divs"][0]["extra"], 2)


class Instrument(unittest.TestCase):
    """Phase 2b: the ledger instrumentation of a mapped -O0 module."""

    def test_folded_loop_ledger(self):
        clang_bin = shutil.which("clang")
        c, r, m = lc.map_ir(FOLDED_IR, "lane_func_80100000", BASE, folded_words())
        text, rows = lc.instrument(c, r, m, guard=True, segs_symbol="lane_segs_func_80100000")
        self.assertIn("@musashi_lane_ledger", text)
        self.assertIn("call void @musashi_native_lane_tick(ptr @lane_segs_func_80100000", text)
        # each charged state's row holds exactly the retail instructions it charges
        for (i, rpc, insns), key in zip(rows, sorted(m["graph"], key=lambda k: (str(k[0]), k[1], k[2]))):
            edges = m["graph"][key]
            charged = edges[0][1] if edges[0][0] in ("cond", "call", "ret") else 0
            self.assertEqual(sum(cst for _, cst, fl in insns if not fl & 2), charged)
        if not clang_bin:
            raise unittest.SkipTest("needs clang to check the IR")
        with tempfile.TemporaryDirectory() as d:
            src = Path(d) / "x.ll"
            src.write_text(text)
            out = subprocess.run([clang_bin, "--target=x86_64-unknown-linux-gnu", "-O2", "-S", "-emit-llvm",
                                  "-w", str(src), "-o", str(Path(d) / "y.ll")], capture_output=True, text=True)
            self.assertEqual(out.returncode, 0, out.stderr[-1500:])
            opt = (Path(d) / "y.ll").read_text()
            self.assertIn("@musashi_lane_ledger", opt)

    def test_division_mismatch_refused(self):
        # clang divides by 4 (data-dependent retail bias expected) but the
        # retail code has no bgez bias branch: the mapping cannot charge it
        ir = fn("""  %2 = sdiv i32 %0, 4
  ret void""", params="i32 noundef %0")
        words = [(4 << 16) | (2 << 11) | (2 << 6) | 3, JR_RA, NOP]   # sra v0,a0,2
        out = lc.analyse(ir, "lane_func_80100000", BASE, words)
        self.assertEqual(out["status"], "refused")
        self.assertIn("division mismatch", out["reason"])


def exe_words(vram, size):
    exe = g.MAIN_EXE
    if not exe.exists():
        raise unittest.SkipTest("needs the user's SLUS_007.26 extract")
    data = exe.read_bytes()
    off = vram - 0x80010000 + 0x800
    return [int.from_bytes(data[off + i:off + i + 4], "little") for i in range(0, size, 4)]


class Retail(unittest.TestCase):
    def test_vsync_minus_one_is_64(self):
        # bfm_psyq_VSync's hand count (native_lane_psyq.c VSYNC_NATIVE_CYCLES)
        r = lc.Retail(0x8004239C, exe_words(0x8004239C, 0x148))
        total, costs = lc.walk(r, [False])          # bgez a0 not taken: mode < 0
        self.assertEqual(total, 64)
        self.assertEqual(lc.path_cost(r, 0x8004239C, 0x800423E8) +
                         lc.path_cost(r, 0x800424CC, 0x800424E0), 64)

    def test_800d2a24_25_21(self):
        info = g.member_info("main_0003")
        clang = shutil.which("clang")
        if info is None:
            raise unittest.SkipTest("needs the main_0003 extract")
        off = 0x800D2A24 - info["vram"] + info["start"]
        words = [int.from_bytes(info["data"][off + i:off + i + 4], "little") for i in range(0, 124, 4)]
        r = lc.Retail(0x800D2A24, words)
        self.assertEqual(lc.shape(r), "loop+call")
        # entry to the first Setloc call (jal + delay slot): 25; one retry
        # (status bit clear, result 0, back to the call): 21
        _, costs = lc.walk(r, [False, True, False, False, False])
        self.assertEqual(costs[:2], [25, 21])
        if not clang:
            raise unittest.SkipTest("needs clang for the mapping half")
        with tempfile.TemporaryDirectory() as d:
            (Path(d) / "ir").mkdir()
            entry = dict(vram=0x800D2A24, size=124, name="func_800D2A24",
                         source="src/overlays/main_0003/800d2a24.c")
            res = g.deny_cycle_analysis(entry, Path(d), g.load_symbol_addrs("main_0003"), clang, info)
            self.assertEqual(res["status"], "mapped", res)
            ir = next((Path(d) / "ir").glob("*.deny.O0.ll")).read_text()
            o0 = g.lower_arith(g.narrow_pointer_cells(g.rewrite_symbols(
                ir, g.load_symbol_addrs("main_0003"), "main_0003", info["code"])))
            c, rr, m = lc.map_ir(o0, "lane_main_0003__func_800D2A24", 0x800D2A24, words)
            start = (c.entry, 0, 0x800D2A24)
            # clang arms: (bit set? no) (result == 0? yes) -> retry once, then
            # bit set -> return 1
            got = lc.charge_path(m["graph"], start, [1, 0, 0])
            self.assertEqual(got[:2], [25, 21])


class Generator(unittest.TestCase):
    """The report from a release-mode run; admission is unchanged."""

    def test_report(self):
        clang = shutil.which("clang")
        if not clang or g.member_info("main_0003") is None or not g.MAIN_EXE.exists():
            raise unittest.SkipTest("needs clang and the user's extract")
        with tempfile.TemporaryDirectory() as d:
            only = Path(d) / "only.txt"
            only.write_text("8001d388\n8001fb8c\n80020da4\n")
            r = subprocess.run([sys.executable, str(ROOT / "tools/native_lane_gen.py"), "--out", d,
                                "--clang", clang, "--jobs", "2", "--own-code-only", "--only", str(only),
                                "--overlay-allow", str(ROOT / "config/lane_own_code_allow_overlay.txt")],
                               capture_output=True, text=True, timeout=900)
            self.assertEqual(r.returncode, 0, r.stderr[-2000:])
            rep = json.loads((Path(d) / "report.json").read_text())
            by = {(f["member"], f["vram"]): f for f in rep["functions"]}
            for vram in (0x8001D388, 0x8001FB8C, 0x80020DA4):
                self.assertTrue(by[(None, vram)]["admitted"])
                self.assertEqual(by[(None, vram)]["cycles"]["status"], "mapped")
            d2454 = by[("main_0003", 0x800D2454)]["cycles"]
            self.assertEqual((d2454["call_costs"], d2454["return_cost"]), ([24, 4, 9, 15, 4], 18))
            d2a24 = by[("main_0003", 0x800D2A24)]
            self.assertEqual((d2a24["admitted"], d2a24["rule"]), (False, "deny"))
            self.assertEqual(d2a24["cycles"]["status"], "mapped")
            self.assertIn("by_class", rep["cycles"])
            self.assertIn("native lane cycles (D-011)", r.stdout)


if __name__ == "__main__":
    unittest.main()
