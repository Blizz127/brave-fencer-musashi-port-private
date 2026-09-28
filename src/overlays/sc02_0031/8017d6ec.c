/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017D6EC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_80147324(s32 arg0);
extern void func_80147084(s32 *a0);
extern void func_801472B4(void *a0);
extern void func_8017D2F4(int);

void func_8017D6EC(void *a0)
{
    s32 t;
    s32 *sub;

    t = *(s32 *)((s32)a0 + 0x1C);
    sub = *(s32 **)((s32)a0 + 0x34);
    *(s32 *)((s32)a0 + 0x1C) = t + 1;
    if (t < 0x20) {
        *(u16 *)((s32)a0 + 0x2A) = *(u16 *)((s32)a0 + 0x2A) - 0x10;
    } else {
        func_80147324(*(u16 *)((s32)a0 + 0x2C));
        func_80147084(sub);
        func_801472B4(sub);
        *(s32 *)((s32)a0 + 0x1C) = 0;
        *(u16 *)((s32)a0 + 0x2) = *(u16 *)((s32)a0 + 0x2) + 1;
    }
    ((void (*)(void *))func_8017D2F4)(a0);
}
