/* Main-exec range [8005B400,8005B684) from the SLUS executable.
 * SHA256(span)=2807c590b90ff014153034358b59a041e9116a99606f4d9781f6301159fe4468.
 * Word export for the native seam (m2c produced no draft). */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8007278C;
extern s32 *D_80072858;
extern s32 *D_8007285C;
extern s32 *D_80072860;
extern s32 *D_80072864;
extern s32 *D_80072868;
void func_8005C020();                            /* static */
s32 func_8005C054();                                /* static */
extern s16 D_8007278E;

s32 func_8005B400(void *arg0, s32 *arg1) {
    s16 temp_a1;
    s16 temp_a1_2;
    s16 var_a0;
    s16 var_v1;
    s32 *var_s2;
    s32 temp_a0;
    s32 temp_s0;
    s32 temp_v1;
    s32 var_s0;
    s32 var_v0;
    s32 var_v0_2;

    var_s2 = arg1;
    func_8005C020();
    temp_a1 = M2C_FIELD(arg0, s16 *, 4);
    var_v1 = temp_a1;
    if (temp_a1 >= 0) {
        if (D_8007278C < temp_a1) {
            var_v1 = D_8007278C;
        }
    } else {
        var_v1 = 0;
    }
    temp_a1_2 = M2C_FIELD(arg0, s16 *, 6);
    M2C_FIELD(arg0, s16 *, 4) = var_v1;
    if (temp_a1_2 >= 0) {
        var_a0 = temp_a1_2;
        var_v0_2 = var_a0 << 0x10;
        if (D_8007278E < temp_a1_2) {
            var_a0 = D_8007278E;
            goto block_8;
        }
    } else {
        var_a0 = 0;
block_8:
        var_v0_2 = var_a0 << 0x10;
    }
    M2C_FIELD(arg0, s16 *, 6) = var_a0;
    temp_v1 = (M2C_FIELD(arg0, s16 *, 4) * (var_v0_2 >> 0x10)) + 1;
    temp_a0 = temp_v1 / 2;
    temp_s0 = temp_v1 >> 5;
    if (temp_a0 <= 0) {
        return -1;
    }
    if (!(*D_8007285C & 0x04000000)) {
loop_13:
        var_v0 = -1;
        if (func_8005C054() == 0) {
            if (*D_8007285C & 0x04000000) {
                goto block_15;
            }
            goto loop_13;
        }
    } else {
block_15:
        *D_8007285C = 0x04000000;
        *D_80072858 = 0x01000000;
        *D_80072858 = 0xC0000000;
        *D_80072858 = M2C_FIELD(arg0, s32 *, 0);
        *D_80072858 = (s32) M2C_FIELD(arg0, s16 *, 4);
        if (!(*D_8007285C & 0x08000000)) {
loop_17:
            var_v0 = -1;
            if (func_8005C054() == 0) {
                if (*D_8007285C & 0x08000000) {
                    goto block_19;
                }
                goto loop_17;
            }
        } else {
block_19:
            var_s0 = (temp_a0 - (temp_s0 * 0x10)) - 1;
            if (var_s0 != -1) {
                do {
                    var_s0 -= 1;
                    *var_s2 = *D_80072858;
                    var_s2 += 4;
                } while (var_s0 != -1);
            }
            if (temp_s0 != 0) {
                *D_8007285C = 0x04000003;
                *D_80072860 = var_s2;
                *D_80072864 = (temp_s0 << 0x10) | 0x10;
                *D_80072868 = 0x01000200;
            }
            var_v0 = 0;
        }
    }
    return var_v0;
}
