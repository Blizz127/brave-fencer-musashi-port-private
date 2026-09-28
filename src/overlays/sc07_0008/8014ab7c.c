/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014AB7C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80162CCC();
extern s32 D_8011F9D0;

void func_8014AB7C(s32 arg0) {
    u8 *p;
    for (p = (u8 *)&D_8011F9D0; p < (u8 *)&D_8011F9D0 + 0x820; p += 0x68) {
        if (*(u16 *)p == arg0) {
            ((void (*)(u8 *))func_80162CCC)(p);
        }
    }
}
