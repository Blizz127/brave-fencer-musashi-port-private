/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
s32 func_801615C4();
s32 func_8016163C();
/* B28: returns func_8016163C's result; the retail tail call leaves it in v0,
 * which callers read. Byte-identical (gcc-2.7.2-psx -O2). */
s32 func_80161418(void *p) {
    return func_8016163C(p, func_801615C4(p, 0));
}
