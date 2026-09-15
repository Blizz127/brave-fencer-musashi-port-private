/* Overlay range [8014A238,8014A2E4) from MAIN.CD member 0012.
 * SHA256(span)=97348bbea520eaf143f6c41a39ae6c9fd2e26da924e89bb9a4a89cd2dda90d3f.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_8014C278(s32, void *, s32);            /* static */
s32 func_8014C2B0(s32, void *, s32);            /* static */
extern s32 *D_801202A0;

void *func_8014A238(s32 arg0) {
    s32 var_s1;
    u32 var_s2;
    void *temp_s0;
    void *var_v0;

    var_s2 = 0;
    var_s1 = 0;
loop_1:
    temp_s0 = var_s1 + &D_801202A0;
    if ((M2C_FIELD(temp_s0, u16 *, 0) == 0) || (M2C_FIELD(temp_s0, s16 *, 0xAA) == 0) || (func_8014C278(arg0, temp_s0, 0x30) == 0) || (var_v0 = temp_s0, (func_8014C2B0(arg0, temp_s0, 0x200) == 0))) {
        var_s2 += 1;
        var_s1 += 0x10C;
        if (var_s2 >= 0x60U) {
            var_v0 = 0;
        } else {
            goto loop_1;
        }
    }
    return var_v0;
}
