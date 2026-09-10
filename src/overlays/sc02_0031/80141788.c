/* SC02.CD FILE_031 / ov_SC02_031 retail span [80141788,801417C4).
 * Offset 0x19630 at overlay base 80128158. SHA256(span)=c5ea6e45fe4f0f9c2b7994af05db43c5223934378fe9f9a8c11fc94803a93156.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_8017F774 here is D_8017FFFC (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
typedef void (*CB)();
extern CB D_8017FFFC[];
extern u16 D_80115112;
void func_80141788(void) {
    D_8017FFFC[D_80115112]();
}
