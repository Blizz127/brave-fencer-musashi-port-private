/* Overlay range [8013240C,801325B8) from MAIN.CD member 0012.
 * SHA256(span)=1d8a59c7470fb38abe13ee68f6efc3c56bd23947a322a1094e951025c6fad560.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_801325B8(s32, s32, s32, s32, s32);           /* static */

void func_8013240C(void *arg0) {
    s16 temp_v0;
    s16 temp_v0_2;
    s16 var_v0_2;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_v0;
    s32 var_v1;
    void *temp_a3;
    void *temp_s1;

    temp_s1 = arg0->unk0 + (arg0->unk4 * 8);
    temp_a3 = temp_s1->unk0;
    temp_v1 = arg0->unkC & 0xFFFF3FFF;
    arg0->unkC = temp_v1;
    if (temp_a3 == (void *)-1) {
        var_v0 = temp_v1 | 0x4000;
        goto block_13;
    }
    if (temp_s1->unk6 < 0) {
        var_v1 = 0x1000 - ((s32) (arg0->unk6 << 0xC) / (s16) temp_s1->unk4);
    } else {
        var_v1 = (s32) (arg0->unk6 << 0xC) / (s16) temp_s1->unk4;
    }
    func_801325B8(arg0->unk8, temp_a3->unk0, temp_a3->unk4, temp_a3->unk8, var_v1);
    temp_v0 = temp_s1->unk6;
    if (temp_v0 < 0) {
        var_v0_2 = (u16) arg0->unk6 - temp_v0;
    } else {
        var_v0_2 = (u16) arg0->unk6 + temp_v0;
    }
    arg0->unk6 = var_v0_2;
    if (arg0->unk6 >= temp_s1->unk4) {
        arg0->unk6 = 0;
        temp_v0_2 = (u16) arg0->unk4 + 1;
        arg0->unk4 = temp_v0_2;
        temp_v1_2 = *(((s32) (temp_v0_2 << 0x10) >> 0xD) + arg0->unk0);
        if (temp_v1_2 != -1) {
            if (temp_v1_2 == 0) {
                arg0->unk4 = 0;
                var_v0 = arg0->unkC | 0x8000;
                goto block_13;
            }
        } else {
            var_v0 = arg0->unkC | 0x4000;
block_13:
            arg0->unkC = var_v0;
        }
    }
}
