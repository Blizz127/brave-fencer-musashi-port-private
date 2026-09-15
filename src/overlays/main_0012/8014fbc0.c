/* Overlay range [8014FBC0,8014FC18) from MAIN.CD member 0012.
 * SHA256(span)=50a22ddd30f7dda917052025fa18e08b7a7ac7fee5e112fe3102b3533dfdf6de.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8018424C;
s32 func_8014FC18();                                /* static */

s32 func_8014FBC0(void) {
    **(void ***)0x1F8003FC = sp;
    D_8018424C = func_8014FC18();
    return D_8018424C;
}
