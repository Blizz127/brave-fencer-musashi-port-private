/* SC02.CD FILE_031 / ov_SC02_031 retail span [801743F0,80174430).
 * Offset 0x4C298 at overlay base 80128158. SHA256(span)=26b637a7ec5f914932ed3c9d2062a9b5533b82c125ad22f5363899593f4d4bea.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801743f0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

/* Decompiled by m2c from main_0012.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

void func_80171A1C(s32);                               /* static */
s32 func_80172658();                                /* static */
void func_80174650(s32);                               /* static */

void func_801743F0(s32 arg0) {
    if (func_80172658() != 0) {
        func_80171A1C(arg0);
        func_80174650(arg0);
    }
}
