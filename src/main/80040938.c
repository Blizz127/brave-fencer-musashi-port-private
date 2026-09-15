/* Main-exec range [80040938,80040DE8) from the SLUS executable.
 * SHA256(span)=f8fc3a5e4b65a8cc774b7cf5171519fb1c30b81be115c26a90d5c84a716c9827.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern u16 D_80078D8C;
extern u16 D_80078D8E;
extern u16 D_80078D90;
extern u16 D_80078D92;
extern s32 *D_8007958C;
extern s32 *D_800A4620;
extern s16 D_800A6434;
extern void *D_800A6580;
extern u8 D_800B9B24;
extern u8 D_800B9B25;
extern u8 D_800B9B2A;
extern u8 D_800B9B2B;
extern u8 D_800B9B2D;
extern u8 D_800B9B2E;
extern u8 D_800B9B34;
extern u16 D_800B9B36;
extern s16 D_800B9B3A;
extern s32 *D_800B9B5C;
extern s32 *D_800C73D8;
extern u16 D_800C7F04;
extern u16 D_800C7F06;

void func_80040938(s16 arg1) {
    s32 temp_a0;
    s32 temp_hi;
    s32 temp_hi_10;
    s32 temp_hi_11;
    s32 temp_hi_2;
    s32 temp_hi_3;
    s32 temp_hi_4;
    s32 temp_hi_5;
    s32 temp_hi_6;
    s32 temp_hi_7;
    s32 temp_hi_8;
    s32 temp_hi_9;
    s32 temp_lo;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 var_a1_2;
    s32 var_a2_2;
    u16 temp_a0_2;
    u16 temp_v0;
    u16 temp_v1_2;
    u16 temp_v1_3;
    u32 var_a1;
    u32 var_a2;
    u32 var_a3;
    void *temp_v1;

    temp_lo = ((D_800B9B24 * (D_800A6580->unk18 * 0x3FFF)) / 16129) * D_800B9B2A * D_800B9B2D;
    temp_hi = MULTU_HI(temp_lo, 0x040C2051);
    var_a2 = (u32) (temp_hi + ((u32) (temp_lo - temp_hi) >> 1)) >> 0xD;
    temp_v1 = *(&D_800C73D8 + ((D_800B9B36 & 0xFF) * 4)) + (((u32) (D_800B9B36 << 0x10) >> 0x18) * 0xB0);
    var_a3 = var_a2;
    if ((s16) D_800B9B36 != 0x21) {
        temp_v0 = temp_v1->unk58;
        temp_v1_2 = temp_v1->unk5A;
        temp_hi_2 = (var_a2 * temp_v0) / 127;
        temp_hi_3 = (var_a2 * temp_v1_2) / 127;
        var_a3 = (u32) (temp_hi_2 + ((u32) ((var_a2 * temp_v0) - temp_hi_2) >> 1)) >> 6;
        var_a2 = (u32) (temp_hi_3 + ((u32) ((var_a2 * temp_v1_2) - temp_hi_3) >> 1)) >> 6;
    }
    if ((u8) D_800B9B2E < 0x40U) {
        temp_hi_4 = (var_a2 * D_800B9B2E) / 63;
        var_a1 = var_a3;
        var_a2 = (u32) (temp_hi_4 + ((u32) ((var_a2 * D_800B9B2E) - temp_hi_4) >> 1)) >> 5;
    } else {
        temp_v0_2 = 0x7F - D_800B9B2E;
        temp_hi_5 = (var_a3 * temp_v0_2) / 63;
        var_a1 = (u32) (temp_hi_5 + ((u32) ((var_a3 * temp_v0_2) - temp_hi_5) >> 1)) >> 5;
    }
    if ((u8) D_800B9B2B < 0x40U) {
        temp_hi_6 = (var_a2 * D_800B9B2B) / 63;
        var_a2 = (u32) (temp_hi_6 + ((u32) ((var_a2 * D_800B9B2B) - temp_hi_6) >> 1)) >> 5;
    } else {
        temp_v0_3 = 0x7F - D_800B9B2B;
        temp_hi_7 = (var_a1 * temp_v0_3) / 63;
        var_a1 = (u32) (temp_hi_7 + ((u32) ((var_a1 * temp_v0_3) - temp_hi_7) >> 1)) >> 5;
    }
    if ((u8) D_800B9B25 < 0x40U) {
        temp_hi_8 = (var_a2 * D_800B9B25) / 63;
        var_a2 = (u32) (temp_hi_8 + ((u32) ((var_a2 * D_800B9B25) - temp_hi_8) >> 1)) >> 5;
    } else {
        temp_v0_4 = 0x7F - D_800B9B25;
        temp_hi_9 = (var_a1 * temp_v0_4) / 63;
        var_a1 = (u32) (temp_hi_9 + ((u32) ((var_a1 * temp_v0_4) - temp_hi_9) >> 1)) >> 5;
    }
    if (D_800A6434 == 1) {
        if (var_a1 < var_a2) {
            var_a1 = var_a2;
        } else {
            var_a2 = var_a1;
        }
    }
    temp_hi_10 = (var_a1 * var_a1) / 16383;
    temp_hi_11 = (var_a2 * var_a2) / 16383;
    temp_a0 = ((D_800B9B3A * 8) & 0xFFFF) * 2;
    *(&D_800B9B5C + temp_a0) = arg1;
    *(temp_a0 + (&D_800B9B5C - 4)) = (s16) ((u32) (temp_hi_10 + ((u32) ((var_a1 * var_a1) - temp_hi_10) >> 1)) >> 0xD);
    *(temp_a0 + (&D_800B9B5C - 2)) = (s16) ((u32) (temp_hi_11 + ((u32) ((var_a2 * var_a2) - temp_hi_11) >> 1)) >> 0xD);
    *(&D_800A4620 + D_800B9B3A) = *(&D_800A4620 + D_800B9B3A) | 7;
    *(&D_8007958C + (D_800B9B3A * 0x34)) = arg1;
    if (D_800B9B3A < 0x10) {
        var_a2_2 = 1 << D_800B9B3A;
        var_a1_2 = 0;
    } else {
        var_a2_2 = 0;
        var_a1_2 = 1 << (D_800B9B3A - 0x10);
    }
    if (D_800B9B34 & 4) {
        D_80078D90 |= var_a2_2;
        D_80078D92 |= var_a1_2;
    } else {
        D_80078D90 &= ~var_a2_2;
        D_80078D92 &= ~var_a1_2;
    }
    temp_v1_3 = D_80078D8C | var_a2_2;
    D_80078D8C = temp_v1_3;
    D_800C7F04 &= ~temp_v1_3;
    temp_a0_2 = D_80078D8E | var_a1_2;
    D_80078D8E = temp_a0_2;
    D_800C7F06 &= ~temp_a0_2;
}
