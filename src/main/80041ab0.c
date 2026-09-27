/* Exact retail word export for [80041AB0,80041E8C); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_800401A0();                                 /* static */
s32 func_800401CC();                                /* static */
s32 func_80041E8C(s32, s32, u16 *, s32);            /* static */
extern s32 *D_800A5ED8;
extern s32 *D_800A5F20;
extern s32 *D_800A60B0;
extern s16 D_800A6540;
extern s32 *D_800B9B40;
extern s32 *D_800C7C98;
extern u16 D_800C7CD8;
extern s32 *D_800C7CE0;

s16 func_80041AB0(void *arg0, s16 arg1, s32 arg2, s32 arg3) {
    s32 sp410;
    s16 var_a1;
    s16 var_s1;
    s16 var_v0_2;
    s32 *temp_a3_2;
    s32 *var_a0;
    s32 *var_a1_3;
    s32 temp_a3;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 var_a1_2;
    s32 var_a1_4;
    s32 var_a3;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s0_3;
    s32 var_v0;
    s32 var_v0_3;
    u16 *var_a2;
    u16 temp_v1;
    u32 temp_a1;
    u32 var_v1_2;
    u8 temp_s3;
    void *temp_a2;
    void *temp_a2_2;
    void *var_v1;

    var_s1 = 0x10;
    if (func_800401CC() == 1) {
        return -1;
    }
    func_800401A0(1);
    if (arg1 < 0x10) {
        var_a1 = 0;
        if (arg1 == -1) {
loop_4:
            if (*(&D_800B9B40 + var_a1) != 0) {
                var_a1 += 1;
                var_v0 = 0x10 << 0x10;
                if (var_a1 >= 0x10) {

                } else {
                    goto loop_4;
                }
            } else {
                *(&D_800B9B40 + var_a1) = 1;
                var_s1 = var_a1;
                goto block_10;
            }
        } else {
            var_v0 = 0x10 << 0x10;
            if (*(&D_800B9B40 + arg1) == 0) {
                *(&D_800B9B40 + arg1) = 1;
                var_s1 = arg1;
block_10:
                D_800C7CD8 += 1;
                var_v0 = var_s1 << 0x10;
            }
        }
        temp_a3 = var_v0 >> 0x10;
        if (temp_a3 >= 0x10) {
            goto block_12;
        }
        *(&D_800A5F20 + (temp_a3 * 4)) = arg0;
        temp_a1 = arg0->unk0;
        temp_a2 = arg0 + 0x20;
        if ((temp_a1 >> 8) != 0x564142) {
            *(&D_800B9B40 + temp_a3) = 0;
            goto block_37;
        }
        var_v0_2 = 0x40;
        if ((temp_a1 & 0xFF) == 0x70) {
            var_v0_2 = 0x40;
            if (arg0->unk4 >= 5) {
                var_v0_2 = 0x80;
            }
        }
        D_800A6540 = var_v0_2;
        if (D_800A6540 >= (s32) arg0->unk12) {
            *(&D_800A5ED8 + ((s32) (var_s1 << 0x10) >> 0xE)) = temp_a2;
            temp_a2_2 = temp_a2 + (D_800A6540 * 0x10);
            var_a1_2 = 0;
            var_s0 = 0;
            if (D_800A6540 > 0) {
                var_v1 = temp_a2;
                do {
                    var_v1->unk8 = var_s0;
                    if (var_v1->unk0 != 0) {
                        var_s0 += 1;
                    }
                    var_a1_2 += 1;
                    var_v1 += 0x10;
                } while (var_a1_2 < D_800A6540);
            }
            var_s0_2 = 0;
            var_a1_3 = &sp10[0];
            *(&D_800A60B0 + ((s32) (var_s1 << 0x10) >> 0xE)) = temp_a2_2;
            temp_s3 = arg0->unk16;
            var_a2 = temp_a2_2 + (arg0->unk12 << 9);
            temp_a3_2 = &var_a1_3[temp_s3];
            do {
                if ((s32) temp_a3_2 >= (s32) var_a1_3) {
                    temp_v1 = *var_a2;
                    var_v0_3 = temp_v1 * 4;
                    if (arg0->unk4 >= 5) {
                        var_v0_3 = temp_v1 * 8;
                    }
                    *var_a1_3 = var_v0_3;
                    var_s0_2 += *var_a1_3;
                }
                var_a1_3 += 4;
                var_a2 += 2;
            } while ((s32) var_a1_3 < (s32) &sp410);
            var_a3 = arg3;
            if ((arg2 << 0x10) == 0) {
                var_a3 = func_80041E8C(var_s0_2, (s32) var_a1_3, var_a2, var_a3);
                var_v1_2 = var_a3 + var_s0_2;
                if (var_a3 == -1) {
                    goto block_36;
                }
                goto block_34;
            }
            var_v1_2 = var_a3 + var_s0_2;
block_34:
            var_s0_3 = 0;
            if (var_v1_2 > 0x80000U) {
                goto block_35;
            }
            *(&D_800C7CE0 + ((s32) (var_s1 << 0x10) >> 0xE)) = var_a3;
            temp_v1_2 = temp_s3 & 0xFF;
            var_a1_4 = 0;
            if (temp_v1_2 >= 0) {
                var_a0 = &sp10[0];
                do {
                    var_s0_3 += *var_a0;
                    temp_v1_3 = var_a1_4 / 2;
                    if (!(var_a1_4 & 1)) {
                        ((temp_v1_3 * 0x10) + temp_a2)->unkC = (s16) ((u32) (var_a3 + var_s0_3) >> 3);
                    } else {
                        ((((s32) (var_a1_4 + temp_v1_3) >> 1) * 0x10) + temp_a2)->unkE = (s16) ((u32) (var_a3 + var_s0_3) >> 3);
                    }
                    var_a1_4 += 1;
                    var_a0 += 4;
                } while (temp_v1_2 >= var_a1_4);
            }
            *(&D_800C7C98 + (var_s1 * 4)) = var_s0_3;
            *(&D_800B9B40 + var_s1) = 2;
            return var_s1;
        }
block_35:
block_36:
        *(&D_800B9B40 + var_s1) = 0;
block_37:
        func_800401A0(0);
        D_800C7CD8 -= 1;
        return -1;
    }
block_12:
    func_800401A0(0);
    return -1;
}
