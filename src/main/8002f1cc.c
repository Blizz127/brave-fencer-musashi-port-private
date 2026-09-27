/* Main-exec range [8002F1CC,8002F248) from the SLUS executable.
 * SHA256(span)=be19626151ad7a73a72243ecd4c6df857b74ea7aea47e9162839355e3681116a.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 *D_800A4694;

void func_8002F1CC(s32 arg0) {
    s32 var_a1;
    void *var_a0;

    var_a1 = 0;
    var_a0 = &D_800A4694 + 0x2F4;
    do {
        if (M2C_FIELD(((arg0 * 0x54) + &D_800A4694 + var_a1), u8 *, 0xE) != 0) {
            M2C_FIELD(var_a0, s16 *, 0x30) = 0;
            M2C_FIELD(var_a0, s8 *, 0x38) = 0;
            M2C_FIELD(var_a0, s32 *, 0x2C) = 0x18;
            M2C_FIELD(var_a0, s32 *, 0x28) = (s32) (M2C_FIELD(var_a0, s32 *, 0x20) + 0x100);
            M2C_FIELD(var_a0, u8 *, 0x37) = (u8) (M2C_FIELD(var_a0, u8 *, 0x37) | 1);
        }
        var_a1 += 1;
        var_a0 += 0x54;
    } while (var_a1 < 8);
}
