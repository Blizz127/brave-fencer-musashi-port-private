/* Overlay range [8012B8E4,8012BA10) from MAIN.CD member 0012.
 * SHA256(span)=35eeaa608d1a071588bd42e61a6686574312f645cc4d4d4852fdc5c68d6dae0c.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_8004CFEC(s32, s32);                        /* extern */
extern s16 D_80126CB4;
extern s16 D_80126CB8;

s32 func_8012B8E4(void *arg0, s16 arg1) {
    s16 temp_s1;
    s32 temp_a0;
    s32 temp_lo;
    s32 temp_lo_2;
    s32 temp_s1_2;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v1;
    s32 var_v1_2;

    temp_s1 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), s16 *, 0x12);
    temp_a0 = (func_8004CFEC(M2C_FIELD(arg0, s16 *, 0xE) - D_80126CB8, D_80126CB4 - M2C_FIELD(arg0, s16 *, 6)) - 0x400) & 0xFFF;
    temp_s1_2 = temp_s1 & 0xFFF;
    if (temp_s1_2 == temp_a0) {
        return 0;
    }
    var_v1 = temp_a0 - temp_s1_2;
    var_v0_2 = var_v1 < -0x800;
    if (var_v1 >= 0x801) {
        var_v1 = temp_a0 - (temp_s1_2 + 0x1000);
        var_v0_2 = var_v1 < -0x800;
    }
    if (var_v0_2 != 0) {
        var_v1 = temp_a0 - (temp_s1_2 - 0x1000);
    }
    if (var_v1 >= 0) {
        temp_lo = var_v1 / arg1;
        var_v0 = temp_lo;
        if (temp_lo == 0) {
            var_v1_2 = 1;
            goto block_11;
        }
    } else {
        temp_lo_2 = var_v1 / arg1;
        var_v0 = temp_lo_2;
        if (temp_lo_2 == 0) {
            var_v1_2 = -1;
block_11:
            var_v0 = var_v1_2;
        }
    }
    return var_v0;
}
