/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016E9EC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_800D2CA8(s32 a0, s32 a1);
extern void func_800D2D10(s32 a0, s32 a1, void *a2, s32 a3);
extern s32 func_80024054(void *a0, void *a1);
extern void func_8016EC0C(s32 a0, s32 a1);
extern void func_8012A568(void (*a0)(void));

void func_8016E9EC(u8 *p)
{

    extern u8 *D_8018069C[];
    extern u8 D_801806B4[];
    extern u16 D_801806B8[];
    register u32 zr __asm__("$0");
    int i;
    int c;
    u8 *buf;
    u8 off;
    u16 h;
    s32 r;

    i = p[0] - 1;
    off = D_801806B4[i];
    buf = D_8018069C[i];
    c = i + zr;
    r = func_800D2CA8(p[3], 0x1C);
    func_800D2D10(r, 1, buf + off, 0);
    func_80024054(buf, p + 8);
    p[3] = c;
    *(s16 *)(p + 4) = -0xD7;
    h = D_801806B8[i];
    p[2] = 0;
    *(u16 *)(p + 6) = h;
    p[1] = p[1] + 1;
    ((void (*)(u8 *, s32))func_8016EC0C)(p, 0x80);
}
