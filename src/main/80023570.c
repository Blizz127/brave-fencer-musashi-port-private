/* Exact retail [80023570,8002374C).
 * Words from pinned SLUS_007.26.
 */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80058B40(s32, s32, s32, s32);  /* static */
void func_8005A600(s32 *, s32, s32, s32, s32); /* static */
extern s32 *D_800A5E60;
extern s32 *D_800A6610;
extern u16 D_800B9A02;

void func_80023570(void *arg0) {
    s32 *temp_a0;
    s32 *temp_s0;
    s32 *temp_s1;
    s32 *temp_t2;
    s32 *var_a3;
    s32 temp_v1;
    s8 var_t3;
    u16 temp_s2;
    u32 temp_a1;
    u8 *var_t0;
    void *temp_s3;
    void *var_a0;
    void *var_a2;

    var_t0 = M2C_FIELD(arg0, u8 **, 0x20);
    var_a3 = D_800A5E60;
    temp_a1 = M2C_FIELD(arg0, u32 *, 4);
    temp_s2 = M2C_FIELD(arg0, u16 *, 0x2C);
    temp_s3 = (D_800B9A02 << 0xE) + &D_800A6610;
    var_t3 = 0x60;
    if (temp_a1 & 0x40000000) {
        var_t3 = 0x62;
    }
    temp_t2 = (temp_s2 * 4) + temp_s3;
    var_a2 = var_t0 + 3;
    var_a0 = var_a3 + 0xE;
    do {
        M2C_FIELD(var_a0, s8 *, -7) = var_t3;
        *var_a3 = 0x03000000;
        M2C_FIELD(var_a0, u8 *, -0xA) = (u8) *var_t0;
        M2C_FIELD(var_a0, u8 *, -9) = (u8) M2C_FIELD(var_a2, u8 *, -2);
        M2C_FIELD(var_a0, u8 *, -8) = (u8) M2C_FIELD(var_a2, u8 *, -1);
        M2C_FIELD(var_a0, s16 *, -6) = (s16) (M2C_FIELD(arg0, u16 *, 8) + M2C_FIELD(var_a2, u16 *, 1));
        temp_s0 = D_800A5E60;
        M2C_FIELD(var_a0, s16 *, -4) = (s16) (M2C_FIELD(arg0, u16 *, 0xA) + M2C_FIELD(var_a2, u16 *, 3));
        var_t0 += 0xC;
        M2C_FIELD(var_a0, u16 *, -2) = (u16) M2C_FIELD(var_a2, u16 *, 5);
        temp_s1 = temp_s0 + 0x10;
        D_800A5E60 = temp_s1;
        M2C_FIELD(var_a0, u16 *, 0) = (u16) M2C_FIELD(var_a2, u16 *, 7);
        var_a0 += 0x10;
        *var_a3 = (*var_a3 & 0xFF000000) | (*temp_t2 & 0xFFFFFF);
        temp_v1 = (s32) var_a3 & 0xFFFFFF;
        var_a3 += 0x10;
        *temp_t2 = (*temp_t2 & 0xFF000000) | temp_v1;
        var_a2 += 0xC;
    } while (M2C_FIELD(var_a2, u8 *, 0) == 0);
    if (temp_a1 & 0x40000000) {
        D_800A5E60 = temp_s0 + 0x1C;
        func_8005A600(temp_s1, 0, 0, func_80058B40(2, (temp_a1 >> 0x1C) & 3, 0x280, 0) & 0xFFFF, 0);
        temp_a0 = (temp_s2 * 4) + temp_s3;
        M2C_FIELD(temp_s0, s32 *, 0x10) = (s32) ((M2C_FIELD(temp_s0, s32 *, 0x10) & 0xFF000000) | (*temp_a0 & 0xFFFFFF));
        *temp_a0 = (*temp_a0 & 0xFF000000) | ((s32) temp_s1 & 0xFFFFFF);
    }
}
