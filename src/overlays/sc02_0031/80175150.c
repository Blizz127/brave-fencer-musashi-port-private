/* SC02.CD FILE_031 / ov_SC02_031 retail span [80175150,80175184).
 * Offset 0x4CFF8 at overlay base 80128158. SHA256(span)=ed25fbaeefd73a601d4bdc88941c29d2cf548b733f043bf4774a0d1348343551.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80175150.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
void func_80147078();
void func_80175184();
void func_80175150(void *p) {
    func_80147078(p, 8);
    func_80175184(p);
}
