/* Main-exec range [80015F04,80016110) from the SLUS executable.
 * SHA256(span)=25db6fffc302062b0a6568596f094968a5dd944a2727595aefb32f934e9c4d2c.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 *func_80010A08(s32, s16);                   /* static */
void func_80016638(void *, u16, u32, s32 *);     /* static */
extern s32 *D_800A6518;
extern s32 *D_800A651C;
extern s32 *D_800AF630;

void func_80015F04(u16 arg0, u16 arg1, s32 arg2, s32 arg3, u8 arg4, u8 arg5, u8 arg6, u16 arg7, u16 arg8) {
    s16 sp1E;
    u16 sp1C;
    s16 sp1A;
    s16 sp18;
    u16 sp16;
    s16 sp14;
    u16 sp12;
    u16 sp10;
    s16 temp_a1;
    s16 temp_v0;
    s32 *temp_v1_3;
    s32 *var_a3;
    s32 temp_a0;
    s32 temp_t1;
    s32 var_a2;
    u32 temp_a2;
    void *temp_v1;
    void *temp_v1_2;
    void *var_a1;

    temp_v0 = arg0 + arg2;
    temp_a1 = arg1 + arg3;
    sp10 = arg0;
    sp12 = arg1;
    sp14 = temp_v0;
    sp16 = arg1;
    sp18 = temp_v0;
    sp1A = temp_a1;
    sp1C = arg0;
    sp1E = temp_a1;
    var_a3 = func_80010A08(0x40, temp_a1);
    var_a2 = 0;
    var_a1 = var_a3 + 0xE;
    temp_t1 = arg7 * 4;
    do {
        M2C_FIELD(var_a1, s8 *, -0xB) = 3;
        M2C_FIELD(var_a1, s8 *, -7) = 0x40;
        if (arg8 < 4U) {
            M2C_FIELD(var_a1, s8 *, -7) = 0x42;
        }
        temp_v1 = &sp10 + (var_a2 * 4);
        M2C_FIELD(var_a1, u8 *, -0xA) = arg4;
        M2C_FIELD(var_a1, u8 *, -9) = arg5;
        M2C_FIELD(var_a1, u8 *, -8) = arg6;
        temp_a0 = var_a2 + 1;
        M2C_FIELD(var_a1, u16 *, -6) = (u16) M2C_FIELD(temp_v1, u16 *, 0);
        temp_v1_2 = &sp10 + (temp_a0 * 4);
        M2C_FIELD(var_a1, u16 *, -4) = (u16) M2C_FIELD(temp_v1, u16 *, 2);
        M2C_FIELD(var_a1, u16 *, -2) = (u16) M2C_FIELD(temp_v1_2, u16 *, 0);
        M2C_FIELD(var_a1, u16 *, 0) = (u16) M2C_FIELD(temp_v1_2, u16 *, 2);
        var_a2 = temp_a0;
        *var_a3 = (*var_a3 & 0xFF000000) | (*(temp_t1 + *(&D_800A651C + (M2C_FIELD(&D_800AF630, u16 *, 0xA3D2) * 0x14))) & 0xFFFFFF);
        var_a1 += 0x10;
        temp_v1_3 = temp_t1 + *(&D_800A651C + (M2C_FIELD(&D_800AF630, u16 *, 0xA3D2) * 0x14));
        *temp_v1_3 = (*temp_v1_3 & 0xFF000000) | ((s32) var_a3 & 0xFFFFFF);
        var_a3 += 0x10;
    } while (var_a2 < 4);
    M2C_FIELD(var_a3, u16 *, -4) = sp10;
    temp_a2 = arg8 & 0xFFFF;
    M2C_FIELD(var_a3, u16 *, -2) = sp12;
    if (temp_a2 < 4U) {
        func_80016638((M2C_FIELD(&D_800AF630, u16 *, 0xA3D2) * 0x14) + &D_800A6518, arg7, temp_a2, var_a3);
    }
}
