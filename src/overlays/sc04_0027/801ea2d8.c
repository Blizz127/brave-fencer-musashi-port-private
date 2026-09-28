/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801EA2D8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


s32 func_801EA2D8(void *a0) {

    extern void (*D_801EBB58[])(void);
    extern void func_801EA88C(void);
    extern s32 D_801F249C;

    if (((s32 (*)(void))D_801EBB58[*(u8 *)((s32)a0 + 0x15)])() != 0 && D_801F249C != 0) {
        return 1;
    }
    D_801F249C = ((s32 (*)(void))func_801EA88C)();
    return 0;
}
