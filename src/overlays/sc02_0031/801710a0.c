/* SC02.CD FILE_031 / ov_SC02_031 retail span [801710A0,801710DC).
 * Offset 0x48F48 at overlay base 80128158. SHA256(span)=051bab46c3fd23269e7c7dd6d9e2ef8425a422c39d81835aed1b9a0ab828f1e3.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801710a0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
void func_801719A4();
void func_80171990();
void func_801710DC();
void func_801710A0(void *p) {
    func_801719A4(p, 1);
    func_80171990(p);
    func_801710DC(p);
}
