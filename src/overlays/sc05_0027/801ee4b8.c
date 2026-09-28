/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801EE4B8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8018CDB0(void);

void func_801EE4B8(void) {
    extern s32 D_801ED90C;
    extern s16 D_801ED838;
    extern u8 D_801EE878[];
    extern u8 D_801EE898[];

    func_8018CDB0();
    if (D_801ED838 == 0) {
        *(s32 *)(D_801ED90C + 4) = (s32)D_801EE878;
    } else {
        *(s32 *)(D_801ED90C + 4) = (s32)D_801EE898;
    }
}
