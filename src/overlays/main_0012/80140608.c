/* Overlay range [80140608,801407F4) from MAIN.CD member 0012.
 * SHA256(span)=d48da7e5f2f8c08ea12ffc632074d64d79ea01b4934dcfeceafb59505e27a764.
 * Word export for the native seam (m2c produced no draft). */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80019064(void *);                   /* extern */
s32 func_80028D58(s32);                             /* extern */
void func_80028D78(s16);                         /* extern */
s32 func_80028D9C(s32);                             /* extern */
void func_80028DBC(s16);                         /* extern */
s32 func_80028DE0(s32);                             /* extern */
void func_80028E00(s16);                         /* extern */
s32 func_80028FBC(s32);                             /* extern */
void func_80028FDC(s16);                         /* extern */
s32 func_80029000(s32);                             /* extern */
void func_80029020(s16);                         /* extern */
void func_8002D4C8(s32, s32);                /* extern */
extern s32 *D_80062BDC;
extern u16 D_8011511E;
extern s32 *D_80115148;

s32 func_80140608(s32 arg0) {
    s32 var_a0;
    s16 temp_s0;
    s16 temp_s0_2;
    s16 temp_v0_2;
    s16 temp_v0_3;
    s16 temp_v0_5;
    s16 temp_v0_6;
    s16 var_s0;
    s16 var_s0_2;
    s32 temp_a0;
    s32 temp_v0;
    s32 temp_v0_4;
    s32 var_a1;
    s32 var_s1;
    s32 var_v0;
    u8 temp_v1;

    temp_a0 = (s32) (arg0 << 0x10) >> 0xF;
    temp_v1 = *(&D_80115148 + temp_a0);
    var_s1 = 1;
    switch (temp_v1) {
    case 0:
        temp_s0 = func_80028D58(temp_a0) ^ 1;
        func_80028D78(temp_s0);
        var_v0 = 1;
        if (temp_s0 == 0) {
            func_80019064(&D_80062BDC);
            return 1;
        }
        return var_v0;
    case 1:
        func_80028E00((s16) (func_80028DE0(temp_a0) ^ 1));
        return 1;
    case 2:
        temp_v0 = func_80028FBC(temp_a0);
        if (D_8011511E & 0x8000) {
            temp_v0_2 = temp_v0 - 1;
            var_s0 = temp_v0_2;
            if (temp_v0_2 & 0x8000) {
                var_s0 = 0;
                goto block_10;
            }
        } else {
            temp_v0_3 = temp_v0 + 1;
            var_s0 = temp_v0_3;
            if (temp_v0_3 >= 8) {
                var_s0 = 7;
block_10:
                var_s1 = 0;
            }
        }
        func_80028FDC(var_s0);
        var_a0 = 0x21;
        var_a1 = var_s0 & 0xFFFF;
block_22:
        func_8002D4C8(var_a0, var_a1);
    default:
        var_v0 = var_s1;
        /* Duplicate return node #24. Try simplifying control flow for better match */
        return var_v0;
    case 3:
        temp_v0_4 = func_80029000(temp_a0);
        if (D_8011511E & 0x8000) {
            temp_v0_5 = temp_v0_4 - 1;
            var_s0_2 = temp_v0_5;
            if (temp_v0_5 & 0x8000) {
                var_s0_2 = 0;
                goto block_17;
            }
        } else {
            temp_v0_6 = temp_v0_4 + 1;
            var_s0_2 = temp_v0_6;
            if (temp_v0_6 >= 8) {
                var_s0_2 = 7;
block_17:
                var_s1 = 0;
            }
        }
        func_80029020(var_s0_2);
        var_a0 = 0x22;
        var_a1 = var_s0_2 & 0xFFFF;
        goto block_22;
    case 4:
        temp_s0_2 = func_80028D9C(temp_a0) ^ 1;
        func_80028DBC(temp_s0_2);
        var_a0 = 0xB;
        if (temp_s0_2 == 0) {
            var_a0 = 0xC;
        }
        var_a1 = 0;
        goto block_22;
    }
}
