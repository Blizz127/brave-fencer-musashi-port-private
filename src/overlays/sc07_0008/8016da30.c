/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016DA30 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8016DBD8(u8 *a0);
extern void (*D_801805FC[])(int);
extern void func_8012A568(void (*a0)(void));

void func_8016DA30(int param_1)
{
    ((void (*)(void))func_8016DBD8)();
    D_801805FC[*(unsigned short *)(param_1 + 2)](param_1);
}
