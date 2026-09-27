/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015CC40,8015CC74).
 * Offset 0x34AE8 at overlay base 80128158. SHA256(span)=e692e8c6bd169b98e593cfc537919c9763b72feffd740fbc67b49b717dc353cf.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015cc40.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
void func_80147078();
void func_8015CC74();
void func_8015CC40(void *p) {
    func_80147078(p, 11);
    func_8015CC74(p);
}
