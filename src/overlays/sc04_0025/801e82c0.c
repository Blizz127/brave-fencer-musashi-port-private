/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801E82C0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_801E82C0(void) {

    extern u8 D_80078EB1;
    extern s32 D_801EE5D4;
    extern s32 D_801E7AAC;
    extern s32 D_801E8828[];
    extern s32 D_801E87F8[];

    D_801EE5D4 = 0;
    if ((u32)D_80078EB1 >= 0x12) {
        *(s32 *)(D_801E7AAC + 4) = (s32)D_801E8828;
    } else {
        *(s32 *)(D_801E7AAC + 4) = (s32)D_801E87F8;
    }
}
