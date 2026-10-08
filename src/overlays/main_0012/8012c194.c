#include "psx_types.h"

/* Decompiled by m2c from main_0012.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

void * func_8001D074(s32, s32);                              /* extern */

/* B28: returns func_8001D074's result; the retail tail call leaves it in v0,
 * which callers read. Byte-identical (gcc-2.7.2-psx -O2). */
void * func_8012C194(void) {
    return func_8001D074(0x3E, 0x7D);
}
