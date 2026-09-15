/* Overlay range [801778A8,80177940) from MAIN.CD member 0012.
 * SHA256(span)=8b5bbfd874d7c4d1ca0c1afe2039f0076689b0c3f3013e36287db414732d5062.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_801778A8(s32 arg0, s32 arg1, s16 arg2, s16 arg3) {
    s16 temp_v0;
    s16 var_t0;
    s32 var_a1;
    s32 var_t1;
    u32 temp_v0_2;
    void *var_a3;

    var_a1 = arg1;
    var_t1 = 0x100;
    var_t0 = 0;
    if (arg2 > 0) {
        var_a3 = arg0 + 0xC;
        do {
            temp_v0_2 = (u32) (var_a1 << 0x10) >> 0x1C;
            if ((temp_v0_2 != 0) || (var_t0 == (arg2 - 1)) || (var_t0 == arg3)) {
                var_t1 = 0;
            }
            var_a1 *= 0x10;
            temp_v0 = var_t0 + 1;
            var_t0 = temp_v0;
            M2C_FIELD(var_a3, s8 *, 0) = (s8) ((temp_v0_2 * 8) + 8);
            M2C_FIELD(var_a3, u16 *, -2) = (u16) (var_t1 | (M2C_FIELD(var_a3, u16 *, -2) & ~0x100));
            var_a3 += 0x14;
        } while (temp_v0 < arg2);
    }
}
