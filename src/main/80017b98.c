/* Main-exec range [80017B98,80017D98) from the SLUS executable.
 * SHA256(span)=52c684c1a109ead90be33be634327b5dc7577d488250c1f674c419bbf22da269.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void *func_80010A08();                       /* static */
extern s32 *D_800A651C;
extern s32 *D_800AF630;

void func_80017B98(void *arg0) {
    s16 var_v0;
    s32 *temp_a1_4;
    s32 temp_a1_3;
    s32 temp_v1;
    s32 var_a1;
    u16 temp_a1;
    u8 temp_a1_2;
    u8 temp_v0_2;
    void *temp_a0;
    void *temp_v0;

    temp_v0 = func_80010A08(0x2C);
    M2C_FIELD(temp_v0, s32 *, 0) = 0x05000000;
    temp_a1 = M2C_FIELD(arg0, u16 *, 0xE);
    M2C_FIELD(temp_v0, s8 *, 0xB) = 0x64;
    M2C_FIELD(temp_v0, s32 *, 4) = (s32) ((((u32) M2C_FIELD(arg0, u32 *, 0x14) >> 0x17) & 0x60) | ((temp_a1 >> 4) & 0x10) | (((u16) M2C_FIELD(arg0, u16 *, 0xC) >> 8) & 0xF) | ((temp_a1 & 0x200) * 4) | 0xE1000000);
    temp_a1_2 = M2C_FIELD(arg0, u8 *, 0x12);
    M2C_FIELD(temp_v0, s32 *, 8) = (s32) ((temp_a1_2 << 0x10) | ((M2C_FIELD(arg0, u8 *, 0x11) << 8) | 0x64000000) | temp_a1_2);
    M2C_FIELD(temp_v0, s16 *, 0xC) = (s16) (M2C_FIELD(arg0, u16 *, 0) - ((u16) M2C_FIELD(arg0, u16 *, 8) >> 1));
    M2C_FIELD(temp_v0, s16 *, 0xE) = (s16) (M2C_FIELD(arg0, u16 *, 2) - ((u16) M2C_FIELD(arg0, u16 *, 0xA) >> 1));
    M2C_FIELD(temp_v0, s8 *, 0x10) = (s8) M2C_FIELD(arg0, u16 *, 0xC);
    M2C_FIELD(temp_v0, s8 *, 0x11) = (s8) M2C_FIELD(arg0, u16 *, 0xE);
    temp_v0_2 = M2C_FIELD(arg0, u8 *, 0x18);
    temp_a0 = temp_v0 + 4;
    temp_v1 = (temp_v0_2 + 0x100) << 6;
    if (temp_v0_2 < 0xE0U) {
        var_v0 = temp_v1 | 0x16;
    } else {
        var_v0 = temp_v1 | 0x10;
    }
    M2C_FIELD(temp_a0, s16 *, 0xE) = var_v0;
    M2C_FIELD(temp_a0, u16 *, 0x10) = (u16) M2C_FIELD(arg0, u16 *, 8);
    M2C_FIELD(temp_a0, u16 *, 0x12) = (u16) M2C_FIELD(arg0, u16 *, 0xA);
    if (M2C_FIELD(arg0, u32 *, 0x14) & 0x40000000) {
        M2C_FIELD(temp_a0, s32 *, 4) = (s32) (M2C_FIELD(temp_a0, s32 *, 4) | 0x02000000);
    }
    var_a1 = M2C_FIELD(arg0, s32 *, 4);
    if (var_a1 >= 0x1000) {
        var_a1 = 0xFFF;
    }
    temp_a1_3 = var_a1 * 4;
    M2C_FIELD(temp_v0, s32 *, 0) = (s32) ((M2C_FIELD(temp_v0, s32 *, 0) & 0xFF000000) | (*(temp_a1_3 + *(&D_800A651C + (M2C_FIELD(&D_800AF630, u16 *, 0xA3D2) * 0x14))) & 0xFFFFFF));
    temp_a1_4 = temp_a1_3 + *(&D_800A651C + (M2C_FIELD(&D_800AF630, u16 *, 0xA3D2) * 0x14));
    *temp_a1_4 = (*temp_a1_4 & 0xFF000000) | ((s32) temp_v0 & 0xFFFFFF);
}
