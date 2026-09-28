/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8013E67C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_800D24A0(s32 a0);
extern void func_8013E5E8(void);
extern void *D_8011DB24;

void func_8013E67C(void) {
    func_800D24A0(0);
    D_8011DB24 = (void *)func_8013E5E8;
}
