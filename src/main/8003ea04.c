/* Main-exec range [8003EA04,8003EAB4) from the SLUS executable.
 * SHA256(span)=029de41112355ac1b9490c6d8d6cac948851670f732c869c7f7ff6919bce1339.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 *D_800C73D8;

s32 func_8003EA04(s32 arg0, s16 arg1) {
    s32 temp_v0;
    s32 var_v0;
    u8 *temp_v1;
    u8 *temp_v1_3;
    u8 temp_v1_2;
    u8 var_a0;
    void *temp_a1;

    temp_a1 = *(&D_800C73D8 + ((s32) (arg0 << 0x10) >> 0xE)) + (arg1 * 0xB0);
    temp_v1 = M2C_FIELD(temp_a1, u8 **, 0);
    M2C_FIELD(temp_a1, u8 **, 0) = (u8 *) (temp_v1 + 1);
    var_a0 = *temp_v1;
    if (var_a0 == 0) {
        return 0;
    }
    var_v0 = var_a0 * 4;
    if (var_a0 & 0x80) {
        var_a0 &= 0x7F;
        do {
            temp_v1_3 = M2C_FIELD(temp_a1, u8 **, 0);
            M2C_FIELD(temp_a1, u8 **, 0) = (u8 *) (temp_v1_3 + 1);
            temp_v1_2 = *temp_v1_3;
            var_a0 = (var_a0 << 7) + (temp_v1_2 & 0x7F);
        } while (temp_v1_2 & 0x80);
        var_v0 = var_a0 * 4;
    }
    temp_v0 = (var_v0 + var_a0) * 2;
    M2C_FIELD(temp_a1, s32 *, 0x88) = (s32) (M2C_FIELD(temp_a1, s32 *, 0x88) + temp_v0);
    return temp_v0;
}
