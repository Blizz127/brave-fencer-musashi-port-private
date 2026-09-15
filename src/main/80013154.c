/* Main-exec range [80013154,80013200) from the SLUS executable.
 * SHA256(span)=6a1c53b25aab826244e312e62db9b42ec62c7925775749e713f50a19e4b80ed5.
 * Word export for the native seam; the body below is kept
 * byte-identical (wrap only, no rewrite). */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80013154(s16 arg0, s16 arg1, s32 arg2) {
    s16 var_v0_2;
    s32 temp_a3;
    s32 var_t0;
    s32 var_v0;

    var_t0 = arg2;
    if (arg0 == arg1) {
        return 0;
    }
    temp_a3 = arg1 < arg0;
    var_v0_2 = arg0 + var_t0;
    if (temp_a3 != 0) {
        var_t0 = -arg2;
        var_v0_2 = arg0 + var_t0;
    }
    if ((var_v0_2 >= arg1) && (temp_a3 == 0)) {
        var_v0 = (arg1 - arg0) << 0x10;
    } else {
        var_v0 = var_t0 << 0x10;
        if (arg1 >= var_v0_2) {
            if (arg0 >= arg1) {
                var_v0 = (arg1 - arg0) << 0x10;
            } else {
                var_v0 = var_t0 << 0x10;
            }
        }
    }
    return var_v0 >> 0x10;
}
