/* Exact retail word export for [8003C4F0,8003C598); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006B0E0;
extern s32 D_8006B0E8;
extern s32 D_8006B580;
s32 func_8005CEA8(s32);                             /* static */

s32 func_8003C4F0(s32 arg0) {
    s32 var_v0;

    if ((D_8006B0E8 == 1) || (D_8006B580 == 1)) {
        return 1;
    }
    var_v0 = func_8005CEA8(D_8006B0E0);
    if (arg0 == 1) {
        var_v0 = 1;
        if (var_v0 == 0) {
            do {
                var_v0 = 1;
            } while (func_8005CEA8(D_8006B0E0) == 0);
        }
        goto block_8;
    }
    if (var_v0 == 1) {
block_8:
        D_8006B580 = var_v0;
    }
    return var_v0;
}
