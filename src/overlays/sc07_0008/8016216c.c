/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016216C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_800291C8(s32, s32);
extern void func_80016714(void *a0, s32 a1);
extern int D_80195488[];

void func_8016216C(void)
{
    int *p;
    int i;

    func_800291C8(8, 0);
    i = 0;
    p = D_80195488;
    do {
        int v = *p;
        ((void (*)(int, int))func_80016714)(v, 0x38);
        p = p + 1;
        i = i + 1;
    } while (i < 3);
}
