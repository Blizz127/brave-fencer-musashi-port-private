/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801627E8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_801627E8(void)
{

    extern s32 D_8011F750;               /* canonical: engine_core.h `extern s32 D_8011F750;` (func_8005CF28 here as a byte) */
    extern void (*D_801817AC[])(void);   /* word-stride table of dispatch fn pointers */
    register u8 *p __asm__("$4") = (u8 *)&D_8011F750;
    s32 idx;

    __asm__ __volatile__("" : "=r"(p) : "0"(p));   /* materialize &D_8011F750 into $a0 (defeat %lo-fold of the lbu) */
    idx = *p;
    if (idx != 0) {
        idx = idx - 1;
        D_801817AC[idx]();
    }
}
