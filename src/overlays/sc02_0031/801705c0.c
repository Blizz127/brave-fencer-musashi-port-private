/* SC02.CD FILE_031 / ov_SC02_031 retail span [801705C0,801705F8).
 * Offset 0x48468 at overlay base 80128158. SHA256(span)=bd0b0c2514b7bcbd7116753de98446c34e5829f0c0351c606456a64be94cd35d.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801705c0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

/* Decompiled by m2c from main_0012.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

void func_80171928(s32);                               /* static */
extern s32 (*D_8011F738)();

void func_801705C0(s32 arg0) {
    D_8011F738();
    func_80171928(arg0);
}
