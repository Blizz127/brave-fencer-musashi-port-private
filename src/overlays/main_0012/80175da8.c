/* Overlay range [80175DA8,80176144) from MAIN.CD member 0012.
 * SHA256(span)=45cd35c7f3cee1909a20b7e98cbcddfac8e045331074f2a9fb69d31e2bf166e2.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_800183E0(void *, void *);                       /* extern */
void func_8005A600(s32 *, s32, s32, s32, s32);               /* extern */
extern s32 D_80181A40;
extern s32 D_80181A90;
extern s32 D_80181A9C;
extern s32 D_80181B1C;
extern s32 D_80181B30;
extern s32 D_80181B48;
s32 *func_8017742C(s32 *, s16, s16, s16);           /* static */
extern s32 *D_800AF634;
extern s32 *D_800AF638;
extern u8 D_800B9A13;
extern s32 *D_800D43D4;
extern s32 *D_800D4414;
extern s32 *D_800D45D4;
extern s32 D_8011F7F0;

void func_80175DA8(s16 arg0) {
    s32 (*var_a1)();
    s32 (*var_v1_2)();
    void *var_a0;
    void *var_a0_2;
    s16 temp_v1;
    s16 var_a3;
    s32 *temp_v0_2;
    s32 *var_s0;
    s32 temp_a0;
    s32 temp_v0;
    s32 temp_v0_3;
    s32 temp_v1_2;
    u16 var_v1;
    void *temp_a0_2;
    void *temp_a1;
    void *temp_a1_2;
    void *temp_a1_3;
    void *temp_a1_4;
    void *temp_s0;
    void *temp_s1;
    void *var_a1_2;
    void *var_a2;

    var_a1 = D_80181A40;
    var_a3 = 0;
    temp_v0 = arg0 * 0xC;
    temp_s1 = &D_8011F7F0 - 0x48;
    var_s0 = *(&D_800AF638 + temp_v0) + (*(&D_800AF634 + temp_v0) * 4);
    var_a2 = var_s0 + 0x10;
    ((arg0 * 4) + temp_s1)->unk28 = var_s0;
    do {
        *var_s0 = ((var_s0 - 0x14) & 0xFFFFFF) | 0x04000000;
        var_a2->unk-C = (s32) var_a1->unk0;
        temp_a1 = var_a1 + 4;
        if (var_a3 < 2) {
            var_a2->unk-8 = (s16) (var_a1->unk4 + temp_s1->unkC);
            var_v1 = temp_s1->unkE;
            var_a1_2 = temp_a1 + 2 + 2;
        } else if (var_a3 == 2) {
            var_a2->unk-8 = (s16) (var_a1->unk4 + temp_s1->unk10);
            var_v1 = temp_s1->unk12;
            var_a1_2 = temp_a1 + 2 + 2;
        } else {
            var_a2->unk-8 = (s16) (var_a1->unk4 + temp_s1->unk14);
            var_v1 = temp_s1->unk16;
            var_a1_2 = temp_a1 + 2 + 2;
        }
        var_a2->unk-6 = (s16) (temp_a1->unk2 + var_v1);
        var_s0 += 0x14;
        temp_v1 = var_a3 + 1;
        var_a3 = temp_v1;
        var_a2->unk-4 = (s32) var_a1_2->unk0;
        var_a1 = var_a1_2 + 4 + 4;
        var_a2->unk0 = (s32) var_a1_2->unk4;
        var_a2 += 0x14;
    } while (temp_v1 < 5);
    temp_s1->unk7 = (u8) D_800B9A13;
    temp_v0_2 = func_8017742C(var_s0, (s16) (temp_s1->unk10 - 0x98), (s16) (temp_s1->unk12 + 9), var_a3);
    func_8005A600(temp_v0_2, 0, 0, 0x16, 0);
    *temp_v0_2 = ((s32) (temp_v0_2 - 0x14) & 0xFFFFFF) | 0x02000000;
    temp_a1_2 = (arg0 * 4) + temp_s1;
    temp_a1_2->unk30 = temp_v0_2;
    temp_a0 = arg0 * 0xC;
    *(&D_800AF634 + temp_a0) = *(&D_800AF634 + temp_a0) + ((s32) ((temp_v0_2 + 0x14) - temp_a1_2->unk28) >> 2);
    temp_s0 = temp_a1_2->unk28;
    if (D_8011F7F0.unk48 != 0) {
        temp_s0->unkD = 0;
    } else {
        temp_s0->unkD = 0xA0;
    }
    temp_a1_3 = (((s32) (arg0 << 0x10) >> 0xE) + temp_s1)->unk28;
    temp_a1_3->unk22 = 0x6CD6;
    temp_v0_3 = D_8011F7F0.unk48 & 0xFF;
    if (D_8011F7F0.unk48 & 0x80) {
        var_a0 = &D_800D45D4;
        temp_a1_3->unk20 = (u16) D_80181A9C;
    } else {
        var_v1_2 = D_80181A90;
        if (temp_v0_3 != 0) {
            var_v1_2 = ((temp_v0_3 - 1) * 2) + D_80181A90;
        }
        temp_a1_3->unk20 = (u16) *var_v1_2;
        var_a0 = *(D_80181B48 + (D_8011F7F0.unk48 * 4));
    }
    func_800183E0(var_a0, temp_a1_3);
    temp_a0_2 = (((s32) (arg0 << 0x10) >> 0xE) + temp_s1)->unk28;
    temp_v1_2 = D_8011F7F0.unk2E << 0x10;
    if (temp_v1_2 != 0) {
        temp_a0_2->unk49 = (u8) *(D_80181B30 + (temp_v1_2 >> 0x14));
    } else {
        temp_a0_2->unk49 = 0xA0U;
    }
    temp_a1_4 = (((s32) (arg0 << 0x10) >> 0xE) + temp_s1)->unk28;
    if ((u16) D_8011F7F0.unk40 < 0x64U) {
        temp_a1_4->unk5D = (u8) *(D_80181B1C + ((D_8011F7F0.unk40 / 5) & 0xFFFF));
    } else {
        temp_a1_4->unk5D = 0U;
    }
    var_a0_2 = &D_800D43D4;
    if (D_8011F7F0.unk1E & 0x8000) {
        var_a0_2 = &D_800D4414;
    }
    func_800183E0(var_a0_2, temp_a1_4);
}
