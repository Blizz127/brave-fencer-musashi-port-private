/* SC02.CD FILE_031 / ov_SC02_031 retail span [801711FC,80171238).
 * Offset 0x490A4 at overlay base 80128158. SHA256(span)=de161537d7acd068f0d803af15f96f253e5938a8763407af6db376fd03599d5f.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801711fc.c (recovery=c, -O2); the span is
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
void func_80171238();
void func_801711FC(void *p) {
    func_801719A4(p, 1);
    func_80171990(p);
    func_80171238(p);
}
