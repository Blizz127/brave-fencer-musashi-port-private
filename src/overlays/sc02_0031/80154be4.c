/* SC02.CD FILE_031 / ov_SC02_031 retail span [80154BE4,80154C24).
 * Offset 0x2CA8C at overlay base 80128158. SHA256(span)=6deb4de22d1c283d97a605654b83ddd5e528867534d3c6c764e1afb8be327d1b.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80154be4.c (m2c-derived, oracle MATCH); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80154C24();
void func_80154F9C();
void func_80154BE4(void *p) {
    s32 a;
    s32 b;
    a = 0;
    b = 0;
    func_80154C24(p, &a, &b);
    func_80154F9C(p);
}
