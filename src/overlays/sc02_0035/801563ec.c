/* SC02.CD member35 [801563EC,8015640C): twin of main_0012 801563EC (src/overlays/main_0012/801563ec.c); only the
 * global addresses differ. Byte-identical to the sc02_0035 retail words
 * (gcc-2.7.2 -O2, B28 inc 104 twin port). */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
extern u8 D_80186534[];
void *func_801563EC(u16 a0) {
    return D_80186534 + a0 * 12;
}
