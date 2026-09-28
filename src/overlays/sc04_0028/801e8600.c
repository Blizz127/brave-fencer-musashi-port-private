/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801E8600 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_801E8600(void) {
    extern s32 D_801E7AAC;
    extern s32 D_801E79E4;
    extern s32 D_801E79E0;
    extern s32 D_801E8A58;
    *(s32 *)(D_801E7AAC + 4) = D_801E79E4;
    D_801E8A58 = D_801E79E0;
}
