/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801702B8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s16 func_80171AB0(s32 a0, void *a1);
extern void func_80171928(void *a0);
extern void *D_8011F738;
extern void func_8012A568(void (*a0)(void));

void func_801702B8(s32 a0) {
    if (func_80171AB0(a0, &D_8011F738) == 0) {
        func_80171928((void *)a0);
    }
}
