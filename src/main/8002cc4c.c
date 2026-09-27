/* Exact retail word export for [8002CC4C,8002CCB4); EXE-verified. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80065504;
extern s32 D_8006A970;

void func_8002CC4C(void) {
    s32 (*var_a2)();
    s32 (*var_t0)();
    s32 var_a0;
    s32 var_a3;
    void *var_v1;

    var_t0 = D_8006A970;
    var_a2 = D_80065504;
    var_a3 = 0;
    do {
        var_v1 = *var_t0;
        var_a0 = 0;
        if (*var_a2 > 0) {
            do {
                var_a0 += 1;
                M2C_FIELD(var_v1, s8 *, 0xA) = 0;
                var_v1 += 0xC;
            } while (var_a0 < *var_a2);
        }
        var_a2 += 4;
        var_a3 += 4;
        var_t0 += 4;
    } while (var_a3 < 0x10);
}
