/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
void func_80136BC4();
extern void *D_801ED3B4[];
extern void *D_801ED3B0;
void func_8013373C(s32 a0) {
    void *p = D_801ED3B4[(s16)a0];
    if (p) {
        D_801ED3B0 = p;
        func_80136BC4(p);
    }
}
