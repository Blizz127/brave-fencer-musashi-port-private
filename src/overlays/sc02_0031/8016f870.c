/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016F870,8016F8AC).
 * Offset 0x47718 at overlay base 80128158. SHA256(span)=eee3b5686734c122e9877bd365c242b6f834c53e143191d3163a7a8d57da68af.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016f870.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
void func_801719A4();
void func_80171990();
void func_8016F8AC();
void func_8016F870(void *p) {
    func_801719A4(p, 2);
    func_80171990(p);
    func_8016F8AC(p);
}
