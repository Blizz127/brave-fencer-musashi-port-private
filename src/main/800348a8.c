/* Exact retail word export for [800348A8,8003491C); EXE and assembly verified. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern u16 D_800A46E8;

s32 func_800348A8(u32 arg0) {
    s32 var_v0;
    s32 var_v1;
    u16 *var_a1;
    u16 *var_a2;
    u32 temp_a0;

    var_a2 = &D_800A46E8;
    var_v1 = 0;
    temp_a0 = arg0 >> 0x10;
    var_a1 = &D_800A46E8 + 6;
loop_1:
    if ((*var_a2 != 5) || (M2C_FIELD(var_a1, u16 *, -2) != (arg0 & 0xFFFF)) || ((var_v0 = var_v1 + 1, (temp_a0 != 0)) && (var_v0 = var_v1 + 1, (M2C_FIELD(var_a1, u16 *, 0) != temp_a0)))) {
        var_v1 += 1;
        var_a1 += 0x54;
        var_a2 += 0x54;
        if (var_v1 >= 8) {
            var_v0 = 0;
        } else {
            goto loop_1;
        }
    }
    return var_v0;
}
