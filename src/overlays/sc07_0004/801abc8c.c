/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801ABC8C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_801ABC8C(void *a0)
{
    extern void func_801292C8(u8 *a0);
    extern void func_8012931C(struct vec *a0);
    extern void func_801A8B64(s32 a0, s32 a1);

    u16 local[3];

    if (*(s32 *)((s32)a0 + 0x1C) != 0) {
        (*(s32 *)((s32)a0 + 0x1C))--;
        local[0] = *(u16 *)((s32)a0 + 0x6);
        local[1] = *(u16 *)((s32)a0 + 0xA);
        local[2] = *(u16 *)((s32)a0 + 0xE);

        if (*(s16 *)((s32)a0 + 0x2C) == 0) {
            func_8012931C((struct vec *)a0);
        } else {
            void *s1 = *(void **)((s32)a0 + 0x34);

            *(u16 *)((s32)a0 + 0x6) = *(u16 *)((s32)a0 + 0x2E);
            *(u16 *)((s32)a0 + 0xA) = *(u16 *)((s32)a0 + 0x30);
            *(u16 *)((s32)a0 + 0xE) = *(u16 *)((s32)a0 + 0x32);
            func_8012931C((struct vec *)a0);

            *(u16 *)((s32)a0 + 0x2E) = *(u16 *)((s32)a0 + 0x6);
            *(u16 *)((s32)a0 + 0x30) = *(u16 *)((s32)a0 + 0xA);
            *(u16 *)((s32)a0 + 0x32) = *(u16 *)((s32)a0 + 0xE);

            if (s1 != 0) {
                *(u16 *)((s32)a0 + 0x6) = *(u16 *)((s32)a0 + 0x6) + *(u16 *)((s32)s1 + 0x6);
                *(u16 *)((s32)a0 + 0xA) = *(u16 *)((s32)a0 + 0xA) + *(u16 *)((s32)s1 + 0xA);
                *(u16 *)((s32)a0 + 0xE) = *(u16 *)((s32)a0 + 0xE) + *(u16 *)((s32)s1 + 0xE);
            }
        }

        func_801A8B64((s32)a0, (s32)local);
    } else {
        func_801292C8((u8 *)a0);
    }
}
