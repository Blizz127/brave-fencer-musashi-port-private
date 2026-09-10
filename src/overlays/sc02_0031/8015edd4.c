/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015EDD4,8015EE08).
 * Offset 0x36C7C at overlay base 80128158. SHA256(span)=36b16b1da741840eced14735d78d13e000fe73d9e8358d8eb8fac77bd8b28dfd.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015edd4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
void func_80147078();
void func_8015EE08();
void func_8015EDD4(void *p) {
    func_80147078(p, 18);
    func_8015EE08(p);
}
