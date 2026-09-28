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

extern u8 D_801A4680;
extern u8 D_801A4681;
extern u8 D_801A4682;

s32 func_80164E40(void) {
    u8 *p = &D_801A4680;
    if (*p != 0) {
        *p -= 0x10;
    }
    if (D_801A4681 != 0) {
        D_801A4681 -= 0x10;
    }
    if (D_801A4682 != 0) {
        D_801A4682 -= 0x10;
    }
    return *(s32 *)p == 0;
}
