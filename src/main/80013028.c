/* Main-exec range [80013028,800130D0) from the SLUS executable.
 * SHA256(span)=9af503680e158f1e94465c07e72dbaa739d1fa89d3ec347f0c6b3b5fd9c14c34.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s16 func_80013028(s32 arg0, s32 arg1, s16 arg2, s16 arg3, s16 *arg4) {
    s16 temp_a1;
    s16 var_v0;

    temp_a1 = arg1 - arg0;
    if ((*arg4 == 0) || (arg2 == 0)) {
        return temp_a1;
    }
    var_v0 = (s16) ((s32) (temp_a1 * arg3) / arg2);
    if (var_v0 == 0) {
        var_v0 = -1;
        if (temp_a1 > 0) {
            var_v0 = 1;
        }
    }
    return var_v0;
}
