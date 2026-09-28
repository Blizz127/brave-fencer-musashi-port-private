/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801EE148 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_801EE148(void) {
    extern u8 D_80078EB1;
    extern s32 D_801ED90C;
    extern u8 D_801EE680[];
    extern u8 D_801EE6B0[];
    extern s32 D_801F445C;

    D_801F445C = 0;
    if (D_80078EB1 >= 0x12) {
        *(s32 *)(D_801ED90C + 4) = (s32)D_801EE6B0;
    } else {
        *(s32 *)(D_801ED90C + 4) = (s32)D_801EE680;
    }
}
