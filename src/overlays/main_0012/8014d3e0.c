/* Overlay range [8014D3E0,8014D438) from MAIN.CD member 0012.
 * SHA256(span)=574825d2ff58f824e635a11c062eda1425dbae5b7d1575191c267c1e18e6cf5d.
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
s32 func_8014D438();                                /* static */

s32 func_8014D3E0(void) {
    **(void ***)0x1F8003FC = sp;
    D_80184248 = func_8014D438();
    return D_80184248;
}
