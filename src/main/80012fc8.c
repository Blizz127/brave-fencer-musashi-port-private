/* Main-exec range [80012FC8,80013028) from the SLUS executable.
 * SHA256(span)=cf4ddf052e199ef47d268db0d55cf17fd5b86a58a9021af25932350820dfe06b.
 * Word export only: the native seam executes the retail instruction
 * stream itself; this is not a C match claim. */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
s32 func_80013028();
s32 func_80012FC8(s32 a0, s32 a1, s32 a2, s32 a3) {
    s16 tmp = 4;
    if ((s16)a0 == (s16)a1) {
        return 0;
    }
    return (s16)func_80013028((s16)a0, (s16)a1, (s16)a2, (s16)a3, &tmp);
}
