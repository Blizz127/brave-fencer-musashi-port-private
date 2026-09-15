/* Exact retail word export for [80010B40,80010BB4); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_800629F4;
extern s32 D_800AF630;

void func_80010B40(void) {
    *((D_800AF630.unkA3AE * 4) + D_800629F4)();
}
