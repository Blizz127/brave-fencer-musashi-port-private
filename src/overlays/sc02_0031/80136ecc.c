/* SC02.CD FILE_031 / ov_SC02_031 retail span [80136ECC,80136F3C).
 * Offset 0xED74 at overlay base 80128158. SHA256(span)=ecd9b3ab753856c2d40a5879f33e047b37fe75f630f4408e00e94b115d44dac9.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80136ecc.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80051DC8();
extern u16 D_800B9A02;
extern u8 D_800A6518[];
typedef struct { s32 tag; s16 x, y, w, h; u8 r, g, b; } P;
void func_80136ECC(s16 x, s16 y, s16 w, s16 h, u8 r, u8 g, u8 b) {
    P s;
    s.tag = 0;
    s.x = x;
    s.y = y;
    s.w = w;
    s.h = h;
    s.r = r;
    s.g = g;
    s.b = b;
    func_80051DC8(&s, D_800A6518 + D_800B9A02 * 20, 0);
}
