/* Main-exec range [8002A960,8002A998) from the SLUS executable.
 * SHA256(span)=1c814beb68f20b456d90e2e22d3a8c6b678ab1b8495cefc114dd39c432a99644.
 * Word export for the native seam; the body below is kept
 * byte-identical (wrap only, no rewrite). */
#include "psx_types.h"

/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

extern s32 D_80078EF4;
extern s32 D_80078EF8;

void func_8002A960(void) {
    s32 var_v1;

    var_v1 = D_80078EF4 + 1;
    if (var_v1 >= 0x1F) {
        var_v1 = 0x1E;
    }
    D_80078EF4 = var_v1;
    D_80078EF8 = 0;
}
