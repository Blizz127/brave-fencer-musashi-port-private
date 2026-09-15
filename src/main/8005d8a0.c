/* Exact retail word export for [8005D8A0,8005D8B4); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_800729C4;

s32 func_8005D8A0(void) {
    s32 temp_v0;

    temp_v0 = D_800729C4;
    D_800729C4 = 0;
    return temp_v0;
}
