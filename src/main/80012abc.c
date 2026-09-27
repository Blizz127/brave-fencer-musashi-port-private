/* Complete retail export [80012ABC,80012B04). */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
s32 func_80012B04();
s32 func_80012ABC(s32 a0, s32 a1, s32 a2) {
    return (a0 + func_80012B04((s16)a0, (s16)a1, (s16)a2)) & 0xFFF;
}
