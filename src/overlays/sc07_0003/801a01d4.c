/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A01D4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_801A6B2C[])(void *);
extern void func_801A293C(void *a0);
extern void func_801A4268();
extern void func_801A2EC8(void *a0);
extern s32 D_801F4360[];

void func_801A01D4(void *a0) {
    D_801A6B2C[*(u16 *)((s32)a0 + 0x2)](a0);
    if (*(u16 *)a0 != 0) {
        func_801A293C(a0);
        func_801A4268(a0);
        func_801A2EC8(a0);
    }
    {
        s32 i;
        for (i = 0; i < 3; i++) {
            D_801F4360[i] += 1;
        }
    }
}
