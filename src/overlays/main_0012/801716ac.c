/* Overlay range [801716AC,801717A0) from MAIN.CD member 0012.
 * SHA256(span)=d7f37a0484206841f3c7ac584e212077f144e6e73626c97e30f3f8a99be5b9d4.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s16 func_80012FC8(u8, u8, s32, s32);        /* extern */
extern s32 *D_800A5E94;
extern s32 *D_800A5E95;
extern s32 *D_800A5E96;

void func_801716AC(s32 arg0, s32 arg1, s32 *arg2) {
    s16 temp_v0;
    s16 temp_v0_2;
    s16 temp_v0_3;
    s32 temp_s2;
    void *temp_s0;

    temp_s2 = arg0 * 0x10;
    temp_s0 = temp_s2 + arg1;
    temp_v0 = func_80012FC8(M2C_FIELD(temp_s0, u8 *, 0xC), *(&D_800A5E94 + temp_s2), 0xA, 1);
    *arg2 += temp_v0;
    M2C_FIELD(temp_s0, u8 *, 0xC) = (u8) (M2C_FIELD(temp_s0, u8 *, 0xC) + temp_v0);
    temp_v0_2 = func_80012FC8(M2C_FIELD(temp_s0, u8 *, 0xD), *(&D_800A5E95 + temp_s2), 0xA, 1);
    *arg2 += temp_v0_2;
    M2C_FIELD(temp_s0, u8 *, 0xD) = (u8) (M2C_FIELD(temp_s0, u8 *, 0xD) + temp_v0_2);
    temp_v0_3 = func_80012FC8(M2C_FIELD(temp_s0, u8 *, 0xE), *(&D_800A5E96 + temp_s2), 0xA, 1);
    *arg2 += temp_v0_3;
    M2C_FIELD(temp_s0, u8 *, 0xE) = (u8) (M2C_FIELD(temp_s0, u8 *, 0xE) + temp_v0_3);
}
