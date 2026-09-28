/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80164E40 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_8019C220;
extern u8 D_8019C221;
extern u8 D_8019C222;

s32 func_80164E40(void) {
    u8 *p = &D_8019C220;
    if (*p != 0) {
        *p -= 0x10;
    }
    if (D_8019C221 != 0) {
        D_8019C221 -= 0x10;
    }
    if (D_8019C222 != 0) {
        D_8019C222 -= 0x10;
    }
    return *(s32 *)p == 0;
}
