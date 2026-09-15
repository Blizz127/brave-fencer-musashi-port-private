/* Overlay range [8014FCFC,8014FD54) from MAIN.CD member 0012.
 * SHA256(span)=907107ec0bfd9e7e75947cb9641aee18e95b7bb32bc155e58b8e54dc6e0cdb33.
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
s32 func_8014FD54();                                /* static */

s32 func_8014FCFC(void) {
    **(void ***)0x1F8003FC = sp;
    D_80184248 = func_8014FD54();
    return D_80184248;
}
