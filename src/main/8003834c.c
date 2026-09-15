/* Exact retail word export for [8003834C,8003836C); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 *D_800B9ECA;

void func_8003834C(s32 arg0, s16 arg1) {
    *(&D_800B9ECA + (arg0 * 0x1FC)) = arg1;
}
