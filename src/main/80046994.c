/* Exact retail word export [80046994,800469A8); verified against pinned EXE and asm. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_800B9B54;

s32 func_80046994(s32 arg0) {
    s32 temp_v0;

    temp_v0 = D_800B9B54;
    D_800B9B54 = arg0;
    return temp_v0;
}
