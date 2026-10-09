/* SC02.CD member35 [8017B7A8,8017B824): twin of main_0012 8017B7A8 (src/overlays/main_0012/8017b7a8.c); only the
 * global addresses differ. Byte-identical to the sc02_0035 retail words
 * (gcc-2.7.2 -O2, B28 inc 104 twin port). */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
extern s32 D_80114F30, D_80114F34, D_80114F38;
extern s32 D_80114F24, D_80114F28, D_80114F2C;
extern u8 D_8012694C;
extern s16 D_801BE834;
extern s16 D_801BE8AC, D_801BE8AE, D_801BE8B0;
extern s16 D_801BE8A4, D_801BE8A6, D_801BE8A8;
void func_8017B7A8(void) {
    D_8012694C = 1;
    D_801BE834 = 0;
    D_801BE8AC = D_80114F30;
    D_801BE8AE = D_80114F34;
    D_801BE8B0 = D_80114F38;
    D_801BE8A4 = D_80114F24;
    D_801BE8A6 = D_80114F28;
    D_801BE8A8 = D_80114F2C;
}
