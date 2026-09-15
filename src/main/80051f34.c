/* Main-exec range [80051F34,80052430) from the SLUS executable.
 * SHA256(span)=06d51cc9ea7bedb38dddc5b5e3d2464280f553825ebc803ac847a2049a7260ef.
 * Word export for the native seam (m2c produced no draft). */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8004901C(s32 *, s32 *);                /* static */
void func_8004914C(s32 *);                       /* static */
void func_800491AC(s32 *);                       /* static */
s32 func_800491EC();                                /* static */
void func_8004961C(s16 *, s16 *, s16 *, s16 *, s32 *, s32 *, s32 *, s32 *, void *, void *); /* static */
void func_8004978C(s16 *, s32 *, s32);       /* static */
void *func_80051EA0(void *, s32, s32, s32); /* static */
void func_80052430(s32 *, s32 *);                /* static */
extern void *D_800A5E60;
extern s16 D_800A6548;
extern s16 D_800A654A;
extern s32 *D_800AE620;

void func_80051F34(void *arg0, s32 arg1, s32 arg2) {
    s32 sp94;
    s32 sp90;
    s32 sp8C;
    s32 sp88;
    s32 sp84;
    s32 sp80;
    s16 sp7C;
    s16 sp7A;
    s16 sp78;
    s16 sp74;
    s16 sp72;
    s16 sp70;
    s16 sp6C;
    s16 sp6A;
    s16 sp68;
    s16 sp64;
    s16 sp62;
    s16 sp60;
    s32 sp58;
    s32 sp54;
    s32 sp50;
    s16 sp4C;
    s16 sp4A;
    s16 sp48;
    s32 sp44;
    s32 sp40;
    s32 sp3C;
    s32 sp38;
    s32 sp34;
    s32 sp30;
    s32 sp2C;
    s32 sp28;
    s32 var_a3;
    s16 temp_t0;
    s16 temp_v1_2;
    s32 temp_s1;
    s32 temp_t1;
    s32 temp_t2;
    s32 temp_v0;
    s32 temp_v1;
    s32 temp_v1_5;
    s32 var_a1;
    s32 var_a2;
    s32 var_v0;
    s32 var_v0_2;
    u16 var_v1;
    u8 temp_v1_3;
    u8 temp_v1_4;
    u8 var_t1;
    u8 var_t2;
    u8 var_t3;
    u8 var_t4;
    void *temp_s2;

    temp_s1 = M2C_FIELD(arg0, s32 *, 0);
    if ((temp_s1 >= 0) && (M2C_FIELD(arg0, u16 *, 8) != 0)) {
        var_a1 = 0;
        if (M2C_FIELD(arg0, u16 *, 0xA) != 0) {
            temp_s2 = D_800A5E60;
            temp_v1 = ((u32) temp_s1 >> 0x1B) & 1;
            if (M2C_FIELD(arg0, s32 *, 0x1C) == 0x10001000) {
                var_v0 = temp_v1 | 0;
                if (M2C_FIELD(arg0, s32 *, 0x20) == 0) {
                    var_a1 = (temp_s1 & 0xC00000) == 0;
                    goto block_6;
                }
            } else {
block_6:
                var_v0 = temp_v1 | var_a1;
            }
            if (var_v0 != 0) {
                var_a2 = arg2 & 0xFFFF;
                M2C_FIELD(temp_s2, s32 *, 4) = (s32) ((M2C_FIELD(arg0, u16 *, 0xC) & 0x1F) | ((((u32) temp_s1 >> 0x11) & 0x180) | 0xE1000200) | (((u32) temp_s1 >> 0x17) & 0x60));
                var_a3 = 5;
                M2C_FIELD(temp_s2, s32 *, 8) = (s32) ((((u32) temp_s1 >> 5) & 0x02000000) | (((temp_s1 << 0x12) & 0x01000000) | 0x64000000) | (M2C_FIELD(arg0, u8 *, 0x16) << 0x10) | (M2C_FIELD(arg0, u8 *, 0x15) << 8) | M2C_FIELD(arg0, u8 *, 0x14));
                M2C_FIELD(temp_s2, s32 *, 0xC) = (s32) ((((M2C_FIELD(arg0, s16 *, 4) + D_800A6548) - M2C_FIELD(arg0, s16 *, 0x18)) & 0xFFFF) | (((M2C_FIELD(arg0, s16 *, 6) + D_800A654A) - M2C_FIELD(arg0, s16 *, 0x1A)) << 0x10));
                M2C_FIELD(temp_s2, s32 *, 0x10) = (s32) (M2C_FIELD(arg0, u8 *, 0xE) | (M2C_FIELD(arg0, u8 *, 0xF) << 8) | (M2C_FIELD(arg0, s16 *, 0x12) << 0x16) | ((M2C_FIELD(arg0, s16 *, 0x10) << 0xC) & 0x3F0000));
                var_v1 = M2C_FIELD(arg0, u16 *, 8);
                var_v0_2 = M2C_FIELD(arg0, u16 *, 0xA) << 0x10;
            } else {
                if (M2C_FIELD(arg0, s32 *, 0x20) == 0) {
                    sp28 = M2C_FIELD(&D_800AE620, s32 *, 0);
                    sp2C = M2C_FIELD(&D_800AE620, s32 *, 4);
                    sp30 = M2C_FIELD(&D_800AE620, s32 *, 8);
                    sp34 = M2C_FIELD(&D_800AE620, s32 *, 0xC);
                    sp38 = M2C_FIELD(&D_800AE620, s32 *, 0x10);
                    sp3C = M2C_FIELD(&D_800AE620, s32 *, 0x14);
                    sp40 = M2C_FIELD(&D_800AE620, s32 *, 0x18);
                    sp44 = M2C_FIELD(&D_800AE620, s32 *, 0x1C);
                } else {
                    sp48 = 0;
                    sp4A = 0;
                    sp4C = M2C_FIELD(arg0, s32 *, 0x20) / 360;
                    func_8004978C(&sp48, &sp28, 0xE1000000);
                }
                if (M2C_FIELD(arg0, s32 *, 0x1C) != 0x10001000) {
                    sp50 = (s32) (s16) M2C_FIELD(arg0, s32 *, 0x1C);
                    sp58 = 0;
                    sp54 = (s32) M2C_FIELD(arg0, s16 *, 0x1E);
                    func_8004901C(&sp28, &sp50);
                }
                sp50 = (s32) M2C_FIELD(arg0, s16 *, 4);
                sp54 = (s32) M2C_FIELD(arg0, s16 *, 6);
                sp58 = func_800491EC();
                func_80052430(&sp28, &sp50);
                func_8004914C(&sp28);
                func_800491AC(&sp28);
                sp64 = 0;
                temp_v1_2 = -M2C_FIELD(arg0, s16 *, 0x18);
                temp_t0 = -M2C_FIELD(arg0, s16 *, 0x1A);
                sp60 = temp_v1_2;
                sp62 = temp_t0;
                sp6A = temp_t0;
                sp6C = 0;
                sp70 = temp_v1_2;
                sp68 = M2C_FIELD(arg0, u16 *, 8) + temp_v1_2;
                sp74 = 0;
                sp72 = M2C_FIELD(arg0, u16 *, 0xA) + temp_t0;
                sp78 = M2C_FIELD(arg0, u16 *, 8) + temp_v1_2;
                sp7C = 0;
                sp7A = M2C_FIELD(arg0, u16 *, 0xA) + temp_t0;
                func_8004961C(&sp60, &sp68, &sp70, &sp78, &sp80, &sp84, &sp88, &sp8C, &sp90, &sp94);
                if (temp_s1 & 0x800000) {
                    temp_v1_3 = M2C_FIELD(arg0, u8 *, 0xE);
                    var_t1 = (temp_v1_3 + (u8) M2C_FIELD(arg0, u16 *, 8)) - 1;
                    var_t4 = temp_v1_3;
                } else {
                    var_t1 = M2C_FIELD(arg0, u8 *, 0xE);
                    var_t4 = (var_t1 + (u8) M2C_FIELD(arg0, u16 *, 8)) - 1;
                }
                if (temp_s1 & 0x400000) {
                    temp_v1_4 = M2C_FIELD(arg0, u8 *, 0xF);
                    var_t2 = (temp_v1_4 + (u8) M2C_FIELD(arg0, u16 *, 0xA)) - 1;
                    var_t3 = temp_v1_4;
                } else {
                    var_t2 = M2C_FIELD(arg0, u8 *, 0xF);
                    var_t3 = (var_t2 + (u8) M2C_FIELD(arg0, u16 *, 0xA)) - 1;
                }
                temp_t1 = var_t1 & 0xFF;
                temp_t2 = (var_t2 & 0xFF) << 8;
                M2C_FIELD(temp_s2, s32 *, 8) = sp80;
                var_a2 = arg2 & 0xFFFF;
                M2C_FIELD(temp_s2, s32 *, 4) = (s32) ((((u32) temp_s1 >> 5) & 0x02000000) | (((temp_s1 << 0x12) & 0x01000000) | 0x2C000000) | (M2C_FIELD(arg0, u8 *, 0x16) << 0x10) | (M2C_FIELD(arg0, u8 *, 0x15) << 8) | M2C_FIELD(arg0, u8 *, 0x14));
                M2C_FIELD(temp_s2, s32 *, 0x10) = sp84;
                M2C_FIELD(temp_s2, s32 *, 0xC) = (s32) (temp_t1 | temp_t2 | (M2C_FIELD(arg0, s16 *, 0x12) << 0x16) | ((M2C_FIELD(arg0, s16 *, 0x10) << 0xC) & 0x3F0000));
                var_a3 = 9;
                M2C_FIELD(temp_s2, s32 *, 0x18) = sp88;
                temp_v0 = (var_t3 & 0xFF) << 8;
                M2C_FIELD(temp_s2, s32 *, 0x1C) = (s32) (temp_t1 | temp_v0);
                M2C_FIELD(temp_s2, s32 *, 0x20) = sp8C;
                temp_v1_5 = var_t4 & 0xFF;
                M2C_FIELD(temp_s2, s32 *, 0x24) = (s32) (temp_v1_5 | temp_v0);
                var_v1 = temp_v1_5 | temp_t2 | ((M2C_FIELD(arg0, u16 *, 0xC) & 0x1F) << 0x10) | (((u32) temp_s1 >> 1) & 0x01800000);
                var_v0_2 = ((u32) temp_s1 >> 7) & 0x600000;
            }
            M2C_FIELD(temp_s2, s32 *, 0x14) = (s32) (var_v1 | var_v0_2);
            D_800A5E60 = func_80051EA0(temp_s2, arg1, var_a2, var_a3);
        }
    }
}
