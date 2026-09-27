/* Overlay range [8013E5E8,8013E67C) from MAIN.CD member 0012.
 * SHA256(span)=b6eda234ec50440ff8d531ba216025da9b6561ba2848c3561fc82fa3ba99f6d3.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s16 func_80014ED4();                               /* extern */
s16 func_80015018();                               /* extern */
void func_800190AC();                                  /* extern */
void func_80029444();                                  /* extern */
extern s32 D_8017F734;
void func_80141C04();                                  /* static */
void func_801754A8();                                  /* static */
extern u16 D_80115112;
extern u16 D_80115116;
extern s16 D_8011511C;
extern s16 D_8011511E;

void func_8013E5E8(void) {
    func_80029444();
    func_801754A8();
    D_8011511E = func_80014ED4(0);
    D_8011511C = func_80015018(0);
    *(D_8017F734 + (D_80115112 * 4))();
    func_800190AC();
    func_80141C04();
    D_80115116 += 1;
}
