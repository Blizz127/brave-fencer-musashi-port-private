/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015D4B4,8015D4E8).
 * Offset 0x3535C at overlay base 80128158. SHA256(span)=25efd2f7970b449de6776af1028f8ae421160569c005300686358fefea938ef7.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015d4b4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
void func_80147078();
void func_8015D4E8();
void func_8015D4B4(void *p) {
    func_80147078(p, 13);
    func_8015D4E8(p);
}
