/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80171B4C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80146D90(s32);
extern s32 func_8004CFEC(s32, s32);
extern s32 D_801151D4;

s32 func_80171B4C(arg0, arg1)
s32 arg0;
u8 arg1;
{
    s32 p, ang, idx;
    u8 c;
    p = D_801151D4;
    *(u8 *)(arg0 + 0xA9) = 0x41;
    ang = func_8004CFEC(*(s32 *)(p + 0x68) - *(s32 *)(p + 0x5C),
                 *(s32 *)(p + 0x70) - *(s32 *)(p + 0x64));
    idx = ((*(s16 *)(*(s32 *)(arg0 + 0x20) + 0x12) - ((ang + 0x800) & 0xFFF)) + 0x100) & 0xE00;
    switch (idx / 0x200) {
    case 0: *(u16 *)(arg0 + 0xAA) = 0x1000; break;
    case 1: *(u16 *)(arg0 + 0xAA) = 0x3000; break;
    case 2: *(u16 *)(arg0 + 0xAA) = 0x2000; break;
    case 3: *(u16 *)(arg0 + 0xAA) = 0x6000; break;
    case 4: *(u16 *)(arg0 + 0xAA) = 0x4000; break;
    case 5: *(u16 *)(arg0 + 0xAA) = 0xC000; break;
    case 6: *(u16 *)(arg0 + 0xAA) = 0x8000; break;
    case 7: *(u16 *)(arg0 + 0xAA) = 0x9000; break;
    }
    c = *(u8 *)(arg0 + 0x20C);
    *(u8 *)(arg0 + 0x20C) = c + 1;
    if (c != arg1) {
        return 0;
    }
    func_80146D90(arg0);
    return 1;
}
