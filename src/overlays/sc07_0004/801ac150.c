/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801AC150 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_8001CC3C(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_80128EA8(s32 a0, s32 a1, s32 a2);
extern s32 D_801B05F0[];
extern u8 D_801B04A4[];

void func_801AC150(void *a0) {
    s32 s0;
    s32 v1;
    u16 v2;

    s0 = D_801B05F0[*(s16 *)((s32)a0 + 0x2C)];
    func_8001CC3C(*(s32 *)((s32)a0 + 0x20), (s32)D_801B04A4, *(s16 *)s0, *(s16 *)(s0 + 2));
    v1 = *(s32 *)((s32)a0 + 0x20);
    *(s8 *)(v1 + 0x27) = 0x5A;
    *(s16 *)(*(s32 *)((s32)a0 + 0x20) + 0x18) = 0x3000;
    *(s16 *)(*(s32 *)((s32)a0 + 0x20) + 0x1A) = 0x3000;
    v2 = 0xC018;
    *(s16 *)(*(s32 *)((s32)a0 + 0x20) + 0x2C) = v2;
    *(s32 *)(*(s32 *)((s32)a0 + 0x20) + 0x4) |= 0x50000000;
    func_80128EA8(*(s32 *)((s32)a0 + 0x20), (s32)a0 + 0x24, s0);
    if (*(s16 *)((s32)a0 + 0x2C) == 2) {
        *(s32 *)((s32)a0 + 0x14) = -0x80000;
        *(s16 *)(*(s32 *)((s32)a0 + 0x20) + 0x18) = 0x5000;
    }
    (*(u16 *)((s32)a0 + 0x2))++;
}
