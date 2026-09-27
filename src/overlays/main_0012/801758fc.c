/* Overlay range [801758FC,801759D8) from MAIN.CD member 0012.
 * SHA256(span)=d44053038430db6f411e94bdee48e889582ddb028a98560ab513f2e6649c1668.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 *D_800AE7BC;
extern s32 *D_800AF634;
extern u16 D_800B9A02;
extern s32 *D_8011F7A8;
extern s32 *D_8011F7D0;
extern s32 *D_8011F7D8;

void func_801758FC(void) {
    s32 *temp_v1;
    s32 temp_a0;
    s32 temp_a1_2;
    void *temp_a1;
    void *temp_v0;

    temp_a1 = *(&D_800AE7BC + (D_800B9A02 * 0x14));
    temp_a0 = temp_a1->unkC;
    temp_a1->unkC = (s32) ((temp_a0 & 0xFF000000) | (*(&D_8011F7D8 + (D_800B9A02 * 4)) & 0xFFFFFF));
    temp_v1 = *(&D_8011F7D0 + (D_800B9A02 * 4));
    *temp_v1 = (*temp_v1 & 0xFF000000) | (temp_a0 & 0xFFFFFF);
    temp_a1_2 = D_800B9A02 * 0xC;
    temp_v0 = (D_800B9A02 * 4) + &D_8011F7A8;
    *(&D_800AF634 + temp_a1_2) = *(&D_800AF634 + temp_a1_2) + ((s32) (temp_v0->unk30 - (temp_v0->unk28 - 0x14)) >> 2);
}
