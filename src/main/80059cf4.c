/* Exact retail word export for [80059CF4,80059D68); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void D_80072784();
extern s32 D_80072780;
extern s32 D_800741D8;
extern u8 D_8007278A;

void func_80059CF4(s32 arg0) {
    if ((u8) D_8007278A >= 2U) {
        D_80072784(D_800741D8, arg0);
    }
    D_80072780->unk8(D_80072780->unk18, arg0, 0, 0);
}
