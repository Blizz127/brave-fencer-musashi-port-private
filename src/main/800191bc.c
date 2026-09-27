/* Exact retail word export [800191BC,800191D4); verified against pinned EXE and asm. */
#include "psx_types.h"

/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

extern s32 D_80078E30;

void func_800191BC(s16 arg0) {
    D_80078E30 = (s32) arg0;
}

