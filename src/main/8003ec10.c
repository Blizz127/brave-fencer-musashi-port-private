/* Main-exec range [8003EC10,8003ED94) from the SLUS executable.
 * SHA256(span)=cb0315804f68e674b8e5f9267c00700fae26a97a004e2c5c35c37e89b6bc69b5.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8003FA54();                            /* static */
void func_80041448(s16, s32, void *, s32);   /* static */
extern s32 *D_800C73D8;

void func_8003EC10(s32 arg0, s16 arg1) {
    s32 *temp_t0;
    s32 temp_a1;
    s32 temp_v1;
    s8 var_a3;
    void *temp_a2;
    void *temp_a2_2;
    void *temp_a2_3;
    void *temp_s0;
    void *temp_v0;
    void *temp_v1_2;
    void *var_t0;

    temp_t0 = ((s32) (arg0 << 0x10) >> 0xE) + &D_800C73D8;
    temp_v1 = arg1 * 0xB0;
    temp_s0 = *temp_t0 + temp_v1;
    M2C_FIELD(temp_s0, s32 *, 0x98) = (s32) (M2C_FIELD(temp_s0, s32 *, 0x98) & ~1);
    temp_a2 = temp_v1 + *temp_t0;
    M2C_FIELD(temp_a2, s32 *, 0x98) = (s32) (M2C_FIELD(temp_a2, s32 *, 0x98) & ~2);
    temp_a1 = arg1 << 8;
    temp_a2_2 = temp_v1 + *temp_t0;
    M2C_FIELD(temp_a2_2, s32 *, 0x98) = (s32) (M2C_FIELD(temp_a2_2, s32 *, 0x98) & ~8);
    temp_a2_3 = temp_v1 + *temp_t0;
    M2C_FIELD(temp_a2_3, s32 *, 0x98) = (s32) (M2C_FIELD(temp_a2_3, s32 *, 0x98) & ~0x400);
    temp_v1_2 = temp_v1 + *temp_t0;
    M2C_FIELD(temp_v1_2, s32 *, 0x98) = (s32) (M2C_FIELD(temp_v1_2, s32 *, 0x98) | 4);
    func_80041448((s16) (arg0 | temp_a1), temp_a1, temp_a2_3, -0x401);
    func_8003FA54();
    var_a3 = 0;
    var_t0 = temp_s0;
    M2C_FIELD(temp_s0, s8 *, 0x14) = 0;
    M2C_FIELD(temp_s0, s32 *, 0x88) = 0;
    M2C_FIELD(temp_s0, s8 *, 0x1C) = 0;
    M2C_FIELD(temp_s0, s8 *, 0x18) = 0;
    M2C_FIELD(temp_s0, s8 *, 0x19) = 0;
    M2C_FIELD(temp_s0, s8 *, 0x1E) = 0;
    M2C_FIELD(temp_s0, s8 *, 0x1A) = 0;
    M2C_FIELD(temp_s0, s8 *, 0x1B) = 0;
    M2C_FIELD(temp_s0, s8 *, 0x1F) = 0;
    M2C_FIELD(temp_s0, s8 *, 0x17) = 0;
    M2C_FIELD(temp_s0, s8 *, 0x21) = 0;
    M2C_FIELD(temp_s0, s8 *, 0x1C) = 0;
    M2C_FIELD(temp_s0, s8 *, 0x1D) = 0;
    M2C_FIELD(temp_s0, s8 *, 0x15) = 0;
    M2C_FIELD(temp_s0, s8 *, 0x16) = 0;
    M2C_FIELD(temp_s0, s32 *, 0x90) = (s32) M2C_FIELD(temp_s0, s32 *, 0x84);
    M2C_FIELD(temp_s0, s32 *, 0x94) = (s32) M2C_FIELD(temp_s0, s32 *, 0x8C);
    M2C_FIELD(temp_s0, u16 *, 0x54) = (u16) M2C_FIELD(temp_s0, u16 *, 0x56);
    M2C_FIELD(temp_s0, s32 *, 0) = (s32) M2C_FIELD(temp_s0, s32 *, 4);
    M2C_FIELD(temp_s0, s32 *, 8) = (s32) M2C_FIELD(temp_s0, s32 *, 4);
    do {
        temp_v0 = temp_s0 + var_a3;
        M2C_FIELD(temp_v0, s8 *, 0x37) = var_a3;
        M2C_FIELD(temp_v0, s8 *, 0x27) = 0x40;
        M2C_FIELD(var_t0, s16 *, 0x60) = 0x7F;
        var_a3 += 1;
        var_t0 += 2;
    } while (var_a3 < 0x10);
    M2C_FIELD(temp_s0, s16 *, 0x5C) = 0x7F;
    M2C_FIELD(temp_s0, s16 *, 0x5E) = 0x7F;
}
