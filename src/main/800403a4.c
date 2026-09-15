/* Main-exec range [800403A4,80040868) from the SLUS executable.
 * SHA256(span)=1b12d44fd58f02a737cdf03a874a4d9c5c815fe0b19ad60156c14146cbc75e15.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006B8FC;
extern u16 D_80078D8C;
extern u16 D_80078D8E;
extern u16 D_80078D90;
extern u16 D_80078D92;
extern s32 *D_8007958C;
extern s32 *D_800795A3;
extern s32 *D_800A4620;
extern s16 D_800A6434;
extern u8 D_800AE614;
extern u8 D_800B9B22;
extern u8 D_800B9B25;
extern u8 D_800B9B2A;
extern u8 D_800B9B2B;
extern u8 D_800B9B2D;
extern u8 D_800B9B2E;
extern u8 D_800B9B30;
extern u8 D_800B9B34;
extern u16 D_800B9B36;
extern s32 *D_800B9B58;
extern s32 *D_800B9B5A;
extern s32 *D_800C73D8;
extern u16 D_800C7F04;
extern u16 D_800C7F06;

void func_800403A4(s32 arg0) {
    s16 temp_v1_2;
    s16 var_a1_2;
    s16 var_a2_2;
    s16 var_a3;
    s32 temp_a1;
    s32 temp_a3;
    s32 temp_hi;
    s32 temp_hi_10;
    s32 temp_hi_2;
    s32 temp_hi_3;
    s32 temp_hi_4;
    s32 temp_hi_5;
    s32 temp_hi_6;
    s32 temp_hi_7;
    s32 temp_hi_8;
    s32 temp_hi_9;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v1;
    s32 var_v1;
    u16 temp_a0_3;
    u16 temp_v1_3;
    u32 temp_a0_2;
    u32 temp_a1_2;
    u32 temp_a3_2;
    u32 temp_a3_3;
    u32 var_a1;
    u32 var_a2;
    void *temp_a0;

    temp_a0 = *(&D_800C73D8 + ((D_800B9B36 & 0xFF) * 4)) + (((u16) D_800B9B36 >> 8) * 0xB0);
    temp_a1 = temp_a0->unk58 * 0x81;
    temp_a3 = temp_a0->unk5A * 0x81;
    temp_hi = (temp_a1 * D_800B9B2A) / 127;
    temp_hi_2 = (temp_a3 * D_800B9B2A) / 127;
    temp_a1_2 = (u32) (temp_hi + ((u32) ((temp_a1 * D_800B9B2A) - temp_hi) >> 1)) >> 6;
    temp_a3_2 = (u32) (temp_hi_2 + ((u32) ((temp_a3 * D_800B9B2A) - temp_hi_2) >> 1)) >> 6;
    temp_hi_3 = (temp_a1_2 * D_800B9B2D) / 127;
    temp_hi_4 = (temp_a3_2 * D_800B9B2D) / 127;
    var_a1 = (u32) (temp_hi_3 + ((u32) ((temp_a1_2 * D_800B9B2D) - temp_hi_3) >> 1)) >> 6;
    temp_a3_3 = (u32) (temp_hi_4 + ((u32) ((temp_a3_2 * D_800B9B2D) - temp_hi_4) >> 1)) >> 6;
    if ((u8) D_800B9B2E < 0x40U) {
        temp_hi_5 = (temp_a3_3 * D_800B9B2E) / 63;
        var_a2 = (u32) (temp_hi_5 + ((u32) ((temp_a3_3 * D_800B9B2E) - temp_hi_5) >> 1)) >> 5;
    } else {
        temp_v0 = 0x7F - D_800B9B2E;
        temp_hi_6 = (var_a1 * temp_v0) / 63;
        var_a2 = temp_a3_3;
        var_a1 = (u32) (temp_hi_6 + ((u32) ((var_a1 * temp_v0) - temp_hi_6) >> 1)) >> 5;
    }
    if ((u8) D_800B9B2B < 0x40U) {
        temp_hi_7 = (var_a2 * D_800B9B2B) / 63;
        var_a2 = (u32) (temp_hi_7 + ((u32) ((var_a2 * D_800B9B2B) - temp_hi_7) >> 1)) >> 5;
    } else {
        temp_v0_2 = 0x7F - D_800B9B2B;
        temp_hi_8 = (var_a1 * temp_v0_2) / 63;
        var_a1 = (u32) (temp_hi_8 + ((u32) ((var_a1 * temp_v0_2) - temp_hi_8) >> 1)) >> 5;
    }
    if ((u8) D_800B9B25 < 0x40U) {
        temp_hi_9 = (D_800B9B25 * var_a2) / 63;
        var_a2 = (u32) (temp_hi_9 + ((u32) ((D_800B9B25 * var_a2) - temp_hi_9) >> 1)) >> 5;
    } else {
        temp_v0_3 = 0x7F - D_800B9B25;
        temp_hi_10 = (var_a1 * temp_v0_3) / 63;
        var_a1 = (u32) (temp_hi_10 + ((u32) ((var_a1 * temp_v0_3) - temp_hi_10) >> 1)) >> 5;
    }
    if (D_800A6434 == 1) {
        if (var_a1 < var_a2) {
            var_a1 = var_a2;
        } else {
            var_a2 = var_a1;
        }
    }
    temp_a0_2 = arg0 & 0xFF;
    D_8006B8FC->unk1AA = (u16) ((D_8006B8FC->unk1AA & 0xC0FF) | (((D_800B9B22 - D_800B9B30) & 0x3F) << 8));
    temp_v1 = temp_a0_2 * 0x10;
    *(&D_800B9B5A + temp_v1) = (s16) var_a2;
    *(&D_800B9B58 + temp_v1) = (s16) var_a1;
    *(&D_800A4620 + temp_a0_2) = *(&D_800A4620 + temp_a0_2) | 3;
    if (temp_a0_2 < 0x10U) {
        var_a3 = 1 << temp_a0_2;
        var_a2_2 = 0;
    } else {
        var_a3 = 0;
        var_a2_2 = 1 << (temp_a0_2 - 0x10);
    }
    *(&D_8007958C + ((arg0 & 0xFF) * 0x34)) = 0xA;
    var_a1_2 = 0;
    if (D_800AE614 != 0) {
        var_v1 = 0 << 0x10;
        do {
            temp_v0_4 = (var_v1 >> 0x10) * 0x34;
            temp_v1_2 = var_a1_2 + 1;
            var_a1_2 = temp_v1_2;
            *(&D_800795A3 + temp_v0_4) = *(&D_800795A3 + temp_v0_4) & 1;
            var_v1 = var_a1_2 << 0x10;
        } while (temp_v1_2 < (s32) D_800AE614);
    }
    *(&D_800795A3 + ((arg0 & 0xFF) * 0x34)) = 2;
    temp_v1_3 = D_80078D8C | var_a3;
    temp_a0_3 = D_80078D8E | var_a2_2;
    D_80078D8C = temp_v1_3;
    D_80078D8E = temp_a0_3;
    D_800C7F04 &= ~temp_v1_3;
    D_800C7F06 &= ~temp_a0_3;
    if (D_800B9B34 & 4) {
        D_80078D90 |= var_a3;
        D_80078D92 |= var_a2_2;
    } else {
        D_80078D90 &= ~var_a3;
        D_80078D92 &= ~var_a2_2;
    }
    D_8006B8FC->unk194 = var_a3;
    D_8006B8FC->unk196 = var_a2_2;
}
