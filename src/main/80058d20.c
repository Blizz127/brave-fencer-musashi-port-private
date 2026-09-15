/* Main-exec range [80058D20,80058D48) from the SLUS executable.
 * SHA256(span)=eb964be03801d86f8b89264d4ae4ce91b6e17ce436ebe941ee58896fb90be7e7.
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
typedef struct { u8 pad[7]; u8 flags; } T;
void func_80058D20(T *p, s32 on) {
    if (on) p->flags |= 2;
    else p->flags &= ~2;
}
