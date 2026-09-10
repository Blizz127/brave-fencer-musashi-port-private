/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012A5F8,8012A62C).
 * Offset 0x24A0 at overlay base 80128158. SHA256(span)=f7b119d1fb481b2151dd3894f45f822fd4ef9209a23000ec9efb3cd1d644d17d.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012a5f8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

/* Decompiled by m2c from main_0012.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

void func_8012A62C(s32);                               /* static */

void func_8012A5F8(s32 (*arg0)(), s32 arg1) {
    func_8012A62C(arg1 & 0xFF);
    arg0();
}
