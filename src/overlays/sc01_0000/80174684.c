/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80174684 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern u8 D_80126D6C;
extern void (*D_80127088)(void);
extern s32 D_801270BC;

void func_80174684(void* a0)
{
    D_80126D6C = 0;
    (*(void * *)&D_80127088) = a0;
    D_801270BC = 0;
}
