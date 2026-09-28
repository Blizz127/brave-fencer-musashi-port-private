/* Exact retail overlay 0010 export [800D1E28,800D1EBC), offset 0x23030. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800D1E28 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_800167B8(s32 arg0);
extern s16 D_800B9A08;
extern u16 D_80078E50;
extern s32 func_800CFC5C(s32);
extern s32 func_800CFD68(s32);

void func_800D1E28(void) {
    extern s16 D_800B9A08;
    extern u16 D_80078E50;
    extern int func_800CFC5C(int);
    extern int func_800CFD68(int);
    extern void func_800168B4(int);
    extern void func_800167B8(int);
    int result;
    int r;

    if (D_800B9A08 == 0x3005) goto two;
    r = func_800CFC5C(D_800B9A08);
    result = 2;
    if (r != 0) goto test;
    if (func_800CFD68(D_80078E50) == 0) goto two;
    r = func_800CFC5C(D_80078E50);
    result = 1;
    if (r == 0) goto test;
two:
    result = 2;
test:
    if (result < 0) goto other;
    if (result >= 2) goto other;
    func_800168B4(4);
    return;
other:
    func_800167B8(4);
}
