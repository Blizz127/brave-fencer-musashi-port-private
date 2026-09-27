/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015DC84,8015DCB8).
 * Offset 0x35B2C at overlay base 80128158. SHA256(span)=5c5cfdbd07773f8c12d5511ce20cb0d78ad1e9081e37408a35eec025c86f5e48.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015dc84.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
void func_80154A74();
void func_8015DD74();
void func_8015DC84(void *p) {
    func_80154A74(p, 17);
    func_8015DD74(p);
}
