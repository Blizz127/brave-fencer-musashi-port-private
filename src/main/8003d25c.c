/* Exact retail word export for [8003D25C,8003D32C); EXE and assembly verified. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006B0E4;
extern s32 D_8006B54C;

s32 func_8003D25C(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_a1;
    s32 var_a0;
    s32 var_a1;
    s32 var_a3;
    s32 var_v0;
    s8 *var_a2;
    u16 temp_v0;

    var_a0 = arg0;
    var_a1 = arg1;
    var_v0 = var_a0 < 0x18;
    if (var_a0 < 0) {
        var_a0 = 0;
        var_v0 = 0 < 0x18;
    }
    if (var_v0 != 0) {
        if (var_a1 >= 0x18) {
            var_a1 = 0x17;
        }
        if ((var_a1 < 0) || (var_a3 = var_a0, ((var_a1 < var_a0) != 0))) {
            goto block_7;
        }
        temp_a1 = var_a1 + 1;
        if (var_a3 < temp_a1) {
            var_a2 = var_a3 + arg2;
            do {
                temp_v0 = M2C_FIELD(((var_a3 * 0x10) + D_8006B54C), u16 *, 0xC);
                if (D_8006B0E4 & (1 << var_a3)) {
                    if (temp_v0 != 0) {
                        *var_a2 = 1;
                    } else {
                        *var_a2 = 3;
                    }
                } else if (temp_v0 != 0) {
                    *var_a2 = 2;
                } else {
                    *var_a2 = 0;
                }
                var_a3 += 1;
                var_a2 += 1;
            } while (var_a3 < temp_a1);
        }
        return 0;
    }
block_7:
    return -3;
}
