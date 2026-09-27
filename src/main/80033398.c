/* Exact retail word export for [80033398,8003350C); EXE and assembly verified. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80030D80(u16 *, s32);              /* static */
void func_80034650(u16 *, s32);              /* static */
extern u16 D_800A46E8;

void func_80033398(u32 arg0) {
    s32 temp_a0;
    s32 temp_v1;
    s32 var_s1;
    s32 var_s4;
    u16 *temp_s2;
    u16 *var_s0;
    u16 *var_s3;
    u16 *var_s5;
    u32 temp_s6;
    void *temp_v1_2;

    var_s5 = &D_800A46E8;
    var_s4 = 0;
    temp_s6 = arg0 >> 0x10;
    var_s3 = &D_800A46E8 + 6;
    do {
        temp_a0 = *var_s5 & 0x3F;
        if ((temp_a0 == 1) && (M2C_FIELD(var_s3, u16 *, -2) == (arg0 & 0xFFFF)) && ((temp_s6 == 0) || (M2C_FIELD(var_s3, u16 *, 0) == temp_s6))) {
            temp_s2 = ((var_s4 & 0xFFFF) * 0x54) + &D_800A46E8;
            temp_v1 = *temp_s2 & 0x3F;
            if (temp_v1 != temp_a0) {
                if (temp_v1 != 5) {
                    var_s4 += 1;
                } else {
                    func_80034650(temp_s2, 0);
                    goto block_15;
                }
            } else {
                var_s1 = 0;
                var_s0 = &D_800A46E8 + 0x2A0;
                do {
                    temp_v1_2 = temp_s2 + var_s1;
                    if (M2C_FIELD(temp_v1_2, u8 *, 0xE) != 0) {
                        M2C_FIELD(temp_v1_2, u8 *, 0xE) = 0U;
                        M2C_FIELD(var_s0, s32 *, 0x40) = 0;
                        if (M2C_FIELD(var_s0, u8 *, 0x4E) != 0) {
                            func_80030D80(var_s0, 0);
                        }
                    }
                    var_s1 += 1;
                    var_s0 += 0x54;
                } while (var_s1 < 8);
                *temp_s2 = 0;
                goto block_15;
            }
        } else {
block_15:
            var_s4 += 1;
        }
        var_s3 += 0x54;
        var_s5 += 0x54;
    } while (var_s4 < 8);
}
