/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012E364 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_8012E364(s32 arg0_)
{

    extern s16 D_80126CE0;
    extern s32 D_801952B0;
    extern s32 D_801952B4;
    register s32 arg0 __asm__("$6");
    register s32 prev __asm__("$5");
    register u16 flags __asm__("$2");
    s32 a;
    s32 diff;
    s32 v;
    register s32 d __asm__("$2");
    s32 spd;
    s32 e1;
    s32 e2;

    arg0 = arg0_;
    *(s16 *)(arg0 + 0x5C) = 0;
    a = D_80126CE0;
    if (a == 0) {
        D_801952B0 = 0x1000;
        D_801952B4 = 0x1000;
    }
    a = ((0x90 - a) << 12) / 0x90;
    *(s32 *)(arg0 + 0x1C) += 1;
    spd = 0x1000;

    diff = D_801952B0 - a;
    if (diff > 0) {
        D_801952B0 -= diff >> 2;
    } else if (diff < 0) {
        D_801952B0 += (-diff) / 4;
    }

    prev = D_801952B4;
    e1 = *(s32 *)(arg0 + 0x20);
    v = D_801952B0 - prev + spd;
    D_801952B4 = spd;
    flags = *(u16 *)(e1 + 0x2C);
    D_801952B0 = v;
    *(u16 *)(e1 + 0x2C) = flags | 0x10;

    e2 = *(s32 *)(arg0 + 0x20);
    d = __builtin_abs(v);
    *(s16 *)(e2 + 0x1C) = d;
    *(s16 *)(e2 + 0x18) = d;
    *(s16 *)(*(s32 *)(arg0 + 0x20) + 0x1A) = 0x1000;
}
