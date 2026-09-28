/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80153C74 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s16 D_8011DB0C;
extern s16 D_8011DB1A;

void func_80153C74(s16 a0, s16 a1) {
    D_8011DB0C = a0;
    D_8011DB1A = a1;
}
