/* Exact retail word export [8001AF04,8001AF34); verified against pinned EXE and asm. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_800BA1B4;

s32 func_8001AF04(void) {
    s32 var_v0;

    if (D_800BA1B4 == 0) {
        return 0;
    }
    var_v0 = 1;
    if (D_800BA1B4 != 3) {
        var_v0 = 2;
    }
    return var_v0;
}
