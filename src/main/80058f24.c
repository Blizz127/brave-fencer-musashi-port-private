/* Main-exec range [80058F24,80058F44) from the SLUS executable.
 * SHA256(span)=e0926522ff1bf4fac909d4f3a682033658994d5799c28567dfd48332a8149311.
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
    u8 rest[28];
    u32 tag;
} P;
void func_80058F24(P *p) {
    p->code = 9;
    p->code2 = 92;
    p->tag = 0x55555555u;
}
