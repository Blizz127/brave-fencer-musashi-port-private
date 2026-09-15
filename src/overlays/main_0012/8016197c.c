/* Overlay range [8016197C,801619A4) from MAIN.CD member 0012.
 * SHA256(span)=e8ab3e29e739f4a995e7f0380f1426c3051402893ae374e0dabec40df253a493.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_8016197C(u32 arg1) {
    s32 var_v0;

    var_v0 = 1;
    if (!(arg1 & 1)) {
        var_v0 = 2;
        if (!(arg1 & 0x4000)) {
            var_v0 = (arg1 >> 0xB) & 4;
        }
    }
    return var_v0;
}
