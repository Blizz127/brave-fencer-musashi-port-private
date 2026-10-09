/* SC02.CD member35 [80161C98,80161CD0): twin of main_0012 80161C98 (src/overlays/main_0012/80161c98.c); only the
 * global addresses differ. Byte-identical to the sc02_0035 retail words
 * (gcc-2.7.2 -O2, B28 inc 104 twin port). */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
void func_80147324();
extern u16 D_80186FA8[];
void func_80161C98(s32 a0, u32 a1) {
    if (a1 < 8) {
        func_80147324(D_80186FA8[a1]);
    }
}
