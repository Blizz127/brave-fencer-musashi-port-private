/* Exact retail word export for [8002C8BC,8002C8F4); EXE-verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 *D_800C5328;
extern s32 *D_800C532A;

void func_8002C8BC(void) {
    u32 var_v1;

    var_v1 = 0;
    do {
        *(&D_800C5328 + var_v1) = -1;
        *(&D_800C532A + var_v1) = -1;
        var_v1 += 4;
    } while (var_v1 < 0x1E4U);
}
