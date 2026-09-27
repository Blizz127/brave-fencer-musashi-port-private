/* SC02.CD FILE_031 / ov_SC02_031 retail span [801574DC,80157510).
 * Offset 0x2F384 at overlay base 80128158. SHA256(span)=79b0e13ecd5d5058fb7318f8427599547feb57d440ecf6011f790003712105f5.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801574dc.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
void func_80147078();
void func_801575E4();
void func_801574DC(void *p) {
    func_80147078(p, 6);
    func_801575E4(p);
}
