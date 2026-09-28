/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801ACA88 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_801ACA88(void *a0)
{
    extern void func_801292C8(u8 *a0);
    extern void func_8012931C(struct vec *a0);
    extern void func_8017E5D4(void *a0);
    extern void func_8017E1E8(void *a0, void *a1, void *a2);

    s16 buf[4];
    s32 v0;

    v0 = *(s32 *)((s32)a0 + 0x1C);
    if (v0 == 0) {
        if (*(void **)((s32)a0 + 0x2C) != NULL) {
            func_8017E5D4(*(void **)((s32)a0 + 0x2C));
        }
        func_801292C8((u8 *)a0);
    } else {
        *(s32 *)((s32)a0 + 0x1C) = v0 - 1;
        func_8012931C((struct vec *)a0);

        buf[0] = *(u16 *)((s32)a0 + 0x6);
        buf[1] = *(u16 *)((s32)a0 + 0xA);
        buf[2] = *(u16 *)((s32)a0 + 0xE);

        if (*(void **)((s32)a0 + 0x2C) != NULL) {
            func_8017E1E8(*(void **)((s32)a0 + 0x2C), &buf[0], NULL);
        }
    }
}
