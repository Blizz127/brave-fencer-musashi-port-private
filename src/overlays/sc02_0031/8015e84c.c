/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015E84C,8015E880).
 * Offset 0x366F4 at overlay base 80128158. SHA256(span)=b268d9b7edff04f5880a17c736975bd92c9aa740e5601bba9cea05c702aa414c.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015e84c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
void func_80147078();
void func_8015E95C();
void func_8015E84C(void *p) {
    func_80147078(p, 17);
    func_8015E95C(p);
}
