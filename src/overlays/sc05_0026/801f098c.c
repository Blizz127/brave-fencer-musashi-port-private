/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801F098C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80029504(void);
extern s32 func_80029178(s32);

void func_801F098C(void) {
    extern s32 D_801ED90C;
    extern u8 D_801F1CAC[];
    extern u8 D_801F1CE0[];
    s32 r;
    s32 f;

    r = func_80029504();

    if ((u32)(r - 0xC8) < 0x64) {
        f = 0;
    } else if (r >= 0x12C) {
        if ((func_80029178(0xFA) & 0xFF) != 0) {
            goto isCAC;
        }
        f = 1;
    } else {
        f = 1;
    }
    goto join;
isCAC:
    f = 0;
join:
    if (f != 0) {
        *(s32 *)(D_801ED90C + 4) = (s32)D_801F1CAC;
    } else {
        *(s32 *)(D_801ED90C + 4) = (s32)D_801F1CE0;
    }
}
