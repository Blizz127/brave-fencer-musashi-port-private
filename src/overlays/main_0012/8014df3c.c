/* Overlay range [8014DF3C,8014DF94) from MAIN.CD member 0012.
 * SHA256(span)=48611fe981098db5618ca1a94161391959728d14852e5f9912c8407ecd41751a.
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
s32 func_8014DF94();                                /* static */

s32 func_8014DF3C(void) {
    **(void ***)0x1F8003FC = sp;
    D_80184248 = func_8014DF94();
    return D_80184248;
}
