/* Overlay range [8014ED28,8014ED80) from MAIN.CD member 0012.
 * SHA256(span)=f39841a9fc374d2773c91a0d68adc7bafd6a8356b8ea73c0320203505ab048ee.
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
s32 func_8014ED80();                                /* static */

s32 func_8014ED28(void) {
    **(void ***)0x1F8003FC = sp;
    D_80184248 = func_8014ED80();
    return D_80184248;
}
