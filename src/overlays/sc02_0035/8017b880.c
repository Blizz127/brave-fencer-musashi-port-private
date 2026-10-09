/* SC02.CD member35 [8017B880,8017B8E8): twin of main_0012 8017B880 (src/overlays/main_0012/8017b880.c); only the
 * global addresses differ. Byte-identical to the sc02_0035 retail words
 * (gcc-2.7.2 -O2, B28 inc 104 twin port). */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
extern s16 D_801BE8C4, D_801BE8C6, D_801BE8C8;
extern s16 D_801BE8CC, D_801BE8CE, D_801BE8D0;
extern s32 D_80114F30, D_80114F34, D_80114F38;
extern s32 D_80114F24, D_80114F28, D_80114F2C;
void func_8017B880(void) {
    D_80114F30 = D_801BE8C4;
    D_80114F34 = D_801BE8C6;
    D_80114F38 = D_801BE8C8;
    D_80114F24 = D_801BE8CC;
    D_80114F28 = D_801BE8CE;
    D_80114F2C = D_801BE8D0;
}
