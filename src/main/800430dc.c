/* Exact retail word export for [800430DC,80043300); EXE-verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006CC90;
extern s32 D_800735BC;
extern s32 D_800735CC;
extern s32 D_800735E8;
s32 func_8004359C(s32);                             /* static */
s32 func_80043830(s32, s8 *, void *, s8);                /* static */
void func_8005C604(s32 (*)(), s32, s32);                 /* static */

s32 func_800430DC(void *arg1) {
    s32 sp18;
    s8 sp10;
    s32 temp_s1;
    s32 temp_s3;
    s32 temp_s5;
    s32 var_s0;
    s32 var_s2;
    s32 var_s2_2;
    s8 temp_a3;
    u8 temp_a1;
    u8 temp_a2;
    void *var_s0_2;
    void *var_s1;

    sp10 = 1;
    temp_s5 = func_8004359C(0);
    if (func_80043830(0x13, 0, &sp18) != 0) {
        var_s0 = ((sp19 >> 4) * 0xA) + (sp19 & 0xF);
        temp_s3 = ((sp1A >> 4) * 0xA) + (sp1A & 0xF);
        if (D_8006CC90 >= 2) {
            func_8005C604(D_800735BC, var_s0, temp_s3);
        }
        sp10 = 0;
        if (func_80043830(0x14, &sp10, &sp18) != 0) {
            arg1->unk0 = sp19;
            arg1->unk2 = 0;
            arg1->unk1 = sp1A;
            var_s2 = 1;
            if (temp_s3 >= var_s0) {
                var_s1 = arg1 + 4;
loop_6:
                temp_a3 = ((var_s0 / 10) * 0x10) + (var_s0 % 10);
                sp10 = temp_a3;
                var_s2 += 1;
                if (func_80043830(0x14, &sp10, &sp18, temp_a3) != 0) {
                    var_s1->unk0 = sp19;
                    var_s0 += 1;
                    var_s1->unk2 = 0;
                    var_s1->unk1 = sp1A;
                    var_s1 += 4;
                    if (temp_s3 < var_s0) {
                        goto block_8;
                    }
                    goto loop_6;
                }
                goto block_13;
            }
block_8:
            temp_s1 = var_s2 - 1;
            if (D_8006CC90 >= 2) {
                var_s2_2 = 0;
                if (temp_s1 >= 0) {
                    var_s0_2 = arg1;
                    do {
                        temp_a1 = var_s0_2->unk0;
                        temp_a2 = var_s0_2->unk1;
                        var_s0_2 += 4;
                        var_s2_2 += 1;
                        func_8005C604(D_800735CC, (s32) temp_a1, (s32) temp_a2);
                    } while (temp_s1 >= var_s2_2);
                }
            }
            func_8004359C(temp_s5);
            return temp_s1;
        }
        goto block_13;
    }
block_13:
    if (D_8006CC90 != 0) {
        func_8005C604(D_800735E8);
    }
    func_8004359C(temp_s5);
    return 0;
}
