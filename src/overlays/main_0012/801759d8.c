/* Overlay range [801759D8,80175AB8) from MAIN.CD member 0012.
 * SHA256(span)=7faf63be181e30fe9648330727a88b01aac9f6a93d0e09f9302e583c9e638568.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 *D_800AE7BC;
extern s32 *D_800AF634;
extern u16 D_800B9A02;
extern s32 *D_8011F7A8;
extern u8 D_8011F7B1;

void func_801759D8(void) {
    s32 *temp_v1;
    s32 temp_a0;
    s32 temp_a1_2;
    void *temp_a1;
    void *temp_v0;

    if (D_8011F7B1 == 0) {
        temp_a1 = *(&D_800AE7BC + (D_800B9A02 * 0x14));
        temp_a0 = M2C_FIELD(temp_a1, s32 *, 4);
        M2C_FIELD(temp_a1, s32 *, 4) = (s32) ((temp_a0 & 0xFF000000) | (M2C_FIELD(((D_800B9A02 * 4) + &D_8011F7A8), s32 *, 0x40) & 0xFFFFFF));
        temp_v1 = M2C_FIELD(((D_800B9A02 * 4) + &D_8011F7A8), s32 **, 0x38);
        *temp_v1 = (*temp_v1 & 0xFF000000) | (temp_a0 & 0xFFFFFF);
        temp_a1_2 = D_800B9A02 * 0xC;
        temp_v0 = (D_800B9A02 * 4) + &D_8011F7A8;
        *(&D_800AF634 + temp_a1_2) = *(&D_800AF634 + temp_a1_2) + ((s32) (M2C_FIELD(temp_v0, s32 *, 0x40) - (M2C_FIELD(temp_v0, s32 *, 0x38) - 0x14)) >> 2);
    }
}
