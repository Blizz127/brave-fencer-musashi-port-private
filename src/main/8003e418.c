/* Main-exec range [8003E418,8003E65C) from the SLUS executable.
 * SHA256(span)=4aa844a1178d6f215549591611cfc9d6e71305cd562f899e1a3f11c4698b78cc.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8003EAB4(u8, u8, s32, s32 *);          /* static */
void func_80041448(s16);                         /* static */
extern s32 *D_800C73D8;

void func_8003E418(s32 arg0, s16 arg1) {
    s32 *temp_a3;
    s32 temp_a2;
    s32 var_v1;
    u8 temp_v0;
    u8 temp_v1;
    void *temp_s0;
    void *temp_v1_2;
    void *temp_v1_3;
    void *temp_v1_4;
    void *temp_v1_5;
    void *temp_v1_6;

    temp_a3 = ((s32) (arg0 << 0x10) >> 0xE) + &D_800C73D8;
    temp_a2 = arg1 * 0xB0;
    temp_s0 = *temp_a3 + temp_a2;
    temp_v1 = M2C_FIELD(temp_s0, u8 *, 0x20);
    temp_v0 = M2C_FIELD(temp_s0, u8 *, 0x21) + 1;
    M2C_FIELD(temp_s0, u8 *, 0x21) = temp_v0;
    if (temp_v1 == 0) {
        M2C_FIELD(temp_s0, s32 *, 0x88) = 0;
        M2C_FIELD(temp_s0, s8 *, 0x1C) = 0;
        M2C_FIELD(temp_s0, s32 *, 0x90) = 0;
        if (M2C_FIELD((temp_a2 + *temp_a3), s32 *, 0x98) & 0x400) {
            M2C_FIELD(temp_s0, s32 *, 0) = (s32) M2C_FIELD(temp_s0, s32 *, 0xC);
            return;
        }
        M2C_FIELD(temp_s0, s32 *, 0) = (s32) M2C_FIELD(temp_s0, s32 *, 4);
        return;
    }
    if ((u32) (temp_v0 & 0xFF) < temp_v1) {
        M2C_FIELD(temp_s0, s32 *, 0x88) = 0;
        M2C_FIELD(temp_s0, s8 *, 0x1C) = 0;
        M2C_FIELD(temp_s0, s32 *, 0x90) = 0;
        if (M2C_FIELD((temp_a2 + *temp_a3), s32 *, 0x98) & 0x400) {
            var_v1 = M2C_FIELD(temp_s0, s32 *, 0xC);
            M2C_FIELD(temp_s0, s32 *, 0) = (s32) M2C_FIELD(temp_s0, s32 *, 0xC);
        } else {
            var_v1 = M2C_FIELD(temp_s0, s32 *, 4);
            M2C_FIELD(temp_s0, s32 *, 0) = (s32) M2C_FIELD(temp_s0, s32 *, 4);
        }
        M2C_FIELD(temp_s0, s32 *, 8) = var_v1;
        return;
    }
    temp_v1_2 = temp_a2 + *temp_a3;
    M2C_FIELD(temp_v1_2, s32 *, 0x98) = (s32) (M2C_FIELD(temp_v1_2, s32 *, 0x98) & ~1);
    temp_v1_3 = temp_a2 + *temp_a3;
    M2C_FIELD(temp_v1_3, s32 *, 0x98) = (s32) (M2C_FIELD(temp_v1_3, s32 *, 0x98) & ~8);
    temp_v1_4 = temp_a2 + *temp_a3;
    M2C_FIELD(temp_v1_4, s32 *, 0x98) = (s32) (M2C_FIELD(temp_v1_4, s32 *, 0x98) & ~2);
    temp_v1_5 = temp_a2 + *temp_a3;
    M2C_FIELD(temp_v1_5, s32 *, 0x98) = (s32) (M2C_FIELD(temp_v1_5, s32 *, 0x98) | 0x200);
    temp_v1_6 = temp_a2 + *temp_a3;
    M2C_FIELD(temp_v1_6, s32 *, 0x98) = (s32) (M2C_FIELD(temp_v1_6, s32 *, 0x98) | 4);
    M2C_FIELD(temp_s0, s8 *, 0x14) = 0;
    if (M2C_FIELD((temp_a2 + *temp_a3), s32 *, 0x98) & 0x400) {
        M2C_FIELD(temp_s0, s32 *, 8) = (s32) M2C_FIELD(temp_s0, s32 *, 0xC);
    } else {
        M2C_FIELD(temp_s0, s32 *, 8) = (s32) M2C_FIELD(temp_s0, s32 *, 4);
    }
    if (M2C_FIELD(temp_s0, u8 *, 0x22) != 0xFF) {
        M2C_FIELD(temp_s0, s8 *, 0x14) = 0;
        func_8003EAB4(M2C_FIELD(temp_s0, u8 *, 0x22), M2C_FIELD(temp_s0, u8 *, 0x23), temp_a2, temp_a3);
        func_80041448((s16) (arg0 | (arg1 << 8)));
    }
    func_80041448((s16) (arg0 | (arg1 << 8)));
    M2C_FIELD(temp_s0, s32 *, 0x90) = (s32) M2C_FIELD(temp_s0, s16 *, 0x54);
}
