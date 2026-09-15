/* Overlay range [8014A2E4,8014A380) from MAIN.CD member 0012.
 * SHA256(span)=576180d49ff85e52b39e9aace097fdfcd222b1f18d1ee05b3b1cf44e0b394078.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_8014C278(s32, void *, s32);         /* static */
extern s32 *D_801202A0;

void *func_8014A2E4(s32 arg0) {
    void *var_s0;
    void *var_v0;
    u32 var_s1;

    var_s1 = 0;
    var_s0 = &D_801202A0;
loop_1:
    if ((M2C_FIELD(var_s0, u16 *, 0) == 0) || !(M2C_FIELD(var_s0, u16 *, 0x5C) & 0x8000) || (M2C_FIELD(var_s0, s16 *, 0xAA) == 0) || (var_v0 = var_s0, (func_8014C278(arg0, var_s0, 0x30) == 0))) {
        var_s1 += 1;
        var_s0 += 0x10C;
        if (var_s1 >= 0x60U) {
            var_v0 = 0;
        } else {
            goto loop_1;
        }
    }
    return var_v0;
}
