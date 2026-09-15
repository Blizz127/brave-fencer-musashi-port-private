/* Main-exec range [80040DE8,80041354) from the SLUS executable.
 * SHA256(span)=cb0830e60c7489b8bce43f38d2aa4d6b4cd2cb8b9f53a0765a2a0695d068b8cb.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 *D_80079590;
extern s32 *D_80079592;
extern s32 *D_80079596;
extern s32 *D_80079598;
extern s32 *D_8007959A;
extern s32 *D_8007959E;
extern s32 *D_800A4620;
extern s16 D_800A6434;
extern s32 D_800A6578;
extern void *D_800A6580;
extern s32 D_800A6584;
extern u8 D_800AE614;
extern s16 D_800B9B36;
extern s32 *D_800B9B58;
extern s32 *D_800C73D8;

s16 func_80040DE8(s16 arg0, u16 arg1, u16 arg2, s32 arg3) {
    s16 temp_a2;
    s16 var_t2;
    s16 var_v0_2;
    s32 temp_a0_4;
    s32 temp_hi;
    s32 temp_hi_2;
    s32 temp_hi_3;
    s32 temp_hi_4;
    s32 temp_hi_5;
    s32 temp_lo;
    s32 temp_t0;
    s32 temp_v0_2;
    s32 temp_v1_5;
    s32 var_v0;
    s32 var_v1;
    u16 temp_v0;
    u16 temp_v1;
    u16 var_a2;
    u16 var_t0;
    u32 temp_a0_2;
    u32 temp_a0_3;
    u32 temp_a3;
    u32 var_a2_2;
    u32 var_t0_2;
    u32 var_v0_3;
    u8 temp_a0;
    u8 temp_v1_2;
    u8 temp_v1_3;
    u8 temp_v1_4;
    void *temp_a2_2;
    void *temp_t1;

    var_a2 = arg2;
    var_t0 = arg1;
    D_800B9B36 = arg0;
    temp_t1 = *(&D_800C73D8 + ((arg0 & 0xFF) * 4)) + (((s32) (arg0 & 0xFF00) >> 8) * 0xB0);
    if (!(var_t0 & 0xFFFF)) {
        var_t0 = 1;
    }
    if (!(var_a2 & 0xFFFF)) {
        var_a2 = 1;
    }
    temp_t1->unk58 = var_t0;
    temp_t1->unk5A = var_a2;
    if ((u16) temp_t1->unk58 >= 0x80U) {
        temp_t1->unk58 = 0x7FU;
    }
    var_v0 = arg3 << 0x10;
    if ((u16) temp_t1->unk5A >= 0x80U) {
        temp_t1->unk5A = 0x7FU;
        var_v0 = arg3 << 0x10;
    }
    if ((var_v0 >> 0x10) == 1) {
        var_t2 = 0;
        if (D_800AE614 != 0) {
            var_v1 = 0 << 0x10;
            do {
                temp_t0 = (var_v1 >> 0x10) * 0x34;
                var_v0_2 = var_t2 + 1;
                if (*(&D_80079596 + temp_t0) == arg0) {
                    temp_a0 = temp_t1->unk17;
                    temp_a2 = *(&D_8007959A + temp_t0);
                    var_v0_2 = var_t2 + 1;
                    if (temp_a2 == (temp_t1 + temp_a0)->unk37) {
                        var_v0_2 = var_t2 + 1;
                        if (*(&D_8007959E + temp_t0) == temp_t1->unk26) {
                            temp_a2_2 = (((*(&D_80079598 + temp_t0) * 0x10) + (temp_t0 + 0x80080000)->unk-6A64) << 5) + D_800A6584;
                            temp_lo = ((D_800A6580->unk18 * (((*(&D_80079590 + temp_t0) * ((temp_a0 * 2) + temp_t1)->unk60) / 127) * 0x3FFF)) / 16129) * ((temp_a2 * 0x10) + D_800A6578)->unk1 * temp_a2_2->unk2;
                            temp_hi = MULTU_HI(temp_lo, 0x040C2051);
                            temp_v0 = temp_t1->unk58;
                            temp_a0_2 = (u32) (temp_hi + ((u32) (temp_lo - temp_hi) >> 1)) >> 0xD;
                            temp_v1 = temp_t1->unk5A;
                            temp_hi_2 = (temp_a0_2 * temp_v0) / 127;
                            temp_hi_3 = (temp_a0_2 * temp_v1) / 127;
                            temp_a3 = (u32) (temp_hi_2 + ((u32) ((temp_a0_2 * temp_v0) - temp_hi_2) >> 1)) >> 6;
                            temp_v1_2 = temp_a2_2->unk3;
                            temp_a0_3 = (u32) (temp_hi_3 + ((u32) ((temp_a0_2 * temp_v1) - temp_hi_3) >> 1)) >> 6;
                            if (temp_v1_2 < 0x40U) {
                                temp_hi_4 = (temp_a0_3 * temp_v1_2) / 63;
                                var_t0_2 = temp_a3;
                                var_a2_2 = (u32) (temp_hi_4 + ((u32) ((temp_a0_3 * temp_v1_2) - temp_hi_4) >> 1)) >> 5;
                            } else {
                                temp_v0_2 = 0x7F - temp_v1_2;
                                temp_hi_5 = (temp_a3 * temp_v0_2) / 63;
                                var_a2_2 = temp_a0_3;
                                var_t0_2 = (u32) (temp_hi_5 + ((u32) ((temp_a3 * temp_v0_2) - temp_hi_5) >> 1)) >> 5;
                            }
                            temp_v1_3 = ((*(&D_8007959A + (var_t2 * 0x34)) * 0x10) + D_800A6578)->unk4;
                            if (temp_v1_3 < 0x40U) {
                                var_a2_2 = ((var_a2_2 & 0xFFFF) * temp_v1_3) / 63;
                            } else {
                                var_t0_2 = ((var_t0_2 & 0xFFFF) * (0x7F - temp_v1_3)) / 63;
                            }
                            temp_v1_4 = *(&D_80079592 + (var_t2 * 0x34));
                            if (temp_v1_4 < 0x40U) {
                                var_a2_2 = ((var_a2_2 & 0xFFFF) * temp_v1_4) / 63;
                            } else {
                                var_t0_2 = ((var_t0_2 & 0xFFFF) * (0x7F - temp_v1_4)) / 63;
                            }
                            var_v0_3 = var_t0_2 & 0xFFFF;
                            if (D_800A6434 == 1) {
                                if (var_v0_3 < (u32) (var_a2_2 & 0xFFFF)) {
                                    var_t0_2 = var_a2_2;
                                } else {
                                    var_a2_2 = var_t0_2;
                                }
                                var_v0_3 = var_t0_2 & 0xFFFF;
                            }
                            temp_a0_4 = var_a2_2 & 0xFFFF;
                            temp_v1_5 = var_t2 * 0x10;
                            *(temp_v1_5 + &D_800B9B58) = (var_v0_3 * var_v0_3) / 16383;
                            *(temp_v1_5 + (&D_800B9B58 + 2)) = (temp_a0_4 * temp_a0_4) / 16383;
                            *(&D_800A4620 + var_t2) = *(&D_800A4620 + var_t2) | 3;
                            var_v0_2 = var_t2 + 1;
                        }
                    }
                }
                var_t2 = var_v0_2;
                var_v1 = var_t2 << 0x10;
            } while (var_v0_2 < (s32) D_800AE614);
        }
    }
    return D_800B9B36;
}
