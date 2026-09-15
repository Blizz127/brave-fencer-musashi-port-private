/* Main-exec range [8005A468,8005A4A0) from the SLUS executable.
 * SHA256(span)=d96383b1203a46ea071332e7d8ff1514b1966b30d3902d77b6799d84192da41e.
 * Word export for the native seam; the body below is kept
 * byte-identical (wrap only, no rewrite). */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
void func_8005C324();
extern s32 D_800727F4;
void *func_8005A468(void *p) {
    func_8005C324(p, &D_800727F4, 0x14);
    return p;
}
