/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80161B84 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80149884(void);
extern void func_801599A4(void *a0);
extern void func_801498C0(void);

s32 func_80161B84(void *a0) {
    if ((((s32 *)a0)[0x11] & 0x100) != 0) {
        if (func_80149884() != 0) {
            func_801599A4(a0);
            (*(void (*)(void *))func_801498C0)(a0);
            return 1;
        }
    }
    return 0;
}
