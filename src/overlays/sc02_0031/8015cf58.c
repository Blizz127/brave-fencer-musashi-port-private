/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015CF58,8015CF8C).
 * Offset 0x34E00 at overlay base 80128158. SHA256(span)=1e980744bf1706b8127b51428cfb1c9a02d8335890eeb9462e7576ca9411ff00.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015cf58.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
void func_80147078();
void func_8015D01C();
void func_8015CF58(void *p) {
    func_80147078(p, 12);
    func_8015D01C(p);
}
