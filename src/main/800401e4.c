/* Main-exec range [800401E4,800402A8) from the SLUS executable.
 * SHA256(span)=1fc910e345e577244882e437e98e21150f88ca6c3d710cc533ffb4c911c18dfb.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006B900[];
extern u8 D_800B9B22;
extern u8 D_800B9B30;
extern u8 D_800B9B31;

s32 func_800401E4(void) {
    s16 temp_v0_2;
    s32 temp_v0;
    u16 var_v1;
    u32 var_a1_2;
    u8 var_a1;

    var_a1 = D_800B9B31;
    temp_v0 = D_800B9B22 + 0x3C;
    if ((s32) var_a1 < 0) {
        var_a1 += 7;
    }
    var_a1_2 = var_a1 >> 3;
    if (var_a1_2 >= 0x10U) {
        var_a1_2 = 0xF;
    }
    var_v1 = *(D_8006B900 + ((((s32) (((temp_v0 - D_800B9B30) % 12) << 0x10) >> 0xC) + (var_a1_2 & 0xFFFF)) * 2));
    temp_v0_2 = ((temp_v0 - D_800B9B30) / 12) - 5;
    if (temp_v0_2 > 0) {
        var_v1 <<= temp_v0_2;
    } else if (temp_v0_2 < 0) {
        var_v1 = (u16) ((s32) (var_v1 & 0xFFFF) >> -temp_v0_2);
    }
    return var_v1 & 0xFFFF;
}
