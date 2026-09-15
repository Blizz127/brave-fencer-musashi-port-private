/* Main-exec range [80049F3C,8004A0D4) from the SLUS executable.
 * SHA256(span)=33e9d29231bec8252fc833a5bf3b5c61d409ed9f0566207df031013cef30833a.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006DF1C;

void *func_80049F3C(s32 arg0, void *arg1) {
    s16 temp_t2;
    s16 temp_t3;
    s16 temp_t4;
    s16 temp_t5;
    s16 temp_t6;
    s16 temp_t7_2;
    s16 var_t1;
    s32 temp_t7;
    s32 temp_t9;
    s32 temp_t9_2;
    s32 var_t0;

    if (arg0 < 0) {
        temp_t7 = -arg0;
        if (temp_t7 < 0) {

        }
        temp_t9 = *(D_8006DF1C + ((temp_t7 & 0xFFF) * 4));
        var_t1 = -(s16) temp_t9;
        var_t0 = temp_t9 >> 0x10;
    } else {
        temp_t9_2 = *(D_8006DF1C + ((arg0 & 0xFFF) * 4));
        var_t1 = (s16) temp_t9_2;
        var_t0 = temp_t9_2 >> 0x10;
    }
    temp_t2 = arg1->unk6;
    temp_t5 = arg1->unkC;
    temp_t3 = arg1->unk8;
    temp_t6 = arg1->unkE;
    temp_t4 = arg1->unkA;
    temp_t7_2 = arg1->unk10;
    arg1->unk6 = (s16) ((s32) ((var_t0 * temp_t2) - (var_t1 * temp_t5)) >> 0xC);
    arg1->unk8 = (s16) ((s32) ((var_t0 * temp_t3) - (var_t1 * temp_t6)) >> 0xC);
    arg1->unkA = (s16) ((s32) ((var_t0 * temp_t4) - (var_t1 * temp_t7_2)) >> 0xC);
    arg1->unkC = (s16) ((s32) ((var_t1 * temp_t2) + (var_t0 * temp_t5)) >> 0xC);
    arg1->unkE = (s16) ((s32) ((var_t1 * temp_t3) + (var_t0 * temp_t6)) >> 0xC);
    arg1->unk10 = (s16) ((s32) ((var_t1 * temp_t4) + (var_t0 * temp_t7_2)) >> 0xC);
    return arg1;
}
