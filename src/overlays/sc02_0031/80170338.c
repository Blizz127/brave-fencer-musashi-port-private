/* SC02.CD FILE_031 / ov_SC02_031 retail span [80170338,80170374).
 * Offset 0x481E0 at overlay base 80128158. SHA256(span)=d0f3258cf41790970e18abff059448525ee7205bf5aad7cbf98c018b13a88845.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80170338.c (recovery=c, -O2); the span is
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
void func_80170374();
void func_80170338(void *p) {
    func_801719A4(p, 1);
    func_80171990(p);
    func_80170374(p);
}
