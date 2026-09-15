/* Exact retail word export [80046ABC,80046B44); verified against pinned EXE and asm. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80046CFC();                                 /* static */
extern s32 D_80078E38;
extern s16 D_800A2B94;
extern s32 D_800A2B9C;
extern s32 D_800A5E80;
extern s32 D_800A5E84;
extern s32 D_800A6424;
extern s32 D_800A6608;
extern s32 D_800C7C78;

void func_80046ABC(s32 arg0, s32 arg3, s32 arg4) {
    func_80046CFC(1);
    D_800C7C78 = 0;
    D_800A5E80 = arg3;
    D_800A2B9C = arg0 & 1;
    D_800A6608 = 0;
    D_800A6424 = 0;
    D_800A2B94 = 0;
    D_80078E38 = 0;
    D_800A5E84 = arg4;
}
