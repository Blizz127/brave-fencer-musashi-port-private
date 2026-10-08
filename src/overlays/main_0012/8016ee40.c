/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
void func_8016EF78(s32, s32);
void func_801599A4();
void func_80159B3C();
extern u16 D_80126B58;
void func_8016EE40(s32 p, s32 a1) {
    u16 *s = &D_80126B58;
    func_8016EF78(p, a1); /* a0/a1 pass through (retail) */
    if ((u16)(*s - 25) < 2) {
        return;
    }
    func_801599A4(s);
    func_80159B3C(s);
}
