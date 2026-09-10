/* SC02.CD FILE_031 / ov_SC02_031 retail span [80170B48,80170B90).
 * Offset 0x489F0 at overlay base 80128158. SHA256(span)=2e3e6913015c2277aa2c3a68eb40f79c820b57929a0c9600a3c4ac1637549e10.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80170b48.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

/* Decompiled by m2c from main_0012.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

void func_8014706C();                                  /* static */
void func_80154274(s32, s32);                          /* static */
void func_80170B90(s32);                               /* static */
void func_80171990(s32);                               /* static */
extern s32 D_8011F738;

void func_80170B48(s32 arg0) {
    func_8014706C();
    func_80154274(arg0, D_8011F738);
    func_80171990(arg0);
    func_80170B90(arg0);
}
