/* Overlay range [80140958,80140D68) from MAIN.CD member 0012.
 * SHA256(span)=e4e15e6d5e9ea4bfb92ef25ceec307d63522d42fc2081a9f7f203fc8a5008582.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8017F1A0;
extern s32 D_8017F1F0;
extern s32 D_8017F222;
extern s32 D_8017F2E4;
extern s32 D_8017F700;
extern s32 D_8017F710;
s32 *func_80140D68(s32 *, s32 (*)(), s16, s16, s32);  /* static */
s32 func_8014168C(s32);                             /* static */
extern s32 *D_800AE7BC;
extern u16 D_800B9A02;
extern s32 D_80115110;
extern s32 *D_80115140;
extern u8 D_80115143;
extern u8 D_8011514E;
extern s32 *D_80115158;
extern s32 *D_8011516A;
extern u16 D_8017F220;

s32 *func_80140958(s32 *arg0, s16 arg1, s16 arg2) {
    s16 sp18;
    s32 (*var_a1)();
    s32 (*var_s2)();
    s16 var_a2;
    s16 var_a2_2;
    s16 var_a3;
    s16 var_s3;
    s16 var_v0_2;
    s16 var_v0_5;
    s16 var_v0_7;
    s16 var_v0_8;
    s16 var_v1;
    s32 *var_a0;
    s32 *var_a1_2;
    s32 *var_s1;
    s32 temp_a0;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_v0;
    s32 var_v0_3;
    s32 var_v0_4;
    s32 var_v0_6;
    void *temp_a0_2;
    void *temp_s5;
    void *temp_s7;

    var_s1 = arg0;
    var_s3 = arg1;
    sp18 = arg2;
    if (arg1 < arg2) {
        temp_s5 = &D_80115110 + 0xA;
        temp_s7 = &D_80115110 + 6;
        do {
            var_v0 = var_s3 << 0x10;
            if (D_80115110.unk0 == 0) {
                if ((D_80115110.unk2 != 3) && ((u16) D_80115110.unk2 < 6U)) {
                    var_a2 = var_s3;
                    var_v0_2 = var_s3;
                    if (var_a2 == D_80115110.unkA) {
                        var_a0 = var_s1;
                        var_a3 = *(D_8017F700 + ((D_80115110.unk6 & 7) * 2));
                        var_a1 = (var_a2 * 4) + D_8017F1A0;
                        goto block_21;
                    }
                } else {
                    var_v0 = var_s3 << 0x10;
                    goto block_8;
                }
            } else {
block_8:
                temp_v1 = var_v0 >> 0x10;
                var_s2 = *(D_8017F2E4 + (temp_v1 * 4));
                var_v0_3 = var_s3 << 0x10;
                if (var_s2 != 0) {
                    var_v0_3 = var_s3 << 0x10;
                    if (temp_v1 == D_80115110.unkA) {
                        if (temp_v1 != 6) {
                            var_v0_4 = var_s3 << 0x10;
                            if (temp_v1 == 2) {
                                var_v0_4 = var_s3 << 0x10;
                                if (temp_s5->unkE != 0) {
                                    var_s2 = D_8017F1F0;
                                }
                            }
                            temp_a0 = var_v0_4 >> 0x10;
                            if (temp_a0 != 3) {
                                var_v0_5 = func_8014168C(temp_a0) * 2;
                            } else {
                                var_v0_5 = (D_8011514E - D_80115143) * 2;
                            }
                            var_s1 = func_80140D68(var_s1, var_s2, var_s3, *(D_8017F710 + ((D_80115110.unk6 & 7) * 2)), (s32) var_v0_5);
                            var_v0_3 = var_s3 << 0x10;
                            if (var_s3 == 2) {
                                var_v0_3 = var_s3 << 0x10;
                                if (temp_s7->unk12 == 1) {
                                    if (temp_s7->unk18 != 0) {
                                        var_a0 = var_s1;
                                        var_a1 = var_s2;
                                        var_a2 = 2;
                                        var_a3 = 8;
block_21:
                                        var_s1 = func_80140D68(var_a0, var_a1, var_a2, var_a3);
                                    }
                                    goto block_22;
                                }
                            }
                        } else {
block_22:
                            var_v0_3 = var_s3 << 0x10;
                        }
                    }
                }
                var_v0_2 = (s16) (var_v0_3 >> 0x10);
            }
            var_v1 = var_s3 + 1;
            if (var_v0_2 == 3) {
                if ((D_80115110.unkA == var_v0_2) && (temp_s5->unk-4 & 8)) {
                    var_a2_2 = 0;
                    var_a1_2 = var_s1 + 0x10;
                    var_v0_6 = 0 << 0x10;
                    do {
                        if (var_v0_6 == 0) {
                            if (*(&D_80115140 + D_80115110.unkA) != 0) {
                                var_a1_2->unk-3 = 0x30;
                                var_v0_8 = D_8017F222 - 4;
                                goto block_33;
                            }
                            goto block_34;
                        }
                        var_v0_7 = var_a2_2 + 1;
                        if ((*(&D_80115158 + (D_80115110.unkA * 2)) - *(&D_80115140 + D_80115110.unkA)) >= 2) {
                            var_a1_2->unk-3 = 0x38;
                            var_v0_8 = D_8017F222 + 3;
block_33:
                            var_a1_2->unk-6 = var_v0_8;
                            *var_s1 = 0x04000000;
                            var_a1_2->unk-4 = 0x78;
                            var_a1_2->unk-C = 0x64808080;
                            var_a1_2->unk-2 = 0x4056;
                            var_a1_2->unk2 = 8;
                            var_a1_2->unk0 = 8;
                            var_a1_2->unk-8 = (s16) (D_8017F220 + *(&D_8011516A + (D_80115110.unkA * 4)) + 0x4A);
                            *var_s1 = (*var_s1 & 0xFF000000) | ((*(&D_800AE7BC + (D_800B9A02 * 0x14)))->unk8 & 0xFFFFFF);
                            var_a1_2 += 0x14;
                            temp_a0_2 = *(&D_800AE7BC + (D_800B9A02 * 0x14));
                            temp_v1_2 = (s32) var_s1 & 0xFFFFFF;
                            var_s1 += 0x14;
                            temp_a0_2->unk8 = (s32) ((temp_a0_2->unk8 & 0xFF000000) | temp_v1_2);
block_34:
                            var_v0_7 = var_a2_2 + 1;
                        }
                        var_a2_2 = var_v0_7;
                        var_v0_6 = var_a2_2 << 0x10;
                    } while (var_v0_7 < 2);
                }
                var_v1 = var_s3 + 1;
            }
            var_s3 = var_v1;
        } while (var_v1 < (s16) (u16) sp18);
    }
    return var_s1;
}
