/* Exact retail word export for [80019A24,80019AF8); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80019AF8();                                 /* static */
s32 func_80034B98();                                /* static */
extern s32 D_800AE708;
extern s32 D_800AE720;
extern s32 D_800AE724;
extern s32 D_800AE72C;
extern s32 *D_800AE7A4;
extern s32 D_800AE7A8;
extern s32 D_800AE7B0;

s32 func_80019A24(s32 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (func_80034B98() == 0) {
        if (D_800AE708 != 0) {
            if (*arg0 != D_800AE708) {
                goto block_3;
            }
            goto block_5;
        }
block_5:
        D_800AE72C = arg1;
        D_800AE7A8 = arg2;
        D_800AE7A4 = arg0;
        D_800AE724 = arg3;
        D_800AE720 = 0;
        D_800AE708 = *arg0;
        if (arg3 == 0) {
            D_800AE720 = 1;
        }
        func_80019AF8(0);
        return D_800AE7B0;
    }
block_3:
    return 0;
}
