/* Exact retail word export for [8005C020,8005C054); EXE and assembly verified. */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
extern s32 D_800728A0;
extern s32 D_800728A4;

s32 func_8004239C();                               /* static */

void func_8005C020(void) {
    D_800728A0 = func_8004239C(-1) + 0xF0;
    D_800728A4 = 0;
}
