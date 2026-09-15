/* Exact retail word export for [800419B0,80041A20); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_800401A0();                                 /* static */
extern s32 *D_800B9B40;

s16 func_800419B0(s16 arg0) {
    if (((u32) (arg0 & 0xFFFF) < 0x11U) && (*(&D_800B9B40 + arg0) == 2)) {
        func_800401A0(0);
        *(&D_800B9B40 + arg0) = 1;
        return arg0;
    }
    return -1;
}
