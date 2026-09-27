/* SC02.CD FILE_031 / ov_SC02_031 retail span [80159B08,80159B3C).
 * Offset 0x319B0 at overlay base 80128158. SHA256(span)=350ed196530bdfc7e79b1a1c31434ae5532df058b6fb23008ad4705797577ef9.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80159b08.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
void func_80147078();
void func_80159BE4();
void func_80159B08(void *p) {
    func_80147078(p, 0);
    func_80159BE4(p);
}
