/* Overlay range [8012CEB0,8012CFA8) from MAIN.CD member 0012.
 * SHA256(span)=0c436c382f288f9d4b2e5b550279fb5855f2be4d581742fae71ff66869ce3ff7.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80133784(s16, void *, void *);                   /* static */

s32 func_8012CEB0(void *arg0, void *arg1, s16 arg2) {
    s32 sp10;
    s32 temp_s0;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v1;
    s32 var_v0;
    u8 temp_a0;
    u8 temp_a1;

    if (arg2 & 1) {
        temp_a1 = arg1->unk6;
        temp_s0 = func_80133784(arg2, arg0, arg1) | temp_a1;
        if ((temp_a1 == 2) || (var_v0 = temp_s0, (temp_a1 == 0x1B))) {
            return temp_s0 | 0x1000;
        }
        /* Duplicate return node #10. Try simplifying control flow for better match */
        return var_v0;
    }
    temp_v0 = func_80133784(0, arg0, arg1);
    if ((temp_v0 == 0) || (temp_v0_2 = func_80133784(2, arg1, &sp10), ((temp_v0_2 & 0x6000) == 0))) {
        return 0;
    }
    temp_a0 = arg1->unk6;
    arg1->unk2 = sp12;
    temp_v1 = (temp_v0_2 & 0xFFFF7FFF) | (temp_v0 & 0x8000) | temp_a0;
    if ((temp_a0 == 2) || (var_v0 = temp_v1, (temp_a0 == 0x1B))) {
        var_v0 = temp_v1 | 0x1000;
    }
    return var_v0;
}
