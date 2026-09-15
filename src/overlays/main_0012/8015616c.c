/* Overlay range [8015616C,80156370) from MAIN.CD member 0012.
 * SHA256(span)=74af055b3c3524704e75ccf790c36ac1ba37f9e0610cf49bca017f4399b796e3.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80029178();                         /* extern */
s32 func_80029B4C(s32, s16);                        /* extern */
s32 func_80029BC8(s16, s16);                        /* extern */
s32 func_80029C44(s32, s16);                        /* extern */
s32 func_8005C49C(s32);                             /* extern */
void *func_801563EC(s32);                           /* static */
s32 func_8015640C(s32, s32);                        /* static */
extern u16 D_801152B8;
extern u16 D_8012693A;

s32 func_8015616C(s32 arg0, s32 arg1) {
    s32 temp_s0_2;
    s32 temp_s1;
    s32 var_s0;
    s32 var_s1;
    u16 temp_s0;
    u16 temp_s2;
    u16 temp_s3;
    u16 temp_s4;
    u16 temp_s5;
    u16 temp_s6;
    u16 var_v0;
    void *temp_v0;

    temp_v0 = func_801563EC(arg1 & 0xFFFF);
    temp_s4 = M2C_FIELD(temp_v0, u16 *, 0);
    temp_s0 = M2C_FIELD(temp_v0, u16 *, 2);
    temp_s2 = M2C_FIELD(temp_v0, u16 *, 4);
    temp_s3 = M2C_FIELD(temp_v0, u16 *, 6);
    temp_s5 = M2C_FIELD(temp_v0, u16 *, 8);
    temp_s6 = M2C_FIELD(temp_v0, u16 *, 0xA);
    temp_s1 = temp_s4 & 0xFFF;
    if (temp_s4 & 0x4000) {
        temp_s0_2 = func_80029B4C(temp_s1, (s16) temp_s0);
        var_s0 = temp_s0_2 + func_80029BC8((s16) temp_s2, (s16) temp_s3);
    } else if (temp_s4 & 0x2000) {
        var_s0 = func_80029C44(temp_s1, (s16) temp_s0);
    } else {
        var_s0 = temp_s1 + (func_8005C49C(temp_s1) % (s32) (temp_s0 + 1));
    }
    D_8012693A = temp_s5;
    if (func_80029178(0x81) & 0xFF) {
        D_8012693A *= 2;
    }
    var_s1 = 0;
    if (temp_s6 != 0) {
        if (func_80029178(0x1A) & 0xFF) {
            var_s1 = 5;
            goto block_18;
        }
        if (func_80029178(0x19) & 0xFF) {
            var_s1 = 4;
            goto block_18;
        }
        if (func_80029178(0x18) & 0xFF) {
            var_s1 = 3;
            goto block_18;
        }
        if (func_80029178(0x17) & 0xFF) {
            var_s1 = 2;
            goto block_18;
        }
        var_v0 = temp_s6;
        if (func_80029178(0x16) & 0xFF) {
            var_s1 = 1;
            goto block_18;
        }
    } else {
block_18:
        var_v0 = temp_s6 + var_s1;
    }
    D_801152B8 = var_v0;
    if (temp_s4 & 0x8000) {
        var_s0 = func_8015640C(arg0, var_s0 & 0xFFFF);
    }
    return var_s0 & 0xFFFF;
}
