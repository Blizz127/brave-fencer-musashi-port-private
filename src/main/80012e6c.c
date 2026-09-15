/* Main-exec range [80012E6C,80012F74) from the SLUS executable.
 * SHA256(span)=d6c7c1cfd71e6bab4f02085ec962dba2a370434053a34810f775329a78510d5f.
 * Word export for the native seam; the body below is kept
 * byte-identical (wrap only, no rewrite). */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s16 func_80012E6C(s32 arg0, s32 arg1, s16 arg2, s16 arg3, s16 *arg4) {
    s16 temp_a1;
    s16 var_a0;
    s16 var_v0;
    s16 var_v1;
    s32 var_v0_2;
    s32 var_v0_3;

    temp_a1 = arg1 - arg0;
    var_v1 = temp_a1;
    var_a0 = var_v1;
    if ((*arg4 == 0) || (arg2 == 0)) {
        var_v0_2 = var_a0 << 0x10;
        if (temp_a1 >= 0x801) {
            var_a0 = temp_a1 - 0x1000;
            var_v0_2 = var_a0 << 0x10;
        }
        if ((var_v0_2 >> 0x10) < -0x800) {
            var_a0 += 0x1000;
        }
        return var_a0;
    }
    var_v0_3 = var_v1 << 0x10;
    if (temp_a1 >= 0x801) {
        var_v1 = temp_a1 - 0x1000;
        var_v0_3 = var_v1 << 0x10;
    }
    if ((var_v0_3 >> 0x10) < -0x800) {
        var_v1 += 0x1000;
    }
    var_v0 = (s16) ((s32) (var_v1 * arg3) / arg2);
    if (var_v0 == 0) {
        var_v0 = -1;
        if (temp_a1 > 0) {
            var_v0 = 1;
        }
    }
    return var_v0;
}
