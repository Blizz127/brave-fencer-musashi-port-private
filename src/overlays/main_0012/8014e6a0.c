/* Overlay range [8014E6A0,8014E6F8) from MAIN.CD member 0012.
 * SHA256(span)=96c873df6b7e1a74a580d48ef92d7dfbcc557a96d21771ef01019ef27cdeccfb.
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
s32 func_8014E6F8();                                /* static */

s32 func_8014E6A0(void) {
    **(void ***)0x1F8003FC = sp;
    D_80184248 = func_8014E6F8();
    return D_80184248;
}
