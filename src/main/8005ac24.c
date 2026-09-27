/* Exact retail word export for [8005AC24,8005ACF0); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8007278C;
extern s32 D_80072788;
extern s16 D_8007278E;

s32 func_8005AC24(s16 arg0, s16 arg1) {
    s16 var_a1;
    s16 var_v0_2;
    s32 var_v0;
    s32 var_v1;

    var_a1 = arg1;
    if (arg0 >= 0) {
        var_v0_2 = D_8007278C - 1;
        if ((D_8007278C - 1) >= arg0) {
            var_v0_2 = arg0;
        }
    } else {
        var_v0_2 = 0;
    }
    if (var_a1 >= 0) {
        if ((D_8007278E - 1) < var_a1) {
            var_a1 = D_8007278E - 1;
        }
    } else {
        var_a1 = 0;
    }
    if ((u32) (D_80072788 - 1) >= 2U) {
        var_v1 = (var_a1 & 0x3FF) << 0xA;
        var_v0 = var_v0_2 & 0x3FF;
    } else {
        var_v1 = (var_a1 & 0xFFF) << 0xC;
        var_v0 = var_v0_2 & 0xFFF;
    }
    return var_v1 | (var_v0 | 0xE4000000);
}
