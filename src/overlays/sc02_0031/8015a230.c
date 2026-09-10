/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015A230,8015A264).
 * Offset 0x320D8 at overlay base 80128158. SHA256(span)=2f12ef24419cdef40c1c0f8804a076be450d6d2b520feefd2dd7090c39023423.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015a230.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
void func_80147078();
void func_8015A264();
void func_8015A230(void *p) {
    func_80147078(p, 1);
    func_8015A264(p);
}
