#include "psx_types.h"

/* Decompiled by m2c from main_0012.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

extern s32 D_801ED3B0;
extern s32 D_801ED3B4;
extern s32 D_801ED3B8;
void func_80136BC4();                                  /* static */

void func_801336E8(s32 arg0, s32 arg1, s32 arg2) {
    if (arg0 != 0) {
        D_801ED3B0 = arg0;
        func_80136BC4();
    }
    D_801ED3B4 = arg1;
    D_801ED3B8 = arg2;
}
