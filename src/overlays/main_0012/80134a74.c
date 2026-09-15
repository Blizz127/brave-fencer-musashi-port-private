/* Overlay range [80134A74,80134C20) from MAIN.CD member 0012.
 * SHA256(span)=dc7552ea8c14e044b3d1b3faf4a7a63bcee3d2895170f5ba3d95ad265b050613.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80184130;
s32 func_80134C20(s16, u16 *, s32, s32);            /* static */

s32 func_80134A74(s32 arg0, s32 arg1, s32 arg2, void *arg3) {
    s32 temp_a1;
    s32 temp_s3;
    s32 temp_s4;
    s32 temp_s5;
    s32 temp_s6;
    s32 temp_v0;
    s32 temp_v0_3;
    u16 *var_s0;
    u16 *var_s1;
    u16 temp_t0;
    u16 temp_v1;
    u16 var_s2;
    void *temp_v0_2;

    temp_t0 = M2C_FIELD(arg3, u16 *, 4);
    temp_a1 = (((s32) ((arg1 & 0xFFFF) + 0x8000) >> 7) & 0x1FF) - M2C_FIELD(arg3, u16 *, 0);
    if ((u32) (temp_a1 & 0xFFFF) < temp_t0) {
        temp_v0 = (((s32) ((arg2 & 0xFFFF) + 0x8000) >> 7) & 0x1FF) - M2C_FIELD(arg3, u16 *, 2);
        if ((u32) (temp_v0 & 0xFFFF) >= (u16) M2C_FIELD(arg3, u16 *, 6)) {
            return 0;
        }
        temp_s6 = M2C_FIELD(arg3, s32 *, 0xC);
        temp_s5 = M2C_FIELD(arg3, s32 *, 0x10);
        temp_s4 = M2C_FIELD(arg3, s32 *, 0x18);
        temp_s3 = M2C_FIELD(arg3, s32 *, 0x1C);
        temp_v0_2 = ((((((temp_v0 & 0xFFFF) * temp_t0) + (temp_a1 & 0xFFFF)) * 2) & 0xFFFF) * 2) + M2C_FIELD(arg3, s32 *, 8);
        var_s2 = M2C_FIELD(temp_v0_2, u16 *, 2);
        var_s1 = (M2C_FIELD(arg3, s32 *, 0x14) + M2C_FIELD(temp_v0_2, u16 *, 0) + (var_s2 * 2)) - 2;
loop_9:
        var_s2 -= 1;
        if (!(var_s2 & 0xFFFF)) {
            goto block_10;
        }
        temp_v1 = *var_s1;
        temp_v0_3 = temp_v1 & 0x8000;
        if (temp_v0_3 == 0) {
            var_s0 = temp_s4 + (temp_v1 * 0x12);
        } else {
            var_s0 = temp_s3 + ((temp_v1 & 0x7FFF) * 0x16);
        }
        var_s1 -= 2;
        if (func_80134C20((s16) (temp_v0_3 | arg0), var_s0, temp_s5, temp_s6) == 0) {
            goto loop_9;
        }
        D_80184130 = (u16) *var_s0;
        return 1;
    }
block_10:
    return 0;
}
