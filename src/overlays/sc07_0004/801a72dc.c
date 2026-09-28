/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A72DC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_801F8744[];

void func_801A72DC(void *a0)
{
    extern void func_801292C8(u8 *a0);
    extern void func_8012931C(struct vec *a0);

    s32 v0;

    v0 = *(u16 *)((s32)a0 + 0x2C) + 1;
    *(u16 *)((s32)a0 + 0x2C) = v0;
    if ((s16)v0 >= 4) {
        func_801292C8((u8 *)a0);
        return;
    }
    func_8012931C((struct vec *)a0);
    *(s32 *)(*(s32 *)((s32)a0 + 0x20) + 0x20) =
        (s32)D_801F8744 + (*(s16 *)((s32)a0 + 0x2C) << 6);
}
