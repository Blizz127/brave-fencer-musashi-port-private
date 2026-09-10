/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015EFA4,8015EFD8).
 * Offset 0x36E4C at overlay base 80128158. SHA256(span)=e9f11199dae209624d3f369936a2e5f175a09f7e9d41e63efb331e459908bcf3.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015efa4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
void func_80147078();
void func_8015F080();
void func_8015EFA4(void *p) {
    func_80147078(p, 19);
    func_8015F080(p);
}
