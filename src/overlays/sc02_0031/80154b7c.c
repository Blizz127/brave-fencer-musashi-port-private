/* SC02.CD FILE_031 / ov_SC02_031 retail span [80154B7C,80154B98).
 * Offset 0x2CA24 at overlay base 80128158. SHA256(span)=7c0cdca4e596298d81aa03877248591f8a5b20e172328db022eae61702ce3c05.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80154b7c.c (m2c-derived, oracle MATCH); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
typedef struct { u8 pad[0xD0]; s32 d0; s16 d4, d6; u8 d8, d9; } T;
void func_80154B7C(T *p, s32 a1) {
    p->d0 = a1;
    p->d6 = 1;
    p->d4 = 1;
    p->d8 = 0;
    p->d9 = 0;
}
