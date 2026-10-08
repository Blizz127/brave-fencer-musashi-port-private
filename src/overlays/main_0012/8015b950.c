/* Overlay range [8015B950,8015BD8C) from MAIN.CD member 0012.
 * SHA256(span)=ae5fb113ffe29d2775a8d82630b29f38b9c9bd8632dff0fefd7413afe790224e.
 * Word export for the native seam (m2c produced no draft). */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015B950 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

/* File-scope declarations from the vendor translation unit. */
struct S_80149744 {
    char pad44[0x44];
    s32 w44;       /* 0x44 */
    char pad48[0xAC - 0x48];
    u16 h_AC;      /* 0xAC */
};
void func_8012A568(void (*a0)(void));
extern s32 func_80029178(s32);
extern void func_8012A568(void (*a0)(void));
extern s32 func_80013294(void *a0, void *a1);
extern void func_80146D90(s32 a0);
extern void func_80146DB8(s32 *a0, s32 *a1);
extern void func_80147078(s32 *a0, s16 a1);
extern s32 func_801488A8(u8 *a0);
extern int func_80148AFC(void *a0);
extern s32 func_801496D4(void *a0);
extern void func_80149704(void);
extern s32 func_80149744(struct S_80149744 *a0);
extern void func_80149788(void);
extern s32 func_8016F1AC(void);
extern s32 func_80149AA8(s32 *a0);
extern s32 func_80149B54(s32 *a0);
extern s32 func_801498E0(s32 *a0);
extern s32 func_80149954(s32 s0);
extern s32 func_80149A64(s32 *a0);
extern void func_80149AD4(s32 *a0);
extern void func_80149BAC(s32 *a0);
extern s32 func_80149CD4(s32 a0);
extern void func_80154150(s32 a0, s32 a1);
extern void func_801541D8(u8 *a0, s32 a1, s32 a2);
extern int func_80161208();
extern void func_8015E880(s32 *a0);
extern s32 func_801725A4(u8 *a0);
extern void func_80159B70(void *a0);
extern void func_8015A264(void *a0);
extern s32 func_80161B18(void *a0);
extern s32 func_801619A4(s32 *a0);
extern void func_800CCCC0(s32 a0);
extern s32 D_8011F9C4;
extern s32 func_80161CD0(s32 a0, s32 a1);
extern void (*D_80180A1C[])(void *);

// @class: plumbing
// @stuck: none — MATCH (271/271, pin-free, zero asm). The ONLY residual is DEF-SIDE plumbing, and it is now named exactly: the in-TU instantiation `DEFINE_func_8015BEE4()` (engine_core.h:1851-1855) expands to `extern s32 func_8015B950(void);` INSIDE ov_SC01_077_jr_8015AE2C.c, ~14 lines BELOW this definition, so the 1-param def collides with a `(void)` prototype -> `conflicting types for func_8015B950` (.run/bank_func_8015B950.log). §73 PARAMS axis / T0. Surgical fix = §65b de-macroize that ONE instantiation (blast radius: this TU); the fleet-wide `(void)`->`()` header edit is §63 and must be R22-validated.
/* func_8015B950 (ov_SC01_077_jr_8015AE2C, 271 ins, jtbl_801D8B74) — SESSION-21 re-verified
 *
 * ── ROUND-2 INDEPENDENT RE-VERIFICATION (2026-07-27, fresh agent, §88e discipline) ─────────────
 *   match_one : MATCH (271 ins) against the CURRENT tree — §87 staleness re-checked today.
 *   .text size: compiled .text = 0x43C = 1084 B = 271 ins, EXACTLY the target's declared 0x43C
 *               ("nonmatching func_8015B950, 0x43C"). So this is NOT a §83a length drift hiding
 *               behind a zero count — the count is over equal-length streams.
 *   jtbl      : RE-DECODED MECHANICALLY, not inherited. Compiled .rodata = 0x1C = 28 B = 7 words,
 *               7x R_MIPS_32 -> .text with implicit addends [58,58,58,E0,F0,100,58]; +0x8015B950
 *               = [8015B9A8, 8015B9A8, 8015B9A8, 8015BA30, 8015BA40, 8015BA50, 8015B9A8].
 *               Diffed word-for-word against asm/ov_SC01_077/data/tail14.data.s:15-23 — 7/7 identical.
 *   symcheck  : SYMS-DIFF target=35 draft=34, sole MISSING = jtbl_801D8B74. This is the §81 jr
 *               FALSE POSITIVE, re-confirmed here by reading the relocs: gcc emits its OWN table and
 *               references it with R_MIPS_HI16/LO16 against the SECTION `.rodata` (t.o +0x40/+0x48),
 *               so the splat's dlabel NAME can never appear in the draft object's relocation set.
 *               Nothing is dropped and nothing is invented: the draft's other 34 symbols are exactly
 *               the target's other 34.
 *   FAMILY    : the x138 remap is clean and §84-safe. Every sibling is 271 ins with an IDENTICAL
 *               callee set; only THREE names vary per overlay — the two data labels and the jtbl:
 *                 ov_SC01_077  D_801809B0 / D_80180A1C / jtbl_801D8B74
 *                 ov_SC03_099  D_80185A50 / D_80185ABC / jtbl_801BD898
 *                 ov_SC06_008  D_80187E44 / D_80187EB0 / jtbl_801A8734
 *               The pair is always +0x6C apart, and NO literal in this draft encodes that distance
 *               (both labels are referenced by name), so there is no §84 derived-offset hazard.
 *               D_8011F9C4 is fleet-constant (main-EXE data) and must NOT be remapped.
 *
 * match_one: MATCH (271 ins) against the CURRENT tree (§87 staleness re-checked, 2026-07-27).
 * PIN-FREE, zero asm, offset-pure (s32 arg0 + raw offsets) — x138 template-safe.
 * Provenance: this is the Phase-26 crack (.run/phase26-cracks/func_8015B950.c) re-gated verbatim,
 * with ONE deliberate change: the definition's return type void -> s32.
 *   - `void func_8015B950(s32 arg0)` : MATCH (271 ins)   [the Phase-26 form]
 *   - `s32  func_8015B950(s32 arg0)` : MATCH (271 ins)   [shipped — §3a-1 void->s32 is byte-neutral]
 * The fleet/engine_core.h canonical decl is `extern s32 func_8015B950(void);` (engine_core.h:1852),
 * and the last bank attempt (.run/bank_func_8015B950.log) died on `conflicting types for
 * func_8015B950`. Shipping the s32 return kills the §73 RETURN axis for free and leaves only the
 * cheap T0 PARAMS axis for the ladder (fix_header_decl.py / --fix-def-sig / cast_call_sites).
 * Both forms are byte-identical, so the orchestrator may swap the return type back at zero cost.
 *
 * SYMBOLS (§58 rules 1/2 — all splat spellings, all verified present):
 *   D_80180A1C    asm/ov_SC01_077/data/tail.data.s:4355 (the state-handler vtable)
 *   D_801809B0    asm/ov_SC01_077/data/tail.data.s:4293
 *   D_8011F9C4    main-EXE data; spelled `extern s32 D_8011F9C4;` in 5+ already-banked TUs
 *   jtbl_801D8B74 asm/ov_SC01_077/data/tail14.data.s:15 (compiler jump table — not named in C)
 *
 * JTBL VERIFIED (§8a gate): compiled .rodata = exactly 0x1C B / 7 words, 7x R_MIPS_32 .text with
 * addends [0x58,0x58,0x58,0xE0,0xF0,0x100,0x58] -> +0x8015B950 = [B9A8,B9A8,B9A8,BA30,BA40,BA50,
 * B9A8] == the original words at 0x801D8B74..0x801D8B8C. Bound `sltiu $v0,$v1,0x7` matches.
 * The raw dlabel's 8th word 0x00000000 is NOT an entry — it is the intra-TU `.align 3` pad of the
 * B34/B54/B74 jtbl chain; the object can never emit it (maspsx drops .align), so it must stay in
 * the post-carve RAW data piece (the §53/§62/§81 carve chain applies at bank time).
 *
 * Same family as the TU's own already-matched func_8015AE2C: 7-case switch on ((s32 (*)(s32))func_801619A4)()
 * (0/1/2/6 shared, 3/4/5 own, no default block — out-of-range and every `break` fall to the
 * after-switch join), then a chain of "state handler" tests, each dispatching
 * D_80180A1C[*(u16*)arg0](arg0) and returning.
 *
 * THREE LEVERS (draft -> MATCH in 3 compiles):
 *
 * 1. PROLOGUE CONSTANT = an INITIALIZED LOCAL, not a literal in the compare.
 *    Target opens with `lui $s2, 0xFFF5` in the *prologue*, used once ~200 ins later in
 *    `slt $v0,$s2,$s1`. No gcc-2.7.2 pass hoists a (set reg const_int) across basic blocks
 *    (loop.c needs a loop; cse/combine/sched never move insns between BBs) — so the insn must
 *    have been EMITTED in the first BB, i.e. the constant is a local initialized at the top of
 *    the function. cse then cannot fold it back into the compare: the `slt` operand predicate is
 *    `arith_operand`, which rejects a CONST_INT wider than 16 bits, so validate_change fails and
 *    the pseudo survives. Its live range spans every call -> global.c gives it a callee-saved reg.
 *    Writing `z > -0xB0000` inline instead emits the `lui` into the branch delay slot next to the
 *    compare (caller-saved $v0) and the function is 1 insn short. => `s32 lim = -0xB0000;` at top.
 *
 * 2. `lh` vs `lhu`: a short->short copy is a pure HImode move and gcc emits `lhu`. The target's
 *    `lh $v0,0x26($s0)` means the value passed through an SImode (int) temp: expand makes
 *    (set (reg:SI) (sign_extend (mem:HI))) + (set (mem:HI) (subreg:HI ...)), and combine cannot
 *    merge them (the merged form is mem<-mem, which no movhi accepts) so the sign-extending load
 *    survives. => route both halfword copies through the `s32 t` temp.
 *
 * 3. THE `goto` LAYOUT — dodging jump.c's store-flag conversion (jump.c:1005-1065).
 *    An if/else chain writing 0/1 into `doit` makes gcc collapse the last pair into
 *    `sltiu $v0,$v0,1`. jump.c fires that conversion when the insn immediately after a
 *    conditional jump is a lone `SET pseudo, CONST_INT` whose following simplejump targets the
 *    SAME label as the branch (jump.c:1038 `reallabelprev == temp || ... JUMP_LABEL(temp4) ==
 *    JUMP_LABEL(insn)`) — exactly the shape of `if (c) x=0; else x=1;`.
 *    The target instead cross-jumps ALL the `doit=0` exits into ONE shared block placed after the
 *    `doit=1` fall-through; reorg's fill_slots_from_thread then COPIES that single set into all
 *    three branch delay slots and redirects each branch past it (which is why `addu $v0,$zero,
 *    $zero` appears 3x in delay slots and the shared block vanishes). A `goto zero;` / `goto one;`
 *    chain expresses that layout directly, and each conditional jump is then followed by a
 *    compare/call rather than a lone const set, so the store-flag conversion never triggers.
 *    GENERAL RULE: multiple predicates that all assign the SAME constant to one flag => write
 *    them as `goto` to a shared assignment, never as an if/else ladder.
 */


void func_8015B950(s32 arg0)
{
    extern s32 D_801809B0;


    s16 sp10[4];
    s16 sp18[4];
    s32 t;
    s32 z;
    s32 doit;
    s32 lim = -0xB0000;

    if (((s32(*)())func_80161B18)() != 0) {
        return;
    }
    switch (((s32 (*)(s32))func_801619A4)(arg0)) {
    case 0:
    case 1:
    case 2:
    case 6:
        if (((s32 (*)(s32))func_80149AA8)(arg0) != 0) {
            D_80180A1C[*(u16 *)arg0]((void *)arg0);
            ((void (*)(s32))func_80149AD4)(arg0);
            return;
        }
        if (((s32 (*)(s32))func_80149B54)(arg0) != 0) {
            D_80180A1C[*(u16 *)arg0]((void *)arg0);
            ((void (*)(s32))func_80149BAC)(arg0);
            return;
        }
        break;
    case 3:
        ((void (*)(s32))func_801498E0)(arg0);
        break;
    case 4:
        ((void (*)(s32))func_80149954)(arg0);
        break;
    case 5:
        if (((s32 (*)(s32))func_80149A64)(arg0) != 0) {
            D_80180A1C[*(u16 *)arg0]((void *)arg0);
            func_800CCCC0(arg0);
            return;
        }
        break;
    }
    if (func_80149CD4(arg0) != 0) {
        D_80180A1C[*(u16 *)arg0]((void *)arg0);
        ((void (*)(s32))func_8015E880)(arg0);
        return;
    }
    if (((s32 (*)(s32))func_80149744)(arg0) != 0) {
        D_80180A1C[*(u16 *)arg0]((void *)arg0);
        ((void (*)(s32))func_80149788)(arg0);
        return;
    }
    if (((s32 (*)(s32))func_801496D4)(arg0) != 0) {
        D_80180A1C[*(u16 *)arg0]((void *)arg0);
        ((void (*)(s32))func_80149704)(arg0);
        if (((u8)((s32 (*)(s32))func_80148AFC)(arg0)) == 0) {
            func_80146D90(arg0);
        }
        if ((*(s32 *)(arg0 + 0x24) | *(s32 *)(arg0 + 0x2C)) != 0) {
            func_80154150(arg0, 0xF);
        } else {
            ((void (*)(s32, s32, s32))func_801541D8)(arg0, 0xD, 6);
        }
        *(s32 *)(arg0 + 0x238) = 1;
        return;
    }
    if (((s32 (*)(s32))func_801488A8)(arg0) != 0) {
        sp10[0] = 0;
        sp10[1] = 0;
        sp10[2] = 0;
        t = *(s16 *)(arg0 + 0x26);
        sp18[0] = t;
        sp18[1] = 0;
        t = *(s16 *)(arg0 + 0x2E);
        sp18[2] = t;
        D_80180A1C[*(u16 *)arg0]((void *)arg0);
        ((void (*)(s32, s32))func_80147078)(arg0, 1);
        ((void (*)(s32))func_8015A264)(arg0);
        t = -(((s32 (*)(s16 *, s16 *))func_80013294)(sp10, sp18) << 0x10);
        if (t < *(s32 *)(arg0 + 0x2C)) {
            *(s32 *)(arg0 + 0x2C) = t;
        }
        return;
    }
    if (*(u16 *)(arg0 + 0xB8) == 0x8000) {
        D_80180A1C[*(u16 *)arg0]((void *)arg0);
        ((void (*)(s32, s32))func_80147078)(arg0, 0);
        ((void (*)(s32))func_80159B70)(arg0);
        return;
    }
    z = *(s32 *)(arg0 + 0x2C);
    if (func_8016F1AC() != 0) {
        goto zero;
    }
    if (z <= lim) {
        goto one;
    }
    if (D_8011F9C4 == 0) {
        goto zero;
    }
    if (((u8)((s32(*)(s32))func_80029178)(0x21)) != 0) {
        goto zero;
    }
one:
    doit = 1;
    goto join;
zero:
    doit = 0;
join:
    if (doit != 0) {
        D_80180A1C[*(u16 *)arg0]((void *)arg0);
        ((void (*)(s32, s32))func_80147078)(arg0, 0);
        ((void (*)(s32))func_80159B70)(arg0);
        func_80154150(arg0, 9);
        ((void (*)(s32, s32 *))func_80146DB8)(arg0, &D_801809B0);
        ((void (*)(s32, s32))func_80161CD0)(arg0, *(u16 *)(arg0 + 0x16E));
        return;
    }
    if (((s32(*)(s32))func_80161208)(arg0) == 0) {
        ((void (*)(s32))func_801725A4)(arg0);
    }
}
