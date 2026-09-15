/* Exact retail word export for [800346D0,800347C8); EXE and assembly verified. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80030D80(u16 *, s32);              /* static */
extern u16 D_800A46E8;

void func_800346D0(s16 arg0) {
    s32 temp_s5;
    s32 var_s0;
    s32 var_s4;
    u16 *var_s1;
    u16 *var_s2;
    u16 *var_s3;

    var_s2 = &D_800A46E8;
    var_s4 = 0;
    temp_s5 = arg0 >> 0x10;
    var_s3 = &D_800A46E8 + 6;
    do {
        if ((*var_s2 == 5) && (M2C_FIELD(var_s3, u16 *, -2) == arg0) && ((var_s0 = 0, (temp_s5 == 0)) || (temp_s5 == M2C_FIELD(var_s3, u16 *, 0)))) {
            var_s1 = &D_800A46E8 + 0x2A0;
            do {
                if (M2C_FIELD((var_s2 + var_s0), u8 *, 0x3A) != 0) {
                    func_80030D80(var_s1, 0);
                }
                var_s0 += 1;
                var_s1 += 0x54;
            } while (var_s0 < 8);
            *var_s2 = 0;
        }
        var_s4 += 1;
        var_s3 += 0x54;
        var_s2 += 0x54;
    } while (var_s4 < 8);
}
