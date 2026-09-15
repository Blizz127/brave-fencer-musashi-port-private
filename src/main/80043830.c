/* Exact retail word export for [80043830,80043974); EXE-verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006CBFC;
extern s32 D_8006CC84;
extern s32 D_8006CC94;
s32 func_80044124(s32, s32);                            /* static */
s32 func_80044670(s32, s32, s32, s32);                  /* static */

s32 func_80043830(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_s3;
    s32 temp_s5;
    s32 var_s0;
    s32 var_v0;

    var_s0 = 3;
    temp_s3 = arg0 & 0xFF;
    temp_s5 = D_8006CC84;
loop_1:
    D_8006CC84 = 0;
    if ((temp_s3 != 1) && (D_8006CC94 & 0x10)) {
        func_80044670(1, 0, 0, 0);
    }
    if (((arg1 != 0) && (*((temp_s3 * 4) + D_8006CBFC) != 0) && (func_80044670(2, arg1, arg2, 0) != 0)) || (D_8006CC84 = temp_s5, var_v0 = 0, (func_80044670(arg0 & 0xFF, arg1, arg2, 0) != 0))) {
        var_s0 -= 1;
        var_v0 = -1;
        if (var_s0 == -1) {
            D_8006CC84 = temp_s5;
        } else {
            goto loop_1;
        }
    }
    if (var_v0 == 0) {
        return func_80044124(0, arg2) == 2;
    }
    return 0;
}
