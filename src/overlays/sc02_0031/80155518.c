/* SC02.CD FILE_031 / ov_SC02_031 retail span [80155518,8015554C).
 * Offset 0x2D3C0 at overlay base 80128158. SHA256(span)=16cc54d2c1e856887ed9ff0edffe37d01263fdb7226440458d9288b622718cf7.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80155518.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
void func_80147078();
void func_801555F4();
void func_80155518(void *p) {
    func_80147078(p, 5);
    func_801555F4(p);
}
