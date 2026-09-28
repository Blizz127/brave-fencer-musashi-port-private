/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A7C58 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_801F88C8[];
extern u8 D_801F88CA[];
extern u8 D_801F8A38[];
extern u8 D_801F8A3A[];

void func_801A7C58(s32 a0) {
    s32 i;
    s32 j;
    s32 v;
    s32 temp;

    i = 0;
    j = 0;
    do {
        v = *(u16 *)(D_801F88C8 + i);
        *(u16 *)(D_801F8A38 + j) = v;
        v = *(u16 *)(D_801F88CA + i);
        i += 8;
        *(u16 *)(D_801F8A3A + j) = v;
        j += 4;
    } while (i < 0x30);

    temp = *(s32 *)(a0 + 0x20);
    *(s32 *)(a0 + 0x1C) = 6;
    *(u16 *)(temp + 0x1A) = 0x400;
    *(u16 *)(temp + 0x18) = 0x400;
    *(u16 *)(a0 + 2) = 3;
    *(u16 *)(a0 + 0x2C) = 0;
}
