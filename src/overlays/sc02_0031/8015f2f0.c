/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015F2F0,8015F324).
 * Offset 0x37198 at overlay base 80128158. SHA256(span)=a3de6c3c379b9d10d86537dc903351f294a9bcb81e88abacbb71811baf6d2a05.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015f2f0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
void func_80147078();
void func_8015F324();
void func_8015F2F0(void *p) {
    func_80147078(p, 20);
    func_8015F324(p);
}
