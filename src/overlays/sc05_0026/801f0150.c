/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801F0150 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


s32 func_801F0150(u8 *a0) {
    extern s32 (*D_801F19E0[])(void);
    extern s32 D_801F8324;
    extern void func_801F0714(void);

    if (D_801F19E0[a0[0x15]]() != 0 && D_801F8324 != 0) {
        return 1;
    }
    D_801F8324 = ((s32 (*)(void))func_801F0714)();
    return 0;
}
