/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801E7FD8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_801E7FD8(void) {
    extern s32 D_801F2470;
    extern u8 D_801F2480[];
    extern s16 D_801F2188;
    extern s16 D_801F2184;
    extern s16 D_801F2190;
    extern s16 D_80115118;
    extern s32 D_801EB918;
    extern s16 D_8011512C;
    extern void *D_801EB9B0;
    extern s16 D_80115126;
    extern s32 D_80115130[];
    extern s32 D_80115134;
    extern u8 D_80115138[];
    extern s32 D_801EBA5C[];
    s16 i;
    s32 *p32;
    u16 *out;

    D_801F2470 = 0;
    for (i = 0; i < 8; i++) {
        D_801F2480[i] = 0xFF;
    }
    D_801F2184 = 0;
    D_801F2190 = 0;
    D_80115118 = 0;
    if (D_801F2188 == 0) {
        D_8011512C = 0;
        D_801EB9B0 = (void *)D_801EB918;
    } else {
        D_8011512C = 9;
        D_801EB9B0 = (void *)0x1A;
    }
    i = 0;
    p32 = D_80115130;
    *p32 = 0;
    D_80115134 = D_801EBA5C[D_80115126];
    out = (u16 *)(p32 + 10);
    for (; i < 6; i++) {
        D_80115138[i] = *(u16 *)(D_80115134 + i * 32);
        out[i] = *(u16 *)(D_80115134 + i * 32 + 2);
    }
}
