/* Exact retail word export for [80034650,800346D0); EXE and assembly verified. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80030D80(void *, s16);              /* static */
extern s32 *D_800A4988;

void func_80034650(s16 *arg0, s32 arg1) {
    void *var_s1;
    s32 var_s0;

    var_s0 = 0;
    var_s1 = &D_800A4988;
    do {
        if (M2C_FIELD((arg0 + var_s0), u8 *, 0x3A) != 0) {
            func_80030D80(var_s1, (s16) (arg1 & 0xFF));
        }
        var_s0 += 1;
        var_s1 += 0x54;
    } while (var_s0 < 8);
    *arg0 = 0;
}
