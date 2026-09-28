/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801AE060 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32  func_8004787C(s32 a0);
extern void func_801ACD4C(void);
extern s32 D_800B9AA8;
extern s16 D_800B9AA4;
extern s16 D_800B9AA6;
extern s16 D_800B9AB8;
extern s16 D_800B9ABA;

void func_801AE060(s32 a0) {
    s32 s0 = a0;
    s32 t;
    s32 *p = &D_800B9AA8;

    *p = *p - 0x300;

    t = *(u16 *)(s0 + 0xFE);
    t += 0x18;
    *(u16 *)(s0 + 0xFE) = t;
    D_800B9AA4 = func_8004787C((s16)t) + 0x2700;
    D_800B9AA6 = func_8004787C(*(s16 *)(s0 + 0xFE) + 0x400) + 0x2700;

    D_800B9AB8 -= 1;
    D_800B9ABA += 1;

    switch (*(u16 *)(s0 + 0x34)) {
    case 0:
        *(u16 *)(s0 + 0x34) = *(u16 *)(s0 + 0x34) + 1;
        break;
    case 1:
        func_801ACD4C();
        break;
    }
}
