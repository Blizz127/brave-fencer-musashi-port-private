/* Overlay range [801488A8,8014891C) from MAIN.CD member 0012.
 * SHA256(span)=f1d643f29936a018ecea6acbf834702bb644fd3db10e6415460d452cfcaf0a2d.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_801488A8(void *arg0) {
    s32 temp_v1_2;
    s32 var_v0;
    u16 temp_a0;
    u8 temp_v1;

    temp_v1 = M2C_FIELD(arg0, u8 *, 0xA9);
    if (temp_v1 != 0x53) {
        if ((s32) temp_v1 < 0x54) {
            if (temp_v1 != 0x41) {
                return 0;
            }
            return M2C_FIELD(arg0, u16 *, 0xAA) & 0xF000;
        }
        if (temp_v1 != 0x73) {
            return 0;
        }
        goto block_7;
    }
block_7:
    temp_a0 = M2C_FIELD(arg0, u16 *, 0xAE);
    temp_v1_2 = temp_a0 & 0xFF;
    var_v0 = 1;
    if (temp_v1_2 == 0x80) {
        var_v0 = 1;
        if ((temp_a0 >> 8) == temp_v1_2) {
            var_v0 = 0;
        }
    }
    return var_v0;
}
