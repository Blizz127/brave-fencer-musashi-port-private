/* Main-exec range [80039308,80039B20) from the SLUS executable.
 * SHA256(span)=9b854732a01e70248085c9d91a4916dc29ad84a560d9295f50fcc87c5ad3be4a.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006ABD8;
extern s32 D_8006ACD8;
extern s32 D_8006AF08;
extern s32 D_80073140;
extern s32 *D_8006AB30;
extern u8 *D_800762B0;
extern s32 *D_800762B3;
extern u8 D_800762B4;
extern s32 D_800A2B98;
extern s32 D_800A2BA0;
extern u8 D_800A4F19;
extern s32 *D_800C6DD0;
extern s32 *D_800C6DD4;
extern s32 *D_800C6DDD;
extern s32 D_800C7D20;
extern s32 D_800C7D2C;

void func_80039308(void *arg0, s16 arg1) {
    s32 sp10;
    s16 sp0;
    void *var_a3;
    s16 temp_a0_4;
    s16 var_a2_2;
    s16 var_t0;
    s16 var_t7;
    s16 var_v0_2;
    s16 var_v1;
    s32 *temp_a0_8;
    s32 temp_a0_3;
    s32 temp_a1_2;
    s32 temp_s2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v0_5;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 var_a1_2;
    s32 var_a1_3;
    s32 var_a2;
    s32 var_a3_2;
    s32 var_t0_2;
    s32 var_t1_2;
    s32 var_t3;
    s32 var_t5;
    s32 var_v0;
    s32 var_v0_3;
    s32 var_v0_4;
    s32 var_v0_5;
    s32 var_v0_6;
    s8 var_t8;
    u32 temp_a0;
    u32 temp_a0_5;
    u32 temp_v1;
    u32 var_t2;
    u8 *var_a0;
    u8 *var_a1;
    u8 *var_t1;
    u8 *var_t9;
    u8 temp_a1;
    u8 temp_fp;
    u8 temp_s4;
    u8 temp_s5;
    u8 temp_v0_2;
    void *temp_a0_2;
    void *temp_a0_6;
    void *temp_a0_7;
    void *temp_a2;
    void *temp_a3;
    void *temp_s0;
    void *temp_v0;
    void *var_t4;

    temp_v0 = arg0->unk0;
    arg0->unk0 = (void *) (temp_v0 + 1);
    temp_s5 = temp_v0->unk0;
    arg0->unk0 = (void *) (temp_v0 + 2);
    temp_fp = temp_v0->unk1;
    sp0 = arg1;
    if (temp_fp != 0) {
        if (!((arg0 + arg1)->unk1BA & 1)) {
            temp_s0 = arg0 + ((arg1 * 0x1A) + 0x1A);
            var_t8 = 0;
            temp_s4 = temp_s0->unk0;
            temp_v0_2 = *(arg0->unk1DC + (temp_s4 * 0x10));
            var_t9 = arg0->unk1E0 + (temp_s4 << 9);
            sp10 = (s32) temp_v0_2;
            if (temp_v0_2 != 0) {
                temp_s2 = temp_s5 << 8;
                var_t4 = var_t9 + 1;
                do {
                    if ((s32) temp_s5 >= (s32) var_t4->unk5) {
                        var_t2 = 0x100;
                        if ((s32) var_t4->unk6 >= (s32) temp_s5) {
                            var_t3 = 0;
                            var_t5 = 0;
                            var_t7 = -1;
                            var_t0 = 0;
                            var_a3 = &D_800C6DDD;
                            var_a2 = 1;
                            var_t1 = D_800762B0;
loop_7:
                            temp_v1 = var_t2 & 0xFF;
                            if (var_a3->unk4E != 0) {
                                temp_a1 = var_a3->unk0;
                                temp_a0 = temp_a1 & 0xFF;
                                if (temp_a0 < temp_v1) {
                                    var_t3 = var_a2;
                                    var_t2 = temp_a1 & 0xFF;
                                } else if ((temp_a0 == temp_v1) && (*(&D_800762B3 + var_a2) == 0) && (*var_t1 == 2)) {
                                    var_t3 = var_a2;
                                }
                                var_a2 += 1;
                                var_t1 += 1;
                                var_t0 += 1;
                                var_a3 += 0x60;
                                if (var_t0 < 0x10) {
                                    goto loop_7;
                                }
                            } else {
                                var_t5 = 1;
                                var_t7 = var_t0;
                            }
                            var_v0 = var_t7 << 0x10;
                            if (!(var_t5 & 0xFF)) {
                                var_v1 = 0;
                                if ((u8) *var_t9 >= var_t2) {
                                    var_t7 = (var_t3 & 0xFF) - 1;
                                } else {
                                    var_a1 = D_800762B0;
                                    var_a0 = &D_800762B4;
loop_20:
                                    if ((*var_a1 != 2) || (var_v0_2 = var_v1, (*var_a0 != 0))) {
                                        var_v1 += 1;
                                        var_a1 += 1;
                                        var_a0 += 1;
                                        if (var_v1 >= 0x10) {
                                            var_v0_2 = -1;
                                        } else {
                                            goto loop_20;
                                        }
                                    }
                                    var_t7 = var_v0_2;
                                }
                                var_v0 = var_t7 << 0x10;
                            }
                            temp_v1_2 = var_v0 >> 0x10;
                            if (temp_v1_2 >= 0) {
                                temp_a2 = (temp_v1_2 * 0x60) + &D_800C6DD0;
                                temp_a3 = temp_a2 + 0x10;
                                temp_a2->unkD = (u8) *var_t9;
                                if ((temp_a2->unk5C != 0) && (temp_a2->unk8 == temp_s4) && (temp_a2->unkC == var_t8) && (temp_a2->unk50->unk1EC == arg0->unk1EC)) {
                                    temp_a2->unk14 = 0x13;
                                } else {
                                    temp_v0_3 = var_t4->unk15 - 1;
                                    temp_a0_2 = arg0->unk1DC + ((temp_v0_3 >> 1) * 0x10);
                                    if (temp_v0_3 & 1) {
                                        var_v0_3 = temp_a0_2->unkE * 8;
                                    } else {
                                        var_v0_3 = temp_a0_2->unkC * 8;
                                    }
                                    temp_a3->unk1C = var_v0_3;
                                    temp_a3->unk3A = (u16) var_t4->unkF;
                                    temp_a3->unk4 = 0x6009F;
                                    temp_a3->unk3C = (u16) var_t4->unk11;
                                }
                                temp_a0_3 = (s32) (*(D_8006ACD8 + (((s32) (((s32) (temp_fp * temp_s0->unk1) >> 7) * var_t4->unk1) >> 7) * 2)) * arg0->unk1F2) >> 7;
                                if (D_800A4F19 != 0) {
                                    temp_v0_4 = (temp_s0->unk4 + var_t4->unk2) - 0x40;
                                    var_a1_2 = temp_v0_4;
                                    if (temp_v0_4 < 0) {
                                        var_a1_2 = 0;
                                        goto block_41;
                                    }
                                    var_v0_4 = var_a1_2 << 0x10;
                                    if (temp_v0_4 >= 0x80) {
                                        var_a1_2 = 0x7F;
block_41:
                                        var_v0_4 = var_a1_2 << 0x10;
                                    }
                                    temp_v1_3 = var_v0_4 >> 0x10;
                                    if (temp_v1_3 > 0) {
                                        var_v0_5 = temp_a0_3 * *(D_8006AF08 + ((0x80 - temp_v1_3) * 2)) * 4;
                                    } else {
                                        var_v0_5 = temp_a0_3 << 0x10;
                                    }
                                    var_t1_2 = var_v0_5 >> 0x10;
                                    var_t0_2 = (s32) (temp_a0_3 * *(D_8006AF08 + ((s32) (var_a1_2 << 0x10) >> 0xF)) * 4) >> 0x10;
                                } else {
                                    var_t0_2 = (s32) (temp_a0_3 * 0x2D41) >> 0xE;
                                    var_t1_2 = var_t0_2;
                                }
                                temp_a3->unk8 = (s16) ((u32) ((s16) var_t1_2 * arg0->unk10) >> 0xE);
                                temp_a3->unkA = (s16) ((u32) ((s16) var_t0_2 * arg0->unk10) >> 0xE);
                                temp_a0_4 = temp_s0->unk2;
                                var_a1_3 = temp_s2;
                                if (temp_a0_4 >= 0x41) {
                                    var_a1_3 = temp_s2 + ((temp_a0_4 - 0x40) * var_t4->unkC * 4);
                                } else if (temp_a0_4 < 0x40) {
                                    var_a1_3 = temp_s2 - ((0x40 - temp_a0_4) * var_t4->unkB * 4);
                                }
                                temp_v0_5 = (var_t4->unk3 << 8) - var_t4->unk4;
                                temp_a2->unk54 = temp_v0_5;
                                temp_a0_5 = (var_a1_3 - (temp_v0_5 - 0x3C00)) & 0xFFFF;
                                temp_a2->unk58 = (u8) var_t4->unkB;
                                temp_a2->unk59 = (u8) var_t4->unkC;
                                if (temp_a0_5 >= 0x5301U) {
                                    temp_a3->unk14 = 0x3FFF;
                                } else {
                                    temp_a3->unk14 = (s16) ((u32) (*(&D_8006AB30 + ((temp_a0_5 >> 8) * 2)) * *(D_8006ABD8 + (temp_a0_5 & 0xFE))) >> 0xF);
                                }
                                temp_a2->unk5D = 1;
                                D_800A2B98 &= ~temp_a2->unk10;
                                D_800C7D20 |= temp_a2->unk10;
                                (&D_800762B4)[var_t7] = 1;
                                if (var_t4->unk0 & 4) {
                                    D_800A2BA0 &= ~temp_a2->unk10;
                                    D_800C7D2C |= temp_a2->unk10;
                                    var_v0_6 = var_t7 << 0x10;
                                } else {
                                    D_800C7D2C &= ~temp_a2->unk10;
                                    D_800A2BA0 |= temp_a2->unk10;
                                    var_v0_6 = var_t7 << 0x10;
                                }
                                temp_a1_2 = var_v0_6 >> 0x10;
                                temp_a0_6 = (temp_a1_2 * 0x60) + &D_800C6DD0;
                                if (temp_a0_6->unk5A != 0) {
                                    (temp_a0_6->unk50 + (temp_a0_6->unk6 * 0x1A) + temp_a1_2)->unk23 = 0;
                                    temp_a0_6->unk5A = 0U;
                                }
                                (temp_s0 + temp_a1_2)->unk9 = 1;
                                temp_a0_6->unk4 = (s16) temp_s5;
                                temp_a0_6->unk8 = (s16) temp_s4;
                                temp_a0_6->unkC = var_t8;
                                temp_a0_6->unk5C = 1;
                                temp_a0_6->unk0 = (s16) var_t1_2;
                                temp_a0_6->unk2 = (s16) var_t0_2;
                                temp_a0_6->unk50 = arg0;
                                temp_a0_6->unk5B = 1;
                                temp_a0_6->unk6 = (s16) (u16) sp0;
                                if (arg0->unk1F4 != 0) {
                                    temp_a0_6->unk5A = 2U;
                                } else {
                                    temp_a0_6->unk5A = 1U;
                                }
                            }
                        }
                    }
                    var_t8 += 1;
                    var_t4 += 0x20;
                    var_t9 += 0x20;
                } while (var_t8 < sp10);
            }
        }
    } else {
        var_a2_2 = 0;
        var_a3_2 = 0;
        do {
            if (((arg0 + (arg1 * 0x1A) + var_a2_2)->unk23 != 0) && (*(&D_800C6DD4 + var_a3_2) == temp_s5)) {
                temp_a0_7 = (var_a2_2 * 0x60) + &D_800C6DD0;
                if (temp_a0_7->unk5A != 0) {
                    (temp_a0_7->unk50 + (temp_a0_7->unk6 * 0x1A) + var_a2_2)->unk23 = 0;
                    temp_a0_7->unk5A = 0U;
                }
                temp_a0_8 = (var_a2_2 * 4) + D_80073140;
                D_800C7D20 &= ~*temp_a0_8;
                D_800A2B98 |= *temp_a0_8;
                D_800762B0[var_a2_2] = 2;
                (&D_800762B4)[var_a2_2] = 0;
            }
            var_a2_2 += 1;
            var_a3_2 += 0x60;
        } while (var_a2_2 < 0x10);
    }
}
