/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
void func_8016EE40(s32, s32);
extern s32 D_80126D70;
void func_8016EDBC(s32 a0, s32 a1, s32 a2) {
    func_8016EE40(a0, a1);
    D_80126D70 = a2;
}
