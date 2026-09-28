/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016533C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_80078EC1;
extern s32 D_80126B58;
extern u8 D_80126CF8;
extern s32 func_801659DC();

void func_8016533C(void) {
    D_80126CF8 = D_80078EC1;
    func_801659DC((u8 *)&D_80126B58);
}
