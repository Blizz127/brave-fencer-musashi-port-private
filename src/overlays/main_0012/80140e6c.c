/* Overlay range [80140E6C,80140F00) from MAIN.CD member 0012.
 * SHA256(span)=7932bf38107f6aeb577459308be95eb54cf2378ef3e58bc9372282d6e2cb5dfa.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_800D2CA8(u8, s32);                           /* extern */
void func_800D2D10(s32, s32, s32, s32);                    /* extern */
extern s32 D_8017F314;
extern u8 D_80078E7D;
extern u8 D_80078E7E;
extern u8 D_80078E7F;

void func_80140E6C(void) {
    s32 temp_s0;
    s32 temp_s1;
    s32 temp_s2;

    temp_s2 = D_8017F314;
    temp_s1 = func_800D2CA8(D_80078E7F, 0x18);
    temp_s0 = func_800D2CA8(D_80078E7E, 0xC);
    func_800D2D10(temp_s1 | (temp_s0 | 0xB00000) | (func_800D2CA8(D_80078E7D, 0) | 0xB00), 8, temp_s2, 0);
}
