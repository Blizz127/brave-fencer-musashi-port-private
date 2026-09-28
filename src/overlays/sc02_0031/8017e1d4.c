/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017E1D4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern s16 D_80126B0C;
extern void func_80146E90(s32 *a0, s32 a1);
extern void func_80146CA0(void *a0);

void func_8017E1D4(s32 p) {
    s32 o;
    s32 lim1, lim2;
    s16 t1, t2, lv1, lv2;
    s32 pad[3];

    (void)&pad;
    o = *(s32 *)(p + 0x20);
    t1 = *(u16 *)(o + 0x1C) + 0x800;
    *(s16 *)(o + 0x1C) = t1;
    *(s16 *)(o + 0x18) = t1;
    lim1 = **(s16 **)(p + 0x58);
    lv1 = lim1;
    __asm__("" : "=r"(lv1) : "0"(lv1));
    if (lim1 < t1) {
        *(s16 *)(o + 0x1C) = lv1;
        *(s16 *)(o + 0x18) = lv1;
        D_80126B0C = 1;
    }
    t2 = *(u16 *)(o + 0x1A) + 0x800;
    *(s16 *)(o + 0x1A) = t2;
    lim2 = *(s16 *)(*(s32 *)(p + 0x58) + 2);
    lv2 = lim2;
    if (lim2 < t2) {
        *(s16 *)(o + 0x1A) = lv2;
        func_80146E90((s32 *)p, *(s16 *)(*(s32 *)(p + 0x58) + 4));
        func_80146CA0((void *)p);
    }
}
