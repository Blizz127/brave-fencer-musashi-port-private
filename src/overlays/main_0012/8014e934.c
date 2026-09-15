/* Overlay range [8014E934,8014E98C) from MAIN.CD member 0012.
 * SHA256(span)=c84f70a9f80d87e4925150f9cf923d9def7d528faf1fe7fbbc54d695569529b6.
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
s32 func_8014E98C();                                /* static */

s32 func_8014E934(void) {
    **(void ***)0x1F8003FC = sp;
    D_80184248 = func_8014E98C();
    return D_80184248;
}
