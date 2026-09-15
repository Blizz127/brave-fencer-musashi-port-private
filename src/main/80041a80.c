/* Exact retail word export for [80041A80,80041AB0); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s16 func_80041AB0(s16, s32, s32);                       /* static */

s16 func_80041A80(s16 arg1, s32 arg2) {
    return func_80041AB0(arg1, 1, arg2);
}
