/* SC02.CD member35 [80157788,801577C8): twin of main_0012 80157788 (src/overlays/main_0012/80157788.c); only the
 * global addresses differ. Byte-identical to the sc02_0035 retail words
 * (gcc-2.7.2 -O2, B28 inc 104 twin port). */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
extern s32 D_801BD768;
void func_80147078();
void func_801578C0();
void func_80157788(void *p) {
    D_801BD768 = 300;
    func_80147078(p, 7);
    func_801578C0(p);
}
