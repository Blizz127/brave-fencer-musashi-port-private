/* Exact retail word export for [80016224,80016450); EXE and assembly verified. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void *func_80010A08();                       /* static */
void func_80016638(void *, s32, s32);        /* static */
extern s32 *D_800A6518;
extern s32 *D_800A651C;
extern s32 *D_800AE7B8;
extern s32 *D_800AE7BC;
extern u16 D_800AF7BC;
extern u16 D_800AF7BE;
extern u16 D_800B9A02;

void func_80016224(s8 arg0, s32 arg1) {
    void *var_v0;
    s32 *temp_a2_2;
    s32 *temp_v1;
    s32 temp_a2;
    s32 temp_v0_2;
    s32 temp_v0_5;
    s32 var_a0;
    s32 var_a1;
    u32 temp_v0_3;
    u32 temp_v0_4;
    u32 temp_v0_6;
    u32 temp_v0_7;
    void *temp_v0;

    temp_v0 = func_80010A08(0x18);
    M2C_FIELD(temp_v0, s8 *, 3) = 5;
    M2C_FIELD(temp_v0, s8 *, 7) = 0x2A;
    M2C_FIELD(temp_v0, s8 *, 6) = arg0;
    M2C_FIELD(temp_v0, s8 *, 5) = arg0;
    M2C_FIELD(temp_v0, s8 *, 4) = arg0;
    temp_v0_2 = -(s32) D_800AF7BC;
    temp_v0_3 = (u32) (temp_v0_2 + ((u32) temp_v0_2 >> 0x1F)) >> 1;
    M2C_FIELD(temp_v0, s16 *, 0x10) = (s16) temp_v0_3;
    M2C_FIELD(temp_v0, s16 *, 8) = (s16) temp_v0_3;
    temp_v0_4 = (u16) D_800AF7BC >> 1;
    M2C_FIELD(temp_v0, s16 *, 0x14) = (s16) temp_v0_4;
    M2C_FIELD(temp_v0, s16 *, 0xC) = (s16) temp_v0_4;
    temp_v0_5 = -(s32) D_800AF7BE;
    temp_v0_6 = (u32) (temp_v0_5 + ((u32) temp_v0_5 >> 0x1F)) >> 1;
    M2C_FIELD(temp_v0, s16 *, 0xE) = (s16) temp_v0_6;
    M2C_FIELD(temp_v0, s16 *, 0xA) = (s16) temp_v0_6;
    var_a1 = arg1 & 0xFFFF;
    temp_v0_7 = (u16) D_800AF7BE >> 1;
    M2C_FIELD(temp_v0, s16 *, 0x16) = (s16) temp_v0_7;
    M2C_FIELD(temp_v0, s16 *, 0x12) = (s16) temp_v0_7;
    if (var_a1 != 0) {
        temp_a2 = var_a1 * 4;
        M2C_FIELD(temp_v0, s32 *, 0) = (s32) ((M2C_FIELD(temp_v0, s32 *, 0) & 0xFF000000) | (*(temp_a2 + *(&D_800A651C + (D_800B9A02 * 0x14))) & 0xFFFFFF));
        temp_a2_2 = temp_a2 + *(&D_800A651C + (D_800B9A02 * 0x14));
        *temp_a2_2 = (*temp_a2_2 & 0xFF000000) | ((s32) temp_v0 & 0xFFFFFF);
        var_v0 = &D_800A6518;
        var_a0 = D_800B9A02 * 0x14;
    } else {
        M2C_FIELD(temp_v0, s32 *, 0) = (s32) ((M2C_FIELD(temp_v0, s32 *, 0) & 0xFF000000) | (**(&D_800AE7BC + (D_800B9A02 * 0x14)) & 0xFFFFFF));
        temp_v1 = *(&D_800AE7BC + (D_800B9A02 * 0x14));
        var_a1 = 0;
        *temp_v1 = (*temp_v1 & 0xFF000000) | ((s32) temp_v0 & 0xFFFFFF);
        var_a0 = D_800B9A02 * 0x14;
        var_v0 = &D_800AE7B8;
    }
    func_80016638(var_a0 + var_v0, var_a1, 2);
}
