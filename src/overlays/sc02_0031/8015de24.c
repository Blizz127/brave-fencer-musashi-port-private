/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015DE24,8015DE58).
 * Offset 0x35CCC at overlay base 80128158. SHA256(span)=65a7bd22f0c2238f6b7921a77f728629f028edd837daa0b0168b6a9c8885f0d0.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015de24.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
void func_80147078();
void func_8015DE58();
void func_8015DE24(void *p) {
    func_80147078(p, 15);
    func_8015DE58(p);
}
