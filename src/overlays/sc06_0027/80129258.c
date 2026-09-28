/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80129258 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s16 D_8011DB30;

void func_80129258(void) {
    s16 *p = &D_8011DB30;
    s32 i = 0x7F;
    do {
        *p = 0;
        p = (s16 *)((s32)p + 0x38);
        i--;
    } while (i >= 0);
}
