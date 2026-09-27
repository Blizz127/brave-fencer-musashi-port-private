/* Overlay range [801653F4,801654A8) from MAIN.CD member 0012.
 * SHA256(span)=391e3cd804c91efa188c6e4082370d9e3f347c0642e18334a43319c489fd0ca8.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80165624();                                /* static */
extern u8 D_80078EC1;
extern s8 D_80078EC5;
extern s16 D_800B9A08;

void func_801653F4(void) {
    s16 temp_s0;

    temp_s0 = D_800B9A08;
    D_80078EC5 = 0;
    D_80078EC1 &= 0x7F;
    if ((func_80165624() != 0) || ((D_80078EC1 == 0x1A) && ((u32) (temp_s0 - 0x305C) >= 2U) && ((u32) (temp_s0 - 0x305E) >= 2U) && ((u32) (temp_s0 - 0x3060) >= 2U) && ((u32) (temp_s0 - 0x3062) >= 2U) && ((u32) (temp_s0 - 0x3064) >= 2U) && (temp_s0 != 0x3066))) {
        D_80078EC5 = 0x80;
    }
}
