/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016F4C4,8016F4F4).
 * Offset 0x4736C at overlay base 80128158. SHA256(span)=eb9adc8f8be204dd3f444f027bb592ae12dfcc7cb36c38a0a4206b0a096a4847.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016f4c4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

/* Decompiled by m2c from main_0012.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

void func_80165770(s32);                               /* static */
void func_8016F0E4();                                  /* static */

void func_8016F4C4(s32 arg0) {
    func_8016F0E4();
    func_80165770(arg0);
}
