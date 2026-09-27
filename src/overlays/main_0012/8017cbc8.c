/* Overlay range [8017CBC8,8017CEB8) from MAIN.CD member 0012.
 * SHA256(span)=28d9f792974dea8dae330b22ba1849de6ead22956d7281f7f9a9e14261cb268f.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80024054(s32, s32 (*)[], s16);               /* extern */
s32 func_800D2650(s32, s32 (*)[], s16, s16, s32, s32); /* extern */
s32 func_800D27DC(s32, s32, s32 *, s16, s32);       /* extern */
void func_800D29F8(s32, s32, s32, s16, s32);           /* extern */
extern s32 D_801826EC;
extern s32 D_80182774;
s32 func_8017CEB8(s32, s16, s16, s16, s32 *);       /* static */
extern u16 D_8011511A;

void func_8017CBC8(s32 arg0, void *arg1, s16 arg2) {
    s32 sp78;
    s32 sp60;
    s16 *var_s4_2;
    s16 *var_s5;
    s16 temp_a3;
    s16 temp_v0;
    s16 temp_v0_2;
    s16 var_s1;
    s16 var_s1_2;
    s16 var_s4;
    s32 *temp_s0;
    s32 temp_a0;
    s32 temp_v0_3;
    s32 var_a0;
    s32 var_a0_2;
    s32 var_s2;
    s32 var_s7;
    s32 var_v0;
    void *var_s0;

    var_s2 = arg0;
    if (arg2 == 0) {
        var_s7 = 0;
    } else {
        var_s7 = -(D_8011511A != arg2) & 0xFF;
    }
    temp_a0 = arg1->unk14;
    if (temp_a0 < 0) {
        func_80024054(temp_a0, (s32 (*)[]) &sp18[0], arg2);
        if (var_s7 != 0) {
            var_v0 = 0x585858;
        } else {
            var_v0 = 0x808080;
        }
        var_s2 = func_800D2650(var_s2, (s32 (*)[]) &sp18[0], arg1->unk10, arg1->unk12, var_v0);
    } else {
        var_s0 = *(D_801826EC + (temp_a0 * 4));
        var_s4 = 0;
        if (*(D_80182774 + temp_a0) != 0) {
            do {
                var_s1 = 0;
loop_11:
                if (var_s1 == 0) {
                    sp60 = ((var_s0->unk0 + arg1->unk10) & 0xFFFF) | ((var_s0->unk2 + arg1->unk12) << 0x10);
                } else {
                    (&sp18[0])[var_s1].unk48 = (s32) *((var_s1 * 4) + var_s0);
                }
                temp_v0_2 = var_s1 + 1;
                var_s1 = temp_v0_2;
                if (temp_v0_2 < 5) {
                    goto loop_11;
                }
                var_a0 = 2;
                if (var_s7 != 0) {
                    var_a0 = 3;
                }
                var_s2 = func_800D27DC(var_a0, var_s2, &sp60, 1, 0);
                temp_v0 = var_s4 + 1;
                var_s4 = temp_v0;
                var_s0 += 0x14;
            } while (temp_v0 < (s32) *(D_80182774 + arg1->unk14));
        }
    }
    var_s1_2 = 0;
    var_s4_2 = arg1->unk18;
    var_s5 = var_s4_2 + 2;
loop_19:
    temp_a3 = var_s1_2;
    var_s1_2 += 1;
    temp_v0_3 = func_8017CEB8(arg1->unk1C, arg1->unk0, arg2, temp_a3, &sp78);
    if (temp_v0_3 != 0) {
        var_a0_2 = 2;
        if (temp_v0_3 < 0) {
            func_80024054(temp_v0_3, (s32 (*)[]) &sp18[0]);
            if (var_s7 != 0) {
                sp78 = 0x585858;
            }
            var_s2 = func_800D2650(var_s2, (s32 (*)[]) &sp18[0], *var_s4_2, *var_s5, 1, sp78);
        } else {
            temp_s0 = *(D_801826EC + (temp_v0_3 * 4));
            *temp_s0 = (u16) *var_s4_2 | (*var_s5 << 0x10);
            if (var_s7 != 0) {
                var_a0_2 = 3;
            }
            var_s2 = func_800D27DC(var_a0_2, var_s2, temp_s0, 1, 0);
        }
        var_s5 += 4;
        var_s4_2 += 4;
        goto loop_19;
    }
    func_800D29F8(var_s7, func_800D27DC(var_s7 != 0, var_s2, arg1->unk4, arg1->unkC, 0), arg1->unk8, arg1->unkE, 0);
}
