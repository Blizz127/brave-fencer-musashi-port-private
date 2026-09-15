/* Exact retail word export for [80018F88,80018FC8); EXE and assembly verified. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80018F88(s32 arg0) {
    s32 var_v1;
    s32 var_v1_2;
    void *var_v0;

    var_v1 = 1;
    var_v0 = arg0 + 1;
    do {
        M2C_FIELD(var_v0, s8 *, 0x2A) = 0;
        var_v1 -= 1;
        var_v0 -= 1;
    } while (var_v1 >= 0);
    var_v1_2 = 2;
    do {
        M2C_FIELD((arg0 + var_v1_2), s8 *, 0x2A) = 0x80;
        var_v1_2 += 1;
    } while (var_v1_2 < 6);
}
