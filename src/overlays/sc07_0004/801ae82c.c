/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801AE82C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801ADA10();

void func_801AE82C(s32 a0) {
    register u32 zr __asm__("$0");
    s32 cnt;
    s32 v1;
    s32 t;
    s32 w;
    s32 frame_pad[1];

    (void)&frame_pad;

    cnt = *(s32 *)((s32)a0 + 0x1C);
    v1 = *(s32 *)((s32)a0 + 0x34);
    if (cnt != 0) {
        *(s32 *)((s32)a0 + 0x1C) = cnt - 1;
    } else {
        t = *(s16 *)(v1 + 0xC);
        w = t + zr;
        if (t < 0x1000) {
            t = w + 0x400;
            *(s16 *)(v1 + 0xC) = t;
            *(s16 *)(v1 + 0x10) = t;
        } else {
            *(u16 *)((s32)a0 + 2) += 1;
            *(s32 *)((s32)a0 + 0x1C) = 0x48;
        }
    }
    if (*(s32 *)((s32)a0 + 0x1C) & 1) {
        func_801ADA10(a0);
    }
}
