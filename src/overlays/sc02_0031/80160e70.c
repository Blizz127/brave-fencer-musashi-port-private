/* SC02.CD FILE_031 / ov_SC02_031 retail span [80160E70,80160EA4).
 * Offset 0x38D18 at overlay base 80128158. SHA256(span)=c1878b26da96c4d1cf04b567c4f5668659937bbbbc6301ba1a1575f4858eb774.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80160e70.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
void func_80147078();
void func_80160EA4();
void func_80160E70(void *p) {
    func_80147078(p, 30);
    func_80160EA4(p);
}
