/* Main-exec range [8004978C,80049A18) from the SLUS executable.
 * SHA256(span)=63cc495238c216ab03d42e85e1c2a0047bed7e8e6c93d69c64c2d145c39f491e.
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

void *func_8004978C(void *arg0, void *arg1) {
    s16 temp_t7;
    s16 temp_t7_2;
    s16 temp_t7_3;
    s16 temp_t7_4;
    s16 temp_t7_5;
    s16 temp_t7_6;
    s16 var_t3;
    s16 var_t4;
    s16 var_t5;
    s16 var_t6;
    s32 temp_lo;
    s32 temp_t8;
    s32 temp_t8_2;
    s32 temp_t9;
    s32 temp_t9_2;
    s32 temp_t9_3;
    s32 temp_t9_4;
    s32 temp_t9_5;
    s32 temp_t9_6;
    s32 var_t0;
    s32 var_t1;
    s32 var_t2;

    temp_t7 = arg0->unk0;
    if (temp_t7 < 0) {
        temp_t7_2 = -temp_t7;
        if (temp_t7_2 < 0) {

        }
        temp_t9 = *(D_8006DF1C + ((temp_t7_2 & 0xFFF) * 4));
        var_t3 = -(s16) temp_t9;
        var_t0 = temp_t9 >> 0x10;
    } else {
        temp_t9_2 = *(D_8006DF1C + ((temp_t7 & 0xFFF) * 4));
        var_t3 = (s16) temp_t9_2;
        var_t0 = temp_t9_2 >> 0x10;
    }
    temp_t7_3 = arg0->unk2;
    if (temp_t7_3 < 0) {
        temp_t7_4 = -temp_t7_3;
        if (temp_t7_4 < 0) {

        }
        temp_t9_3 = *(D_8006DF1C + ((temp_t7_4 & 0xFFF) * 4));
        var_t4 = (s16) temp_t9_3;
        var_t6 = -var_t4;
        var_t1 = temp_t9_3 >> 0x10;
    } else {
        temp_t9_4 = *(D_8006DF1C + ((temp_t7_3 & 0xFFF) * 4));
        var_t6 = (s16) temp_t9_4;
        var_t4 = -var_t6;
        var_t1 = temp_t9_4 >> 0x10;
    }
    temp_t7_5 = arg0->unk4;
    arg1->unk4 = var_t6;
    temp_lo = var_t1 * var_t0;
    arg1->unkA = (s16) ((s32) -(var_t1 * var_t3) >> 0xC);
    if (temp_t7_5 < 0) {
        arg1->unk10 = (s16) (temp_lo >> 0xC);
        temp_t7_6 = -temp_t7_5;
        if (temp_t7_6 < 0) {

        }
        temp_t9_5 = *(D_8006DF1C + ((temp_t7_6 & 0xFFF) * 4));
        var_t5 = -(s16) temp_t9_5;
        var_t2 = temp_t9_5 >> 0x10;
    } else {
        arg1->unk10 = (s16) (temp_lo >> 0xC);
        temp_t9_6 = *(D_8006DF1C + ((temp_t7_5 & 0xFFF) * 4));
        var_t5 = (s16) temp_t9_6;
        var_t2 = temp_t9_6 >> 0x10;
    }
    arg1->unk0 = (s16) ((s32) (var_t2 * var_t1) >> 0xC);
    arg1->unk2 = (s16) ((s32) -(var_t5 * var_t1) >> 0xC);
    temp_t8 = (s32) (var_t2 * var_t4) >> 0xC;
    arg1->unk6 = (s16) (((s32) (var_t5 * var_t0) >> 0xC) - ((s32) (temp_t8 * var_t3) >> 0xC));
    arg1->unkC = (s16) (((s32) (var_t5 * var_t3) >> 0xC) + ((s32) (temp_t8 * var_t0) >> 0xC));
    temp_t8_2 = (s32) (var_t5 * var_t4) >> 0xC;
    arg1->unk8 = (s16) (((s32) (var_t2 * var_t0) >> 0xC) + ((s32) (temp_t8_2 * var_t3) >> 0xC));
    arg1->unkE = (s16) (((s32) (var_t2 * var_t3) >> 0xC) - ((s32) (temp_t8_2 * var_t0) >> 0xC));
    return arg1;
}
