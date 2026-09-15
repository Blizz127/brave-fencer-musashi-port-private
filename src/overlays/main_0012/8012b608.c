/* Overlay range [8012B608,8012B6D4) from MAIN.CD member 0012.
 * SHA256(span)=bb38ef48add1851f48300dcb16ca1c946536517bcbe3c210fcd267d9342dcfe0.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_8012B608(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_a0;
    s32 temp_a1;
    s32 temp_lo;
    s32 temp_lo_2;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v1;
    s32 var_v1_2;

    temp_a0 = arg0 & 0xFFF;
    temp_a1 = arg1 & 0xFFF;
    var_v1 = temp_a1 - temp_a0;
    if (temp_a0 == temp_a1) {
        return 0;
    }
    var_v0_2 = var_v1 < -0x800;
    if (var_v1 >= 0x801) {
        var_v1 = temp_a1 - (temp_a0 + 0x1000);
        var_v0_2 = var_v1 < -0x800;
    }
    if (var_v0_2 != 0) {
        var_v1 = temp_a1 - (temp_a0 - 0x1000);
    }
    if (var_v1 >= 0) {
        temp_lo = var_v1 / arg2;
        var_v0 = temp_lo;
        if (temp_lo == 0) {
            var_v1_2 = 1;
            goto block_11;
        }
    } else {
        temp_lo_2 = var_v1 / arg2;
        var_v0 = temp_lo_2;
        if (temp_lo_2 == 0) {
            var_v1_2 = -1;
block_11:
            var_v0 = var_v1_2;
        }
    }
    return var_v0;
}
