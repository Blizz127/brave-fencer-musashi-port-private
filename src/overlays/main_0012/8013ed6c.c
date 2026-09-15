/* Overlay range [8013ED6C,8013EE10) from MAIN.CD member 0012.
 * SHA256(span)=7f7fa9ae22bdac8b47cbb44f90473cf9e4841145e60990f21f36117984e3baf6.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8013E958();                                  /* static */
void func_8013F350();                                  /* static */
void func_8013FAF8(s32, s32);                              /* static */
s32 func_80141C50();                                /* static */
extern u16 D_800B9A02;
extern s16 D_80115112;
extern u16 D_8011511A;
extern u16 D_8011511E;
extern s32 *D_801151C8;
extern s32 D_801151D0;

void func_8013ED6C(void) {
    if (((func_80141C50() << 0x10) == 0) && ((D_801151D0 = *(&D_801151C8 + (D_800B9A02 * 4)), func_8013F350(), func_8013FAF8(7, 8), (D_8011511A != 7)) || (D_8011511E & 0x810))) {
        func_8013E958();
        D_80115112 = 4;
    }
}
