/* Exact retail word export for [8001B788,8001B7C4); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 *D_80063138;
extern s32 *D_800AE830;

s32 func_8001B788(s16 arg0) {
    return *(&D_800AE830 + (*(&D_80063138 + (arg0 * 6)) * 8));
}
