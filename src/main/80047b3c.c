/* Main-exec range [80047B3C,80047BD8) from the SLUS executable.
 * SHA256(span)=5a722934297a553d0257c327ddb714b0cf06a9c95601b698df6ab760009cf3b7.
 * Word export only: the native seam executes the retail instruction
 * stream itself; this is not a C match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_800479E8(s32);                             /* static */
s32 func_80049440(s32);                             /* static */

s32 func_80047B3C(s32 arg0) {
    s32 temp_s0;
    s32 temp_v0;
    s32 var_a0;
    s32 var_s0;

    if (arg0 == 0) {
        return 0;
    }
    temp_v0 = 8 - func_80049440(arg0);
    var_s0 = temp_v0 >> 1;
    if (temp_v0 >= 0) {
        var_a0 = arg0 >> (var_s0 * 2);
    } else {
        var_s0 = (temp_v0 >> 1) + 1;
        var_a0 = arg0 << -(var_s0 * 2);
    }
    temp_s0 = var_s0 - 6;
    if (temp_s0 < 0) {
        return func_800479E8(var_a0) >> -temp_s0;
    }
    return func_800479E8(var_a0) << temp_s0;
}
