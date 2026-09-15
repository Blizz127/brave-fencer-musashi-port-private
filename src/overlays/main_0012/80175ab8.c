/* Overlay range [80175AB8,80175DA8) from MAIN.CD member 0012.
 * SHA256(span)=ba9bcb057a0826628da442b740462ad69c22a0a2b1433bf5ee12eccf7bbe5379.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80024054(s32, void *);                          /* extern */
void func_8005A600(s32 *, s32, s32, s32, s32);               /* extern */
extern s32 D_80181AA0;
s32 func_80176D94(s32, s16, s16);                   /* static */
s32 func_801770E0(s32, s16, s16);                   /* static */
s32 func_80177940(s32, s16, s16, s16);              /* static */
s32 func_80177B5C(s32, s16, u8, s16, s32);          /* static */
s32 func_80177EA4(s32, s16, s16, s16);              /* static */
s32 *func_80178298(s32, void *, s16, s16);             /* static */
s16 func_801783D0(s32, s32);                          /* static */
extern s32 *D_800AF634;
extern s32 *D_800AF638;
extern u16 D_8011F7B4;
extern u16 D_8011F7B6;
extern u16 D_8011F7BC;
extern u16 D_8011F7BE;
extern s32 D_8011F7F0;
extern s32 D_8011F804;
extern u16 D_8011F80A;
extern u16 D_8011F824;
extern u8 D_8011F832;
extern u8 D_8011F83A;

void func_80175AB8(s16 arg0) {
    s32 sp18;
    s16 temp_s0;
    s32 *temp_v0;
    s32 temp_s1;
    s32 temp_s1_2;
    s32 temp_s1_3;
    s32 temp_s1_4;
    s32 temp_s1_5;
    s32 temp_s3;
    s32 temp_v1;
    u16 var_a0;
    u8 temp_v1_2;
    void *temp_s4;

    temp_s3 = arg0 * 0xC;
    temp_s1 = *(&D_800AF638 + temp_s3) + (*(&D_800AF634 + temp_s3) * 4);
    temp_s4 = (arg0 * 4) + (&D_8011F7F0 - 0x48);
    temp_s4->unk18 = temp_s1;
    temp_s1_2 = func_801770E0(func_80176D94(temp_s1, (s16) (D_8011F7B4 - 0x71), (s16) (D_8011F7B6 + 0x51)), (s16) (D_8011F7B4 - 0x71), (s16) (D_8011F7B6 + 0x65));
    temp_s1_3 = func_80177EA4(temp_s1_2, func_801783D0(D_8011F804, 0), (s16) (D_8011F7BC + 0x39), (s16) (D_8011F7BE + 0x51));
    var_a0 = 0x3E7;
    if ((u16) D_8011F824 < 0x3E8U) {
        var_a0 = D_8011F824;
    }
    temp_s1_4 = func_80177B5C(temp_s1_3, func_801783D0((s32) var_a0, 4), D_8011F832, (s16) (D_8011F7F0.unk-34 + 0x39), (s32) (s16) (D_8011F7F0.unk-32 + 0x65));
    temp_v1 = D_8011F80A / 15;
    temp_s0 = func_801783D0((s32) (temp_v1 << 0x10) >> 0x12, 8);
    temp_s1_5 = func_80177940(temp_s1_4, (s16) (temp_s0 + func_801783D0((temp_v1 & 3) * 0xF, 0)), (s16) (D_8011F7F0.unk-34 + 0x76), (s16) (D_8011F7F0.unk-32 + 0x65));
    temp_v1_2 = D_8011F83A & 0x7F;
    D_8011F83A = temp_v1_2;
    func_80024054(*(D_80181AA0 + (temp_v1_2 * 4)), &sp18);
    temp_v0 = func_80178298(temp_s1_5, &sp18, (s16) (D_8011F7F0.unk-34 + 0x39), (s16) (D_8011F7F0.unk-32 + 0x5B));
    func_8005A600(temp_v0, 0, 0, 0x15, 0);
    *temp_v0 = ((s32) (temp_v0 - 0x14) & 0xFFFFFF) | 0x02000000;
    temp_s4->unk20 = temp_v0;
    *(&D_800AF634 + temp_s3) = *(&D_800AF634 + temp_s3) + ((s32) ((temp_v0 + 0x14) - temp_s4->unk18) >> 2);
}
