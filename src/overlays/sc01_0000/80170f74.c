/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80170F74 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void *D_8011F738;
extern void func_80029124(s32, s32);
extern void func_80171928(void *a0);

void func_80170F74(void *a0) {
    func_80029124((s32)D_8011F738, 1);
    func_80171928(a0);
}
