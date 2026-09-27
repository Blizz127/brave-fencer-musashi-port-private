/* Main-exec range [8005A4D0,8005A50C) from the SLUS executable.
 * SHA256(span)=ab7ee63bde402895e23b768f16f5bf0ed6f9b509bef8456776f1dc4f8d272736.
 * Word export for the native seam; the body below is kept
 * byte-identical (wrap only, no rewrite). */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
s32 func_8005AD34();
typedef struct { u8 pad[3]; u8 unk3; s32 unk4, unk8; } T;
void func_8005A4D0(T *p, void *a1) {
    p->unk3 = 2;
    p->unk4 = func_8005AD34(a1);
    p->unk8 = 0;
}
