/* Overlay range [8017CBC8,8017CEB8) from MAIN.CD member 0012.
 * SHA256(span)=28d9f792974dea8dae330b22ba1849de6ead22956d7281f7f9a9e14261cb268f.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017CBC8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

/* func_8017CBC8 (ov_MAIN_012 / jr_801789AC) — 188 ins, byte-exact vs
 * asm/ov_MAIN_012/nonmatchings/ov_MAIN_012_jr_801789AC/func_8017CBC8.s
 *
 * Sprite/quad draw dispatcher: builds an OT chain for one "part list" entry.
 *
 * Idioms that were load-bearing here (feed these back into the cookbook):
 *  1) `dim`/`dim2`/`dim3` are DELIBERATE copies of `flag`.  The target keeps
 *     `flag` in $s7 and copies it into $s6 in each loop preheader and into $s0
 *     for the tail.  A plain `x = flag;` written in the same basic block as its
 *     use is killed by cse; it survives only when a multi-pred label separates
 *     def from use.  So: the loop-1 copy is written at the END of the outer
 *     body (loop.c hoists it into the preheader), the loop-2 copy is written in
 *     the preheader itself, and the tail copy needs a hard-register pin
 *     (`register s32 dim3 __asm__("$16")`) because nothing separates it from
 *     its uses.  Same shape as the matched sibling func_8013FAF8 (ov_SC06_008),
 *     which also needed a pin for exactly this call pair.
 *  2) `bp = sp18;` exists only to fix the ORDER of the two loop-1 preheader
 *     insns.  loop.c emits hoisted invariants in body order; writing the
 *     sp18-relative store address as an explicit pointer makes `addiu $s5,$sp,0x18`
 *     the FIRST movable, so the `dim` copy lands after it (as in the target).
 *  3) The `do { } while (0)` around the loop-1 call is a REGISTER-ALLOCATION
 *     lever, not dead syntax.  flow.c weights REG_N_REFS by loop_depth; the
 *     extra (never-iterating) loop note gives `ot` 18 weighted refs instead of
 *     16, which raises its global-alloc priority above `s` (21 refs / 159 insns)
 *     and lands the a0/a1 params in $s2/$s3 exactly as the target does.
 *     `mode` is hoisted out of the wrapper so `dim` does NOT get the same +1
 *     (that would swap $s5/$s6 between `bp` and `dim`).
 *  4) Low half of sp60[0] uses `& 0xFFFF`, NOT a (u16) cast: the mask keeps the
 *     operands in SImode so both halves load with `lh`; a (u16) cast makes
 *     gcc-2.7.2 emit `lhu`.
 */

extern u16 D_8011511A;
extern u8  D_80182774[];
extern s32 *D_801826EC[];

extern s32 func_80024054(u8 *, u8 *);
extern s32 func_800D2650(s32, u8 *, s16, s16, s32, s32);
extern s32 func_800D27DC(s32, s32, void *, s16, s32);
extern s32 func_800D29F8(s32, s32, void *, s16, s32);
extern s32 func_8017CEB8(s32, s16, s16, s16, s32 *);

s32 func_8017CBC8(s32 ot, u8 *s, s16 c) {
    u8  sp18[72];
    s32 sp60[5];
    s32 sp78[8];
    s32 flag;
    s32 dim;
    s32 dim2;
    register s32 dim3 __asm__("$16");
    s32 t;
    s16 i;
    s16 k;
    s32 *p;
    u8 *bp;
    s16 *q;
    s32 r;
    s32 mode;

    if (c == 0) {
        flag = 0;
    } else {
        flag = -(D_8011511A != c) & 0xFF;
    }

    t = *(s32 *)(s + 0x14);
    if (t < 0) {
        func_80024054((u8 *)t, sp18);
        ot = func_800D2650(ot, sp18, *(s16 *)(s + 0x10), *(s16 *)(s + 0x12), 1,
                           flag ? 0x585858 : 0x808080);
    } else {
        p = D_801826EC[t];
        for (k = 0; k < D_80182774[*(s32 *)(s + 0x14)]; k++) {
            bp = sp18;
            dim = flag;
            for (i = 0; i < 5; i++) {
                if (i == 0) {
                    sp60[0] = (((s16 *)p)[0] + *(s16 *)(s + 0x10)) & 0xFFFF |
                              ((((s16 *)p)[1] + *(s16 *)(s + 0x12)) << 16);
                } else {
                    *(s32 *)(bp + 0x48 + i * 4) = p[i];
                }
            }
            mode = dim ? 3 : 2;
            do {
                ot = func_800D27DC(mode, ot, sp60, 1, 0);
            } while (0);
            p += 5;
        }
    }

    i = 0;
    q = *(s16 **)(s + 0x18);
    dim2 = flag;
    for (;;) {
        r = func_8017CEB8(*(s32 *)(s + 0x1C), *(s16 *)s, c, i++, sp78);
        if (r == 0) {
            break;
        }
        if (r < 0) {
            func_80024054((u8 *)r, sp18);
            if (dim2 != 0) {
                sp78[0] = 0x585858;
            }
            ot = func_800D2650(ot, sp18, q[0], q[1], 1, sp78[0]);
        } else {
            p = D_801826EC[r];
            *p = (u16)q[0] | (q[1] << 16);
            ot = func_800D27DC(dim2 ? 3 : 2, ot, p, 1, 0);
        }
        q += 2;
    }

    dim3 = flag;
    return func_800D29F8(dim3,
                         func_800D27DC(dim3 != 0, ot, (void *)*(s32 *)(s + 4),
                                       *(s16 *)(s + 0xC), 0),
                         (void *)*(s32 *)(s + 8), *(s16 *)(s + 0xE), 0);
}
