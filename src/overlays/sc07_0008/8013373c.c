/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8013373C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_8019530C[];
extern s32 D_80195308;
extern void func_80136BC4(s32);

void func_8013373C(s16 arg0) {
    s32 temp = D_8019530C[arg0];
    if (temp != 0) {
        D_80195308 = temp;
        func_80136BC4(temp);
    }
}
