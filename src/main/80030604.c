/* Main-exec range [80030604,80030634) from the SLUS executable.
 * SHA256(span)=0562f0137aedd70ae5acbf3a2cdfb328bca1a3fb1e6d1c15ca9cebb2b78a0490.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern u16 D_800A46CC;

s32 func_80030604(void) {
    D_800A46CC += 2;
    return 0;
}
