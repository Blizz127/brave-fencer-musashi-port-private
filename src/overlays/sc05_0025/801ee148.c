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

extern u8 D_80078EBA;
extern s32 D_801ED90C;
extern s32 D_801F51FC;
extern u8 D_801EED7C[];
extern u8 D_801EEDBC[];

void func_801EE148(void) {
    D_801F51FC = 0;
    if (D_80078EBA == 4) {
        *(s32 *)(D_801ED90C + 4) = (s32)D_801EEDBC;
    } else {
        *(s32 *)(D_801ED90C + 4) = (s32)D_801EED7C;
    }
}
