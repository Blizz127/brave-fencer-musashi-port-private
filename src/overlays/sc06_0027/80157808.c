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

extern void (*D_801802E0[])(void);
extern int D_8019C148;
extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);

void func_80157808(void *param_1)
{
    D_801802E0[*(unsigned short *)((char *)param_1 + 2)]();
    D_8019C148 = D_8019C148 - 1;
    if (D_8019C148 == -1) {
        func_801599A4(param_1);
        func_80159B3C(param_1);
    }
}
