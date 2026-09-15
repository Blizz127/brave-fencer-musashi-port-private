/* Overlay range [80177340,8017742C) from MAIN.CD member 0012.
 * SHA256(span)=c9b2584bc64ee4ec02563e906d1fb5464d6ed8ad229ceec87ea865b39fe6ee6a.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_801778A8(s32, s16, s32, s32);  /* static */
s16 func_801783D0(u16, s32);                    /* static */
extern u16 D_8011F82E;
extern u16 D_8011F830;

void func_80177340(s32 arg0) {
    s32 temp_s0;
    s32 temp_s0_2;
    s32 temp_v0;
    void *temp_s0_3;
    void *temp_s0_4;

    temp_s0 = arg0 + 0x50;
    func_801778A8(temp_s0, func_801783D0(D_8011F830, 4), 3, 0xFF);
    temp_s0_2 = temp_s0 + 0x3C;
    func_801778A8(temp_s0_2, func_801783D0(D_8011F82E, 4), 3, 0xFF);
    temp_s0_3 = temp_s0_2 + 0x3C;
    M2C_FIELD(temp_s0_3, s16 *, 0xC) = (s16) ((u32) (D_8011F830 * 0x2873) >> 0xF);
    temp_s0_4 = temp_s0_3 + 0x14;
    temp_v0 = (s32) (D_8011F82E * 0x50E6) >> 0x10;
    M2C_FIELD(temp_s0_4, s16 *, 0xC) = (s16) temp_v0;
    M2C_FIELD(temp_s0_4, s16 *, 0x20) = (s16) (temp_v0 + 2);
}
