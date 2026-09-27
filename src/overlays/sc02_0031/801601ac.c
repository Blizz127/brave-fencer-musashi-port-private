/* SC02.CD FILE_031 / ov_SC02_031 retail span [801601AC,801601E4).
 * Offset 0x38054 at overlay base 80128158. SHA256(span)=c01cdd4b11d44921a5f74be65884bbd0dc59ca74764d32617dc3404d95f9f6c3.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801601ac.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
void func_80154150();
void func_80146C98();
void func_801601AC(void *p) {
    func_80154150(p, 33);
    func_80146C98(p, 1);
}
