/* Exact overlay word export for [800CEE2C,800CF02C) from MAIN.CD
 * member0007 (extracted/overlays/main/0007.bin offset 0x34, base 800CEDF8).
 * Full func_800CEE2C including prologue, 800CEEC8 dispatcher, table[0]
 * 800CEEFC, and 800CEF60/800CEF94/800CEFF8. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0007.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8001534C(s32, s32 (*)(), s32, s32, s32, s32);        /* extern */
extern s32 D_800CFABF;
extern s32 D_800CFAC4;
extern s32 D_800CFAD4;
extern s32 D_800CFADC;
extern s32 D_800D1364;
extern s32 D_800AF630;
extern u8 D_800B99E4;

void func_800CEE2C(void) {
    s32 (*var_a1)();
    s32 var_a0;
    D_800CFABF = (s8) (D_800B99E4 + 0x30);
    func_8001534C(1, D_800CFABF - 0xB, 0x60, 0x64, 0, 0);
    var_a0 = 2;
    if (D_800D1364 != 0) {
        var_a1 = D_800CFAC4;
    } else {
        var_a0 = 3;
        var_a1 = D_800CFAD4;
    }
    func_8001534C(var_a0, var_a1, 0x60, 0x70, 0, 0);
    if ((u16) D_800AF630.unkA3B4 < 4U) {
        *(D_800CFADC + (D_800AF630.unkA3B4 * 4))();
    }
}
