/* Overlay range [8013FAF8,8013FFD8) from MAIN.CD member 0012.
 * SHA256(span)=0ebecd03a3a9decfaf37482d7170ba921114ee61d2dfcac60f978cb03804a81c.
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
s32 *func_800D2650(s32 *, void *, s16, s16, s32, s32); /* extern */
s32 func_800D27DC(s32, s32 *, void *, s32, s32);      /* extern */
s32 *func_800D29F8(s32, s32, void *, s32, s32);       /* extern */
extern s32 D_8017ED80;
extern s32 D_8017F080;
extern s32 D_8017F180;
extern s32 D_8017F1F0;
extern s32 D_8017F2E4;
extern s32 D_8017F304;
extern s32 D_8017F324;
extern s32 D_8017F6FA;
s32 *func_80137D08(s32 *, void *, s32);               /* static */
s32 *func_8013AB54(s32 *, s32, s16 *, s32);           /* static */
s32 func_8013FFD8(s32, s16, s32 *);                 /* static */
s32 *func_80140958(s32 *, s16, s16);                /* static */
void func_80140E6C();                                  /* static */
void func_80140F00();                                  /* static */
s32 *func_80141100(s32 *);                          /* static */
s16 func_8014168C();                               /* static */
extern u8 D_80078EC0;
extern s32 *D_800AE7B8;
extern s32 *D_800AE7BC;
extern u16 D_800B9A02;
extern u16 D_8011511A;
extern s16 D_80115128;
extern s32 *D_8011516A;
extern s32 *D_801151D0;
extern s16 D_8017F6F8;

void func_8013FAF8(s16 arg0, s16 arg1) {
    s32 sp70;
    s16 sp68;
    s32 sp60;
    s32 sp18;
    s32 (*var_s1)();
    s16 temp_a1;
    s16 temp_s0;
    s16 temp_v1;
    s16 var_s4;
    s16 var_s5;
    s32 *var_a0_2;
    s32 *var_s3;
    s32 *var_s3_2;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_s1_2;
    s32 temp_s2;
    s32 temp_v0;
    s32 var_a0;
    s32 var_s6;
    s32 var_t0;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v0_3;
    void *temp_a3;
    void *temp_s1;

    func_80140E6C();
    func_80140F00();
    var_s3 = func_80140958(D_801151D0, arg0, arg1);
    sp68 = arg1;
    if ((u16) D_8011511A < 6U) {
        var_s3 = func_80141100(var_s3);
    }
    var_s5 = arg0;
    if (arg0 < arg1) {
        sp70 = 0xFFFFFF;
        var_v0 = var_s5 << 0x10;
        do {
            temp_a0 = var_v0 >> 0x10;
            if ((temp_a0 == D_8011511A) || (temp_a0 == 2) || (var_s6 = 0xFF, (temp_a0 == 4))) {
                var_s6 = 0;
            }
            temp_a0_2 = var_s5 * 4;
            temp_s1 = temp_a0_2 + D_8017F180;
            if (var_s5 != 5) {
                if (var_s5 == 2) {
                    var_a0 = *(D_8017F324 + (D_80115128 * 4));
                } else {
                    var_a0 = *(D_8017F304 + temp_a0_2);
                }
            } else {
                var_a0 = func_8013FFD8(2, func_8014168C(2), &sp60);
            }
            func_80024054(var_a0, &sp18);
            if (var_s6 != 0) {
                var_v0_2 = 0x585858;
            } else {
                var_v0_2 = 0x808080;
            }
            var_s3_2 = func_800D2650(var_s3, &sp18, (s16) (temp_s1->unk0 + *(&D_8011516A + ((s32) (var_s5 << 0x10) >> 0xE))), temp_s1->unk2, var_v0_2);
            var_s1 = *(D_8017F2E4 + (var_s5 * 4));
            var_s4 = 0;
            if (var_s1 != 0) {
                if (var_s5 == 2) {
                    var_v0_3 = var_s5 << 0x10;
                    if (D_80115128 != 0) {
                        var_s1 = D_8017F1F0;
                        goto block_20;
                    }
                } else {
block_20:
                    var_v0_3 = var_s5 << 0x10;
                }
                temp_s2 = var_v0_3 >> 0x10;
loop_22:
                temp_a1 = var_s4;
                temp_s0 = temp_a1 + 1;
                var_s4 = temp_s0;
                temp_v0 = func_8013FFD8(temp_s2, temp_a1, &sp60);
                var_a0_2 = var_s3_2;
                if (temp_v0 != 0) {
                    if (temp_v0 < 0) {
                        func_80024054(temp_v0, &sp18);
                        var_t0 = 1;
                        if ((temp_s2 == 0) && ((D_80078EC0 & 0x7F) == temp_s0)) {
                            var_t0 = 0xB6;
                        }
                        if (var_s6 != 0) {
                            sp60 += 0xFFD7D7D8;
                        }
                        var_s3_2 = func_800D2650(var_s3_2, &sp18, (s16) (var_s1->unk0 + *(&D_8011516A + (temp_s2 * 4))), var_s1->unk2, var_t0, sp60);
                    }
                    var_s1 += 4;
                    goto loop_22;
                }
            } else {
                var_a0_2 = var_s3_2;
            }
            func_8005A600(var_a0_2, 0, 0, 0x15, 0);
            *var_s3_2 = 0x02000000;
            temp_s1_2 = var_s5 * 4;
            *var_s3_2 = ((*(&D_800AE7BC + (D_800B9A02 * 0x14)))->unk8 & sp70) | 0x02000000;
            temp_a3 = *(&D_800AE7BC + (D_800B9A02 * 0x14));
            temp_a3->unk8 = (s32) ((temp_a3->unk8 & 0xFF000000) | ((s32) var_s3_2 & sp70));
            var_s3 = func_800D29F8(var_s6, func_800D27DC(var_s6 != 0, var_s3_2 + 0x28, (var_s5 * 0x60) + D_8017ED80, 8, (s32) *(&D_8011516A + temp_s1_2)), (var_s5 << 5) + D_8017F080, 2, (s32) *(&D_8011516A + temp_s1_2));
            temp_v1 = var_s5 + 1;
            var_s5 = temp_v1;
            var_v0 = var_s5 << 0x10;
        } while (temp_v1 < (s16) (u16) sp68);
    }
    if (D_8017F6F8 == 0xE) {
        var_s3 = func_80137D08(var_s3, (D_800B9A02 * 0x14) + &D_800AE7B8, 2);
    }
    if ((D_8017F6F8 != 0) && (D_8017F6FA != 0)) {
        var_s3 = func_8013AB54(var_s3, *(&D_800AE7BC + (D_800B9A02 * 0x14)) + 8, &D_8017F6F8 - 4, 0x8000);
    }
    D_801151D0 = var_s3;
}
