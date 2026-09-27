/* Exact retail word export for [800381E4,80038210); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 *D_800B9CF0;

u8 func_800381E4(s32 arg0, s32 arg1) {
    return *(&D_800B9CF0 + (((s32) (arg1 << 0x10) >> 0xD) + (arg0 * 0x1FC)));
}
