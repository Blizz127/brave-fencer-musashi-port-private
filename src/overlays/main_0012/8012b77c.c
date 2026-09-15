/* Overlay range [8012B77C,8012B864) from MAIN.CD member 0012.
 * SHA256(span)=fc1c80f04e2c8e1636d3e46d05b9fcb754341cc066ca6dca460fc435b658e6e2.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_8004787C(s32);                             /* extern */
s32 func_80047948(s32);                             /* extern */
s32 func_8004CFEC(s32, s32);                        /* extern */

void func_8012B77C(s32 *arg0, void *arg1, void *arg2) {
    s32 temp_s0;
    s32 temp_s0_2;
    s32 temp_s1;
    s32 temp_s2;
    s32 temp_s5;

    temp_s5 = arg2->unkA - arg1->unkA;
    temp_s1 = arg2->unk2 - arg1->unk2;
    temp_s2 = arg2->unk6 - arg1->unk6;
    temp_s0 = (func_8004CFEC(-temp_s5, temp_s1) - 0x400) & 0xFFF;
    temp_s0_2 = func_80047948(temp_s0);
    *arg0 = (((saved_reg_s4 & 0xFFFF) | (temp_s0 << 0x10)) & 0xFFFF0000) | (func_8004CFEC(temp_s2, -((s32) ((temp_s5 * temp_s0_2) + (temp_s1 * func_8004787C(temp_s0))) >> 0xC)) & 0xFFFF);
}
