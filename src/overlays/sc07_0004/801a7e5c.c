/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A7E5C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801292C8(u8 *a0);

void func_801A7E5C(void *a0) {
    u8 *obj = *(u8 **)((s32)a0 + 0x24);
    s32 b;
    s16 t[3];

    b = obj[0];
    t[0] = b;
    if (b != 0) {
        t[0] = b - *(u16 *)((s32)a0 + 0x12);
        if (t[0] < 0) {
            t[0] = 0;
        }
        obj[0] = (u8)t[0];
    }

    b = obj[1];
    t[1] = b;
    if (b != 0) {
        t[1] = b - *(u16 *)((s32)a0 + 0x16);
        if (t[1] < 0) {
            t[1] = 0;
        }
        obj[1] = (u8)t[1];
    }

    b = obj[2];
    t[2] = b;
    if (b != 0) {
        t[2] = b - *(u16 *)((s32)a0 + 0x1A);
        if (t[2] < 0) {
            t[2] = 0;
        }
        obj[2] = (u8)t[2];
    }

    if (t[0] | t[1] | t[2]) {
        *(u16 *)(*(s32 *)((s32)a0 + 0x20) + 0x18) += *(u16 *)((s32)a0 + 0x2C);
        *(u16 *)(*(s32 *)((s32)a0 + 0x20) + 0x1A) = *(u16 *)(*(s32 *)((s32)a0 + 0x20) + 0x18);
    } else {
        func_801292C8((u8 *)a0);
    }
}
