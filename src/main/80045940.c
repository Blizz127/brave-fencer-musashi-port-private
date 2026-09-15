/* Exact retail word export for [80045940,800459E8); EXE-verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_8005C4DC(s32, void *);                          /* static */
extern s32 *D_80076A04;
extern s32 *D_80076A0C;

s32 func_80045940(s32 arg0, s32 arg1) {
    void *var_s2;
    s32 temp_v0;
    s32 var_s0;
    s32 var_s1;

    var_s0 = 0;
    var_s2 = &D_80076A0C;
    var_s1 = 0;
loop_1:
    temp_v0 = *(&D_80076A04 + var_s1);
    if (temp_v0 != 0) {
        if (temp_v0 == arg0) {
            var_s2 += 0x2C;
            if (func_8005C4DC(arg1, var_s2) == 0) {
                return var_s0 + 1;
            }
            goto block_6;
        }
        var_s2 += 0x2C;
block_6:
        var_s0 += 1;
        var_s1 += 0x2C;
        if (var_s0 >= 0x80) {
            goto block_7;
        }
        goto loop_1;
    }
block_7:
    return -1;
}
