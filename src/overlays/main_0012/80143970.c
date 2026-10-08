/* Decompiled by m2c from main_0012.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"

s32 func_8012C588(s32, s32);                            /* static */

/* B28: returns func_8012C588's result; the retail tail call leaves it in v0,
 * which callers read. Byte-identical (gcc-2.7.2-psx -O2). */
s32 func_80143970(s32 arg0) {
    return func_8012C588(0x1B, arg0);
}
