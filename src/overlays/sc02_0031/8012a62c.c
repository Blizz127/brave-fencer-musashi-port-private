/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012A62C,8012A68C).
 * Offset 0x24D4 at overlay base 80128158. SHA256(span)=55d3909c5bfcfdcf8406c0e42c72437383731194acd911c85f4b5f133ef7966c.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012a62c.c (recovery=c, -O2); the span is
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

void func_8012A62C(u8 v) {
    D_80126DB8 = *D_801151D4;
    D_80127504 = v;
}
