/* Exact retail word export for [800335B8,800336A8); EXE and assembly verified. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 *D_800A46E8;

void func_800335B8(s32 arg0, s32 arg1) {
    s32 var_v1;
    s32 var_v1_2;
    u16 var_a2;
    u16 var_a2_2;
    void *temp_a3;
    void *var_a0;
    void *var_a0_2;

    temp_a3 = (arg0 * 0x54) + &D_800A46E8;
    if ((M2C_FIELD(temp_a3, u16 *, 0) & 0x3F) == 1) {
        var_v1 = 0;
        if (arg1 & 0x1000) {
            var_a2 = M2C_FIELD(temp_a3, u16 *, 0xC);
            var_a0 = &D_800A46E8 + 0x2A0;
loop_3:
            if (var_a2 != 0) {
                if (M2C_FIELD((temp_a3 + var_v1), u8 *, 0xE) != 0) {
                    var_a2 -= 1;
                    M2C_FIELD(var_a0, s16 *, 0x48) = (s16) (arg1 & 0x7F);
                    M2C_FIELD(var_a0, s8 *, 0x4F) = 1;
                }
                var_v1 += 1;
                var_a0 += 0x54;
                if (var_v1 >= 8) {
                    return;
                }
                goto loop_3;
            }
        } else if (arg1 & 0x2000) {
            var_a2_2 = M2C_FIELD(temp_a3, u16 *, 0xC);
            var_v1_2 = 0;
            var_a0_2 = &D_800A46E8 + 0x2A0;
loop_10:
            if (var_a2_2 != 0) {
                if (M2C_FIELD((temp_a3 + var_v1_2), u8 *, 0xE) != 0) {
                    if (M2C_FIELD(var_a0_2, u8 *, 0x35) != 0) {
                        M2C_FIELD(var_a0_2, s8 *, 0x53) = (s8) (arg1 & 0x7F);
                    }
                    var_a2_2 -= 1;
                }
                var_v1_2 += 1;
                var_a0_2 += 0x54;
                if (var_v1_2 < 8) {
                    goto loop_10;
                }
            }
        }
    }
}
