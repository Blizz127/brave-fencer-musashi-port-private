/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015E150,8015E184).
 * Offset 0x35FF8 at overlay base 80128158. SHA256(span)=b261ce93f449b8f4f14ad1c1206110d26c0f1bccb99485a0c5e430d7c51bf9f0.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015e150.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
void func_80147078();
void func_8015E22C();
void func_8015E150(void *p) {
    func_80147078(p, 16);
    func_8015E22C(p);
}
