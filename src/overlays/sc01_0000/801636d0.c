/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801636D0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8014AD30(s32 a0, u16 *a1, s32 a2, s32 a3);
extern u16 D_80126B18[];
extern s32 D_80115200;

void func_801636D0(s32 a0, s32 a1) {
    u32 i;
    s32 v;
    u16 *p;
    s32 *q;
    i = 0;
    v = a1 & 0x7FFF;
    p = D_80126B18;
    q = &D_80115200;
    do {
        if (*q & 1) {
            func_8014AD30(a0, p, 0, v & 0xFFFF);
        }
        p += 4;
        i++;
        q += 1;
    } while (i < 3);
}
