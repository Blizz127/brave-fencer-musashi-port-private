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
    extern u8 D_80078EBA;
    extern s32 D_801E7AAC;
    extern u8 *D_801E8EF4[];
    extern u8 *D_801E8F34[];
    extern s32 D_801EF374;

    D_801EF374 = 0;
    if (D_80078EBA == 4) {
        *(s32 *)(D_801E7AAC + 4) = (s32)D_801E8F34;
    } else {
        *(s32 *)(D_801E7AAC + 4) = (s32)D_801E8EF4;
    }
}
