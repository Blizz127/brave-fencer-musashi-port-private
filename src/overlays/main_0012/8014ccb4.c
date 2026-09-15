/* Overlay range [8014CCB4,8014CD0C) from MAIN.CD member 0012.
 * SHA256(span)=1ce34536a247a71d81a2b088931a799c1ca87679e36337de34ff3583a0684d54.
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
s32 func_8014CD0C();                                /* static */

s32 func_8014CCB4(void) {
    **(void ***)0x1F8003FC = sp;
    D_80184248 = func_8014CD0C();
    return D_80184248;
}
