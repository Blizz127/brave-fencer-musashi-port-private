/* Exact retail word export for [8004787C,800478B8); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_800478B8(s32);                             /* static */

s32 func_8004787C(s32 arg0) {
    if (arg0 >= 0) {
        return func_800478B8(arg0 & 0xFFF);
    }
    return -func_800478B8(-arg0 & 0xFFF);
}
