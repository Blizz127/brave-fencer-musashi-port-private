/* Exact retail word export for [80029344,8002941C); EXE and assembly verified. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 *D_80078E78;
extern u16 D_80078E92;
extern s8 D_80078EAE;

void func_80029344(void) {
    s32 temp_v1;
    s32 var_v0;
    s8 var_v0_2;

    if ((u32) (D_80078E92 - 0x1A4) >= 0x2D0U) {
        D_80078EAE = 0;
        var_v0 = D_80078E92 << 0x10;
    } else {
        D_80078EAE = 1;
        var_v0 = D_80078E92 << 0x10;
    }
    temp_v1 = var_v0 >> 0x10;
    if (temp_v1 < 0x528) {
        if (temp_v1 >= 0x474) {
            var_v0_2 = 3;
            goto block_13;
        }
        if (temp_v1 >= 0x3C0) {
            var_v0_2 = 2;
            goto block_13;
        }
        if (temp_v1 >= 0x1A4) {
            var_v0_2 = 1;
            goto block_13;
        }
        var_v0_2 = 4;
        if (temp_v1 >= 0x12C) {
            M2C_FIELD(&D_80078E78, s8 *, 0x37) = 0;
        } else {
            goto block_13;
        }
    } else {
        var_v0_2 = 4;
block_13:
        M2C_FIELD(&D_80078E78, s8 *, 0x37) = var_v0_2;
    }
    M2C_FIELD(&D_80078E78, s8 *, 0x39) = (s8) (D_80078E92 / 60);
    M2C_FIELD(&D_80078E78, s8 *, 0x38) = (s8) (D_80078E92 % 60);
}
