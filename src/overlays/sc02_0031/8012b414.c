/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012B414,8012B4B8).
 * Offset 0x32BC at overlay base 80128158. SHA256(span)=3c67b445edbf3f9b2d9eecd48af2834effab029067e3257d782b81f4c17234ea.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012b414.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012B414 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_8004978C(s16 *a0, void *a1);

void func_8012B414(int a0) {
    int q;
    int p;
    q = *(int *)(a0 + 0x20);
    if (q != 0) {
        func_8004978C((s16 *)(q + 0x10), (void *)(q + 0x34));
        p = *(int *)(a0 + 0x20);
        *(s16 *)(p + 0x8) = *(u16 *)(a0 + 0x6) + *(u16 *)(a0 + 0x50);
        *(s32 *)(p + 0x48) = *(s16 *)(p + 0x8);
        *(s16 *)(p + 0xA) = *(u16 *)(a0 + 0xA) + *(u16 *)(a0 + 0x52);
        *(s32 *)(p + 0x4C) = *(s16 *)(p + 0xA);
        {
            u16 e = *(u16 *)(a0 + 0xE);
            u16 t2c = *(u16 *)(p + 0x2C) | 0x1;
            s16 sum = e + *(u16 *)(a0 + 0x54);
            *(s16 *)(p + 0xC) = sum;
            *(u16 *)(p + 0x2C) = t2c;
            *(s32 *)(p + 0x50) = sum;
        }
    }
}
