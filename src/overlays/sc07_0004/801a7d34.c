/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A7D34 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { char c[4]; } Blk4_801A7358;
extern void func_800233CC(void *a0, unsigned short a1);
extern void func_8001CD9C(s32, s32);
extern Blk4_801A7358 D_801A01E8;

void func_801A7D34(s32 a0) {
    s32 s1;
    s32 v1;
    s32 t;

    s1 = *(s32 *)(a0 + 0x24);
    func_800233CC((void *)s1, 0x80);
    *(Blk4_801A7358 *)(s1 + 0x0) = *(Blk4_801A7358 *)(a0 + 0x30);
    *(Blk4_801A7358 *)(s1 + 0x4) = D_801A01E8;
    func_8001CD9C(*(s32 *)(a0 + 0x20), s1);

    v1 = *(s32 *)(a0 + 0x20);
    *(s16 *)(v1 + 0x1E) = 0xC00;

    v1 = *(s32 *)(a0 + 0x20);
    *(u16 *)(v1 + 0x2C) = 0xC040;

    if (*(s32 *)(a0 + 0x30) & 0x2000000) {
        v1 = *(s32 *)(a0 + 0x20);
        *(s32 *)(v1 + 0x4) = 0x60000000;
    } else {
        v1 = *(s32 *)(a0 + 0x20);
        *(s32 *)(v1 + 0x4) = 0x50000000;
    }

    v1 = *(s32 *)(a0 + 0x20);
    *(s16 *)(v1 + 0x1A) = 0x100;
    *(s16 *)(v1 + 0x18) = 0x100;

    t = *(u8 *)(s1 + 0x0) >> 4;
    *(s16 *)(a0 + 0x12) = t;
    if (t == 0) {
        *(s16 *)(a0 + 0x12) = 1;
    }

    t = *(u8 *)(s1 + 0x1) >> 4;
    *(s16 *)(a0 + 0x16) = t;
    if (t == 0) {
        *(s16 *)(a0 + 0x16) = 1;
    }

    t = *(u8 *)(s1 + 0x2) >> 4;
    *(s16 *)(a0 + 0x1A) = t;
    if (t == 0) {
        *(s16 *)(a0 + 0x1A) = 1;
    }

    *(s16 *)(a0 + 0x2) = 7;
}
