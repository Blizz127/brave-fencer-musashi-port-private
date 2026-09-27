/* Main-exec range [80059B44,80059BFC) from the SLUS executable.
 * SHA256(span)=b6e71f25aa74a05afdd5116ccdd978bd511071f3583139f8330a6be3ee704b4c.
 * Word export for the native seam (m2c produced no draft). */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void D_80072784();
extern s32 D_80072844;
extern s32 D_800741A8;
extern u8 D_8007278A;

s32 *func_80059B44(s32 *arg0, s32 arg1) {
    s32 *temp_a0;
    s32 *var_s0;
    s32 var_s1;

    var_s0 = arg0;
    if ((u8) D_8007278A >= 2U) {
        D_80072784(D_800741A8, var_s0, arg1);
    }
    var_s1 = arg1 - 1;
    if (var_s1 != 0) {
        do {
            var_s1 -= 1;
            temp_a0 = var_s0 + 4;
            M2C_FIELD(var_s0, s8 *, 3) = 0;
            M2C_FIELD(var_s0, s32 *, 0) = (M2C_FIELD(var_s0, s32 *, 0) & 0xFF000000) | ((s32) temp_a0 & 0xFFFFFF);
            var_s0 = temp_a0;
        } while (var_s1 != 0);
    }
    *var_s0 = (s32) D_80072844 & 0xFFFFFF;
    return var_s0;
}
