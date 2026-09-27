/* Exact retail word export for [8003AF4C,8003AFF0); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006B54C;
extern s32 D_8006B570;
extern s32 D_8006B574;
extern s32 D_8006B578;
extern s32 D_8006B57C;

u32 func_8003AF4C(s32 arg0, u32 arg1) {
    u32 temp_a3;
    u32 var_a1;

    var_a1 = arg1;
    if ((D_8006B570 != 0) && ((var_a1 % (u32) D_8006B578) != 0)) {
        var_a1 = (var_a1 + D_8006B578) & ~D_8006B57C;
    }
    temp_a3 = var_a1 >> D_8006B574;
    if (arg0 != -2) {
        if (arg0 == -1) {
            return temp_a3 & 0xFFFF;
        }
        *((arg0 * 2) + D_8006B54C) = (s16) temp_a3;
        return var_a1;
    }
    return var_a1;
}
