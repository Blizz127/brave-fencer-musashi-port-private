/* SC02.CD FILE_031 / ov_SC02_031 retail span [801607E4,80160818).
 * Offset 0x3868C at overlay base 80128158. SHA256(span)=44cd8ed1e941f8c5f70a7adb1b4d8a13cd020e47f974b774672fbdbd2c415d76.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801607e4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
void func_80147078();
void func_801608C0();
void func_801607E4(void *p) {
    func_80147078(p, 28);
    func_801608C0(p);
}
