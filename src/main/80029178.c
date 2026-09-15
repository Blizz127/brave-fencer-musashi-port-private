/* Exact retail word export for [80029178,800291A0); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 *D_800AE648;

s32 func_80029178(u32 arg0) {
    return (*(&D_800AE648 + (arg0 >> 3)) & (1 << (arg0 & 7))) != 0;
}
