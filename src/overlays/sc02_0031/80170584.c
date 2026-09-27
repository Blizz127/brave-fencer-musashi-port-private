/* SC02.CD FILE_031 / ov_SC02_031 retail span [80170584,801705C0).
 * Offset 0x4842C at overlay base 80128158. SHA256(span)=9105a856827d44d3e577e568f0c882875952db1e7ab32cdb359c8448e5d5aa71.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80170584.c (recovery=c, -O2); the span is
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
void func_801705C0();
void func_80170584(void *p) {
    func_801719A4(p, 1);
    func_80171990(p);
    func_801705C0(p);
}
