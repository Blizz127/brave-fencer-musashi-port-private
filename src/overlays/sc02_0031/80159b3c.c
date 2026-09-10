/* SC02.CD FILE_031 / ov_SC02_031 retail span [80159B3C,80159B70).
 * Offset 0x319E4 at overlay base 80128158. SHA256(span)=8d0c06bb90e75f6cc634681ff84b42995f91b430adb989a6422b2173590fdad6.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80159b3c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
void func_80147078();
void func_80159B70();
void func_80159B3C(void *p) {
    func_80147078(p, 0);
    func_80159B70(p);
}
