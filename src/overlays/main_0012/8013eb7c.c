/* Overlay range [8013EB7C,8013ED6C) from MAIN.CD member 0012.
 * SHA256(span)=73298edc60248e36f2bace1ec6c52ee21a036b0df2eee25ec97b4b46e966faea.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8002D4C8(s32, s32);                              /* extern */
extern s32 D_8017F6FC;
void func_801376E8(s32, s32 (*)());                      /* static */
void func_80137B80();                                  /* static */
void func_80139954();                                  /* static */
void func_8013E958();                                  /* static */
s32 func_8013F350();                                /* static */
void func_8013FAF8(s16, s16);                          /* static */
s32 func_8014032C(s16, s16);                        /* static */
s16 func_8014168C(s16);                             /* static */
s32 func_80141C50();                                /* static */
s32 func_80141CA4();                                /* static */
extern u16 D_800B9A02;
extern u16 D_80115112;
extern u16 D_8011511A;
extern u16 D_8011511E;
extern s16 D_80115128;
extern s16 D_8011512A;
extern s32 D_80115130;
extern s32 *D_801151C8;
extern s32 D_801151D0;

void func_8013EB7C(void) {
    s16 var_a0;
    s16 var_v0;
    s32 temp_s1;
    s32 temp_v0;

    if ((func_80141C50() << 0x10) == 0) {
        D_801151D0 = *(&D_801151C8 + (D_800B9A02 * 4));
        temp_s1 = func_8013F350();
        if ((u16) D_8011511A >= 4U) {
            func_8013FAF8((s16) D_8011511A, (s16) (D_8011511A + 1));
        }
        func_8013FAF8(0, 5);
        if ((D_8011511A & 0xFFFF) == 5) {
            var_v0 = func_8014168C(2);
            var_a0 = 2;
        } else {
            var_v0 = func_8014168C((s16) D_8011511A);
            var_a0 = (s16) D_8011511A;
        }
        temp_v0 = func_8014032C(var_a0, var_v0);
        if ((temp_v0 != 0) && (temp_v0 != D_80115130)) {
            D_80115130 = temp_v0;
            func_80139954();
            func_801376E8(temp_v0, D_8017F6FC);
        }
        func_80137B80();
        if ((D_8011511E & 0x10) && ((u16) D_8011511A < 5U) && ((temp_s1 << 0x10) == 0)) {
            D_80115128 = 0;
            func_8002D4C8(0x466, 0);
            if (D_8011511A != 4) {
                func_801376E8(func_80141CA4(), D_8017F6FC);
            }
            D_80115112 -= 1;
            return;
        }
        if ((D_8011511E & 0x800) || (D_8011512A != 0)) {
            func_8013E958();
        }
    }
}
