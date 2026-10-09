/* SC02.CD member35 [80164E40,80164EA4): twin of main_0012 80164E40 (src/overlays/main_0012/80164e40.c); only the
 * global addresses differ. Byte-identical to the sc02_0035 retail words
 * (gcc-2.7.2 -O2, B28 inc 104 twin port). */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef struct { u8 a, b, c, d; } G;
extern G D_801BD840;
s32 func_80164E40(void) {
    if (D_801BD840.a) {
        D_801BD840.a = D_801BD840.a - 0x10;
    }
    if (D_801BD840.b) {
        D_801BD840.b = D_801BD840.b - 0x10;
    }
    if (D_801BD840.c) {
        D_801BD840.c = D_801BD840.c - 0x10;
    }
    return *(s32 *)&D_801BD840 == 0;
}
