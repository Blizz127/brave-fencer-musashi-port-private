/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801AD294 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_801B07F0[];
extern u8 D_801B07F2[];
extern u8 D_801F8A78[];
extern void func_801A649C();

void func_801AD294(void) {
    func_801A649C(D_801F8A78, *(u16 *)D_801B07F0, *(u16 *)D_801B07F2);
}
