/* Exact overlay word export for [800CF02C,800D1378) from MAIN.CD
 * member0007 (extracted/overlays/main/0007.bin offset 0x234, base 800CEDF8).
 * 800CF02C dispatcher + OPDEMO/Start handlers (800CF068, 800CF3B0, ...). */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0007.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_800D133C;
extern u16 D_800B99E4;

void func_800CF02C(void) {
    *(D_800D133C + (D_800B99E4 * 4))();
}
