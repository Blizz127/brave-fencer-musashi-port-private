/* Exact retail word export for [8005ACF0,8005AD34); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80072788;
s32 func_8005ACF0(s32 arg0, s32 arg1) {
    s32 var_v0;
    s32 var_v1;

    if ((u32) (D_80072788 - 1) >= 2U) {
        var_v1 = (arg1 & 0x7FF) << 0xB;
        var_v0 = arg0 & 0x7FF;
    } else {
        var_v1 = (arg1 & 0xFFF) << 0xC;
        var_v0 = arg0 & 0xFFF;
    }
    return var_v1 | (var_v0 | 0xE5000000);
}
