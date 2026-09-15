/* Overlay range [80162B1C,80162CC4) from MAIN.CD member 0012.
 * SHA256(span)=120ecd9b610b5d531c5e798c9d68a3a566013eaf8b489648838b963535b4f14a.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80162CC4(void *, u16);                       /* static */
extern s32 *D_8011F9D0;
extern s32 D_80126D40;

void func_80162B1C(void) {
    s32 (*temp_v0)();
    s32 temp_s3;
    s32 var_s1;
    s32 var_s2;
    u16 temp_a1;
    u16 temp_v0_2;
    u16 temp_v0_3;
    u16 temp_v0_4;
    u16 temp_v0_5;
    u16 temp_v0_6;
    u16 temp_v1;
    void *temp_a0;
    void *temp_s0;
    void *temp_v1_2;

    temp_s3 = D_80126D40;
    var_s2 = 0;
    var_s1 = 0;
    do {
        temp_s0 = var_s1 + &D_8011F9D0;
        temp_a1 = temp_s0->unk0;
        temp_s0->unk44 = (u16) temp_s0->unk6;
        temp_s0->unk46 = (u16) temp_s0->unkA;
        temp_s0->unk48 = (u16) temp_s0->unkE;
        if (temp_a1 != 0) {
            temp_v0 = ((temp_a1 * 4) + temp_s3)->unk-4;
            if (temp_v0 != 0) {
                temp_v0(temp_s0, temp_a1);
            } else {
                func_80162CC4(temp_s0, temp_a1);
            }
            temp_a0 = temp_s0->unk20;
            if (temp_a0 != 0) {
                if (temp_a0->unk0 == 1) {
                    temp_v0_2 = temp_s0->unk6;
                    temp_a0->unk8 = temp_v0_2;
                    temp_a0->unk48 = (s32) (s16) temp_v0_2;
                    temp_v0_3 = temp_s0->unkA;
                    temp_a0->unkA = temp_v0_3;
                    temp_a0->unk4C = (s32) (s16) temp_v0_3;
                    temp_v1 = temp_s0->unkE;
                    temp_a0->unkC = temp_v1;
                    temp_a0->unk2C = (u16) (temp_a0->unk2C | 1);
                    temp_a0->unk50 = (s32) (s16) temp_v1;
                } else {
                    temp_v1_2 = temp_a0->unk34;
                    if (temp_v1_2 != 0) {
                        temp_v0_4 = temp_s0->unk6;
                        temp_a0->unk8 = temp_v0_4;
                        temp_v1_2->unk14 = (s32) (s16) temp_v0_4;
                        temp_v0_5 = temp_s0->unkA;
                        temp_a0->unkA = temp_v0_5;
                        temp_a0->unk34->unk18 = (s32) (s16) temp_v0_5;
                        temp_v0_6 = temp_s0->unkE;
                        temp_a0->unkC = temp_v0_6;
                        temp_a0->unk34->unk1C = (s32) (s16) temp_v0_6;
                    } else {
                        temp_a0->unk8 = (u16) temp_s0->unk6;
                        temp_a0->unkA = (u16) temp_s0->unkA;
                        temp_a0->unkC = (u16) temp_s0->unkE;
                    }
                }
            }
        }
        var_s2 += 1;
        var_s1 += 0x68;
    } while (var_s2 < 0x14);
}
