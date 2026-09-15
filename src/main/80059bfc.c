/* Exact retail word export for [80059BFC,80059CF4); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void D_80072784();
extern s32 D_80072780;
extern s32 D_80072844;
extern s32 D_800741C0;
extern u8 D_8007278A;

void func_80059BFC(s32 *arg0, s32 arg1) {
    if ((u8) D_8007278A >= 2U) {
        D_80072784(D_800741C0, arg0, arg1);
    }
    D_80072780->unk2C(arg0, arg1);
    *arg0 = (s32) D_80072844 & 0xFFFFFF;
}
