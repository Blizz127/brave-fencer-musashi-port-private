/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80138BE0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_80183E5C[])(int);

void func_80138BE0(int p)
{
    if (*(unsigned short *)(p + 0xe) != 0) {
        *(unsigned short *)(p + 0xe) -= 1;
    }
    D_80183E5C[*(short *)(p + 4)](p);
}
