/* Native retail instruction export [8005C2C8,8005C2F8).
 * Verified against asm/main.s and the extracted EXE. No C match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s8 *func_8005C2C8(s8 *arg0, s32 arg1) {
    s32 var_a1;
    s8 *var_a0;
    s8 *var_v0;

    var_a0 = arg0;
    var_a1 = arg1;
    var_v0 = 0;
    if (var_a0 != 0) {
        var_v0 = var_a0;
        if (var_a1 <= 0) {
            return 0;
        }
        do {
            *var_a0 = 0;
            var_a1 -= 1;
            var_a0 += 1;
        } while (var_a1 > 0);
        /* Duplicate return node #4. Try simplifying control flow for better match */
        return var_v0;
    }
    return var_v0;
}
