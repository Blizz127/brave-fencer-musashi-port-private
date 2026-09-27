/* Exact retail word export for [8002D29C,8002D320); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8002EE90();                                  /* static */
void func_8003EDE8(s32, s32, s32);                       /* static */
extern s32 D_800A46B4;
extern s16 D_800A46B8;
extern s8 D_800A46BA;
extern s16 D_800A4EF4;

void func_8002D29C(void) {
    s32 temp_a1;
    s32 temp_s0;
    s32 var_s0;

    temp_s0 = D_800A46B4;
    temp_a1 = (s32) (temp_s0 * D_800A4EF4) >> 0x10;
    func_8003EDE8(0, temp_a1, temp_a1);
    var_s0 = temp_s0 - D_800A46B8;
    if (var_s0 <= 0) {
        D_800A46BA = 0;
        var_s0 = 0;
        func_8002EE90();
    }
    D_800A46B4 = var_s0;
}
