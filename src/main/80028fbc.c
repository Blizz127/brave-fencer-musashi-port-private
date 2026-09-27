/* Exact retail word export for [80028FBC,80028FDC); EXE and assembly verified. */
#include "psx_types.h"

/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

s32 func_800291B4();                               /* static */

s32 func_80028FBC(void) {
    return func_800291B4(0x2C) & 0xFF;
}
