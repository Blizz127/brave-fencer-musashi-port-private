/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015554C,80155580).
 * Offset 0x2D3F4 at overlay base 80128158. SHA256(span)=6cb15fbe27ad5978a8f58a8cc76c4f8243ba543c2b43001bb4f34f90d2d288d4.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015554c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
void func_80147078();
void func_80155580();
void func_8015554C(void *p) {
    func_80147078(p, 5);
    func_80155580(p);
}
