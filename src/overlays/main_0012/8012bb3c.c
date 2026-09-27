/* Overlay range [8012BB3C,8012BC60) from MAIN.CD member 0012.
 * SHA256(span)=e2387b4b60633a23e37b28ebacd2a4864e7e041e032dd9470c1c85c492dd73fb.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_8004CFEC(s32, s32, s16);                   /* extern */

s16 func_8012BB3C(void *arg0, void *arg1, s32 arg2, s16 arg3) {
    s16 temp_a2;
    s32 temp_a0;
    s32 temp_lo;
    s32 temp_lo_2;
    s32 temp_s1;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v1;
    s32 var_v1_2;

    temp_a2 = M2C_FIELD(arg0, s16 *, 0xA);
    temp_s1 = arg2 & 0xFFF;
    temp_a0 = (func_8004CFEC(temp_a2 - M2C_FIELD(arg1, s16 *, 0xA), M2C_FIELD(arg1, s16 *, 2) - M2C_FIELD(arg0, s16 *, 2), temp_a2) - 0x400) & 0xFFF;
    if (temp_s1 == temp_a0) {
        var_v0 = 0;
    } else {
        var_v1 = temp_a0 - temp_s1;
        var_v0_2 = var_v1 < -0x800;
        if (var_v1 >= 0x801) {
            var_v1 = temp_a0 - (temp_s1 + 0x1000);
            var_v0_2 = var_v1 < -0x800;
        }
        if (var_v0_2 != 0) {
            var_v1 = temp_a0 - (temp_s1 - 0x1000);
        }
        if (var_v1 >= 0) {
            temp_lo = var_v1 / arg3;
            var_v0 = temp_lo;
            if (temp_lo == 0) {
                var_v1_2 = 1;
                goto block_11;
            }
        } else {
            temp_lo_2 = var_v1 / arg3;
            var_v0 = temp_lo_2;
            if (temp_lo_2 == 0) {
                var_v1_2 = -1;
block_11:
                var_v0 = var_v1_2;
            }
        }
    }
    return (s16) var_v0;
}
