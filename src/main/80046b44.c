/* Exact retail word export [80046B44,80046BFC); verified against pinned EXE and asm. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_800C6D40;
extern s32 D_800C7C94;
extern s32 D_800C7F00;

s32 func_80046B44(s32 arg0) {
    s32 temp_a1;
    s32 temp_v0;
    s32 var_a0;
    u16 temp_v1_2;
    void *temp_v1;

    temp_a1 = (arg0 - (D_800C7C94 + (D_800C7F00 << 5))) / 2016;
    temp_v1 = D_800C7C94 + (temp_a1 << 5);
    temp_v1_2 = temp_v1->unk6;
    if (temp_v1->unk0 != 4) {
        return 1;
    }
    var_a0 = 0;
    if ((s16) temp_v1_2 > 0) {
        do {
            temp_v0 = var_a0 + temp_a1;
            var_a0 += 1;
            *(D_800C7C94 + (temp_v0 << 5)) = 0;
        } while (var_a0 < (s16) temp_v1_2);
    }
    D_800C6D40 = var_a0 + temp_a1;
    return 0;
}
