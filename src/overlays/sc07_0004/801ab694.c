/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801AB694 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_801F88C8[];
extern u8 D_801F8A38[];
extern u8 D_801F8A3A[];
extern void func_80016450(s32 a0, s32 a1);

void func_801AB694(void *arg0) {
    register void *s0 __asm__("$16");
    register u8 *a1 __asm__("$5");
    register s32 a2 __asm__("$6");

    s0 = arg0;
    {
        register s32 a0 __asm__("$4");
        a2 = 0;
        a1 = D_801F88C8;
        do {
            a0 = (a2 >> 1) << 2;
            *(u16 *)(a1 + 0) -= *(u16 *)(D_801F8A38 + a0);
            *(u16 *)(a1 + 2) -= *(u16 *)(D_801F8A3A + a0);
            a2 += 2;
            a1 += 8;
        } while (a2 < 0xC);
    }

    {
        register s32 a0 __asm__("$4");
        a0 = *(u16 *)((u8 *)s0 + 0x2C);
        a0 -= 0x10;
        *(u16 *)((u8 *)s0 + 0x2C) = a0;
        func_80016450(a0 & 0xFF, 1);
    }

    {
        register s32 v0 __asm__("$2");
        v0 = *(s32 *)((u8 *)s0 + 0x1C);
        v0 -= 1;
        *(s32 *)((u8 *)s0 + 0x1C) = v0;
        if (v0 == 0) {
            *(u16 *)((u8 *)s0 + 2) = 1;
            *(u16 *)((u8 *)s0 + 0x2A) = 0;
        }
    }
}
