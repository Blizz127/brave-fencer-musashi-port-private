/* Exact retail word export for [8002FDE8,8002FF0C); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_800652F0;
void func_8002ED90();                                  /* static */
void func_800415A8(s16);                               /* static */
s16 func_800419B0(s16);                             /* static */
s16 func_80041A80(s32, s32, s32);                       /* static */
extern s32 D_800A469C;
extern s16 D_800A46A0;
extern s16 D_800A46A2;
extern s8 D_800A46B0;
extern s16 D_800A46D2;

s32 func_8002FDE8(s32 arg0, s32 arg1) {
    s16 temp_v0;
    s16 var_v0;
    s32 temp_a2;

    func_8002ED90();
    var_v0 = arg0 | 0x4000;
    if (D_800A46A2 >= 0) {
        func_800415A8(D_800A46A2);
        D_800A46A2 = -1;
        var_v0 = arg0 | 0x4000;
    }
    D_800A46A0 = var_v0;
    D_800A46B0 = 1;
    temp_a2 = *(D_800652F0 + (arg0 * 4));
    D_800A469C = temp_a2;
    temp_v0 = func_80041A80(arg1, -1, temp_a2);
    D_800A46D2 = temp_v0;
    D_800A46A2 = temp_v0;
    if (temp_v0 == -1) {
        D_800A46B0 = 1;
        return 1;
    }
    if (func_800419B0(temp_v0) != -1) {
        D_800A46B0 = 0;
        return 1;
    }
    func_800415A8(D_800A46D2);
    D_800A46A2 = -1;
    D_800A46B0 = 1;
    return 1;
}
