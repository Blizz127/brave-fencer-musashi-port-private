/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017E008 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));

void func_8017E008(void) {
    extern u16 D_801888FC;
    extern s16 D_801888FA;
    extern s16 D_801888F8;
    extern void func_80146CA0(void *a0);
    s16 sVar1;

    sVar1 = D_801888FC + 8;
    D_801888FC = sVar1;
    D_801888FA = sVar1;
    D_801888F8 = sVar1;
    if (sVar1 >= 0x101) {
        ((void (*)(void))func_80146CA0)();
    }
}
