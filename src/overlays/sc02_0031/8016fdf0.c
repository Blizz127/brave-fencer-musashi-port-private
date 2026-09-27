/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016FDF0,8016FE2C).
 * Offset 0x47C98 at overlay base 80128158. SHA256(span)=cc0e89798f6ccf0e481b034df63f595ea52a64429869d4aea42f73d9da2cc6b2.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016fdf0.c (recovery=c, -O2); the span is
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
void func_8016FE2C();
void func_8016FDF0(void *p) {
    func_801719A4(p, 2);
    func_80171990(p);
    func_8016FE2C(p);
}
