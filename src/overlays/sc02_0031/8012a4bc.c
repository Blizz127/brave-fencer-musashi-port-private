/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012A4BC,8012A568).
 * Offset 0x2364 at overlay base 80128158. SHA256(span)=5821f68588540ee0c6c267894fb9d2103ceb3e67124b206b2e34e4e006e35a83.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012a4bc.c (recovery=c, -O2); the span is
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

extern T41 D_80114EE8;
void func_8012A4BC(void) {
    D_80126DB8 = *D_801151D4;
    *D_801151D4 = D_80114EE8;
    D_80127504 = 0x30;
}
