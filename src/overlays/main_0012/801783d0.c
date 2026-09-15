/* Overlay range [801783D0,80178438) from MAIN.CD member 0012.
 * SHA256(span)=1c7a8836a1d1776db62d639b25a70f67604568b7602f4c6690850324fd8b6bbd.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_801783D0(s32 arg0, s32 arg1) {
    s32 var_a0;
    s32 var_a2;
    s32 var_a3;
    s32 var_t0;

    var_a0 = arg0;
    var_t0 = 0;
    var_a2 = var_a0;
    var_a3 = 0;
    if (var_a2 >= 0xA) {
        do {
            var_a0 /= 0xA;
            var_t0 |= (var_a2 - (var_a0 * 0xA)) << var_a3;
            var_a2 = var_a0;
            var_a3 += 4;
        } while (var_a2 >= 0xA);
    }
    return (var_t0 | (var_a2 << var_a3)) << arg1;
}
