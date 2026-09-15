/* Overlay range [8017DD28,8017DF18) from MAIN.CD member 0012.
 * SHA256(span)=6cffc999246d9e4de0e07f6c2509bfd0bc6d745aad664c52c3b1fecba9238235.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8005A600(void *, s32, s32, s32, s32);              /* extern */
extern s32 D_80182798;
extern s32 *D_800AE7BC;
extern u16 D_800B9A02;
extern u16 D_80115116;
extern s16 D_8011511A;
extern s16 D_8011512C;
extern s32 D_80115134;

void *func_8017DD28(void *arg0) {
    u16 var_a0;
    void *temp_a0;
    void *temp_a1;
    void *temp_s3;
    void *temp_v1;

    temp_a1 = ((D_8011511A << 5) + D_80115134)->unk18;
    var_a0 = 0;
    if (D_8011512C == 1) {
        var_a0 = *(D_80182798 + ((D_80115116 & 7) * 2));
    }
    arg0->unk0 = 0x04000000;
    arg0->unkC = 0x70;
    arg0->unkD = 0x10;
    arg0->unk4 = 0x64808080;
    arg0->unkE = 0x4056;
    arg0->unk8 = (s16) (temp_a1->unk0 + (var_a0 - 0x60));
    arg0->unk12 = 0x10;
    arg0->unk10 = 0x10;
    arg0->unkA = (s16) (temp_a1->unk2 - 2);
    arg0->unk0 = (s32) ((arg0->unk0 & 0xFF000000) | ((*(&D_800AE7BC + (D_800B9A02 * 0x14)))->unk8 & 0xFFFFFF));
    temp_a0 = *(&D_800AE7BC + (D_800B9A02 * 0x14));
    temp_s3 = arg0 + 0x14;
    temp_a0->unk8 = (s32) ((temp_a0->unk8 & 0xFF000000) | ((s32) arg0 & 0xFFFFFF));
    func_8005A600(temp_s3, 0, 0, 0x15, 0);
    arg0->unk14 = (s32) ((arg0->unk14 & 0xFF000000) | ((*(&D_800AE7BC + (D_800B9A02 * 0x14)))->unk8 & 0xFFFFFF));
    temp_v1 = *(&D_800AE7BC + (D_800B9A02 * 0x14));
    temp_v1->unk8 = (s32) ((temp_v1->unk8 & 0xFF000000) | ((s32) temp_s3 & 0xFFFFFF));
    return temp_s3 + 8;
}
