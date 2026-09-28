/* SC02.CD member31 [8014D790,8014D820); exact word export. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014D790 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_8014DD8C(s32 a0, void *a1, void *a2);
extern s32 func_8014D820(s32 a0, u16 *a1, u16 *a2);

void func_8014D790(s32 a0) {
    s16 l1[3];
    s16 l2[3];
    l1[0] = *(u16 *)(a0 + 0x88);
    l1[1] = *(u16 *)(a0 + 0x8A) - 0x10;
    l1[2] = *(u16 *)(a0 + 0x8C);
    l2[0] = *(u16 *)(a0 + 0x6);
    l2[1] = *(u16 *)(a0 + 0xA) - 0x10;
    l2[2] = *(u16 *)(a0 + 0xE);
    if (*(s32 *)(a0 + 0x170) == 0) {
        func_8014DD8C(a0, l1, l2);
    } else {
        func_8014D820(a0, l1, l2);
    }
}
