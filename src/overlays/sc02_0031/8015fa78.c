/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015FA78,8015FAAC).
 * Offset 0x37920 at overlay base 80128158. SHA256(span)=906551006d432fecaf85cf6071560c49d4f50c47dc89486b29e3a24b56d6ef95.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015fa78.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
void func_80147078();
void func_8015FAAC();
void func_8015FA78(void *p) {
    func_80147078(p, 22);
    func_8015FAAC(p);
}
