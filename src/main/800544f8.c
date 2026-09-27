/* Exact retail word export for [800544F8,80054514); EXE and assembly verified. */
/* Verified byte-exact against retail by tools/match_function.py
 * (7/7 words at 0x800544F8). Types and signatures are whatever
 * reproduces the bytes; they are not evidence of the original
 * declaration. */
#include "psx_types.h"

s32 func_800544F8(s32 arg0) {
    s32 var_a0;
    s32 n;

    n = 0;
    var_a0 = arg0;
    if (var_a0 > 0) {
        do {
            var_a0 = var_a0 >> 1;
            n += 1;
        } while (var_a0 > 0);
    }
    return n;
}
