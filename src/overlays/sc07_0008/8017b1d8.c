/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017B1D8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u16 D_80126B5E;
extern u16 D_80126B62;
extern u16 D_80126B66;
extern s16 D_80196534;
extern u16 D_801965B4;
extern u16 D_801965B6;
extern u16 D_801965B8;
extern s16 D_801966D0;

void func_8017B1D8(void) {
    func_8012A418();
    D_801966D0 = 0;
    D_80196534 = 0;
    D_801965B4 = D_80126B5E;
    D_801965B6 = D_80126B62;
    D_801965B8 = D_80126B66;
}
