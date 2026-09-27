/* Exact retail word export for [8002EFF8,8002F064); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_800A2B98;
extern s32 D_800C7D20;

void func_8002EFF8(s32 arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = ~arg1;
    if (arg0 == 1) {
        D_800A2B98 &= temp_v0;
        D_800C7D20 |= arg1;
        return;
    }
    D_800C7D20 &= temp_v0;
    D_800A2B98 |= arg1;
}
