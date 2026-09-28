/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801E855C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_801E855C(void) {
    extern s32 D_801E7AAC;
    extern s32 D_801E79D8;
    extern s32 D_801E89F0;
    extern s32 D_801E8A28;
    extern s32 D_801E8A5C;

    switch (*(s16 *)&D_801E79D8) {
    case 0:
        *(s32 *)(D_801E7AAC + 4) = (s32)&D_801E89F0;
        break;
    case 1:
        *(s32 *)(D_801E7AAC + 4) = (s32)&D_801E8A28;
        break;
    case 2:
        *(s32 *)(D_801E7AAC + 4) = (s32)&D_801E8A5C;
        break;
    }
}
