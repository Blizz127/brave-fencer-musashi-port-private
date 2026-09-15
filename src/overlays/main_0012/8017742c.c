/* Overlay range [8017742C,801775E0) from MAIN.CD member 0012.
 * SHA256(span)=adcdfbf9ef32e734be83965c5dbe3404b85faef43ffe4e644bafa07a92b4bc68.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern u8 D_8011F7AB;
extern s32 D_8011F7F0;
extern u8 D_8011F837;

void *func_8017742C(void *arg0, s16 arg1, s16 arg2) {
    s32 temp_v1;
    void *temp_a3;

    arg0->unk0 = (s32) (((arg0 - 0x14) & 0xFFFFFF) | 0x03000000);
    arg0->unk7 = 0x60;
    if ((u8) D_8011F837 < 0x80U) {
        arg0->unk4 = 0xFF;
        arg0->unk6 = 0x10;
        arg0->unk5 = 0x10;
    } else if (D_8011F837 == 0x80) {
        switch (D_8011F7AB) {                       /* irregular */
        default:
            D_8011F7AB = 0;
            /* fallthrough */
        case 0:
            arg0->unk4 = 0xFF;
            arg0->unk6 = 0x30;
            arg0->unk5 = 0x30;
            break;
        case 1:
            arg0->unk5 = 0xFF;
            arg0->unk6 = 0x30;
block_12:
            arg0->unk4 = 0x30;
            break;
        case 2:
            arg0->unk6 = 0xFF;
            arg0->unk5 = 0x30;
            goto block_12;
        }
        D_8011F7AB += 1;
    } else {
        arg0->unk5 = 0xFF;
        arg0->unk6 = 0x10;
        arg0->unk4 = 0x10;
    }
    temp_a3 = arg0 + 0x14;
    arg0->unk8 = arg1;
    arg0->unkC = 8;
    temp_v1 = (s32) (D_8011F7F0.unk47 * 3) >> 3;
    arg0->unkA = (s16) ((arg2 + 0x48) - temp_v1);
    arg0->unkE = (s16) temp_v1;
    arg0->unk14 = (s32) (((s32) (temp_a3 - 0x14) & 0xFFFFFF) | 0x03000000);
    temp_a3->unk7 = 0x60;
    temp_a3->unk5 = 0x40;
    temp_a3->unk4 = 0x40;
    if (D_8011F7F0.unk47 != 0) {
        temp_a3->unk6 = 0xA0;
    } else {
        temp_a3->unk6 = 0x40;
    }
    temp_a3->unkC = 8;
    temp_a3->unkE = 0x48;
    temp_a3->unk8 = arg1;
    temp_a3->unkA = arg2;
    return temp_a3 + 0x14;
}
