/* Overlay range [8013AF20,8013B204) from MAIN.CD member 0012.
 * SHA256(span)=99e93b375a079ec69067489e2c622e775e2206605652514cc752b3275c7d2849.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 *func_80010A08();                        /* extern */

void func_8013AF20(s32 *arg0, void *arg1, void *arg2, void *arg3) {
    s32 *var_s0;
    s32 *var_s2;
    s32 *var_t1;
    s32 var_t0;
    s32 var_t0_2;
    s32 var_t0_3;
    u16 temp_v0;
    u16 temp_v0_3;
    u16 temp_v1;
    u8 temp_v0_2;
    void *var_a0;
    void *var_a0_2;
    void *var_a0_3;
    void *var_a1;
    void *var_a1_2;
    void *var_a2;
    void *var_a3;

    var_s2 = func_80010A08(0x168);
    var_s0 = func_80010A08(0x1E0);
    var_t1 = func_80010A08(0x1E0);
    var_t0 = 0;
    var_a0 = var_s0 + 0xE;
    var_a1 = arg2;
    do {
        M2C_FIELD(var_a0, s8 *, -0xB) = 3;
        M2C_FIELD(var_a0, s8 *, -7) = 0x40;
        M2C_FIELD(var_a0, s8 *, -0xA) = 0x3D;
        M2C_FIELD(var_a0, s8 *, -9) = 0x3D;
        M2C_FIELD(var_a0, s8 *, -8) = 0x3D;
        M2C_FIELD(var_a0, u16 *, -6) = (u16) M2C_FIELD(var_a1, u16 *, 0);
        M2C_FIELD(var_a0, u16 *, -4) = (u16) M2C_FIELD(var_a1, u16 *, 2);
        var_t0 += 1;
        M2C_FIELD(var_a0, u16 *, -2) = (u16) M2C_FIELD(var_a1, u16 *, 4);
        temp_v0 = M2C_FIELD(var_a1, u16 *, 6);
        var_a1 += 4;
        M2C_FIELD(var_a0, u16 *, 0) = temp_v0;
        var_a0 += 0x10;
        *var_s0 = (*var_s0 & 0xFF000000) | (*arg0 & 0xFFFFFF);
        *arg0 = (*arg0 & 0xFF000000) | ((s32) var_s0 & 0xFFFFFF);
        var_s0 += 0x10;
    } while (var_t0 < 0x1E);
    var_t0_2 = 0;
    var_a0_2 = var_t1 + 0xE;
    var_a1_2 = arg2;
    var_a3 = arg3;
    do {
        var_t0_2 += 1;
        M2C_FIELD(var_a0_2, s8 *, -0xB) = 3;
        M2C_FIELD(var_a0_2, s8 *, -7) = 0x40;
        M2C_FIELD(var_a0_2, s8 *, -0xA) = 0x92;
        M2C_FIELD(var_a0_2, s8 *, -9) = 0x92;
        M2C_FIELD(var_a0_2, s8 *, -8) = 0x92;
        M2C_FIELD(var_a0_2, s16 *, -6) = (s16) (M2C_FIELD(var_a1_2, u16 *, 0) + (s8) M2C_FIELD(var_a3, u8 *, 0));
        M2C_FIELD(var_a0_2, s16 *, -4) = (s16) (M2C_FIELD(var_a1_2, u16 *, 2) + (s8) M2C_FIELD(var_a3, u8 *, 1));
        M2C_FIELD(var_a0_2, s16 *, -2) = (s16) (M2C_FIELD(var_a1_2, u16 *, 4) + (s8) M2C_FIELD(var_a3, u8 *, 2));
        temp_v1 = M2C_FIELD(var_a1_2, u16 *, 6);
        var_a1_2 += 4;
        temp_v0_2 = M2C_FIELD(var_a3, u8 *, 3);
        var_a3 += 2;
        M2C_FIELD(var_a0_2, s16 *, 0) = (s16) (temp_v1 + (s8) temp_v0_2);
        var_a0_2 += 0x10;
        *var_t1 = (*var_t1 & 0xFF000000) | (*arg0 & 0xFFFFFF);
        *arg0 = (*arg0 & 0xFF000000) | ((s32) var_t1 & 0xFFFFFF);
        var_t1 += 0x10;
    } while (var_t0_2 < 0x1E);
    var_t0_3 = 0;
    var_a0_3 = var_s2 + 0x16;
    var_a2 = arg2;
    do {
        M2C_FIELD(var_a0_3, s8 *, -0x13) = 5;
        M2C_FIELD(var_a0_3, s8 *, -0xF) = 0x28;
        M2C_FIELD(var_a0_3, s8 *, -0x12) = 0xFF;
        M2C_FIELD(var_a0_3, s8 *, -0x11) = 0xFF;
        M2C_FIELD(var_a0_3, s8 *, -0x10) = 0xFF;
        M2C_FIELD(var_a0_3, u16 *, -0xE) = (u16) M2C_FIELD(var_a2, u16 *, 0);
        M2C_FIELD(var_a0_3, u16 *, -0xC) = (u16) M2C_FIELD(var_a2, u16 *, 2);
        M2C_FIELD(var_a0_3, u16 *, -0xA) = (u16) M2C_FIELD(arg1, u16 *, 0);
        M2C_FIELD(var_a0_3, u16 *, -8) = (u16) M2C_FIELD(arg1, u16 *, 2);
        M2C_FIELD(var_a0_3, u16 *, -6) = (u16) M2C_FIELD(var_a2, u16 *, 4);
        M2C_FIELD(var_a0_3, u16 *, -4) = (u16) M2C_FIELD(var_a2, u16 *, 6);
        var_t0_3 += 2;
        M2C_FIELD(var_a0_3, u16 *, -2) = (u16) M2C_FIELD(var_a2, u16 *, 8);
        temp_v0_3 = M2C_FIELD(var_a2, u16 *, 0xA);
        var_a2 += 8;
        M2C_FIELD(var_a0_3, u16 *, 0) = temp_v0_3;
        var_a0_3 += 0x18;
        *var_s2 = (*var_s2 & 0xFF000000) | (*arg0 & 0xFFFFFF);
        *arg0 = (*arg0 & 0xFF000000) | ((s32) var_s2 & 0xFFFFFF);
        var_s2 += 0x18;
    } while (var_t0_3 < 0x1E);
}
