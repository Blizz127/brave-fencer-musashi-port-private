/* SC02.CD FILE_031 / ov_SC02_031 retail span [80160104,80160138).
 * Offset 0x37FAC at overlay base 80128158. SHA256(span)=988d7dca01b9ed8d482098bb4e1f608f100b180a09333511bdfb400010cb24d0.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80160104.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
void func_80147078();
void func_80160138();
void func_80160104(void *p) {
    func_80147078(p, 24);
    func_80160138(p);
}
