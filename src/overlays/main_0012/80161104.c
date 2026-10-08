/* Decompiled by m2c from main_0012.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"

s32 func_80161208(void *);

s32 func_80161104(void *p) {
    return func_80161208(p) == 0; /* a0 passes through (retail) */
}
