/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016C83C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80047E98(void *a0, void *a1);
extern void func_800D22E4(s32 a0);
extern short func_8016CF04();
extern void func_8012A568(void (*a0)(void));

void func_8016C83C(s32 a0) {
    s16 d[20];
    s32 a1 = *(s32 *)(a0 + 0x34);
    s32 v0 = *(s32 *)(a0 + 0x1C) - 1;
    s32 dist;
    *(s32 *)(a0 + 0x1C) = v0;
    if (v0 == 0) {
        *(s16 *)(a0 + 2) = 4;
        func_8016CF04(a0, 2);
        return;
    }
    d[0] = *(u16 *)(a1 + 6) - *(u16 *)(a0 + 6);
    d[1] = *(u16 *)(a1 + 0xA) - *(u16 *)(a0 + 0xA);
    d[2] = *(u16 *)(a1 + 0xE) - *(u16 *)(a0 + 0xE);
    dist = func_80047E98(d, d);
    if (dist < 0x790) {
        *(s16 *)(a0 + 2) = 4;
        func_8016CF04(a0, 2);
        return;
    }
    *(s32 *)(a0 + 0x10) = *(s32 *)(a0 + 0x10) + d[0] * 0x40;
    *(s32 *)(a0 + 0x14) = *(s32 *)(a0 + 0x14) + d[1] * 0x40;
    *(s32 *)(a0 + 0x18) = *(s32 *)(a0 + 0x18) + d[2] * 0x40;
    d[0] = *(u16 *)(a0 + 0x12);
    d[1] = *(u16 *)(a0 + 0x16);
    d[2] = *(u16 *)(a0 + 0x1A);
    dist = func_80047E98(d, d);
    {
        s32 lim = 0x1000;
        if (lim < dist) {
            *(s32 *)(a0 + 0x10) = (s32)d[0] << 10;
            *(s32 *)(a0 + 0x14) = (s32)d[1] << 10;
            *(s32 *)(a0 + 0x18) = (s32)d[2] << 10;
        }
    }
    func_800D22E4(a0);
    func_8016CF04(a0, 1);
}
