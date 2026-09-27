/* Exact retail word export for [80038908,80038958); EXE and assembly verified. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern u16 D_800A4EE0;
extern s16 D_800A4EF8;

void func_80038908(void *arg0) {
    s32 temp_lo;
    s32 var_a1;
    s32 var_v1;
    u16 *var_a2;

    var_a2 = arg0 + 0x12;
    var_v1 = 0;
    var_a1 = (s32) ((D_800A4EF8 << 7) * D_800A4EE0) >> 0xE;
    do {
        temp_lo = var_a1 * *var_a2;
        var_v1 -= 1;
        var_a2 += 8;
        var_a1 = temp_lo >> 0xE;
    } while (var_v1 >= 0);
    M2C_FIELD(arg0, s16 *, 0x10) = (s16) var_a1;
}
