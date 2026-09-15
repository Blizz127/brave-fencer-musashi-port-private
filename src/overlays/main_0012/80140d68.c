/* Overlay range [80140D68,80140E6C) from MAIN.CD member 0012.
 * SHA256(span)=b32357439b00879eb5560f21545e36cb8e7779c2b7a3ee6f4986bb362ab01a1f.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 *D_800AE7BC;
extern u16 D_800B9A02;
extern s32 *D_8011516A;

void *func_80140D68(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    void *temp_v1;
    void *temp_v1_2;

    M2C_FIELD(arg0, s32 *, 0) = 0x04000000;
    M2C_FIELD(arg0, s8 *, 0xC) = 0x70;
    M2C_FIELD(arg0, s8 *, 0xD) = 0x10;
    M2C_FIELD(arg0, s32 *, 4) = 0x64808080;
    M2C_FIELD(arg0, s16 *, 0xE) = 0x4056;
    temp_v1 = ((s32) (arg4 << 0x10) >> 0xF) + arg1;
    M2C_FIELD(arg0, s16 *, 8) = (s16) (M2C_FIELD(temp_v1, u16 *, 0) + *(&D_8011516A + ((s32) (arg2 << 0x10) >> 0xE)) + (arg3 - 0xD));
    M2C_FIELD(arg0, s16 *, 0x12) = 0x10;
    M2C_FIELD(arg0, s16 *, 0x10) = 0x10;
    M2C_FIELD(arg0, s16 *, 0xA) = (s16) (M2C_FIELD(temp_v1, u16 *, 2) - 4);
    M2C_FIELD(arg0, s32 *, 0) = (s32) ((M2C_FIELD(arg0, s32 *, 0) & 0xFF000000) | (M2C_FIELD(*(&D_800AE7BC + (D_800B9A02 * 0x14)), s32 *, 8) & 0xFFFFFF));
    temp_v1_2 = *(&D_800AE7BC + (D_800B9A02 * 0x14));
    M2C_FIELD(temp_v1_2, s32 *, 8) = (s32) ((M2C_FIELD(temp_v1_2, s32 *, 8) & 0xFF000000) | ((s32) arg0 & 0xFFFFFF));
    return arg0 + 0x14;
}
