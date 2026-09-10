/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015CF8C,8015CFC0).
 * Offset 0x34E34 at overlay base 80128158. SHA256(span)=01783322ae0a52324a0921b0c22f84b1736980cba747cb36799374a10b85bb42.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015cf8c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
void func_80147078();
void func_8015CFC0();
void func_8015CF8C(void *p) {
    func_80147078(p, 12);
    func_8015CFC0(p);
}
