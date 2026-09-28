/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801ACC24 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_801ACC24(void *a0)
{
    extern void func_801292C8(u8 *a0);
    extern void func_8012931C(struct vec *a0);
    extern void func_8017E5D4(void *a0);
    extern void func_8017E1E8(void *a0, void *a1, void *a2);

    s16 buf[8];
    s32 t0, t1, t2;
    s32 v0;

    v0 = *(s32 *)((s32)a0 + 0x1C);
    if (v0 == 0) {
        if (*(void **)((s32)a0 + 0x2C) != NULL) {
            func_8017E5D4(*(void **)((s32)a0 + 0x2C));
        }
        func_801292C8((u8 *)a0);
        return;
    }

    *(s32 *)((s32)a0 + 0x1C) = v0 - 1;
    func_8012931C((struct vec *)a0);

    buf[0] = t0 = *(u16 *)((s32)a0 + 0x6);
    buf[1] = t1 = *(u16 *)((s32)a0 + 0xA);
    buf[2] = t2 = *(u16 *)((s32)a0 + 0xE);

    t0 += *(u16 *)(*(s32 *)((s32)a0 + 0x20) + 0x2E);
    buf[4] = t0;
    t1 += *(u16 *)(*(s32 *)((s32)a0 + 0x20) + 0x30);
    buf[5] = t1;
    t2 += *(u16 *)(*(s32 *)((s32)a0 + 0x20) + 0x32);
    buf[6] = t2;

    if (*(void **)((s32)a0 + 0x2C) != NULL) {
        func_8017E1E8(*(void **)((s32)a0 + 0x2C), &buf[0], &buf[4]);
    }
}
