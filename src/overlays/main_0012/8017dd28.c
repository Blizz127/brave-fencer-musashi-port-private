/* Overlay range [8017DD28,8017DF18) from MAIN.CD member 0012.
 * SHA256(span)=6cffc999246d9e4de0e07f6c2509bfd0bc6d745aad664c52c3b1fecba9238235.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8005A600(void *, s32, s32, s32, s32); /* extern */
extern s32 D_80182798[];
extern s32 *D_800AE7BC;
extern u16 D_800B9A02;
extern u16 D_80115116;
extern s16 D_8011511A;
extern s16 D_8011512C;
extern s32 D_80115134;

void *func_8017DD28(void *arg0) {
    u16 var_a0;
    void *temp_a0;
    void *temp_a1;
    void *temp_s3;
    void *temp_v1;

    temp_a1 = M2C_FIELD(((D_8011511A << 5) + D_80115134), void **, 0x18);
    var_a0 = 0;
    if (D_8011512C == 1) {
        var_a0 = *(D_80182798 + ((D_80115116 & 7) * 2));
    }
    M2C_FIELD(arg0, s32 *, 0) = 0x04000000;
    M2C_FIELD(arg0, s8 *, 0xC) = 0x70;
    M2C_FIELD(arg0, s8 *, 0xD) = 0x10;
    M2C_FIELD(arg0, s32 *, 4) = 0x64808080;
    M2C_FIELD(arg0, s16 *, 0xE) = 0x4056;
    M2C_FIELD(arg0, s16 *, 8) = (s16) (M2C_FIELD(temp_a1, u16 *, 0) + (var_a0 - 0x60));
    M2C_FIELD(arg0, s16 *, 0x12) = 0x10;
    M2C_FIELD(arg0, s16 *, 0x10) = 0x10;
    M2C_FIELD(arg0, s16 *, 0xA) = (s16) (M2C_FIELD(temp_a1, u16 *, 2) - 2);
    M2C_FIELD(arg0, s32 *, 0) = (s32) ((M2C_FIELD(arg0, s32 *, 0) & 0xFF000000) | (M2C_FIELD(*(&D_800AE7BC + (D_800B9A02 * 0x14)), s32 *, 8) & 0xFFFFFF));
    temp_a0 = *(&D_800AE7BC + (D_800B9A02 * 0x14));
    temp_s3 = arg0 + 0x14;
    M2C_FIELD(temp_a0, s32 *, 8) = (s32) ((M2C_FIELD(temp_a0, s32 *, 8) & 0xFF000000) | ((s32) arg0 & 0xFFFFFF));
    func_8005A600(temp_s3, 0, 0, 0x15, 0);
    M2C_FIELD(arg0, s32 *, 0x14) = (s32) ((M2C_FIELD(arg0, s32 *, 0x14) & 0xFF000000) | (M2C_FIELD(*(&D_800AE7BC + (D_800B9A02 * 0x14)), s32 *, 8) & 0xFFFFFF));
    temp_v1 = *(&D_800AE7BC + (D_800B9A02 * 0x14));
    M2C_FIELD(temp_v1, s32 *, 8) = (s32) ((M2C_FIELD(temp_v1, s32 *, 8) & 0xFF000000) | ((s32) temp_s3 & 0xFFFFFF));
    return temp_s3 + 8;
}
