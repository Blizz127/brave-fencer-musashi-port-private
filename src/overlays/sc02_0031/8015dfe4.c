/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015DFE4,8015E018).
 * Offset 0x35E8C at overlay base 80128158. SHA256(span)=1f76bc0c158cb9c9e2811ceba319c8ff8620efebe6ae58a4bd7abbf77dab85fe.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015dfe4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
void func_80154A74();
void func_8015E0D4();
void func_8015DFE4(void *p) {
    func_80154A74(p, 17);
    func_8015E0D4(p);
}
