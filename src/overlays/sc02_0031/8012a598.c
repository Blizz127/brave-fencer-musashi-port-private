/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012A598,8012A5F8).
 * Offset 0x2440 at overlay base 80128158. SHA256(span)=3befcdb3e9cd74f3aba4cc0895b0ddcf532a2da9ba2ffdb4bf3edb4c3f082e3f.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012a598.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef struct { u32 w[41]; } T41;
extern T41 *D_801151D4;
extern T41 D_80126DB8;
extern u8 D_80127504;

void func_8012A598(void) {
    D_80126DB8 = *D_801151D4;
    D_80127504 = 0x30;
}
