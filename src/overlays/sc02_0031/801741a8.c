/* SC02.CD FILE_031 / ov_SC02_031 retail span [801741A8,801741EC).
 * Offset 0x4C050 at overlay base 80128158. SHA256(span)=e31a60863e44a59c7e0b937dab0a52a46f14a106466f558c853d9bf148d50840.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801741a8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

/* Decompiled by m2c from main_0012.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

void func_8014B2A8();                                  /* static */
void func_8014BB0C();                                  /* static */
void func_8014BDC8();                                  /* static */
extern s32 D_80078EA4;
extern s32 D_80078ED8;

void func_801741A8(void) {
    func_8014BDC8();
    func_8014BB0C();
    func_8014B2A8();
    D_80078ED8 = 0xA00000;
    D_80078EA4 = 0xA00000;
}
