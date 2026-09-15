/* Overlay range [800CF408,800CF6D0) from MAIN.CD member 0007.
 * SHA256(span)=5decf1ffd0193323d0c7efd3ffe43b7e2dcdb7a07277476b8fc36a122d286477.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0007.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern void *D_800A5E60;
extern s32 *D_800AA60C;
extern u16 D_800B9A02;

void func_800CF408(s32 arg0, s32 arg1) {
    s16 temp_a0;
    s16 temp_a1;
    s16 temp_a1_2;
    s16 temp_s3;
    s32 *temp_a0_2;
    s32 *temp_a0_3;
    s32 *temp_a2;
    s32 *temp_a2_2;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;

    temp_a0 = arg0 - 0xA0;
    temp_a1 = arg1 - 0x78;
    temp_s3 = temp_a0 + 0xA0;
    D_800A5E60->unk3 = 5;
    D_800A5E60->unk4 = 0xE1000086;
    D_800A5E60->unkB = 0x64;
    D_800A5E60->unk12 = 0x7980;
    D_800A5E60->unkA = 0x80;
    D_800A5E60->unk9 = 0x80;
    D_800A5E60->unk8 = 0x80;
    D_800A5E60->unkC = temp_a0;
    D_800A5E60->unkE = temp_a1;
    D_800A5E60->unk10 = 0x20;
    D_800A5E60->unk11 = 0;
    D_800A5E60->unk14 = 0xA0;
    D_800A5E60->unk16 = 0x100;
    D_800A5E60->unk0 = (s32) ((D_800A5E60->unk0 & 0xFF000000) | (*(&D_800AA60C + (D_800B9A02 << 0xE)) & 0xFFFFFF));
    temp_a2 = (D_800B9A02 << 0xE) + &D_800AA60C;
    temp_v0 = D_800A5E60 + 0x18;
    *temp_a2 = (*temp_a2 & 0xFF000000) | ((s32) D_800A5E60 & 0xFFFFFF);
    temp_v0->unk4 = 0xE1000087;
    temp_v0->unk3 = 5;
    temp_v0->unkB = 0x64;
    temp_v0->unk12 = 0x7980;
    temp_v0->unkA = 0x80;
    temp_v0->unk9 = 0x80;
    temp_v0->unk8 = 0x80;
    temp_v0->unkE = temp_a1;
    temp_a1_2 = temp_a1 + 0x100;
    temp_v0->unkC = temp_s3;
    temp_v0->unk10 = 0x40;
    temp_v0->unk11 = 0;
    temp_v0->unk14 = 0xA0;
    temp_v0->unk16 = 0x100;
    D_800A5E60->unk18 = (s32) ((D_800A5E60->unk18 & 0xFF000000) | (*((D_800B9A02 << 0xE) + &D_800AA60C) & 0xFFFFFF));
    temp_a2_2 = (D_800B9A02 << 0xE) + &D_800AA60C;
    temp_v0_2 = temp_v0 + 0x18;
    *temp_a2_2 = (*temp_a2_2 & 0xFF000000) | ((s32) temp_v0 & 0xFFFFFF);
    temp_v0_2->unk3 = 5;
    temp_v0_2->unk4 = 0xE1000096;
    temp_v0_2->unkB = 0x64;
    temp_v0_2->unk12 = 0x7980;
    temp_v0_2->unkA = 0x80;
    temp_v0_2->unk9 = 0x80;
    temp_v0_2->unk8 = 0x80;
    temp_v0_2->unkC = temp_a0;
    temp_v0_2->unkE = temp_a1_2;
    temp_v0_2->unk10 = 0x20;
    temp_v0_2->unk11 = 0;
    temp_v0_2->unk14 = 0xA0;
    temp_v0_2->unk16 = 0x100;
    temp_v0->unk18 = (s32) ((temp_v0->unk18 & 0xFF000000) | (*((D_800B9A02 << 0xE) + &D_800AA60C) & 0xFFFFFF));
    temp_a0_2 = (D_800B9A02 << 0xE) + &D_800AA60C;
    temp_v0_3 = temp_v0_2 + 0x18;
    *temp_a0_2 = (*temp_a0_2 & 0xFF000000) | ((s32) temp_v0_2 & 0xFFFFFF);
    temp_v0_3->unk3 = 5;
    temp_v0_3->unk4 = 0xE1000097;
    temp_v0_3->unkB = 0x64;
    temp_v0_3->unk12 = 0x7980;
    temp_v0_3->unkA = 0x80;
    temp_v0_3->unk9 = 0x80;
    temp_v0_3->unk8 = 0x80;
    temp_v0_3->unkC = temp_s3;
    temp_v0_3->unkE = temp_a1_2;
    temp_v0_3->unk10 = 0x40;
    temp_v0_3->unk11 = 0;
    temp_v0_3->unk14 = 0xA0;
    temp_v0_3->unk16 = 0x100;
    temp_v0_2->unk18 = (s32) ((temp_v0_2->unk18 & 0xFF000000) | (*((D_800B9A02 << 0xE) + &D_800AA60C) & 0xFFFFFF));
    temp_a0_3 = (D_800B9A02 << 0xE) + &D_800AA60C;
    D_800A5E60 = temp_v0_3 + 0x18;
    *temp_a0_3 = (*temp_a0_3 & 0xFF000000) | ((s32) temp_v0_3 & 0xFFFFFF);
}
