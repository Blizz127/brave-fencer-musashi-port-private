/* Exact retail word export for [800527C4,8005283C); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8005283C(s32, s32, s16);                     /* static */
extern s16 D_800A644C;
extern s8 D_800A644E;
extern s8 D_800A644F;
extern s8 D_800A6450;
extern s16 D_800A649C;
extern s16 D_800A649E;
extern s8 D_800A64A8;
extern s8 D_800A64A9;
extern s16 D_800C7C88;

void func_800527C4(s16 arg0, s16 arg1, s32 arg2, s8 arg3, u16 arg4) {
    s16 temp_a2;

    temp_a2 = arg2 & 4;
    D_800A649C = arg0;
    D_800A649E = arg1;
    D_800A644C = 0;
    D_800A644E = arg3;
    D_800A644F = 0;
    D_800A6450 = 0;
    D_800A64A8 = arg2 & 1;
    D_800C7C88 = temp_a2;
    D_800A64A9 = (s8) arg4;
    func_8005283C(arg0 & 0xFFFF, arg1 & 0xFFFF, temp_a2);
}
