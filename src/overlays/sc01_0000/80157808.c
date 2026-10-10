/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80157808 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_80180F14[])(void *);
extern int D_801A45A8;
extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);

void func_80157808(void *param_1)
{
    D_80180F14[*(unsigned short *)((char *)param_1 + 2)](param_1);
    D_801A45A8 = D_801A45A8 - 1;
    if (D_801A45A8 == -1) {
        func_801599A4(param_1);
        func_80159B3C(param_1);
    }
}
