/* Exact retail word export for [8005FA94,8005FB70); EXE and assembly verified. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void D_80072960();                               /* static */

void func_8005FA94(void *arg0) {
    u8 temp_v1;
    u8 temp_v1_2;
    u8 temp_v1_3;
    u8 var_v0;

    temp_v1 = M2C_FIELD(arg0, u8 *, 0x46);
    M2C_FIELD(arg0, s32 *, 0x4C) = (s32) (M2C_FIELD(arg0, s32 *, 0x4C) + 1);
    if (temp_v1 != 0) {
        if (temp_v1 == 1) {
            temp_v1_2 = M2C_FIELD(arg0, u8 *, 0x4A);
            var_v0 = temp_v1_2 + 1;
            if (temp_v1_2 >= 2U) {
                M2C_FIELD(arg0, u8 *, 0x49) = 2U;
                M2C_FIELD(arg0, u8 *, 0x46) = 0xFFU;
                return;
            }
            goto block_5;
        }
        temp_v1_3 = M2C_FIELD(arg0, u8 *, 0x4A);
        var_v0 = temp_v1_3 + 1;
        if (temp_v1_3 < 4U) {
block_5:
            M2C_FIELD(arg0, u8 *, 0x4A) = var_v0;
            return;
        }
        if (M2C_FIELD(arg0, u8 *, 0x49) != 0) {
            D_80072960(arg0);
        }
        goto block_8;
    }
block_8:
    if (*M2C_FIELD(arg0, u8 **, 0x3C) != 0xF3) {
        M2C_FIELD(M2C_FIELD(arg0, void **, 0x30), s8 *, 0) = 0xFF;
        M2C_FIELD(M2C_FIELD(arg0, void **, 0x30), s8 *, 1) = 0;
        M2C_FIELD(arg0, s8 *, 0xE8) = 0;
    }
}
