/* Overlay range [80129010,801290DC) from MAIN.CD member 0012.
 * SHA256(span)=81920458822b3684d851d5b298d56ae2a8106df0c4f426b2261ad9fcc461d7f2.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s16 D_8011DB2C;
extern u16 D_8011DB30;
extern s32 D_80126AEC;

void func_80129010(void) {
    s32 var_s2;
    u16 *var_s0;
    u16 *var_s1;
    u16 temp_v1;
    void *temp_v1_2;

    var_s1 = &D_8011DB30;
    if (D_8011DB2C != 0) {
        var_s2 = 0;
        var_s0 = &D_8011DB30 + 0xE;
        do {
            temp_v1 = *var_s1;
            if (temp_v1 != 0) {
                *((temp_v1 * 4) + D_80126AEC)(var_s1);
                temp_v1_2 = var_s0->unk12;
                if (temp_v1_2 != 0) {
                    temp_v1_2->unk8 = (u16) var_s0->unk-8;
                    var_s0->unk12->unkA = (u16) var_s0->unk-4;
                    var_s0->unk12->unkC = (u16) var_s0->unk0;
                }
            }
            var_s2 += 1;
            var_s0 += 0x38;
            var_s1 += 0x38;
        } while (var_s2 < 0x80);
    }
}
