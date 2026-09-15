/* Overlay range [8017B940,8017BA3C) from MAIN.CD member 0012.
 * SHA256(span)=74c6f1562fe5c4f084976b60dd05452051130ad3d57bfd44b479297d569bf2e2.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8018534C;
extern s32 D_801853BE;
extern s32 D_801853C0;
extern s32 D_801853C6;
extern s32 D_801853C8;
extern s32 D_801853CE;
extern s32 D_801853D0;
extern s32 D_801853D6;
extern s32 D_801853D8;
extern s32 D_80114F24;
extern s32 D_80114F28;
extern s32 D_80114F2C;
extern s32 D_80114F30;
extern s32 D_80114F34;
extern s32 D_80114F38;
extern s8 D_8012694C;
extern s16 D_80126B5E;
extern s16 D_80126B62;
extern s16 D_80126B66;
extern s16 D_801853BC;
extern s16 D_801853C4;
extern s16 D_801853CC;
extern s16 D_801853D4;

void func_8017B940(void) {
    s32 sp8;
    s32 sp4;
    s32 sp0;
    s32 temp_a0;
    s32 temp_a1;
    s32 temp_a2;

    D_8012694C = 2;
    temp_a2 = D_80126B5E - D_801853CC;
    temp_a0 = D_80126B62 - D_801853CE;
    temp_a1 = D_80126B66 - D_801853D0;
    D_801853C4 = D_80114F30 + temp_a2;
    D_8018534C = 0;
    sp0 = temp_a2;
    sp4 = temp_a0;
    D_801853D4 = (s16) temp_a2;
    D_801853D6 = (s16) temp_a0;
    sp8 = temp_a1;
    D_801853D8 = (s16) temp_a1;
    D_801853C6 = (s16) (D_80114F34 + temp_a0);
    D_801853C8 = (s16) (D_80114F38 + temp_a1);
    D_801853BC = D_80114F24 + temp_a2;
    D_801853BE = (s16) (D_80114F28 + temp_a0);
    D_801853C0 = (s16) (D_80114F2C + temp_a1);
}
