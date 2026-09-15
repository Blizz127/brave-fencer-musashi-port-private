/* Exact overlay word export for [8017C008,8017C080) from MAIN.CD
 * member0012 (extracted/overlays/main/0012.bin offset 0x7BEB0, base 80128158).
 * Callee of live STOP 8017BF38; jal 8002D4C8.
 */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8002D4C8(s32, s32);                              /* extern */
extern s32 D_801857EC;
extern s32 D_801857F0;
extern s32 func_8017C080;
extern s8 D_800B9A13;
extern s8 D_800B9A15;
extern s16 D_80115110;
extern s16 D_80115112;
extern s16 D_80115126;
extern s32 (*D_8011DB24)();

void func_8017C008(s16 arg0, s16 arg1) {
    D_800B9A15 = 1;
    D_800B9A13 = 5;
    D_80115110 = 4;
    D_80115126 = arg0;
    D_801857F0 = arg1;
    D_801857EC = arg1;
    D_80115112 = 0;
    D_8011DB24 = func_8017C080;
    func_8002D4C8(0x1E, 0);
}
