/* Main-exec range [800347C8,80034844) from the SLUS executable.
 * SHA256(span)=5cfd35207a748f71ba6935eac5aae5f7ccae6c9eb41edd1ec29bd3906e8bb007.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern u16 D_800A46E8;

void func_800347C8(s16 arg0) {
    s32 temp_a0;
    s32 var_a2;
    u16 *var_a1;
    u16 *var_v1;

    var_a1 = &D_800A46E8;
    var_a2 = 0;
    temp_a0 = arg0 >> 0x10;
    var_v1 = &D_800A46E8 + 0x16;
    do {
        if ((*var_a1 == 5) && (M2C_FIELD(var_v1, u16 *, -0x12) == arg0) && ((temp_a0 == 0) || (temp_a0 == M2C_FIELD(var_v1, u16 *, -0x10)))) {
            M2C_FIELD(var_v1, s8 *, 0) = 1;
        }
        var_a2 += 1;
        var_v1 += 0x54;
        var_a1 += 0x54;
    } while (var_a2 < 8);
}
