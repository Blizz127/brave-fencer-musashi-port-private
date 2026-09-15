/* Exact retail word export for [8002F064,8002F0D0); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_800A2BA0;
extern s32 D_800C7D2C;

void func_8002F064(s32 arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = ~arg1;
    if (arg0 == 1) {
        D_800A2BA0 &= temp_v0;
        D_800C7D2C |= arg1;
        return;
    }
    D_800C7D2C &= temp_v0;
    D_800A2BA0 |= arg1;
}
