/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80153C44 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80153C74(s16 a0, s16 a1);
extern s16 D_8011DB18;

void func_80153C44(int a0, int a1, s16 a2)
{
    ((void (*)(int, int))func_80153C74)(a0, a1);
    D_8011DB18 = a2;
}
