/* Main-exec range [80014E24,80014E80) from the SLUS executable.
 * SHA256(span)=a583177707178bc655438109ceec0dd0e2a262c36b18a67c7923dfb26414db69.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80014ED4(s32, s32);                        /* static */
s32 func_80015018(s32, s32);                        /* static */

s32 func_80014E24(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_a0;
    s32 temp_a1;
    s32 var_v0;

    temp_a0 = arg0 & 0xFF;
    temp_a1 = arg1 & 0xFF;
    if (temp_a1 == 1) {
        var_v0 = func_80015018(temp_a0, temp_a1) & 0xFFFF;
    } else {
        var_v0 = func_80014ED4(temp_a0, temp_a1) & 0xFFFF;
    }
    return (var_v0 & arg2) == arg2;
}
