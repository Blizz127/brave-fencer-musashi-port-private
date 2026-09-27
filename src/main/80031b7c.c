/* Exact retail word export for [80031B7C,80031BE0); EXE and assembly verified. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 *D_800A49D2;

void func_80031B7C(void) {
    void *var_v1;
    s32 var_a0;

    var_a0 = 0;
    var_v1 = &D_800A49D2;
    do {
        if ((M2C_FIELD(var_v1, u8 *, 4) != 0) && (M2C_FIELD(var_v1, u8 *, 2) == 0) && (M2C_FIELD(var_v1, u8 *, 3) != 0)) {
            M2C_FIELD(var_v1, u8 *, 2) = 1U;
            M2C_FIELD(var_v1, s16 *, 0) = 0x7FFF;
        }
        var_a0 += 1;
        var_v1 += 0x54;
    } while (var_a0 < 8);
}
