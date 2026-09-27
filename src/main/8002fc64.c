/* Exact retail word export for [8002FC64,8002FD14); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80037D74();                                  /* static */
void func_8003C438(s32, s32);                            /* static */
s32 func_8003C498(s32);                             /* static */
s32 func_8003C4F0();                               /* static */
extern u8 D_8006AEF4;
extern s32 D_800A46C8;

s32 func_8002FC64(s32 arg0, s32 arg1) {
    if (((D_8006AEF4 & 1) && (func_8003C4F0(0) == 0)) || (func_8003C498(D_800A46C8) == 0)) {
        func_80037D74();
        return 0;
    }
    func_8003C438(arg1, arg0);
    D_800A46C8 += arg0;
    D_8006AEF4 |= 1;
    return 1;
}
