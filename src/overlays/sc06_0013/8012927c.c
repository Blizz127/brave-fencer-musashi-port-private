/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012927C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801292C8(u8 *a0);
extern s16 D_8011DB30;

void func_8012927C(void) {
    s32 i;
    u8 *p = (u8 *)&D_8011DB30;
    for (i = 0; i < 0x80; i++) {
        func_801292C8(p);
        p += 0x38;
    }
}
