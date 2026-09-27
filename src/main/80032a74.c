/* Exact retail word export for [80032A74,8003310C); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80064D44;
extern s32 D_8006A970;
extern s32 D_8006AA30;
extern s32 D_8006AB32;
extern s32 D_8006AED8;
extern s32 D_80073140;
extern s32 D_8007319E;
extern s32 D_800731A0;
extern s32 *D_8007321E;
void func_8002EFF8(s32, s32);                            /* static */
void func_8002F064(s32, s32);                            /* static */
s32 func_80030CA4(u16, u32);                        /* static */
void func_800316F8(void *);                            /* static */
extern s32 func_80033324;
s32 func_8003F144(s16, s32, u8, void *);               /* static */
s32 func_8003F380(s16, s16);                        /* static */
extern s32 *D_8006AB30;
extern s32 *D_800A4646;
extern s16 D_800A46A2;
extern s32 *D_800A4988;
extern s32 *D_800A4C28;
extern s16 D_800A4EF6;
extern s16 D_800A4EFA;
extern u8 D_800A4F19;
extern u8 D_800A4F1E;
extern s32 *D_800C5328;
extern s32 *D_800C532A;

void func_80032A74(void *arg0, s32 arg1, void *arg2, s32 arg3) {
    void *sp40;
    s32 sp38;
    void *sp30;
    s32 sp10;
    s32 var_a0_2;
    s16 var_s2;
    s16 var_v0_4;
    s32 temp_a0_3;
    s32 temp_a1_3;
    s32 temp_s5;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v1_3;
    s32 temp_v1_4;
    s32 var_s6;
    s32 var_v0_2;
    s32 var_v0_3;
    s32 var_v1;
    s8 var_fp;
    u16 temp_a0_2;
    u16 temp_v0_3;
    u16 var_s7;
    u16 var_v0_5;
    u32 temp_a0_4;
    u32 temp_a1;
    u32 temp_a1_2;
    u32 temp_v0_5;
    u8 temp_a0;
    u8 temp_s4;
    u8 temp_v0_4;
    u8 var_a0;
    u8 var_s2_2;
    void *temp_s0;
    void *temp_s1;
    void *temp_v1;
    void *temp_v1_2;
    void *var_s3;
    void *var_v0;

    var_s6 = arg3;
    var_v1 = 7;
    var_v0 = arg0 + 7;
    sp30 = arg0;
    sp38 = arg1;
    sp40 = arg2;
    var_s7 = arg0->unk2;
    do {
        var_v0->unkE = 0;
        var_v1 -= 1;
        var_v0 -= 1;
    } while (var_v1 >= 0);
    sp30->unkC = 0U;
    var_s3 = sp40 + 0xB;
loop_3:
    temp_s4 = var_s3->unk-3;
    var_fp = 0;
    if (!(temp_s4 & 0x80)) {
        temp_v1 = (temp_s4 * 0xC) + D_80064D44;
        temp_a0 = var_s3->unk-2;
        var_v0_2 = temp_s4 * 4;
        if (temp_v1->unk6 != 0) {
            var_fp = temp_a0 < (u8) temp_v1->unk7;
            var_v0_2 = temp_s4 * 4;
        }
        var_s2 = *(&D_800C5328 + var_v0_2);
        if (var_s2 < 0) {
            if (var_fp != 0) {
                var_s2 = *(&D_800C532A + var_v0_2);
                if (var_s2 >= 0) {
                    var_v0_3 = var_s6 & 0x1000;
                    if ((s32) temp_a0 < *(&D_800A4646 + (var_s2 * 0x18))) {
                        goto block_13;
                    }
                }
            }
        } else {
            goto block_12;
        }
    } else {
        var_s2 = 4;
block_12:
        var_v0_3 = var_s6 & 0x1000;
block_13:
        temp_a1 = var_s6 & 0x7F;
        if ((var_v0_3 != 0) && (temp_a1 < 0x30U)) {
            var_s7 = (u16) (var_s7 >> 1);
            var_s6 = (var_s6 & 0xFF80) | (0x2F - ((s32) (0x2F - temp_a1) >> 1));
        }
        temp_v0 = func_80030CA4(var_s7, temp_a1);
        temp_s5 = temp_v0 - 1;
        if (temp_v0 != 0) {
            temp_s1 = (temp_s5 * 0x48) + &D_800A4C28;
            if (!(temp_s4 & 0x80)) {
                temp_v1_2 = *(D_8006A970 + (var_s2 * 4)) + (var_s3->unk-2 * 0xC);
                temp_s1->unk1C = (s32) temp_v1_2->unk0;
                temp_s1->unk18 = (u16) temp_v1_2->unk4;
                temp_s1->unk3A = (u16) temp_v1_2->unk6;
                temp_s1->unk3C = (u16) temp_v1_2->unk8;
                goto block_22;
            }
            if ((func_8003F144(D_800A46A2, temp_s4 & 0x7F, var_s3->unk-2, &sp10) << 0x10) == 0) {
                temp_v0_2 = func_8003F380(D_800A46A2, sp26);
                if (temp_v0_2 >= 0) {
                    temp_s1->unk1C = temp_v0_2;
                    temp_s1->unk18 = (u16) (sp14 << 8);
                    temp_s1->unk3A = sp20;
                    temp_s1->unk3C = sp22;
block_22:
                    temp_a0_2 = temp_s5 + 0x10;
                    temp_s1->unk0 = (s32) *(D_80073140 + (temp_a0_2 * 4));
                    temp_s0 = (temp_s5 * 0x54) + &D_800A4988;
                    temp_s0->unk4C = 0;
                    temp_s0->unk4A = 0x7FFF;
                    if (sp30->unk0 & 0x80) {
                        temp_s0->unk4D = 0;
                    } else {
                        temp_s0->unk4D = 1;
                    }
                    temp_s0->unk4 = 0;
                    temp_s0->unk8 = var_s7;
                    temp_s0->unkA = temp_a0_2;
                    temp_s0->unk0 = (s32) var_s3->unk-9;
                    temp_s0->unkE = (s16) temp_s4;
                    temp_s0->unk36 = var_fp;
                    temp_s0->unk10 = var_s2;
                    temp_s0->unk12 = 0;
                    temp_s0->unkC = (s16) var_s3->unk-2;
                    temp_s0->unk4F = 0;
                    temp_s0->unk4E = 0x85;
                    temp_s0->unk14 = (s32) var_s3->unk5;
                    var_a0 = var_s3->unk-5;
                    if (D_800A4F1E != 0) {
                        var_a0 = (u8) ((u32) (var_a0 * 0x70) >> 7);
                    }
                    var_v0_4 = var_s6 & 0x7F;
                    if (!(var_s6 & 0x1000)) {
                        var_v0_4 = 0x7F;
                    }
                    temp_s0->unk48 = var_v0_4;
                    temp_s0->unk34 = (u8) (var_a0 & 0x7F);
                    var_s2_2 = var_s3->unk-4;
                    temp_s0->unk35 = var_s2_2;
                    if (var_s6 & 0x8000) {
                        var_v0_5 = var_s3->unk-7 - 0x80;
                    } else {
                        var_v0_5 = var_s3->unk-7;
                    }
                    temp_s0->unk24 = (s32) var_v0_5;
                    temp_s0->unk40 = func_80033324;
                    temp_s0->unk44 = sp38;
                    if ((var_s6 & 0x2000) && (var_s2_2 & 0xFF)) {
                        if ((var_s6 & 0x3000) == 0x3000) {
                            temp_s0->unk53 = (u8) *(D_8006AED8 + ((u32) (var_s6 & 0xF00) >> 8));
                        } else {
                            temp_s0->unk53 = (u8) (var_s6 & 0x7F);
                        }
                    } else {
                        temp_s0->unk53 = 0U;
                    }
                    if (var_s3->unk-9 == 0) {
                        func_800316F8(temp_s0);
                    }
                    temp_v0_3 = temp_s1->unk18;
                    temp_a1_2 = temp_s0->unk24 - (((temp_v0_3 & 0xFF00) + ((s32) (temp_v0_3 << 0x18) >> 0x17)) - 0x3C00);
                    if (temp_a1_2 >= 0x5300U) {
                        temp_s1->unk14 = 0x3FFF;
                    } else {
                        temp_a0_3 = (temp_a1_2 >> 8) * 2;
                        temp_a1_3 = temp_a1_2 & 0xFF;
                        temp_s1->unk14 = (s16) ((u32) ((*(&D_8006AB30 + temp_a0_3) * (0x100 - temp_a1_3)) + (*(D_8006AB32 + temp_a0_3) * temp_a1_3)) >> 8);
                    }
                    temp_a0_4 = (u32) (((u32) (*(D_8006AA30 + (temp_s0->unk34 * 2)) * D_800A4EFA) >> 7) * temp_s0->unk48) >> 7;
                    if (var_s2_2 & 0xFF) {
                        temp_v0_4 = temp_s0->unk53;
                        temp_v1_3 = var_s2_2 + temp_v0_4;
                        if (temp_v0_4 != 0) {
                            var_s2_2 = 1;
                            if ((u32) (temp_v1_3 & 0xFF) >= 0x42U) {
                                var_s2_2 = temp_v1_3 - 0x40;
                                if ((u32) (var_s2_2 & 0xFF) >= 0x80U) {
                                    var_s2_2 = 0x7F;
                                }
                            }
                        }
                        temp_v1_4 = var_s2_2 & 0xFF;
                        if (D_800A4F19 != 0) {
                            temp_s1->unkA = (s16) ((u32) (temp_a0_4 * *((temp_v1_4 * 2) + D_8007319E)) >> 0xE);
                            temp_s1->unk8 = (s16) ((u32) (temp_a0_4 * *(((0x7F - temp_v1_4) * 2) + D_800731A0)) >> 0xE);
                        } else {
                            temp_v0_5 = (u32) (temp_a0_4 * D_8007321E) >> 0xE;
                            temp_s1->unkA = (s16) temp_v0_5;
                            temp_s1->unk8 = (s16) temp_v0_5;
                        }
                    } else {
                        temp_s1->unk8 = (s16) temp_a0_4;
                        temp_s1->unkA = (s16) temp_a0_4;
                    }
                    temp_s0->unk52 = var_s2_2;
                    temp_s1->unkC = 0;
                    temp_s1->unkE = 0;
                    temp_s1->unk4 = 0x6009F;
                    var_a0_2 = 1;
                    if ((s32) var_s3->unk-1 < D_800A4EF6) {

                    } else {
                        var_a0_2 = 0;
                    }
                    func_8002F064(var_a0_2, temp_s1->unk0);
                    temp_s1->unk45 = 0;
                    temp_s1->unk44 = 1;
                    temp_s1->unk40 = (s32) temp_s0->unkA;
                    if (var_s3->unk-9 == 0) {
                        func_8002EFF8(1, temp_s1->unk0);
                    }
                    sp30->unkC = (u16) (sp30->unkC + 1);
                    (sp30 + temp_s5)->unkE = 1;
                }
            }
        }
        var_s3 += 0x14;
        if (var_s3->unk0 != 0) {
            sp40 += 0x14;
            var_s7 = sp40->unk14;
            goto loop_3;
        }
    }
    if (sp30->unkC == 0) {
        sp30->unk0 = 0U;
        return;
    }
    sp30->unkA = 4;
}
