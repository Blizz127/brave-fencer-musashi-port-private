"""Implicit argument pass-through (tools/native_lane_gen.py ArgLiveness,
passthrough_flags, apply_passthrough, emit_table): a function whose retail
words hand a0-a3 to a callee untouched, while its C declares fewer
parameters, is never called directly from native code. Synthetic MIPS words
only; no retail bytes."""
from pathlib import Path
import sys
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))
import native_lane_gen as g  # noqa: E402

SP, RA, ZERO, V0, V1, A0, A1, A2, A3, S0, T0, AT = 29, 31, 0, 2, 3, 4, 5, 6, 7, 16, 8, 1
NOP = 0
F, G, H = 0x80100000, 0x80100100, 0x80100200


def addiu(rt, rs, imm):
    return (9 << 26) | (rs << 21) | (rt << 16) | (imm & 0xFFFF)


def sltiu(rt, rs, imm):
    return (0x0B << 26) | (rs << 21) | (rt << 16) | (imm & 0xFFFF)


def lui(rt, imm):
    return (0x0F << 26) | (rt << 16) | (imm & 0xFFFF)


def sw(rt, off, base=SP):
    return (0x2B << 26) | (base << 21) | (rt << 16) | (off & 0xFFFF)


def lw(rt, off, base=SP):
    return (0x23 << 26) | (base << 21) | (rt << 16) | (off & 0xFFFF)


def lh(rt, off, base):
    return (0x21 << 26) | (base << 21) | (rt << 16) | (off & 0xFFFF)


def move(rd, rs):
    return (rs << 21) | (rd << 11) | 0x21


def addu(rd, rs, rt):
    return (rs << 21) | (rt << 16) | (rd << 11) | 0x21


def sll(rd, rt, sa):
    return (rt << 16) | (rd << 11) | (sa << 6)


def jal(target):
    return (3 << 26) | ((target >> 2) & 0x3FFFFFF)


def j(target):
    return (2 << 26) | ((target >> 2) & 0x3FFFFFF)


def jr(rs):
    return (rs << 21) | 8


def jalr(rs):
    return (rs << 21) | (RA << 11) | 9


def beqz(rs, off_words):
    return (4 << 26) | (rs << 21) | (off_words & 0xFFFF)


def place(mem, base, words):
    for i, w in enumerate(words):
        mem[base + 4 * i] = w


def callee_reads_a0_a1():
    """G: lh v0, 2(a0); lh v1, 2(a1); jr ra; addu v0, v0, v1."""
    return [lh(V0, 2, A0), lh(V1, 2, A1), jr(RA), addu(V0, V0, V1)]


def wrapper_words():
    """F: the 80013328 shape: frame, `jal G` with a0/a1 untouched, then
    `jal H` with a0 = v0."""
    return [addiu(SP, SP, -0x18), sw(RA, 0x10), jal(G), NOP,
            jal(H), move(A0, V0), lw(RA, 0x10), addiu(SP, SP, 0x18), jr(RA), NOP]


def analyser(mem, extents=(), strict=False, varargs=False):
    def extent_of(key, pc):
        return next(((lo, hi) for lo, hi in extents if lo <= pc < hi), None)
    return g.ArgLiveness(lambda key, pc: mem.get(pc), lambda key, pc: None, extent_of,
                         strict=strict, varargs=varargs)


def leaf_h():
    return [lh(V0, 0, A0), jr(RA), NOP]


class ArgLivenessTest(unittest.TestCase):
    def mem(self, f_words):
        mem = {}
        place(mem, F, f_words)
        place(mem, G, callee_reads_a0_a1())
        place(mem, H, leaf_h())
        return mem

    def test_pass_through_at_jal(self):
        al = analyser(self.mem(wrapper_words()))
        al.analyse([(None, F)])
        self.assertEqual(al.summary[(None, G)], 0b0011)
        self.assertEqual(al.summary[(None, F)], 0b0011)
        sites = al.sites((None, F), 0b0011)
        self.assertEqual(sites, [(F + 8, "call", G, 0b0011)])

    def test_registers_written_before_the_jal_are_not_live(self):
        w = wrapper_words()
        w[3] = move(A0, S0)                # delay slot writes a0
        w[1:1] = [addiu(A1, ZERO, 5)]      # a1 set before the jal
        al = analyser(self.mem(w))
        al.analyse([(None, F)])
        self.assertEqual(al.summary[(None, F)], 0)

    def test_one_path_is_enough(self):
        # a1 written on the taken path only: still live-in on the other
        w = [addiu(SP, SP, -0x18), sw(RA, 0x10), beqz(A0, 2), NOP, addiu(A1, ZERO, 1),
             jal(G), NOP, lw(RA, 0x10), jr(RA), addiu(SP, SP, 0x18)]
        al = analyser(self.mem(w))
        al.analyse([(None, F)])
        self.assertEqual(al.summary[(None, F)], 0b0011)

    def test_tail_jump(self):
        # F: j G with a0/a1 untouched: G's reads are F's
        al = analyser(self.mem([j(G), NOP]))
        al.analyse([(None, F)])
        self.assertEqual(al.summary[(None, F)], 0b0011)
        self.assertTrue(any(k == "op" and pc == G for pc, k, _, _ in al.sites((None, F), 0b0011)))

    def test_recursion_reaches_a_fixpoint(self):
        # F: jal G (a0/a1 untouched). G: a0 != 0 calls F (a0/a1 untouched),
        # a0 == 0 reads a1. Mutually recursive; solved to the least fixpoint.
        mem = self.mem(wrapper_words())
        place(mem, G, [addiu(SP, SP, -0x18), sw(RA, 0x10), beqz(A0, 4), NOP,
                       jal(F), NOP, lw(RA, 0x10),
                       lh(V0, 0, A1), lw(RA, 0x10), jr(RA), addiu(SP, SP, 0x18)])
        al = analyser(mem)
        al.analyse([(None, F)])
        self.assertEqual(al.summary[(None, G)], 0b0011)
        self.assertEqual(al.summary[(None, F)], 0b0011)
        self.assertEqual(al.callers[(None, F)], {(None, G)})

    def test_jump_table_targets(self):
        # switch on a0 through a 2-entry table at 0x80101000; only case 1
        # reads a2. Without the table the whole extent would be merged.
        table = 0x80101000
        case0, case1 = F + 4 * 9, F + 4 * 11
        w = [sltiu(V0, A0, 2), beqz(V0, 9), sll(V0, A0, 2), lui(AT, table >> 16),
             addu(AT, AT, V0), lw(V0, table & 0xFFFF, AT), NOP, jr(V0), NOP,
             jr(RA), addiu(V0, ZERO, 0),            # case 0
             jr(RA), move(V0, A2)]                  # case 1 (also the default)
        mem = self.mem(w)
        mem[table], mem[table + 4] = case0, case1
        al = analyser(mem, extents=[(F, F + 4 * len(w))])
        al.analyse([(None, F)])
        self.assertEqual(al.summary[(None, F)], 0b0101)    # a0 and a2
        self.assertEqual(al.cfg[(None, F)][1][F + 28], [case0, case1])

    def test_unknown_sinks(self):
        # jalr t0 with a1 untouched: only strict mode assumes it reads a0-a3
        w = [addiu(SP, SP, -0x18), sw(RA, 0x10), lw(T0, 0, A0), NOP, jalr(T0), NOP,
             lw(RA, 0x10), jr(RA), addiu(SP, SP, 0x18)]
        loose = analyser(self.mem(w))
        loose.analyse([(None, F)])
        self.assertEqual(loose.summary[(None, F)], 0b0001)
        self.assertEqual(loose.unknown[(None, F)], F + 16)
        strict = analyser(self.mem(w), strict=True)
        strict.analyse([(None, F)])
        self.assertEqual(strict.summary[(None, F)], 0b1111)

    def test_varargs_home_spills(self):
        # a printf-like callee spills a1-a3 to its home area, reads a0
        printf = [sw(A1, 4), sw(A2, 8), sw(A3, 12), lh(V0, 0, A0), jr(RA), NOP]
        mem = self.mem(wrapper_words())
        place(mem, G, printf)
        counted = analyser(mem)
        counted.analyse([(None, F)])
        self.assertEqual(counted.summary[(None, G)], 0b1111)
        ignored = analyser(mem, varargs=True)
        ignored.analyse([(None, F)])
        self.assertEqual(ignored.summary[(None, G)], 0b0001)
        # a lone spill of a1 (an address-taken parameter) is a read
        place(mem, G, [sw(A1, 4), lh(V0, 0, A0), jr(RA), NOP])
        lone = analyser(mem, varargs=True)
        lone.analyse([(None, F)])
        self.assertEqual(lone.summary[(None, G)], 0b0011)


def admitted_row(qname, vram, params, stubs=(), size=40):
    return dict(qname=qname, vram=vram, size=size, member=None, admitted=True, ledger=True,
                defs={"lane_" + qname: ("i32", (True, False), params)},
                stubs=dict(stubs), icalls={})


PTR = ("ptr", (False, False))


class PassthroughFlagTest(unittest.TestCase):
    def setUp(self):
        self.mem = {}
        place(self.mem, F, wrapper_words())
        place(self.mem, G, callee_reads_a0_a1())
        place(self.mem, H, leaf_h())
        mem = self.mem
        orig = g.make_arg_liveness

        def fake(infos, strict=False, varargs=False):
            return analyser(mem, strict=strict, varargs=varargs)
        g.make_arg_liveness = fake
        self.addCleanup(setattr, g, "make_arg_liveness", orig)

    def test_flags_under_declared_function(self):
        rows = [admitted_row("func_80100000", F, [])]
        flags = g.passthrough_flags(rows, {})
        self.assertEqual(set(flags), {"lane_func_80100000"})
        self.assertEqual(flags["lane_func_80100000"]["bits"], 0b0011)
        self.assertIn("a0,a1 live at jal 80100100", g.passthrough_detail(flags["lane_func_80100000"]))

    def test_declared_parameters_are_not_flagged(self):
        rows = [admitted_row("func_80100000", F, [PTR, PTR])]
        self.assertEqual(g.passthrough_flags(rows, {}), {})

    def test_partly_declared(self):
        rows = [admitted_row("func_80100000", F, [PTR])]
        self.assertEqual(g.passthrough_flags(rows, {})["lane_func_80100000"]["bits"], 0b0010)

    def test_tail_jump_flagged(self):
        place(self.mem, F, [j(G), NOP])
        rows = [admitted_row("func_80100000", F, [PTR])]
        self.assertEqual(g.passthrough_flags(rows, {})["lane_func_80100000"]["bits"], 0b0010)


def stub(callee, nargs):
    sig = ("i32", (True, False), [PTR] * nargs)
    return (f"lane_call_{callee}__x{nargs}", (callee, sig, nargs, None))


class ApplyAndEmitTest(unittest.TestCase):
    """The 8014C278 -> 80013328 shape: a native caller passes two arguments
    to a function whose C takes none but whose words read a0/a1."""

    def rows(self, caller_args=2, caller_params=2):
        callee = admitted_row("func_80100000", F, [])
        caller = admitted_row("func_80100300", 0x80100300, [PTR] * caller_params,
                              [stub("func_80100000", caller_args)])
        return callee, caller

    def test_caller_routes_through_the_thunk(self):
        callee, caller = self.rows()
        flags = {"lane_func_80100000": dict(bits=0b0011, slots=0, sites=[(F + 8, "call", G, 0b0011)],
                                            unknown=None)}
        g.apply_passthrough([callee, caller], flags)
        self.assertTrue(caller["admitted"])
        self.assertIn("implicit argument pass-through", callee["passthrough"])
        with tempfile.TemporaryDirectory() as d:
            direct, thunk, hooked, passed = g.emit_table(
                [callee, caller], Path(d), frozenset(), frozenset({"lane_func_80100000"}))
            table = (Path(d) / "native_lane_table.c").read_text()
        self.assertEqual((direct, thunk, hooked, passed), (0, 1, 0, 1))
        body = table.split("lane_call_func_80100000__x2(", 1)[1].split("\n}", 1)[0]
        self.assertIn("musashi_native_guest_call(0x80100000u, 2u, args, NULL)", body)
        self.assertNotIn("lane_func_80100000(", body)
        # the callee keeps its native table entry (lane_try still runs it)
        self.assertIn("{0x80100000u,", table)

    def test_without_the_flag_the_call_is_direct(self):
        callee, caller = self.rows()
        with tempfile.TemporaryDirectory() as d:
            direct, thunk, hooked, passed = g.emit_table([callee, caller], Path(d))
            table = (Path(d) / "native_lane_table.c").read_text()
        self.assertEqual((direct, passed), (1, 0))
        self.assertIn("lane_func_80100000()", table)

    def test_caller_passing_too_few_is_refused(self):
        # passes only a0 and does not pass a1 through itself
        callee, caller = self.rows(caller_args=1, caller_params=1)
        flags = {"lane_func_80100000": dict(bits=0b0011, slots=0, sites=[], unknown=None)}
        g.apply_passthrough([callee, caller], flags)
        self.assertFalse(caller["admitted"])
        self.assertEqual(caller["rule"], "abi")
        self.assertIn("reads a1 through", caller["detail"])

    def test_caller_that_passes_through_itself_is_kept(self):
        callee, caller = self.rows(caller_args=1, caller_params=1)
        flags = {"lane_func_80100000": dict(bits=0b0011, slots=0, sites=[], unknown=None),
                 "lane_func_80100300": dict(bits=0b0010, slots=1, sites=[], unknown=None)}
        g.apply_passthrough([callee, caller], flags)
        self.assertTrue(caller["admitted"])
        self.assertIn("passthrough", caller)


class ArgSlotsTest(unittest.TestCase):
    def test_slots(self):
        i32 = ("i32", (True, False))
        i64 = ("i64", (True, False))
        self.assertEqual(g.arg_slots([]), 0)
        self.assertEqual(g.arg_slots([i32, PTR]), 2)
        self.assertEqual(g.arg_slots([i32, i64]), 4)   # o32 aligns the pair
        self.assertEqual(g.regs_text(0b1010), "a1,a3")


if __name__ == "__main__":
    unittest.main()
