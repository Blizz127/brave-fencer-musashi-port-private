/* Main-exec range [8002C3B0,8002C410) from the SLUS executable.
 * SHA256(span)=6d28d572fb003263bd945817c14f6d67ff76214641474b1d6dfccf1633ae5206.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_8002C3B0(s32 arg0, void *arg1) {
    s32 temp_v0;
    s32 temp_v1;
    s32 var_a2;
    s32 var_a3;
    s32 var_v1;
    void *var_a1;

    var_a1 = arg1;
    var_a3 = 0;
    var_a2 = 0;
    if (arg0 > 0) {
        do {
            temp_v0 = M2C_FIELD(var_a1, s32 *, 0x18);
            var_v1 = temp_v0;
            if (temp_v0 < 0) {
                var_v1 = temp_v0 + 0x1FFF;
            }
            temp_v1 = var_v1 >> 0xD;
            if (temp_v0 & 0x1FFF) {
                var_a2 = var_a2 + 1 + temp_v1;
            } else {
                var_a2 += temp_v1;
            }
            var_a3 += 1;
            var_a1 += 0x28;
        } while (var_a3 < arg0);
    }
    return var_a2;
}
