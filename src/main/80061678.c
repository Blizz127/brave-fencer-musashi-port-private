/* Main-exec range [80061678,800616D0) from the SLUS executable.
 * SHA256(span)=90bde11fd2119eedede462c5c96af44942d16459b763c49ca18804cc40d24f34.
 * Word export for the native seam; the body below is kept
 * byte-identical (wrap only, no rewrite). */
#include "psx_types.h"

/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

s32 func_80061678(s32 arg0) {
    s32 var_v1;

    var_v1 = 0;
    if (arg0 != 1) {
        if (arg0 < 2) {
            if (arg0 != 0) {
                var_v1 = arg0 | 0x8000;
            }
        } else if (arg0 != 2) {
            var_v1 = 3;
            if (arg0 != 4) {
                var_v1 = arg0 | 0x8000;
            }
        } else {
            var_v1 = 1;
        }
    } else {
        var_v1 = 2;
    }
    return var_v1;
}
