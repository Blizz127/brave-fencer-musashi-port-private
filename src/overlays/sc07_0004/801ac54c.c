/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801AC54C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_8012BEE8(s32 a0);
extern void func_8012C218(void *a0);
extern void func_801A9B80(s32 *a0, u16 a1, u16 a2);
extern u8 D_801F8A58;

void func_801AC54C(s32 param_1) {
    if (func_8012BEE8(param_1) != 0) {
        func_8012C218((void *)param_1);
    } else {
        func_801A9B80(&D_801F8A58, 0x160, 0x157);
    }
}
