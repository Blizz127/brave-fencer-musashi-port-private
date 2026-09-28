/* Complete SC02 retail span [80183810,80183A20).
 * Live STOP 83AC8 cluster; PAC0 member31.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80183810 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern s32 func_8012BEE8(s32 a0);
extern void func_8002D4C8(s32 a0, s32 a1);
extern s32 func_80132EF4(s32 a0, s32 a1);
extern void func_8012EFB8(s32 a0);
extern void func_800D1724(s32 a0);
extern s32 func_801789AC(s32 a0);
extern void func_80178D18(void);
extern u16 D_80126B5E;
extern s32 D_80126B60;
extern u16 D_80126B66;
extern u8 D_80188CCC[];
extern s32 D_80189370[];

void func_80183810(s32 a0) {
    u16 in3[3];   /* 0x10 */
    s16 out2[2];  /* 0x18 */
    s32 ent;
    s32 v;

    switch (*(u16 *)(a0 + 0x34)) {
    case 0:
        if (func_8012BEE8(a0) != 0) {
            *(u16 *)(a0 + 0x34) += 1;
            func_8002D4C8(0xC2E, 0);
        }
        break;
    case 1:
        *(s32 *)(a0 + 0x1C) += 1;
        if (*(s32 *)(a0 + 0x1C) >= 0xB) {
            /* cross_jump merges [addiu +1; j; sh 0x34] with case 2's tail (§162) */
            *(s32 *)(a0 + 0x1C) = 0x20;
            *(u16 *)(a0 + 0x34) += 1;
            break;
        }
        ent = func_80132EF4(a0, 0x6B);
        if (ent == 0) {
            break;
        }
        *(u16 *)(ent + 0xA) -= *(s32 *)(a0 + 0x1C) << 6;
        *(u16 *)(ent + 0x34) = D_80189370[*(s32 *)(a0 + 0x1C)];
        *(u16 *)(ent + 0x36) = 0xA - *(s32 *)(a0 + 0x1C);
        break;
    case 2:
        if (func_8012BEE8(a0) != 0) {
            *(u16 *)(a0 + 0x34) += 1;
        }
        break;
    case 3:
        D_80126B60 -= 0x300000;
        in3[0] = D_80126B5E;
        in3[1] = *(u16 *)((s32)&D_80126B60 + 2);   /* == D_80126B62; see above */
        in3[2] = D_80126B66;
        ((void (*)(u16 *, s16 *))func_8012EFB8)(in3, out2);

        /* |out2[0]| : the MERGED abs (bgez/negu/slti, one compare). */
        v = out2[0];
        if (v < 0) {
            v = -v;
        }
        if (v < 0xC9) {
            /* |out2[1]| : the SPLIT abs — the compare is duplicated into both
             * arms. Written as `>= K -> goto fail` (not `< K -> goto tail`) so
             * BOTH arms end in a conditional branch and only ONE unconditional
             * `j .L801839F0` survives; with the `goto tail` spelling both arms
             * end `j tail` and find_cross_jump's minimum=2 floor (§162) merges
             * the 2-insn [slti; beqz] suffix back into the merged abs (-5 ins). */
            if (out2[1] >= 0) {
                if (out2[1] >= 0xA1) { goto fail; }
            } else {
                if (-out2[1] >= 0xA1) { goto fail; }
            }
            goto tail;
        }
fail:
        func_800D1724((s32)D_80188CCC);
        *(u16 *)(a0 + 2) = 2;
        break;
    }
tail:
    if (func_801789AC(a0) == 1) {
        ((void (*)(s32))func_80178D18)(a0);
    }
}
