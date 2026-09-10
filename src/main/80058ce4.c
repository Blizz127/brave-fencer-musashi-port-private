/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

/* Exact retail word export for [80058CE4,80058D20); EXE and assembly verified. */
#include "psx_types.h"

void func_80058CE4(s32 *arg0, s32 arg1) {
    *arg0 = (*arg0 & 0xFF000000) | (arg1 & 0xFFFFFF);
}
