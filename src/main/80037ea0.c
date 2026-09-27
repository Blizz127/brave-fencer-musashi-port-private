/* Main-exec range [80037EA0,80037F3C) from the SLUS executable.
 * SHA256(span)=50ac7998b3117ad9942bc55d300d1231f38c65ce6084760a7d9bb160a66507a8.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8003D3B4(s32, s32);                /* static */
extern s32 *D_800C6E2E;

void func_80037EA0(void) {
    void *var_s0;
    s32 var_s1;

    var_s1 = 0;
    var_s0 = &D_800C6E2E;
    do {
        if ((M2C_FIELD(var_s0, u8 *, -4) != 0) && (M2C_FIELD(var_s0, u8 *, -1) == 0) && (M2C_FIELD(var_s0, u8 *, 0) != 0)) {
            func_8003D3B4(var_s1, 8);
            M2C_FIELD(var_s0, u8 *, 0) = 0U;
            M2C_FIELD(var_s0, s32 *, -0x4A) = (s32) (M2C_FIELD(var_s0, s32 *, -0x4A) & 0xFFF9FFFF);
        }
        var_s1 += 1;
        var_s0 += 0x60;
    } while (var_s1 < 0x10);
}
