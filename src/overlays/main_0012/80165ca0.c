/* Overlay range [80165CA0,80165E2C) from MAIN.CD member 0012.
 * SHA256(span)=36240827ac0f2f9dc4e0bdad7c462f44e6f3a9678f198ba2b321bb545bc7ac63.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern u16 D_8011D030;
extern s32 D_80126728;

void func_80165CA0(void) {
    s32 var_a2;
    s32 var_s1;
    s32 var_s1_2;
    u16 *var_s0;
    u16 temp_v0;
    u16 temp_v0_2;
    u16 temp_v0_3;
    u16 temp_v0_4;
    u16 temp_v0_5;
    u16 temp_v1;
    u16 temp_v1_2;
    void *temp_a0;
    void *temp_a1;
    void *temp_v1_3;

    var_s1 = 0;
    var_s0 = &D_8011D030;
    do {
        temp_v1 = *var_s0;
        if (temp_v1 != 0) {
            *((temp_v1 * 4) + D_80126728)(var_s0);
        }
        var_s1 += 1;
        var_s0 += 0x58;
    } while (var_s1 < 0x1E);
    var_s1_2 = 0;
    var_a2 = 0;
    do {
        temp_a1 = var_a2 + &D_8011D030;
        temp_a0 = temp_a1->unk20;
        if (temp_a0 != 0) {
            if (temp_a0->unk0 == 1) {
                temp_v0 = temp_a1->unk6;
                temp_a0->unk8 = temp_v0;
                temp_a0->unk48 = (s32) (s16) temp_v0;
                temp_v0_2 = temp_a1->unkA;
                temp_a0->unkA = temp_v0_2;
                temp_a0->unk4C = (s32) (s16) temp_v0_2;
                temp_v1_2 = temp_a1->unkE;
                temp_a0->unkC = temp_v1_2;
                temp_a0->unk2C = (u16) (temp_a0->unk2C | 1);
                temp_a0->unk50 = (s32) (s16) temp_v1_2;
            } else {
                temp_v1_3 = temp_a0->unk34;
                if (temp_v1_3 != 0) {
                    temp_v0_3 = temp_a1->unk6;
                    temp_a0->unk8 = temp_v0_3;
                    temp_v1_3->unk14 = (s32) (s16) temp_v0_3;
                    temp_v0_4 = temp_a1->unkA;
                    temp_a0->unkA = temp_v0_4;
                    temp_a0->unk34->unk18 = (s32) (s16) temp_v0_4;
                    temp_v0_5 = temp_a1->unkE;
                    temp_a0->unkC = temp_v0_5;
                    temp_a0->unk34->unk1C = (s32) (s16) temp_v0_5;
                } else {
                    temp_a0->unk8 = (u16) temp_a1->unk6;
                    temp_a0->unkA = (u16) temp_a1->unkA;
                    temp_a0->unkC = (u16) temp_a1->unkE;
                }
            }
        }
        var_s1_2 += 1;
        var_a2 += 0x58;
    } while (var_s1_2 < 0x1E);
}
