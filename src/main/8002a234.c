/* Main-exec range [8002A234,8002A26C) from the SLUS executable.
 * SHA256(span)=3f0e5e4a6de5a8e27aa73c0eb957a5d179687384cc8240bb577d9499e69a3a17.
 * Word export for the native seam; the body below is kept
 * byte-identical (wrap only, no rewrite). */
#include "psx_types.h"

/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

extern s32 D_80078EE4;
extern s32 D_80078EE8;

void func_8002A234(void) {
    s32 var_v1;

    var_v1 = D_80078EE4 + 1;
    if (var_v1 >= 0x1F) {
        var_v1 = 0x1E;
    }
    D_80078EE4 = var_v1;
    D_80078EE8 = 0;
}
