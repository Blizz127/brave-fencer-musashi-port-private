/* Main-exec range [80058EE4,80058F04) from the SLUS executable.
 * SHA256(span)=efc980d7d5f988f360e632348d8c0e48c3b94643ba9a99fecedfaa45dc7ba349.
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
typedef struct {
    u8 r,g,b,code;
    u8 r2,g2,b2,code2;
    u8 rest[20];
    u32 tag;
} P;
void func_80058EE4(P *p) {
    p->code = 7;
    p->code2 = 88;
    p->tag = 0x55555555u;
}
