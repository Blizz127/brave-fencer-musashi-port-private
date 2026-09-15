/* Native retail instruction export [80046564,8004657C).
 * Verified against asm/main.s and the extracted EXE. No C match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006CFD0;

s32 func_80046564(s32 arg0) {
    s32 temp_v0;

    temp_v0 = D_8006CFD0;
    D_8006CFD0 = arg0;
    return temp_v0;
}
