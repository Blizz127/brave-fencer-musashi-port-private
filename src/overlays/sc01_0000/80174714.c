/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80174714 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern s32 func_800CF8CC(void);
extern void func_80147060(u8 *a0);
extern s32 func_8016F0AC();
extern s32 D_80126B58;

void func_80174714(void) {
    if (func_800CF8CC() == 0) {
        func_80147060((u8 *)&D_80126B58);
        func_8016F0AC();
    }
}
