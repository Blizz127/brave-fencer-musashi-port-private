/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A623C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_800233CC(void *a0, u16 a1);
extern s32 func_8001CA88(s32 a0, void *a1);
extern s32 D_801F44C4;
extern s32 D_801F44C8;
extern s32 D_801F44CC;
extern s32 D_801F44D0;

void func_801A623C(void *a0) {
    s32 v0;

    v0 = func_8012C1B8();
    *(s32 *)((s32)a0 + 0x20) = v0;
    if (v0 == 0) {
        func_8012CAE4(a0);
        return;
    }

    {
        void *s0 = &D_801F44C4;
        *(s32 *)s0 = 0x808080;
        D_801F44C8 = 0;
        D_801F44CC = 0;
        D_801F44D0 = 0;
        func_800233CC(s0, 0x60);
        func_8001CA88(*(s32 *)((s32)a0 + 0x20), s0);
    }

    *(u16 *)(*(s32 *)((s32)a0 + 0x20) + 0x2C) |= 0x10;
    *(u16 *)(*(s32 *)((s32)a0 + 0x20) + 0x18) =
        *(u16 *)(*(s32 *)((s32)a0 + 0x20) + 0x1A) =
            *(u16 *)(*(s32 *)((s32)a0 + 0x20) + 0x1C) = 1;
    *(u16 *)(*(s32 *)((s32)a0 + 0x20) + 0x1E) = 0xAAA;
    *(u16 *)(*(s32 *)((s32)a0 + 0x20) + 0x2E) = 0xC010;

    *(s32 *)(*(s32 *)((s32)a0 + 0x20) + 0x4) |= 0x50000000;

    *(u16 *)((s32)a0 + 0x2) += 1;
}
