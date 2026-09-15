/* Overlay range [801412A8,801415C0) from MAIN.CD member 0012.
 * SHA256(span)=305afe34bd589aff0789e6266f78eb97dc365cf77c6248d9d5ea22158140f30f.
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
extern u16 D_80115116;

void *func_801412A8(void *arg0, s32 arg1, s16 arg2, s16 arg3, u16 arg4, u16 arg5) {
    s32 temp_a1;
    s32 temp_a1_2;
    s32 var_t0;
    s32 var_v1;
    void *temp_a0;
    void *temp_a0_2;
    void *temp_a0_3;
    void *temp_t6;
    void *temp_t6_2;
    void *temp_t6_3;
    void *temp_v1;

    var_t0 = 0xF800F8;
    if ((arg1 << 0x10) != 0) {
        var_v1 = 0x5E;
        if (D_80115116 & 1) {
            goto block_6;
        }
    } else if (arg2 != 0) {
        var_v1 = (s32) (arg3 * 0x5E) / arg2;
    } else {
        var_v1 = 0x5E;
block_6:
        var_t0 = 0xF89C00;
    }
    temp_a1 = arg4 | (((s16) arg5 + 0xA) << 0x10);
    M2C_FIELD(arg0, s32 *, 4) = (s32) (var_t0 | 0x60000000);
    M2C_FIELD(arg0, s32 *, 0) = 0x03000000;
    M2C_FIELD(arg0, s32 *, 8) = temp_a1;
    M2C_FIELD(arg0, s32 *, 0xC) = (s32) (var_v1 | 0x20000);
    M2C_FIELD(arg0, s32 *, 0) = (s32) ((M2C_FIELD(arg0, s32 *, 0) & 0xFF000000) | (M2C_FIELD(*(&D_800AE7BC + (D_800B9A02 * 0x14)), s32 *, 8) & 0xFFFFFF));
    temp_a0 = *(&D_800AE7BC + (D_800B9A02 * 0x14));
    temp_t6_2 = arg0 + 0x10;
    M2C_FIELD(temp_a0, s32 *, 8) = (s32) ((M2C_FIELD(temp_a0, s32 *, 8) & 0xFF000000) | ((s32) arg0 & 0xFFFFFF));
    M2C_FIELD(temp_t6_2, s32 *, 4) = 0x60080808;
    M2C_FIELD(arg0, s32 *, 0x10) = 0x03000000;
    M2C_FIELD(temp_t6_2, s32 *, 8) = temp_a1;
    M2C_FIELD(temp_t6_2, s32 *, 0xC) = 0x2005E;
    M2C_FIELD(arg0, s32 *, 0x10) = (s32) ((M2C_FIELD(arg0, s32 *, 0x10) & 0xFF000000) | (M2C_FIELD(*(&D_800AE7BC + (D_800B9A02 * 0x14)), s32 *, 8) & 0xFFFFFF));
    temp_a1_2 = (arg4 - 1) & 0xFFFF;
    temp_a0_2 = *(&D_800AE7BC + (D_800B9A02 * 0x14));
    temp_t6_3 = temp_t6_2 + 0x10;
    M2C_FIELD(temp_a0_2, s32 *, 8) = (s32) ((M2C_FIELD(temp_a0_2, s32 *, 8) & 0xFF000000) | ((s32) temp_t6_2 & 0xFFFFFF));
    M2C_FIELD(temp_t6_3, s32 *, 4) = 0x60FFFFFF;
    M2C_FIELD(temp_t6_2, s32 *, 0x10) = 0x03000000;
    M2C_FIELD(temp_t6_3, s32 *, 8) = (s32) ((((s16) arg5 + 9) << 0x10) | temp_a1_2);
    M2C_FIELD(temp_t6_3, s32 *, 0xC) = 0x20060;
    M2C_FIELD(temp_t6_2, s32 *, 0x10) = (s32) ((M2C_FIELD(temp_t6_2, s32 *, 0x10) & 0xFF000000) | (M2C_FIELD(*(&D_800AE7BC + (D_800B9A02 * 0x14)), s32 *, 8) & 0xFFFFFF));
    temp_a0_3 = *(&D_800AE7BC + (D_800B9A02 * 0x14));
    temp_t6 = temp_t6_3 + 0x10;
    M2C_FIELD(temp_a0_3, s32 *, 8) = (s32) ((M2C_FIELD(temp_a0_3, s32 *, 8) & 0xFF000000) | ((s32) temp_t6_3 & 0xFFFFFF));
    M2C_FIELD(temp_t6_3, s32 *, 0x10) = 0x03000000;
    M2C_FIELD(temp_t6, s32 *, 4) = 0x60E0C0A0;
    M2C_FIELD(temp_t6, s32 *, 8) = (s32) ((((s16) arg5 + 0xB) << 0x10) | temp_a1_2);
    M2C_FIELD(temp_t6, s32 *, 0xC) = 0x20060;
    M2C_FIELD(temp_t6_3, s32 *, 0x10) = (s32) ((M2C_FIELD(temp_t6_3, s32 *, 0x10) & 0xFF000000) | (M2C_FIELD(*(&D_800AE7BC + (D_800B9A02 * 0x14)), s32 *, 8) & 0xFFFFFF));
    temp_v1 = *(&D_800AE7BC + (D_800B9A02 * 0x14));
    M2C_FIELD(temp_v1, s32 *, 8) = (s32) ((M2C_FIELD(temp_v1, s32 *, 8) & 0xFF000000) | ((s32) temp_t6 & 0xFFFFFF));
    return temp_t6 + 0x10;
}
