/* SC02.CD FILE_031 / ov_SC02_031 retail span [80170DA4,80170DE0).
 * Offset 0x48C4C at overlay base 80128158. SHA256(span)=6c95fced5547a2c738e6950fe5e8f9f5dcff72b88a898ef24fc9d249e0606a15.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80170da4.c (recovery=c, -O2); the span is
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
void func_80170DE0();
void func_80170DA4(void *p) {
    func_801719A4(p, 3);
    func_80171990(p);
    func_80170DE0(p);
}
