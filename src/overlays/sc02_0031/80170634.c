/* SC02.CD FILE_031 / ov_SC02_031 retail span [80170634,80170670).
 * Offset 0x484DC at overlay base 80128158. SHA256(span)=3d962d7ac7566c48b2d748794eaccd222e286559ea359413a95adad648ece80c.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80170634.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

#include "psx_types.h"
void func_801719A4();
void func_80171990();
void func_80170670();
void func_80170634(void *p) {
    func_801719A4(p, 1);
    func_80171990(p);
    func_80170670(p);
}
