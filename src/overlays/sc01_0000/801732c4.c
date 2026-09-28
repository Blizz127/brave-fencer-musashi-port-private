/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801732C4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_8016F2A8(void);
extern s32 func_80174650(s32);

void func_801732C4(s32 *a0) {
        ((void (*)(s32 *))func_8016F2A8)(a0);
        func_80174650((s32)a0);
    }
