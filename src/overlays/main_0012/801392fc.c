/* Overlay range [801392FC,801395D4) from MAIN.CD member 0012.
 * SHA256(span)=bd09c03daaaaabca980a983453e59828b3ddf405df6486817851a68c0bec1df6.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80052460(s32 *, s32, u16);         /* extern */
s16 func_80058B40(s32, s32, s32, s32);      /* extern */

void func_801392FC(void *arg0, s32 arg1, s32 arg2) {
    s8 sp26;
    s8 sp25;
    s8 sp24;
    u16 sp22;
    u16 sp20;
    s8 sp1F;
    s8 sp1E;
    s16 sp1C;
    s16 sp1A;
    u16 sp18;                                       /* compiler-managed */
    u16 sp16;
    u16 sp14;
    s32 sp10;
    s16 temp_v0;
    s32 temp_hi;
    s32 temp_hi_2;
    s32 var_s1;
    s32 var_s4;
    s32 var_v0;
    s8 var_v0_3;
    u16 temp_a0;
    u16 var_v0_2;

    sp10 = 0;
    sp1C = func_80058B40(0, 1, M2C_FIELD(arg0, s16 *, 0x38) & 0xFFC0, M2C_FIELD(arg0, s16 *, 0x3A) & 0xFF00);
    sp20 = M2C_FIELD(arg0, u16 *, 0x3C);
    sp26 = 0x80;
    sp25 = 0x80;
    sp24 = 0x80;
    sp22 = M2C_FIELD(arg0, u16 *, 0x3E);
    var_s1 = 0;
    if (M2C_FIELD(arg0, s16 *, 0x2E) > 0) {
        var_s4 = 0;
        var_v0 = (u16) M2C_FIELD(arg0, s16 *, 0x2E) << 0x10;
        do {
            temp_hi = (s32) (M2C_FIELD(arg0, u16 *, 0x16) + var_s1) % (s32) ((var_v0 >> 0x10) + 1);
            sp14 = M2C_FIELD(arg0, u16 *, 0x30);
            if (var_s1 != 0) {
                var_v0_2 = ((M2C_FIELD(arg0, u16 *, 0x32) + var_s4) - arg1) + (var_s1 * 2);
            } else {
                var_v0_2 = M2C_FIELD(arg0, u16 *, 0x32);
            }
            sp16 = var_v0_2;
            if (var_s1 == 0) {
                sp1A = 0xC - arg1;
            } else {
                sp1A = 0xC;
            }
            sp1E = 0;
            if (var_s1 != 0) {
                var_v0_3 = (temp_hi * 0xC) + (u8) M2C_FIELD(arg0, s16 *, 0x3A);
            } else {
                var_v0_3 = (temp_hi * 0xC) + (u8) M2C_FIELD(arg0, s16 *, 0x3A) + arg1;
            }
            sp1F = var_v0_3;
            var_s4 += 0xC;
            sp18 = M2C_FIELD(arg0, u16 *, 0x34);
            var_s1 += 1;
            func_80052460(&sp10, arg2, M2C_FIELD(arg0, u16 *, 0x1A));
            var_v0 = (u16) M2C_FIELD(arg0, s16 *, 0x2E) << 0x10;
        } while (var_s1 < M2C_FIELD(arg0, s16 *, 0x2E));
    }
    if (arg1 != 0) {
        temp_hi_2 = (s32) (M2C_FIELD(arg0, u16 *, 0x16) + var_s1) % (s32) (M2C_FIELD(arg0, s16 *, 0x2E) + 1);
        sp14 = M2C_FIELD(arg0, u16 *, 0x30);
        sp1A = arg1 - 2;
        sp1E = 0;
        sp16 = ((M2C_FIELD(arg0, u16 *, 0x32) + (var_s1 * 0xC)) - arg1) + (var_s1 * 2);
        sp1F = (temp_hi_2 * 0xC) + (u8) M2C_FIELD(arg0, s16 *, 0x3A);
        temp_v0 = (s16) M2C_FIELD(arg0, u16 *, 0x34);
        if (temp_v0 >= 0xFD) {
            sp18 = 0x100;
            func_80052460(&sp10, arg2, M2C_FIELD(arg0, u16 *, 0x1A));
            temp_a0 = sp18;
            sp18 = 0x20;
            sp1E = temp_hi_2 << 5;
            sp14 = M2C_FIELD(arg0, u16 *, 0x30) + temp_a0;
            sp1F = ((M2C_FIELD(arg0, s16 *, 0x2E) + 1) * 0xC) + (u8) M2C_FIELD(arg0, s16 *, 0x3A);
        } else {
            sp18 = temp_v0;
        }
        func_80052460(&sp10, arg2, M2C_FIELD(arg0, u16 *, 0x1A));
    }
}
