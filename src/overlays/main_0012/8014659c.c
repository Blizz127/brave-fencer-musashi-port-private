/* Decompiled by m2c from main_0012.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"

void * func_8001CFDC(s32, s32);                              /* extern */

/* B28: returns func_8001CFDC's result; the retail tail call leaves it in v0,
 * which callers read. Byte-identical (gcc-2.7.2-psx -O2). */
void * func_8014659C(void) {
    return func_8001CFDC(6, 0x16);
}
