/* SC02.CD FILE_031 / ov_SC02_031 retail span [80168A14,80168A88).
 * Offset 0x408BC at overlay base 80128158. SHA256(span)=da306b77d68de3f37a48925feda0079f3094d2a3ab9dc7a2f056fe6d9ae414ce.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80168a14.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80168BDC();
void func_80146A6C();
void func_80168A14(s16 *p) {
    func_80168BDC(p, 8, 1, 2);
    func_80146A6C(3, p, p[3], p[5], p[7], -5, 0xC0009C00);
    p[1]++;
}
