/* Exact retail word export [80046BFC,80046C38); verified against pinned EXE and asm. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_800C7C94;

void func_80046BFC(s32 arg0, u32 arg1) {
    s32 temp_v0;
    u32 var_a2;

    var_a2 = 0;
    if (arg1 != 0) {
        do {
            temp_v0 = var_a2 + arg0;
            var_a2 += 1;
            *(D_800C7C94 + (temp_v0 << 5)) = 0;
        } while (var_a2 < arg1);
    }
}
