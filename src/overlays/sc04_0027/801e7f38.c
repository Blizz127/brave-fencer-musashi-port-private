/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801E7F38 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80141C04(void);

void func_801E7F38(void) {

    extern u16 D_80115112;
    extern u16 D_80115116;
    extern void (*D_801EBB38[])(void);
    u16 i;
    i = D_80115112;
    D_801EBB38[i]();
    func_80141C04();
    D_80115116++;
}
