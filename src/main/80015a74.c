/* Exact retail word export for [80015A74,80015AD0); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80015A74(void) {
    s32 var_a2;

    var_a2 = 9;
    do {
        var_a2 -= 1;
    } while (var_a2 >= 0);
}
