/* Main-exec range [80038A58,80038FC4) from the SLUS executable.
 * SHA256(span)=05ccdb27f0c65a6e6101d950100ea996630efe116e9b2d36fe792324d46d7409.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80038FC4(void *);                       /* static */
void func_80038FFC(void *);                   /* static */
extern u8 *D_800762B0;
extern u8 D_800762B4;
extern u16 D_800A4EE0;
extern s16 D_800A4EF8;
extern u8 D_800A4F16;
extern s32 *D_800B9CD8;
extern s16 D_800C6DD0;
extern s32 *D_800C6E2A;

void func_80038A58(void) {
    void *var_a0;
    void *var_s3;
    void *var_v1_2;
    s16 *var_a0_4;
    s16 *var_a0_6;
    s16 *var_a1_4;
    s16 *var_a1_6;
    s32 temp_a0;
    s32 temp_lo;
    s32 temp_lo_2;
    s32 temp_lo_3;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 var_a0_2;
    s32 var_a0_3;
    s32 var_a0_5;
    s32 var_a1;
    s32 var_a1_5;
    s32 var_a2_2;
    s32 var_s0;
    s32 var_s2;
    s32 var_s2_2;
    s32 var_t1;
    s32 var_t1_2;
    s32 var_t1_3;
    s32 var_t2;
    s32 var_v1;
    u16 *var_a1_3;
    u16 *var_t0;
    u16 *var_v1_3;
    u16 temp_a2;
    u16 temp_a3;
    u16 temp_v0_2;
    u16 temp_v0_3;
    u16 temp_v1_4;
    u16 temp_v1_5;
    u16 temp_v1_6;
    u32 temp_a0_2;
    u8 *var_a2;
    u8 *var_a3;
    u8 *var_v0;
    u8 temp_v0;
    u8 temp_v0_4;
    u8 temp_v0_5;
    void *var_a1_2;
    void *var_s1;

    var_s3 = &D_800B9CD8;
    var_v0 = &D_800762B4;
    var_s2 = 0xF;
    do {
        *var_v0 = 0;
        var_s2 -= 1;
        var_v0 += 1;
    } while (var_s2 >= 0);
    var_a3 = D_800762B0;
    var_a2 = &D_800762B4;
    var_a1 = 0;
    var_a0 = &D_800C6E2A;
    do {
        temp_v0 = *var_a3;
        if (((temp_v0 == 0) || (temp_v0 == 3)) && (*var_a2 == 0)) {
            M2C_FIELD(var_a0, s8 *, 1) = 0;
            if (M2C_FIELD(var_a0, u8 *, 0) != 0) {
                M2C_FIELD((M2C_FIELD(var_a0, s32 *, -0xA) + (M2C_FIELD(var_a0, s16 *, -0x54) * 0x1A) + var_a1), s8 *, 0x23) = 0;
                M2C_FIELD(var_a0, u8 *, 0) = 0U;
            }
        }
        var_a1 += 1;
        var_a0 += 0x60;
        var_a3 += 1;
        var_a2 += 1;
    } while (var_a1 < 0x10);
    var_s2_2 = 0;
    var_s1 = &D_800B9CD8 + 0x10;
    do {
        if ((M2C_FIELD(var_s1, u8 *, 0x1EB) != 0) && (M2C_FIELD(var_s1, u8 *, 0x1EA) != 0)) {
            temp_a0 = M2C_FIELD(var_s1, s32 *, 0x1C4);
            temp_v1 = M2C_FIELD(var_s1, s32 *, 0x1BC) + M2C_FIELD(var_s1, s32 *, 0x1C0);
            M2C_FIELD(var_s1, s32 *, 0x1BC) = temp_v1;
            if (temp_v1 >= temp_a0) {
                temp_lo = temp_v1 / temp_a0;
                temp_v1_2 = M2C_FIELD(var_s1, s32 *, -8);
                var_a0_2 = temp_v1_2;
                var_s0 = temp_lo;
                M2C_FIELD(var_s1, s32 *, 0x1BC) = (s32) (temp_v1 % temp_a0);
                if (temp_v1_2 != 0) {
                    if (temp_lo >= temp_v1_2) {
loop_15:
                        var_s0 -= var_a0_2;
                        if (var_a0_2 == var_s0) {
                            var_s0 = 0;
                        }
                        M2C_FIELD(var_s1, s32 *, -8) = 0;
loop_18:
                        if ((M2C_FIELD(var_s1, u8 *, 0x1E8) == 0) || (func_80038FFC(var_s3), (M2C_FIELD(var_s1, u8 *, 0x1E9) == 0))) {
                            temp_v1_3 = func_80038FC4(var_s3);
                            M2C_FIELD(var_s1, u8 *, 0x1E8) = 1U;
                            if (temp_v1_3 != 0) {
                                M2C_FIELD(var_s1, s32 *, -8) = temp_v1_3;
                                var_a0_2 = temp_v1_3;
                                if (var_s0 < temp_v1_3) {
                                    M2C_FIELD(var_s1, s32 *, -8) = (s32) (temp_v1_3 - var_s0);
                                    goto block_25;
                                }
                                goto loop_15;
                            }
                            goto loop_18;
                        }
                        M2C_FIELD(var_s1, u8 *, 0x1EA) = 0U;
                        M2C_FIELD(var_s1, u8 *, 0x1E8) = 0U;
                        goto block_66;
                    }
                    M2C_FIELD(var_s1, s32 *, -8) = (s32) (temp_v1_2 - temp_lo);
                    goto block_25;
                }
                M2C_FIELD(var_s1, u8 *, 0x1EA) = 0U;
                M2C_FIELD(var_s1, u8 *, 0x1E8) = 0U;
                goto block_25;
            }
block_25:
            var_t2 = 0;
            if (M2C_FIELD(var_s1, u8 *, 0x1E4) != 0) {
                var_t0 = var_s3 + 0x12;
                var_t1 = 0;
                var_a1_2 = var_s3 + 0x18;
                do {
                    if (M2C_FIELD(var_a1_2, u8 *, 0) != 0) {
                        temp_a3 = *var_t0;
                        temp_a2 = M2C_FIELD(var_a1_2, u16 *, -2);
                        temp_a0_2 = temp_a3 & 0xFFFF;
                        var_t2 = 1;
                        if (temp_a0_2 < temp_a2) {
                            temp_v0_2 = temp_a3 + M2C_FIELD(var_a1_2, u16 *, -4);
                            *var_t0 = temp_v0_2;
                            temp_v1_4 = M2C_FIELD(var_a1_2, u16 *, -2);
                            if ((u32) (temp_v0_2 & 0xFFFF) >= temp_v1_4) {
                                *var_t0 = temp_v1_4;
                                goto block_35;
                            }
                        } else {
                            temp_v1_5 = M2C_FIELD(var_a1_2, u16 *, -4);
                            temp_v0_3 = temp_a3 - temp_v1_5;
                            if (temp_v1_5 < temp_a0_2) {
                                *var_t0 = temp_v0_3;
                                temp_v1_6 = M2C_FIELD(var_a1_2, u16 *, -2);
                                if (temp_v1_6 >= (u32) (temp_v0_3 & 0xFFFF)) {
                                    *var_t0 = temp_v1_6;
                                    goto block_35;
                                }
                            } else {
                                *var_t0 = temp_a2;
block_35:
                                M2C_FIELD(var_a1_2, u8 *, 0) = 0U;
                            }
                        }
                    }
                    var_t1 += 1;
                    var_a1_2 += 8;
                    var_t0 += 8;
                } while (var_t1 <= 0);
                var_v1 = 0;
                var_a1_3 = var_s3 + 0x12;
                var_a0_3 = (s32) ((D_800A4EF8 << 7) * D_800A4EE0) >> 0xE;
                do {
                    temp_lo_2 = var_a0_3 * *var_a1_3;
                    var_v1 -= 1;
                    var_a1_3 += 8;
                    var_a0_3 = temp_lo_2 >> 0xE;
                } while (var_v1 >= 0);
                M2C_FIELD(var_s1, s16 *, 0) = (s16) var_a0_3;
                if ((var_t2 & 0xFF) || (var_t1_2 = 0, (D_800A4F16 != 0))) {
                    var_a1_4 = &D_800C6DD0;
                    var_t1_3 = 0;
                    var_a0_4 = &D_800C6DD0 + 0x5A;
                    do {
                        temp_v0_4 = M2C_FIELD(var_a0_4, u8 *, 0);
                        if (temp_v0_4 == 1) {
                            if (M2C_FIELD(M2C_FIELD(var_a0_4, void **, -0xA), s16 *, 0x1F0) == var_s2_2) {
                                M2C_FIELD(var_a0_4, s16 *, -0x42) = (s16) ((u32) (*var_a1_4 * M2C_FIELD(var_s1, s16 *, 0)) >> 0xE);
                                M2C_FIELD(var_a0_4, s8 *, 3) = 1;
                                M2C_FIELD(var_a0_4, s32 *, -0x46) = (s32) (M2C_FIELD(var_a0_4, s32 *, -0x46) | 3);
                                M2C_FIELD(var_a0_4, s16 *, -0x40) = (s16) ((u32) (M2C_FIELD(var_a0_4, s16 *, -0x58) * M2C_FIELD(var_s1, s16 *, 0)) >> 0xE);
                            }
                        } else if (temp_v0_4 != 0) {
                            M2C_FIELD(var_a0_4, u8 *, 0) = 1U;
                        }
                        var_t1_3 += 1;
                        var_a0_4 += 0x60;
                        var_a1_4 += 0x60;
                    } while (var_t1_3 < 0x10);
                    var_s2_2 += 1;
                } else {
                    M2C_FIELD(var_s1, u8 *, 0x1E4) = 0U;
                    var_v1_2 = &D_800C6E2A;
                    do {
                        if ((M2C_FIELD(var_v1_2, u8 *, 0) == 2) && (M2C_FIELD(M2C_FIELD(var_v1_2, void **, -0xA), s16 *, 0x1F0) == var_s2_2)) {
                            M2C_FIELD(var_v1_2, u8 *, 0) = 1U;
                        }
                        var_t1_2 += 1;
                        var_v1_2 += 0x60;
                    } while (var_t1_2 < 0x10);
                    var_s2_2 += 1;
                }
            } else {
                if (D_800A4F16 != 0) {
                    var_a1_5 = 0;
                    var_v1_3 = var_s3 + 0x12;
                    var_a0_5 = (s32) ((D_800A4EF8 << 7) * D_800A4EE0) >> 0xE;
                    do {
                        temp_lo_3 = var_a0_5 * *var_v1_3;
                        var_a1_5 -= 1;
                        var_v1_3 += 8;
                        var_a0_5 = temp_lo_3 >> 0xE;
                    } while (var_a1_5 >= 0);
                    M2C_FIELD(var_s1, s16 *, 0) = (s16) var_a0_5;
                    var_a1_6 = &D_800C6DD0;
                    var_a2_2 = 0;
                    var_a0_6 = &D_800C6DD0 + 0x5A;
                    do {
                        temp_v0_5 = M2C_FIELD(var_a0_6, u8 *, 0);
                        if (temp_v0_5 == 1) {
                            if (M2C_FIELD(M2C_FIELD(var_a0_6, void **, -0xA), s16 *, 0x1F0) == var_s2_2) {
                                M2C_FIELD(var_a0_6, s16 *, -0x42) = (s16) ((u32) (*var_a1_6 * M2C_FIELD(var_s1, s16 *, 0)) >> 0xE);
                                M2C_FIELD(var_a0_6, s8 *, 3) = 1;
                                M2C_FIELD(var_a0_6, s32 *, -0x46) = (s32) (M2C_FIELD(var_a0_6, s32 *, -0x46) | 3);
                                M2C_FIELD(var_a0_6, s16 *, -0x40) = (s16) ((u32) (M2C_FIELD(var_a0_6, s16 *, -0x58) * M2C_FIELD(var_s1, s16 *, 0)) >> 0xE);
                            }
                        } else if (temp_v0_5 != 0) {
                            M2C_FIELD(var_a0_6, u8 *, 0) = 1U;
                        }
                        var_a2_2 += 1;
                        var_a0_6 += 0x60;
                        var_a1_6 += 0x60;
                    } while (var_a2_2 < 0x10);
                }
                goto block_66;
            }
        } else {
block_66:
            var_s2_2 += 1;
        }
        var_s1 += 0x1FC;
        var_s3 += 0x1FC;
    } while (var_s2_2 < 2);
    D_800A4F16 = 0;
}
