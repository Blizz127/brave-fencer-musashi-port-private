/* Exact retail word export for [80031BE0,80031CC8); EXE and assembly verified. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8003388C(u16 *, s32);                  /* static */
extern u16 D_800A2BB0;
extern u8 D_800A4F17;
extern s32 *D_800BA108;

void func_80031BE0(void) {
    s32 temp_v1;
    s32 var_s1;
    u16 *var_s3;
    u16 temp_v0;
    u8 *var_s0;
    u8 *var_s2;

    var_s2 = &D_800A4F17 - 0x82F;
    if (D_800A4F17 == 0) {
        var_s1 = 0;
        var_s0 = &D_800A4F17 - 0x827;
        var_s3 = &D_800A2BB0;
        do {
            *var_s3 = M2C_FIELD(var_s0, u16 *, -4);
            *(&D_800BA108 + (var_s1 * 2)) = M2C_FIELD(var_s0, u16 *, -2);
            temp_v1 = *var_s2 & 0x3F;
            if (temp_v1 != 1) {
                if (temp_v1 >= 2) {
                    if (temp_v1 != 5) {
                        var_s3 += 2;
                    } else {
                        func_8003388C((u16 *) var_s2, var_s1);
                        goto block_9;
                    }
                } else {
                    goto block_9;
                }
            } else {
                temp_v0 = M2C_FIELD(var_s0, u16 *, 0);
                if (temp_v0 != 0) {
                    M2C_FIELD(var_s0, u16 *, 0) = (u16) (temp_v0 - 1);
                }
block_9:
                var_s3 += 2;
            }
            var_s1 += 1;
            var_s0 += 0x54;
            var_s2 += 0x54;
        } while (var_s1 < 8);
    }
}
