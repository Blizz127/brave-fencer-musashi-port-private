/* SC02.CD FILE_031 / ov_SC02_031 retail span [80136ECC,80136F3C).
 * Offset 0xED74 at overlay base 80128158. SHA256(span)=ecd9b3ab753856c2d40a5879f33e047b37fe75f630f4408e00e94b115d44dac9.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80136ecc.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80136ECC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern short D_800B9A02;
extern u8 D_800A6518[];
extern void func_80051DC8(void *a0, void *a1, s32 a2);

void func_80136ECC(s16 a0, s16 a1, s16 a2, s16 a3, u8 r, u8 g, u8 b) {
    struct {
        u32 tag;
        s16 x0;
        s16 y0;
        s16 x1;
        s16 y1;
        u8 r;
        u8 g;
        u8 b;
    } line;
    line.x0 = a0;
    line.tag = 0;
    line.y0 = a1;
    line.x1 = a2;
    line.y1 = a3;
    line.r = r;
    line.g = g;
    line.b = b;
    func_80051DC8(&line, &D_800A6518[(u16)D_800B9A02 * 20], 0);
}
