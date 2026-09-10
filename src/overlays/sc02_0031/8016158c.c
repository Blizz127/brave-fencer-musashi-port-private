/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016158C,801615C4).
 * Offset 0x39434 at overlay base 80128158. SHA256(span)=f103300011fd8e0ad575dc069347cd503e8a6e322f898e85ea533c19045d62e8.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016158c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
s32 func_801615C4();
void func_80161774();
void func_8016158C(void *p) {
    func_80161774(p, func_801615C4(p, 1));
}
