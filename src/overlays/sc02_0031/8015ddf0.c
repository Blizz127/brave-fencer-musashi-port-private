/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015DDF0,8015DE24).
 * Offset 0x35C98 at overlay base 80128158. SHA256(span)=4ceaec41a664edb8dfe6519daf44d926cc6dbcfa5d4dc294057fb1e41864abbb.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015ddf0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
void func_80147078();
void func_8015DECC();
void func_8015DDF0(void *p) {
    func_80147078(p, 15);
    func_8015DECC(p);
}
