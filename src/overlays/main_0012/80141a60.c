/* Overlay range [80141A60,80141B90) from MAIN.CD member 0012.
 * SHA256(span)=c27ce34d8bf0f56290ccf632162e611417b2457f9e13dc8fd80d85d919dcb651.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_800D0EC4();                                /* extern */
extern s32 D_8017F6FC;
void func_801376E8(s32, s32 (*)());                      /* static */
void func_80137B80();                                  /* static */
void func_80139954();                                  /* static */
void func_8013F350();                                  /* static */
void func_8013FAF8(s16, s16);                          /* static */
s32 func_8014032C(s32, s16, s32);                     /* static */
extern u16 D_800B9A02;
extern u16 D_80115112;
extern s16 D_80115116;
extern u16 D_8011511A;
extern s32 D_80115130;
extern u8 D_8011514C;
extern u8 D_8011514D;
extern u8 D_8011515C;
extern s32 *D_801151C8;
extern s32 D_801151D0;

void func_80141A60(void) {
    s32 temp_lo;
    s32 temp_v0;

    D_801151D0 = *(&D_801151C8 + (D_800B9A02 * 4));
    func_8013F350();
    if ((u16) D_8011511A >= 4U) {
        func_8013FAF8((s16) D_8011511A, (s16) (D_8011511A + 1));
    }
    func_8013FAF8(2, 3);
    temp_lo = D_8011514D * D_8011515C;
    temp_v0 = func_8014032C(2, (s16) (D_8011514C + temp_lo), temp_lo);
    if ((temp_v0 != 0) && (temp_v0 != D_80115130)) {
        D_80115130 = temp_v0;
        func_80139954();
        func_801376E8(temp_v0, D_8017F6FC);
    }
    func_80137B80();
    if (func_800D0EC4() != 0) {
        D_80115116 = 0xFFF8;
        D_80115112 += 1;
    }
}
