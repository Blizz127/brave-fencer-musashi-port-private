/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801E85E8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { char s[10]; } S10_80136C90;

void func_801E85E8(void) {
    extern s32 D_801E7AAC;
    extern S10_80136C90 D_801E79DC;
    *(s32 *)(D_801E7AAC + 4) = *(s32 *)&D_801E79DC;
}
