/* Exact retail word export for [8002FD14,8002FDC8); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8002D240();                                 /* static */
s32 func_8002FF0C(s32, s32);                          /* static */
void func_80037D74();                                  /* static */
s32 func_8003C4F0();                               /* static */
extern u8 D_8006AEF4;
extern s16 D_800A46CC;

s32 func_8002FD14(s32 arg0, s32 arg1) {
    s32 var_s0;
    s32 var_v0;

    if (D_800A46CC == 0) {
        func_80037D74();
        if (func_8003C4F0(0) != 0) {
            D_8006AEF4 &= 0xFE;
            goto block_5;
        }
        var_s0 = 0;
    } else {
block_5:
        var_s0 = func_8002FF0C(arg0, arg1);
    }
    if (var_s0 != 0) {
        var_v0 = var_s0;
        if (arg0 == 0x1A) {
            func_8002D240(0x28);
            return var_s0;
        }
        /* Duplicate return node #10. Try simplifying control flow for better match */
        return var_v0;
    }
    var_v0 = 0;
    return var_v0;
}
