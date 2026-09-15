/* Overlay range [8014F6F4,8014F74C) from MAIN.CD member 0012.
 * SHA256(span)=da7ad05fa964793c5e6364e7ed4fde8b92e67258baa9b3e293a13286e470b586.
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
s32 func_8014F74C();                                /* static */

s32 func_8014F6F4(void) {
    **(void ***)0x1F8003FC = sp;
    D_8018424C = func_8014F74C();
    return D_8018424C;
}
