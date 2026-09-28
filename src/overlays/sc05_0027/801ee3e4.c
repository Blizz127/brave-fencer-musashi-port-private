/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801EE3E4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_801EE3E4(void) {
    extern s16 D_801ED838;
    extern s16 D_801ED90C;
    extern u8 D_801EE878[];
    extern u8 D_801EE8B0[];
    extern u8 D_801EE8E4[];

    switch (D_801ED838) {
    case 0:
        *(s32 *)(*(s32 *)&D_801ED90C + 4) = (s32)D_801EE878;
        break;
    case 1:
        *(s32 *)(*(s32 *)&D_801ED90C + 4) = (s32)D_801EE8B0;
        break;
    case 2:
        *(s32 *)(*(s32 *)&D_801ED90C + 4) = (s32)D_801EE8E4;
        break;
    }
}
