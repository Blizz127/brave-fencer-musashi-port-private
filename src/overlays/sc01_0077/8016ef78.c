/* Decompiled by m2c from main_0012.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"

s32 func_8016EFC8(s32, s32);
void func_801726D0(void *);                               /* static */
extern s32 *D_80126B58;

void func_8016EF78(s32 a0, s32 a1) {
    func_8016EFC8(a0, a1); /* a0/a1 pass through (retail) */
    func_801726D0(&D_80126B58);
}
