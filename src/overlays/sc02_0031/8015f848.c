/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015F848,8015F89C).
 * Offset 0x376F0 at overlay base 80128158. SHA256(span)=8d0680274f980a4caf770183fa4c30beb0b905b7250cfe73d492508e0323e01d.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015f848.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

/* Decompiled by m2c from main_0012.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

void func_80146CA0(s32);                               /* static */
void func_80154150(s32, s32);                            /* static */
void func_801553A8();                                  /* static */
extern s32 D_8011F730;

void func_8015F848(s32 arg0) {
    func_801553A8();
    func_80154150(arg0, 0x1F);
    D_8011F730 |= 5;
    func_80146CA0(arg0);
}
