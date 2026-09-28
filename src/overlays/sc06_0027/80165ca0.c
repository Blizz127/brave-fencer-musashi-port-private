/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80165CA0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

#define ENGINE_SHB(x) __asm__ __volatile__("" : "=r"(x) : "0"(x))

void func_80165CA0(void) {
    extern s32 D_8011D030;
    extern s32 D_80126728;
    register s32 i __asm__("$17");
    s32 off;
    u16 *q;
    s32 a1, base;
    short *p;
    register short v __asm__("$2");
    register short w __asm__("$3");
    i = 0; q = &D_8011D030;
    do {
        if (*q != 0) (*(void (**)(u16 *))((u32)*q * 4 + D_80126728))(q);
        i = i + 1; q = q + 0x2c;
    } while (i < 0x1e);
    i = 0; off = 0;
    do {
        base = (s32)&D_8011D030; ENGINE_SHB(base);
        a1 = off + base;
        p = *(short **)(a1 + 0x20);
        if (p != 0) {
            s32 q2;
            if ((u16)*p == 1) {
                v = *(short *)(a1 + 6); p[4] = v; ENGINE_SHB(v); *(int *)(p + 0x24) = v;
                v = *(short *)(a1 + 0xa); p[5] = v; ENGINE_SHB(v); *(int *)(p + 0x26) = v;
                w = *(short *)(a1 + 0xe); p[6] = w; v = p[0x16] | 1; ENGINE_SHB(w); p[0x16] = v; *(int *)(p + 0x28) = w;
            } else if ((q2 = *(int *)(p + 0x1a)) != 0) {
                v = *(short *)(a1 + 6); p[4] = v; ENGINE_SHB(v); *(int *)(q2 + 0x14) = v;
                v = *(short *)(a1 + 0xa); p[5] = v; q2 = *(int *)(p + 0x1a); ENGINE_SHB(v); *(int *)(q2 + 0x18) = v;
                v = *(short *)(a1 + 0xe); p[6] = v; q2 = *(int *)(p + 0x1a); ENGINE_SHB(v); *(int *)(q2 + 0x1c) = v;
            } else {
                p[4] = *(short *)(a1 + 6); p[5] = *(short *)(a1 + 0xa); p[6] = *(short *)(a1 + 0xe);
            }
        }
        i = i + 1; off = off + 0x58;
    } while (i < 0x1e);
}
