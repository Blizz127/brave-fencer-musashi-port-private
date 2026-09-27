/* Overlay range [80166690,80166994) from MAIN.CD member 0012.
 * SHA256(span)=8195645327c4b904a9c81ad8862d39ac1c7b68381c3c7fd0dfb2d90e35772ff3.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80017758(u16 *, s32 *);                /* extern */
extern s32 D_80184418;
extern s32 *D_800AE620;

s16 func_80166690(s16 arg0, s16 arg1) {
    s32 sp64;
    s32 sp60;
    s32 sp5C;
    s32 sp58;
    s32 sp54;
    s32 sp50;
    s32 sp4C;
    s32 sp48;
    s32 sp40;
    u8 sp3E;
    u8 sp3D;
    u8 sp3C;
    u8 sp3A;
    u8 sp39;
    u8 sp38;
    u8 sp36;
    u8 sp35;
    u8 sp34;
    u8 sp32;
    u8 sp31;
    u8 sp30;
    u16 sp2C;
    u16 sp2A;
    u16 sp28;
    u16 sp24;
    u16 sp22;
    u16 sp20;
    u16 sp1C;
    u16 sp1A;
    u16 sp18;
    u16 sp14;
    u16 sp12;
    u16 sp10;
    s16 temp_v0;
    s16 temp_v1;
    s16 var_s3;
    s16 var_s4;
    s32 temp_s6;
    s32 temp_v0_2;
    s32 var_v1;
    s32 var_v1_2;
    u32 temp_v0_4;
    u32 temp_v1_3;
    u32 var_s0;
    u32 var_v0;
    u32 var_v0_2;
    u8 temp_v0_3;
    u8 var_s1;
    u8 var_s2;
    void *temp_a1;
    void *temp_s7;
    void *temp_v1_2;
    void *temp_v1_4;

    sp48 = M2C_FIELD(&D_800AE620, s32 *, 0);
    sp4C = M2C_FIELD(&D_800AE620, s32 *, 4);
    sp50 = M2C_FIELD(&D_800AE620, s32 *, 8);
    sp54 = M2C_FIELD(&D_800AE620, s32 *, 0xC);
    sp58 = M2C_FIELD(&D_800AE620, s32 *, 0x10);
    sp5C = M2C_FIELD(&D_800AE620, s32 *, 0x14);
    sp60 = M2C_FIELD(&D_800AE620, s32 *, 0x18);
    sp64 = M2C_FIELD(&D_800AE620, s32 *, 0x1C);
    sp40 = 0x50000000;
    temp_a1 = (arg0 * 0xC4) + D_80184418;
    var_s4 = 0;
    if (M2C_FIELD(temp_a1, u8 *, 0) == 0) {
        return 0;
    }
    temp_s7 = temp_a1 + 4;
    var_s2 = M2C_FIELD(temp_a1, u8 *, 1);
    var_s1 = M2C_FIELD(temp_a1, u8 *, 3);
    var_s0 = var_s1 >> 1;
    temp_v1 = M2C_FIELD(temp_a1, u8 *, 2) - 1;
    var_s3 = temp_v1;
    if (temp_v1 != -1) {
        temp_s6 = arg0 < 2;
        var_v1 = var_s2 << 0x10;
        do {
            temp_v1_2 = temp_s7 + ((var_v1 >> 0x10) * 0xC);
            sp10 = M2C_FIELD(temp_v1_2, u16 *, 0);
            sp12 = M2C_FIELD(temp_v1_2, u16 *, 2);
            sp14 = M2C_FIELD(temp_v1_2, u16 *, 4);
            sp18 = M2C_FIELD(temp_v1_2, u16 *, 6);
            sp1A = M2C_FIELD(temp_v1_2, u16 *, 8);
            var_s4 += 1;
            sp1C = M2C_FIELD(temp_v1_2, u16 *, 0xA);
            if (temp_s6 != 0) {
                if (arg1 == 0) {
                    sp36 = var_s1;
                    sp32 = var_s1;
                    var_v0 = var_s0;
                } else {
                    temp_v0_2 = var_s1 << 0x10;
                    temp_v1_3 = (temp_v0_2 >> 0x11) + (temp_v0_2 >> 0x13);
                    var_s0 = temp_v1_3;
                    var_v0 = (u32) var_s1;
                    sp36 = (u8) temp_v1_3;
                    sp32 = (u8) temp_v1_3;
                }
                sp35 = (u8) var_v0;
                sp31 = (u8) var_v0;
                sp34 = (u8) var_v0;
                sp30 = (u8) var_v0;
            } else {
                sp34 = var_s1;
                sp30 = var_s1;
                sp36 = (u8) var_s0;
                sp32 = (u8) var_s0;
                sp35 = (u8) var_s0;
                sp31 = (u8) var_s0;
            }
            temp_v0_3 = var_s2 - 1;
            var_s2 = temp_v0_3;
            var_v1_2 = var_s2 << 0x10;
            if (temp_v0_3 & 0x8000) {
                var_s2 = 0xF;
                var_v1_2 = 0xF << 0x10;
            }
            temp_v1_4 = temp_s7 + ((var_v1_2 >> 0x10) * 0xC);
            sp20 = M2C_FIELD(temp_v1_4, u16 *, 0);
            sp22 = M2C_FIELD(temp_v1_4, u16 *, 2);
            sp24 = M2C_FIELD(temp_v1_4, u16 *, 4);
            sp28 = M2C_FIELD(temp_v1_4, u16 *, 6);
            var_s1 -= 0x10;
            sp2A = M2C_FIELD(temp_v1_4, u16 *, 8);
            temp_v0_4 = var_s0 - 0x10;
            var_s0 = temp_v0_4;
            sp2C = M2C_FIELD(temp_v1_4, u16 *, 0xA);
            if (temp_v0_4 & 0x8000) {
                var_s0 = 0;
            }
            if (temp_s6 != 0) {
                if (arg1 == 0) {
                    sp3E = var_s1;
                    sp3A = var_s1;
                    var_v0_2 = var_s0;
                } else {
                    sp3E = (u8) var_s0;
                    sp3A = (u8) var_s0;
                    var_v0_2 = (u32) var_s1;
                }
                sp3D = (u8) var_v0_2;
                sp39 = (u8) var_v0_2;
                sp3C = (u8) var_v0_2;
                sp38 = (u8) var_v0_2;
            } else {
                sp3C = var_s1;
                sp38 = var_s1;
                sp3E = (u8) var_s0;
                sp3A = (u8) var_s0;
                sp3D = (u8) var_s0;
                sp39 = (u8) var_s0;
            }
            func_80017758(&sp10, &sp48);
            temp_v0 = var_s3 - 1;
            var_s3 = temp_v0;
            var_v1 = var_s2 << 0x10;
        } while (temp_v0 != -1);
    }
    return var_s4;
}
