/* Exact retail word export for [80058890,80058A4C); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80058B40(s32, s32, s16, s32);                /* static */
void func_800599B8(s16 *, s32);                        /* static */

s32 func_80058890(s32 arg0, s32 arg1, s32 arg2, s16 arg3, s32 arg4, s32 arg5, s32 arg6) {
    s16 sp16;
    s16 sp14;
    s16 sp12;
    s16 sp10;
    s32 var_v0;

    sp10 = arg3;
    sp16 = (s16) arg6;
    sp12 = (s16) arg4;
    switch (arg1) {                                 /* irregular */
    case 0:
        var_v0 = arg5;
        if (arg5 < 0) {
            var_v0 = arg5 + 3;
        }
        sp14 = (s16) (var_v0 >> 2);
        break;
    case 1:
        sp14 = (s16) (arg5 / 2);
        break;
    case 2:
        sp14 = (s16) arg5;
        break;
    }
    func_800599B8(&sp10, arg0);
    return func_80058B40(arg1, arg2, arg3, arg4) & 0xFFFF;
}
