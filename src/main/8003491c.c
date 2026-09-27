/* Exact retail word export for [8003491C,80034A54); EXE and assembly verified. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006451C;
s16 func_8002F4E4(u8 *, u8 *, s16);                 /* static */
extern u8 D_800A4F17;

void func_8003491C(s16 arg0) {
    s16 temp_v0;
    s16 var_a2;
    s32 temp_v1;
    s32 var_a0;
    u32 temp_s2;
    u8 *var_a1;
    u8 *var_a1_2;
    u8 *var_v1;
    u8 temp_t3;

    var_a2 = arg0;
    var_a1 = (arg0 * 4) + D_8006451C;
    temp_s2 = (u32) arg0 >> 0x10;
    if ((*var_a1 & 0x7F) == 6) {
        temp_v0 = func_8002F4E4(var_a1, var_a1, var_a2);
        var_a2 = temp_v0;
        if (temp_v0 != 0) {
            var_a1 = (temp_v0 * 4) + D_8006451C;
            goto block_3;
        }
    } else {
block_3:
        if (var_a2 >= 0x100) {
            temp_t3 = D_800A4F17;
            D_800A4F17 = 1;
            temp_v1 = *var_a1 & 0x7F;
            if ((temp_v1 != 1) && (temp_v1 == 5)) {
                var_a1_2 = &D_800A4F17 - 0x82F;
                var_a0 = 0;
                var_v1 = &D_800A4F17 - 0x819;
                do {
                    if ((*var_a1_2 == 5) && (M2C_FIELD(var_v1, u16 *, -0x12) == arg0) && (((s16) temp_s2 == 0) || ((s16) temp_s2 == M2C_FIELD(var_v1, u16 *, -0x10)))) {
                        M2C_FIELD(var_v1, u8 *, 0) = 1;
                    }
                    var_a0 += 1;
                    var_v1 += 0x54;
                    var_a1_2 += 0x54;
                } while (var_a0 < 8);
            }
            D_800A4F17 = temp_t3;
        }
    }
}
