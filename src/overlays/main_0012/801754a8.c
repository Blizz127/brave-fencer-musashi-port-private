/* Overlay range [801754A8,8017553C) from MAIN.CD member 0012.
 * SHA256(span)=cfd1eb9638e26b320ed3d8fa58c0b71d3e6411be4dc290b250ad72d54afb9a22.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80029504();                                /* extern */
extern s32 D_80181B6C;
extern u8 D_800B9A13;
extern s32 D_8011F7A8;
extern s32 D_80126B9C;

void func_801754A8(void) {
    s32 temp_a0;
    s8 var_a1;

    var_a1 = 0;
    temp_a0 = func_80029504();
    if (((D_800B9A13 == 0) && !(D_80126B9C & 0x80)) || ((u32) (temp_a0 - 0xA) >= 0x4B0U)) {
        var_a1 = 1;
    }
    D_8011F7A8.unk9 = var_a1;
    *(D_80181B6C + (D_8011F7A8.unk0 * 4))(&D_8011F7A8, var_a1);
}
