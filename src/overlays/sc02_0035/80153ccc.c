/* SC02.CD member35 [80153CCC,80153D34): twin of main_0012 80153CCC (src/overlays/main_0012/80153ccc.c); only the
 * global addresses differ. Byte-identical to the sc02_0035 retail words
 * (gcc-2.7.2 -O2, B28 inc 104 twin port). */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_801862F0[];
void func_80019064();
extern s32 D_801862C8;
extern s16 D_8011DB0C;
extern s16 D_8011F748;
typedef struct { u8 pad[2]; u16 idx; } T;
void func_80153CCC(T *p) {
    func_80019064(&D_801862C8);
    D_801862F0[p->idx](p);
    D_8011DB0C = 0;
    D_8011F748 = 0;
}
