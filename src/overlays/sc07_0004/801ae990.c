/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801AE990 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80016714(void *a0, s32 a1);
typedef struct {
    u16 a, b, c, d;
} U16x4;
extern U16x4 D_801F8EA0[];
extern u16 D_801F8EA2;
extern u16 D_801F8EA4;

void func_801AE990(void *a0) {
    U16x4 *dst;
    s32 i;
    u8 *p;

    dst = D_801F8EA0;

    if (a0 != NULL) {
        *dst = *(U16x4 *)a0;
    } else {
        D_801F8EA4 = 0;
        D_801F8EA2 = 0;
        *(u16 *)dst = 0;
    }

    *(u16 *)((u8 *)dst + 0xC) = 0x1000;
    *(u16 *)((u8 *)dst + 0xA) = 0x1000;
    *(u16 *)((u8 *)dst + 0x8) = 0x1000;
    *(u16 *)((u8 *)dst + 0x14) = 0;
    *(u16 *)((u8 *)dst + 0x12) = 0;
    *(u16 *)((u8 *)dst + 0x10) = 0;

    p = (u8 *)dst + 0x18;
    i = 0;
    do {
        func_80016714(p, 0x24);
        i++;
        p += 0x24;
    } while (i < 0x20);
}
