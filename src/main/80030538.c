/* Main-exec range [80030538,80030604) from the SLUS executable.
 * SHA256(span)=15cd8f41b9cac7da6597356ccd0dc4834e9f98e231602b36e7ec5b62d9c3e37c.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80030620();                                 /* extern */
void func_80030604();                                  /* static */
s16 func_80042154(s32, s32, s16);                     /* static */
extern s32 *D_800A4642;
extern s32 *D_800A4650;
extern s32 D_800A46C0;
extern s32 D_800A46C4;
extern u16 D_800A46CC;
extern s16 D_800A46CE;

void func_80030538(void) {
    s16 temp_v0;
    s32 temp_s0;

    temp_s0 = D_800A46CE * 0x18;
    temp_v0 = func_80042154(D_800A46C0 + D_800A46C4, 0x8000, *(&D_800A4642 + temp_s0));
    if (temp_v0 != -2) {
        if (temp_v0 != -1) {
            func_80030604();
            return;
        }
        *(&D_800A4650 + temp_s0) = 1;
        D_800A46CC += 2;
        func_80030620();
        return;
    }
    D_800A46C4 += 0x8000;
    D_800A46CC += 1;
    func_80030620(0x8000);
}
