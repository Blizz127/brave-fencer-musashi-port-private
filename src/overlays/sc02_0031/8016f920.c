/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016F920,8016F95C).
 * Offset 0x477C8 at overlay base 80128158. SHA256(span)=c3766b827481b83eed23ca42f312571bb7486a49dc4beacc69bc377bc236caa2.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016f920.c (recovery=c, -O2); the span is
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
void func_8016F95C();
void func_8016F920(void *p) {
    func_801719A4(p, 2);
    func_80171990(p);
    func_8016F95C(p);
}
