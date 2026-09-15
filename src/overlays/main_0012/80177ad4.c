/* Overlay range [80177AD4,80177B5C) from MAIN.CD member 0012.
 * SHA256(span)=756362ff1f6a6190e3c15e7130a711896255cad2787d8e9f5bb48c0197fe6d8e.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80177AD4(s32 arg0, s32 arg1) {
    s16 temp_v0;
    s16 var_a3;
    s32 var_a1;
    s32 var_t0;
    u32 temp_v0_2;
    void *var_a2;

    var_a1 = arg1;
    var_t0 = 0x100;
    var_a3 = 0;
    var_a2 = arg0 + 0x20;
    do {
        temp_v0_2 = (u32) (var_a1 << 0x10) >> 0x1C;
        if ((temp_v0_2 != 0) || (var_a3 == 3) || (var_a3 == 1)) {
            var_t0 = 0;
        }
        var_a1 *= 0x10;
        temp_v0 = var_a3 + 1;
        var_a3 = temp_v0;
        M2C_FIELD(var_a2, s8 *, 0) = (s8) ((temp_v0_2 * 8) + 8);
        M2C_FIELD(var_a2, u16 *, -2) = (u16) (var_t0 | (M2C_FIELD(var_a2, u16 *, -2) & ~0x100));
        var_a2 += 0x14;
    } while (temp_v0 < 4);
}
