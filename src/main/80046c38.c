/* Exact retail word export [80046C38,80046CFC); verified against pinned EXE and asm. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_800C6D40;
extern s32 D_800C7C84;
extern s32 D_800C7C94;
extern s32 D_800C7F00;

s32 func_80046C38(s32 *arg0, u16 **arg1) {
    s32 var_v0;
    u16 *var_a2;

    var_a2 = D_800C7C94 + (D_800C6D40 << 5);
    if ((*var_a2 & 0xFFFF) == 1) {
        D_800C6D40 = 0;
        if (D_800C7C84 != 0) {
            *var_a2 = 0;
        }
        var_a2 = D_800C7C94 + (D_800C6D40 << 5);
    }
    var_v0 = 1;
    if ((*var_a2 & 0xFFFF) == 2) {
        *var_a2 = 4;
        var_v0 = 0;
        *arg0 = D_800C7C94 + (D_800C7F00 << 5) + (D_800C6D40 * 0x7E0);
        *arg1 = var_a2;
    }
    return var_v0;
}
