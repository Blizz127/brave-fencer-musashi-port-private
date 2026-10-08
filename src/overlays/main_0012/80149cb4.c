/* Decompiled by m2c from main_0012.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"

void func_80157D20();                                  /* static */

/* B28: the retail body leaves a0-a1 untouched, so func_80157D20 receives this
 * function's own arguments. Byte-identical (gcc-2.7.2-psx -O2). */
void func_80149CB4(void *arg0, s32 arg1) {
    func_80157D20(arg0, arg1);
}
