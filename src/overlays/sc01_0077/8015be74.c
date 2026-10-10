/* Decompiled by m2c from main_0012.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"

void func_8015BE94();                                  /* static */

/* B28: the retail body leaves a0 untouched, so func_8015BE94 receives this
 * function's own arguments. Byte-identical (gcc-2.7.2-psx -O2). */
void func_8015BE74(s32 arg0) {
    func_8015BE94(arg0);
}
