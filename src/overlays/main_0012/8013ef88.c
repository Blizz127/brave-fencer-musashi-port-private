/* Overlay range [8013EF88,8013F138) from MAIN.CD member 0012.
 * SHA256(span)=6e9052ed74d9bc98cef58ffb6852ce40946eec1243560509dea1634366ff08b8.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_800D0488(s16, s32, s32, s16);              /* extern */
void func_800D2624();                            /* extern */
extern s32 D_8017F6FA;
void func_8013FAF8(s32, s32);            /* static */
extern u16 D_800B9A02;
extern u16 D_80115112;
extern u16 D_80115114;
extern u16 D_80115118;
extern s16 D_80115124;
extern s32 *D_80115168;
extern s32 *D_80115188;
extern s32 D_801151D0;
extern u16 D_8017F6F8;

void func_8013EF88(s32 arg1, s32 arg2, s16 arg3) {
    s16 temp_v1;
    s16 var_a3;
    s32 temp_v0_2;
    s32 var_a1;
    s32 var_a2;
    u16 temp_v0;
    u16 temp_v0_3;

    var_a1 = arg1;
    var_a2 = arg2;
    var_a3 = arg3;
    temp_v0 = D_80115118 - 1;
    if (D_80115118 != 0) {
        D_80115118 = temp_v0;
        if (temp_v0 & 0xFFFF) {
            D_801151D0 = M2C_FIELD((&D_80115118 + (D_800B9A02 * 4)), s32 *, 0xB0);
            func_8013FAF8(0, 5);
            var_a3 = 0;
            do {
                var_a1 = (s32) (var_a3 << 0x10) >> 0xE;
                temp_v1 = var_a3 + 1;
                var_a3 = temp_v1;
                var_a2 = *(&D_80115188 + var_a1);
                temp_v0_2 = var_a2 * 3;
                *(&D_80115188 + var_a1) = temp_v0_2;
                *(&D_80115168 + var_a1) = *(&D_80115168 + var_a1) + temp_v0_2;
            } while (temp_v1 < 5);
            if ((u16) D_80115118 < 3U) {
                D_8017F6FA = (u16) (D_8017F6FA - 1);
            }
            temp_v0_3 = D_8017F6F8 - 2;
            D_8017F6F8 = temp_v0_3;
            if (temp_v0_3 & 0x8000) {
                D_8017F6F8 = 0;
            }
        }
    }
    if (D_80115124 != 0) {
        if (func_800D0488(D_80115124, var_a1, var_a2, var_a3) != 0) {
            D_80115124 = 0;
            goto block_11;
        }
    } else {
block_11:
        if (D_80115118 == 0) {
            if (D_80115114 == (D_800B9A02 ^ 1)) {
                func_800D2624();
                return;
            }
            D_80115112 += 1;
        }
    }
}
