/* Main-exec range [8002A670,8002A6BC) from the SLUS executable.
 * SHA256(span)=885337f0cc86a65c954b0ff2d27a96c74b458931a17fb7c55491b0698ecc6bd9.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_8002A728();                                /* static */
s32 func_8002A738();                                /* static */
s32 func_8002A748();                                /* static */
s32 func_8002AA00(s32);                             /* static */

s32 func_8002A670(void) {
    s32 temp_s0;
    s32 var_v0;

    var_v0 = 0;
    if (func_8002AA00(func_8002A728() + 1) != 0) {
        temp_s0 = func_8002A738();
        var_v0 = temp_s0 == func_8002A748();
    }
    return var_v0;
}
