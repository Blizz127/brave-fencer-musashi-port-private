/* SC02.CD FILE_031 / ov_SC02_031 retail span [80160368,8016039C).
 * Offset 0x38210 at overlay base 80128158. SHA256(span)=b08d3dbb2886cf0dfe8b16c89cd3018cae12a074bc49297ddac0b370747ceb75.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80160368.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
void func_80147078();
void func_8016039C();
void func_80160368(void *p) {
    func_80147078(p, 27);
    func_8016039C(p);
}
