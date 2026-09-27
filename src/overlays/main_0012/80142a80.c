/* Overlay range [80142A80,80142B2C) from MAIN.CD member 0012.
 * SHA256(span)=b2ffe2dc87ad9af9706433101a654d1d6656bb9b0f978c97f81e062b9c0f7488.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80184201;
extern s32 D_80184202;
extern u16 D_800B99D8;
extern s8 D_80184200;

void func_80142A80(void) {
    s32 sp3;
    s32 var_v1;
    u32 temp_v0;

    sp3 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
    temp_v0 = D_800B99D8 & 0xF;
    if (D_800B99D8 & 0x10) {
        var_v1 = (temp_v0 >> 1) + 9;
    } else {
        var_v1 = 0x10 - (temp_v0 >> 1);
    }
    D_80184200 = var_v1 * (sp0 >> 4);
    D_80184201 = (s8) (var_v1 * (sp1 >> 4));
    D_80184202 = (s8) (var_v1 * (sp2 >> 4));
}
