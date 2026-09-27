/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015AD08,8015AD3C).
 * Offset 0x32BB0 at overlay base 80128158. SHA256(span)=eb56edfcb8ad2b606138461e208d465bb2c2f8d58d3264bb39fa06fe992ba824.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015ad08.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
void func_80147078();
void func_8015AD3C();
void func_8015AD08(void *p) {
    func_80147078(p, 2);
    func_8015AD3C(p);
}
