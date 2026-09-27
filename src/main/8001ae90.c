/* Exact retail word export for [8001AE90,8001AF04); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_800747F4;

s32 func_8001AE90(s32 arg0, s32 arg1, s32 *arg2) {
    if (arg0 != 1) {
        if (arg0 < 2) {
            if (arg0 != 0) {
                return 0;
            }
            goto block_5;
        }
        if (arg0 == 2) {
block_5:
            return *arg2 == D_800747F4;
        }
        return 0;
    }
    return arg1 == D_800747F4;
}
