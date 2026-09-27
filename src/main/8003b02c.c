/* Main-exec range [8003B02C,8003B08C) from the SLUS executable.
 * SHA256(span)=6be9a3427b222c65b68d5e98c9ec9ba08efe9a514edddbd5c6e43fcede474242.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 *D_8006B55C;

void func_8003B02C(s32 arg0) {
    s32 var_a0;
    s32 var_v1;

    *D_8006B55C &= 0xFFF8FFFF;
    if (arg0 != 0) {
        var_v1 = *D_8006B55C;
        var_a0 = 0x30000;
    } else {
        var_v1 = *D_8006B55C;
        var_a0 = 0x50000;
    }
    *D_8006B55C = var_v1 | var_a0;
}
