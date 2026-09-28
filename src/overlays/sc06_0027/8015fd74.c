/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015FD74 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern unsigned int D_801809CC[];
extern void func_80147324(s32 arg0);
extern s32 func_8013767C(s32 a0);
extern void func_80146CA0(void *a0);

void func_8015FD74(int param_1)
{
    ((int (*)(int))func_80147324)(0x18);
    *(int *)(param_1 + 0x198) = func_8013767C(D_801809CC[*(unsigned char *)(param_1 + 0x1a0)]);
    ((int (*)(int))func_80146CA0)(param_1);
}
