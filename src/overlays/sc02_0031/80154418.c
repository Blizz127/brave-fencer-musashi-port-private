/* SC02.CD FILE_031 / ov_SC02_031 retail span [80154418,8015444C).
 * Offset 0x2C2C0 at overlay base 80128158. SHA256(span)=7ed972d933de531f7d46c596a4295db5421ccb451ab54ebd5a28144c119feac5.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80154418.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_8015444C();
void func_80154418(void *p) {
    s32 a, b, c;
    a = 0; b = 0; c = 0;
    func_8015444C(p, &a, &b, &c);
}
