/* Exact retail word export for [80030F80,800314DC); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006AA30;
extern s32 D_80073140;
extern s32 D_8007319E;
extern s32 D_800731A0;
extern s32 *D_8007321E;
void func_8002EFF8(s32, s32);                            /* static */
void func_800314DC(s32 *);                             /* static */
void func_800316F8(s32 *);                             /* static */
void func_80031988(s32 *);                             /* static */
void func_8003D3B4(u16, s32);                            /* static */
extern s32 *D_800A4C6D;
extern s32 *D_800A4EFE;
extern u8 D_800A4F19;
extern s32 D_800C7D2C;

void func_80030F80(void) {
    s32 (*temp_v0_12)();
    s32 (*temp_v0_4)();
    s16 temp_v1_4;
    s32 *var_s2;
    s32 temp_a0_2;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_6;
    s32 temp_v0_7;
    s32 var_s1;
    s32 var_s3;
    s32 var_s5;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v0_4;
    u16 temp_a0;
    u16 temp_a0_4;
    u16 temp_v0_10;
    u16 temp_v0_11;
    u16 temp_v0_5;
    u32 var_a1;
    u32 var_v0_3;
    u8 temp_v0;
    u8 temp_v0_8;
    u8 temp_v0_9;
    u8 temp_v1;
    u8 temp_v1_2;
    u8 temp_v1_3;
    u8 temp_v1_5;
    u8 var_a3;
    void *temp_a0_3;
    void *temp_s7;
    void *var_s0;

    var_s2 = &D_800A4EFE - 0x576;
    var_s5 = 0;
    temp_s7 = &D_800A4EFE - 4;
    var_s0 = &D_800A4EFE - 0x56C;
    var_s3 = 0;
    do {
        var_s1 = 0;
        temp_v0 = var_s0->unk44 & 0x7F;
        var_s0->unk44 = temp_v0;
        if (temp_v0 != 0) {
            var_s0->unk-6 = (s32) (var_s0->unk-6 + 1);
            temp_v0_2 = *var_s2;
            temp_v0_3 = temp_v0_2 - 1;
            if (temp_v0_2 != 0) {
                *var_s2 = temp_v0_3;
                if (temp_v0_3 == 0) {
                    func_8002EFF8(1, *((var_s0->unk0 * 4) + D_80073140));
                    func_800316F8(var_s2);
                    var_s3 += 0x48;
                } else {
                    goto block_58;
                }
            } else {
                temp_v1 = var_s0->unk44;
                if (temp_v1 >= 2U) {
                    var_s0->unk44 = (u8) (temp_v1 - 1);
                } else {
                    temp_a0 = var_s0->unk0;
                    temp_v1_2 = *(&D_800A4EFE + temp_a0);
                    if (temp_v1_2 != 2) {
                        if ((s32) temp_v1_2 < 3) {
                            if (temp_v1_2 != 0) {

                            } else {
                                goto block_13;
                            }
                        } else if (temp_v1_2 == 3) {
                            var_s0->unk46 = 0U;
                            func_8002EFF8(0, *((var_s0->unk0 * 4) + D_80073140));
block_13:
                            temp_v0_4 = var_s0->unk36;
                            var_s0->unk44 = 0U;
                            if (temp_v0_4 != 0) {
                                temp_v0_4(var_s0->unk47, var_s0->unk3A);
                            }
                            var_s0->unk36 = 0;
                        }
                    } else if (var_s0->unk46 != 0) {
                        func_8003D3B4(temp_a0, 1);
                        var_s0->unk46 = 0U;
                    }
                }
                if (var_s0->unk42 != 0) {
                    temp_v0_5 = var_s0->unk40 - 0x220;
                    var_s0->unk40 = temp_v0_5;
                    var_s1 = 1;
                    if ((temp_v0_5 << 0x10) <= 0) {
                        var_s0->unk40 = 0U;
                        var_s0->unk42 = 0U;
                        var_s0->unk46 = 1U;
                        *(&D_800A4C6D + var_s3) = 1;
                        func_8002EFF8(0, *((var_s0->unk0 * 4) + D_80073140));
                    }
                }
                if (var_s0->unk45 != 0) {
                    var_s1 = 1;
                    var_s0->unk45 = 0U;
                }
                if (var_s0->unk2D & 2) {
                    if (var_s0->unk12 >= 0) {
                        temp_v0_6 = var_s0->unkE + var_s0->unk28;
                        var_s0->unkE = temp_v0_6;
                        var_v0 = temp_v0_6 < var_s0->unk12;
                    } else {
                        temp_v0_7 = var_s0->unkE - var_s0->unk28;
                        var_s0->unkE = temp_v0_7;
                        var_v0 = var_s0->unk12 < temp_v0_7;
                    }
                    var_s1 = 1;
                    if (var_v0 == 0) {
                        var_s0->unkE = var_s0->unk12;
                        var_s0->unk2D = (u8) (var_s0->unk2D & 0xFD);
                    }
                }
                var_v0_2 = var_s1 & 0xFF;
                if (((D_800A4F19 != 0) && (var_v0_2 = var_s1 & 0xFF, (var_s0->unk49 != 0))) || (var_v0_2 != 0)) {
                    var_a3 = var_s0->unk2B;
                    temp_a0_2 = var_s1 & 0xFF;
                    if (var_a3 != 0) {
                        temp_v1_3 = var_a3 + ((s32) var_s0->unkE >> 8);
                        temp_v0_8 = var_s0->unk49;
                        var_a3 = temp_v1_3;
                        if (temp_v0_8 != 0) {
                            temp_v1_4 = temp_v0_8 + temp_v1_3;
                            var_a3 = 1;
                            if (temp_v1_4 >= 0x42) {
                                temp_v0_9 = temp_v1_4 - 0x40;
                                var_a3 = temp_v0_9;
                                if ((s16) temp_v0_9 >= 0x80) {
                                    var_a3 = 0x7F;
                                }
                            }
                        }
                    }
                    if ((temp_a0_2 != 0) || ((s16) var_a3 != var_s0->unk48)) {
                        var_a1 = (u32) (((u32) (*(D_8006AA30 + (var_s0->unk2A * 2)) * temp_s7->unk0) >> 7) * var_s0->unk3E) >> 7;
                        if (temp_a0_2 != 0) {
                            var_a1 = (u32) (var_a1 * ((s32) (var_s0->unk40 << 0x10) >> 0x17)) >> 8;
                        }
                        temp_a0_3 = var_s3 + (temp_s7 - 0x2D2);
                        temp_a0_3->unk0 = (s32) *((var_s0->unk0 * 4) + D_80073140);
                        var_v0_3 = var_a1;
                        if ((s16) var_a3 != 0) {
                            if (temp_s7->unk1F != 0) {
                                temp_a0_3->unk8 = (s16) ((u32) (var_a1 * *(((0x7F - (s16) var_a3) * 2) + D_800731A0)) >> 0xE);
                                temp_a0_3->unkA = (s16) ((u32) (var_a1 * *(((s16) var_a3 * 2) + D_8007319E)) >> 0xE);
                            } else {
                                var_v0_3 = (u32) (var_a1 * D_8007321E) >> 0xE;
                                goto block_45;
                            }
                        } else {
block_45:
                            temp_a0_3->unkA = (s16) var_v0_3;
                            temp_a0_3->unk8 = (s16) var_v0_3;
                        }
                        temp_a0_3->unk40 = (s32) var_s0->unk0;
                        if (temp_a0_3->unk44 != 0) {
                            var_v0_4 = temp_a0_3->unk4 | 3;
                        } else {
                            temp_a0_3->unk44 = 1U;
                            var_v0_4 = 3;
                        }
                        temp_a0_3->unk4 = var_v0_4;
                        var_s0->unk48 = var_a3;
                    }
                }
                func_800314DC(var_s2);
                temp_v0_10 = var_s0->unk8;
                temp_v0_11 = temp_v0_10 - 1;
                if (temp_v0_10 != 0) {
                    var_s0->unk8 = temp_v0_11;
                    if (!(temp_v0_11 & 0xFFFF)) {
                        func_80031988(var_s2);
                        var_s0->unk46 = 0U;
                        func_8002EFF8(0, *((var_s0->unk0 * 4) + D_80073140));
                        temp_v0_12 = var_s0->unk36;
                        if (temp_v0_12 != 0) {
                            temp_v0_12(var_s0->unk47, var_s0->unk3A);
                        }
                        var_s0->unk36 = 0;
                    }
                }
                goto block_58;
            }
        } else {
            temp_a0_4 = var_s0->unk0;
            temp_v1_5 = *(&D_800A4EFE + temp_a0_4);
            if ((temp_v1_5 == 0) || (temp_v1_5 == 3)) {
                D_800C7D2C &= ~*((temp_a0_4 * 4) + D_80073140);
            }
block_58:
            var_s3 += 0x48;
        }
        var_s5 += 1;
        var_s0 += 0x54;
        var_s2 += 0x54;
    } while (var_s5 < 8);
}
