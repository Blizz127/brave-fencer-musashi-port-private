/* Overlay range [8014F1F4,8014F24C) from MAIN.CD member 0012.
 * SHA256(span)=bf4b0ebff1a87beccd505a1463ae86957cccdf73918f74ac651b1a773f063ec8.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80184248;
s32 func_8014F24C();                                /* static */

s32 func_8014F1F4(void) {
    **(void ***)0x1F8003FC = sp;
    D_80184248 = func_8014F24C();
    return D_80184248;
}
