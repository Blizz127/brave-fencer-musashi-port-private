/* Overlay range [8014E434,8014E48C) from MAIN.CD member 0012.
 * SHA256(span)=8b0ae38dd3a488d02e5ec8a280d4b93162c8bcbfbc7a600e4f1f7f63204d4c09.
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
s32 func_8014E48C();                                /* static */

s32 func_8014E434(void) {
    **(void ***)0x1F8003FC = sp;
    D_80184248 = func_8014E48C();
    return D_80184248;
}
