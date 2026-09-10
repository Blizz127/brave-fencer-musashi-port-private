/* SC02.CD FILE_031 / ov_SC02_031 retail span [8017018C,801701C8).
 * Offset 0x48034 at overlay base 80128158. SHA256(span)=ad40040dbc3dff8ee0cacf04c5c958afaab0fe0c9800beb27618205d3970016f.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8017018c.c (recovery=c, -O2); the span is
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
void func_801701C8();
void func_8017018C(void *p) {
    func_801719A4(p, 1);
    func_80171990(p);
    func_801701C8(p);
}
