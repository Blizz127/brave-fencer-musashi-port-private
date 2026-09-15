/* Main-exec range [800402A8,800403A4) from the SLUS executable.
 * SHA256(span)=c022066b10f12eb9ceba3897cb231ee53855c2ad9acab66a867caf4bca0ecf1c.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006B900[];
extern s32 D_800A6584;
extern u8 D_800B9B27;
extern u8 D_800B9B2C;

s32 func_800402A8(s32 arg0, s32 arg1) {
    s16 temp_a0;
    s32 temp_a1;
    s32 temp_v0;
    s32 var_a2;
    s32 var_a3;
    s32 var_v0;
    u16 var_v1;
    void *temp_v1;

    temp_v1 = ((D_800B9B2C + (D_800B9B27 * 0x10)) << 5) + D_800A6584;
    var_v0 = (arg1 & 0xFFFF) + M2C_FIELD(temp_v1, u8 *, 5);
    if (var_v0 < 0) {
        var_v0 += 7;
    }
    temp_a1 = var_v0 >> 3;
    var_a3 = temp_a1;
    var_a2 = 0;
    if (temp_a1 >= 0x10) {
        var_a2 = 1;
        var_a3 = temp_a1 - 0x10;
    }
    temp_v0 = (arg0 + 0x3C) - M2C_FIELD(temp_v1, u8 *, 4);
    temp_a0 = ((var_a2 + temp_v0) / 12) - 5;
    var_v1 = *(D_8006B900 + ((((s32) (((var_a2 + temp_v0) % 12) << 0x10) >> 0xC) + (s16) var_a3) * 2));
    if (temp_a0 > 0) {
        var_v1 <<= temp_a0;
    } else if (temp_a0 < 0) {
        var_v1 = (u16) ((s32) (var_v1 & 0xFFFF) >> -temp_a0);
    }
    return var_v1 & 0xFFFF;
}
