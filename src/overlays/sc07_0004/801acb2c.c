/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801ACB2C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_801ACB2C(void *a0)
{
    extern void func_801AA7E4(u8 *a0);
    extern s32 func_8017D858(void *a0, void *a1, void *a2, s8 a3);

    s16 buf[8];
    s32 t0, t1, t2;
    s32 v0;
    s16 param3;

    func_801AA7E4((u8 *)a0);

    buf[0] = t0 = *(u16 *)((s32)a0 + 0x6);
    buf[1] = t1 = *(u16 *)((s32)a0 + 0xA);
    buf[2] = t2 = *(u16 *)((s32)a0 + 0xE);

    t0 += *(u16 *)(*(s32 *)((s32)a0 + 0x20) + 0x2E);
    buf[4] = t0;
    t1 += *(u16 *)(*(s32 *)((s32)a0 + 0x20) + 0x30);
    buf[5] = t1;
    t2 += *(u16 *)(*(s32 *)((s32)a0 + 0x20) + 0x32);
    buf[6] = t2;

    param3 = *(s16 *)((s32)a0 + 0x30);
    if (*(s16 *)((s32)a0 + 0x30) == 0)
        param3 = 6;

    if (*(s16 *)((s32)a0 + 0x32) == 0) {
        buf[3] = 0;
        *(s32 *)((s32)a0 + 0x1C) = 0x10;
    } else {
        buf[3] = -0x3F00;
        *(s32 *)((s32)a0 + 0x1C) = 0x18;
    }

    v0 = func_8017D858(&buf[0], &buf[4], (void *)((s32)a0 + 0x34), (s8)param3);
    *(s32 *)((s32)a0 + 0x2C) = v0;

    *(u16 *)((s32)a0 + 0x2) += 1;
}
