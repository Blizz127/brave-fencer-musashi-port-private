/* Main-exec range [8005B6C0,8005B710) from the SLUS executable.
 * SHA256(span)=659c212d27bb10812c58508c78c09460c1d5f9799e7cf80eb60d3af7e1859e99.
 * Word export for the native seam (m2c produced no draft). */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 *D_80072858;
extern s32 *D_8007285C;

s32 func_8005B6C0(s32 *arg0, s32 arg1) {
    s32 *var_a0;
    s32 temp_v1;
    s32 var_a2;

    var_a0 = arg0;
    var_a2 = arg1 - 1;
    *D_8007285C = 0x04000000;
    if (arg1 != 0) {
        do {
            temp_v1 = *var_a0;
            var_a0 += 4;
            var_a2 -= 1;
            *D_80072858 = temp_v1;
        } while (var_a2 != -1);
    }
    return 0;
}
