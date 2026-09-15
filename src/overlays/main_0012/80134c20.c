/* Overlay range [80134C20,80134FB8) from MAIN.CD member 0012.
 * SHA256(span)=30e47e2a95c07d94a3dda8621ebee1e7342af6db2c2adfc1b5f2bc24ba0bb9aa.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80047E98(void *, void *, void *);               /* extern */
extern s32 D_8017E910;
extern s32 D_8017E914;
extern s32 D_8017E918;
extern s32 D_8017E91C;
extern s32 D_80184130;
s32 func_80134FB8(void *, void *, s32, s32);        /* static */
extern s32 D_801152A8;

s32 func_80134C20(s32 arg0, void *arg1, s32 arg2, s32 arg3) {
    s32 temp_a3;
    s32 temp_s1;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_v0;
    s32 var_v0_2;
    u16 temp_a1;
    void *temp_s4;

    temp_s4 = arg2 + (arg1->unk2 * 8);
    temp_s1 = *((arg1->unk4 * 4) + arg3);
    var_v0 = 0;
    if (func_80134FB8(temp_s4, D_8017E914, temp_s1) < 0) {
        temp_v0 = func_80134FB8(temp_s4, D_8017E910, temp_s1);
        if (temp_v0 >= 0) {
            temp_v0_2 = func_80134FB8(temp_s4, D_8017E91C, 0);
            temp_a3 = -temp_v0;
            D_8017E918->unk0 = (u16) (D_8017E910->unk0 + ((s32) (temp_a3 * D_8017E91C->unk0) / temp_v0_2));
            D_8017E918->unk2 = (u16) (D_8017E910->unk2 + ((s32) (temp_a3 * D_8017E91C->unk2) / temp_v0_2));
            D_8017E918->unk4 = (u16) (D_8017E910->unk4 + ((s32) (temp_a3 * D_8017E91C->unk4) / temp_v0_2));
            var_v0 = 0;
            if (func_80134FB8(arg2 + (arg1->unk6 * 8), D_8017E918, *((arg1->unk8 * 4) + arg3), temp_a3) >= -0x2F00) {
                var_v0 = 0;
                if (func_80134FB8(arg2 + (arg1->unkA * 8), D_8017E918, *((arg1->unkC * 4) + arg3)) >= -0x2F00) {
                    var_v0 = 0;
                    if (func_80134FB8(arg2 + (arg1->unkE * 8), D_8017E918, *((arg1->unk10 * 4) + arg3)) >= -0x2F00) {
                        var_v0_2 = arg0 & 1;
                        if (arg0 & 0x8000) {
                            var_v0 = 0;
                            if (func_80134FB8(arg2 + (arg1->unk12 * 8), D_8017E918, *((arg1->unk14 * 4) + arg3)) >= -0x2F00) {
                                var_v0_2 = arg0 & 1;
                                goto block_8;
                            }
                            /* Duplicate return node #15. Try simplifying control flow for better match */
                            return var_v0;
                        }
block_8:
                        if (var_v0_2 != 0) {
                            if (arg1->unk0 & 0x300) {
                                return 0;
                            }
                            goto block_14;
                        }
                        temp_a1 = arg1->unk0;
                        if (temp_a1 & 0x200) {
                            D_80184130 = temp_a1;
                            goto block_13;
                        }
block_14:
                        D_801152A8.unk3 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
                        D_801152A8.unk7 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
                        func_80047E98(D_8017E91C, D_8017E91C, &D_801152A8);
                        D_8017E918->unk0 = (u16) (D_8017E918->unk0 - ((s32) ((u16) D_8017E91C->unk0 << 0x10) >> 0x1B));
                        var_v0 = 1;
                        D_8017E918->unk2 = (u16) (D_8017E918->unk2 - ((s32) ((u16) D_8017E91C->unk2 << 0x10) >> 0x1B));
                        D_8017E918->unk4 = (u16) (D_8017E918->unk4 - ((s32) ((u16) D_8017E91C->unk4 << 0x10) >> 0x1B));
                        /* Duplicate return node #15. Try simplifying control flow for better match */
                        return var_v0;
                    }
                }
            }
            /* Duplicate return node #15. Try simplifying control flow for better match */
            return var_v0;
        }
block_13:
        return 0;
    }
    return var_v0;
}
