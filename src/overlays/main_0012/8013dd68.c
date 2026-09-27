/* Overlay range [8013DD68,8013E054) from MAIN.CD member 0012.
 * SHA256(span)=6f81bc9b70335c8ecc7013250b637d8434fc66548ab943acab9616bade891cff.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8005A658(s32 *, s32 (*)(), void *, s32 (*)());      /* extern */
extern s32 D_8017ED24;
extern s32 D_801841AC;
extern s32 D_801841DC;
extern s32 D_801841E0;
extern s32 D_801841E4;
extern s32 *D_800A5E60;
extern s32 D_800AF630;
extern u16 D_800AF7B8;
extern s32 *D_800BA0E4;

void func_8013DD68(void) {
    s8 sp28;
    ? sp10();
    s32 (*var_a3)();
    void *var_a2;
    void *var_a2_2;
    s32 *temp_s0;
    s32 *temp_v1;
    s32 *temp_v1_2;
    s32 *temp_v1_3;
    s32 *var_s0;
    s32 var_a3_2;
    u16 *var_s1;
    u16 temp_s3;
    u16 temp_v0_2;
    void *temp_v0;
    void *var_a1;

    temp_s0 = D_800A5E60;
    var_a3 = sp10;
    temp_s3 = *D_801841AC;
    var_s1 = D_801841AC + 2;
    temp_v0 = (D_800AF7B8 * 0x5C) + &D_800AF630;
    var_a2 = temp_v0 + 0x38;
    do {
        var_a3->unk0 = (s32) var_a2->unk0;
        var_a3->unk4 = (s32) var_a2->unk4;
        var_a3->unk8 = (s32) var_a2->unk8;
        var_a3->unkC = (s32) var_a2->unkC;
        var_a2 += 0x10;
        var_a3 += 0x10;
    } while (var_a2 != (temp_v0 + 0x88));
    var_a3->unk0 = (s32) var_a2->unk0;
    var_a3->unk4 = (s32) var_a2->unk4;
    var_a3->unk8 = (s32) var_a2->unk8;
    sp28 = 0;
    func_8005A658(temp_s0, sp10, var_a2, var_a3);
    var_a3_2 = 0;
    var_a2_2 = &D_800BA0E4;
    *temp_s0 = (*temp_s0 & 0xFF000000) | (*(&D_800BA0E4 + (D_800AF630.unkA3D2 * 0x10)) & 0xFFFFFF);
    temp_v1 = (D_800AF630.unkA3D2 * 0x10) + &D_800BA0E4;
    var_s0 = temp_s0 + 0x40;
    *temp_v1 = (*temp_v1 & 0xFF000000) | ((s32) temp_s0 & 0xFFFFFF);
    if (temp_s3 != 0) {
        var_a2_2 = var_s1 + 0xE;
        var_a1 = var_s0 + 0x16;
        do {
            var_a1->unk-13 = 5;
            var_a1->unk-B = 0x64;
            var_a1->unk-E = (s8) D_801841DC;
            var_a1->unk-D = (s8) D_801841E0;
            var_a1->unk-12 = (s32) ((var_a2_2->unk-A & 0x9FF) | 0xE1000400);
            var_a1->unk-C = (s8) D_801841E4;
            var_a1->unk-A = (u16) var_a2_2->unk-6;
            var_a3_2 += 1;
            var_a1->unk-8 = (u16) var_a2_2->unk-4;
            var_a1->unk-6 = (s8) *var_s1;
            var_a1->unk-4 = 0x7800;
            var_a1->unk-5 = (s8) var_a2_2->unk-C;
            var_s1 += 0x10;
            var_a1->unk-2 = (u16) var_a2_2->unk-2;
            temp_v0_2 = var_a2_2->unk0;
            var_a2_2 += 0x10;
            var_a1->unk0 = temp_v0_2;
            *var_s0 = (*var_s0 & 0xFF000000) | (*((D_800AF630.unkA3D2 * 0x10) + &D_800BA0E4) & 0xFFFFFF);
            var_a1 += 0x18;
            temp_v1_2 = (D_800AF630.unkA3D2 * 0x10) + &D_800BA0E4;
            *temp_v1_2 = (*temp_v1_2 & 0xFF000000) | ((s32) var_s0 & 0xFFFFFF);
            var_s0 += 0x18;
        } while (var_a3_2 < (s32) temp_s3);
    }
    func_8005A658(var_s0, D_8017ED24, var_a2_2, (s32 (*)()) var_a3_2);
    *var_s0 = (*var_s0 & 0xFF000000) | (*(&D_800BA0E4 + (D_800AF630.unkA3D2 * 0x10)) & 0xFFFFFF);
    temp_v1_3 = (D_800AF630.unkA3D2 * 0x10) + &D_800BA0E4;
    D_800A5E60 = var_s0 + 0x40;
    *temp_v1_3 = (*temp_v1_3 & 0xFF000000) | ((s32) var_s0 & 0xFFFFFF);
}
