/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A6334 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_801F44C4;
extern void func_8012C218(void *a0);

void func_801A6334(s32 arg0) {
    s32 *p;
    *(u16 *)(*(s32 *)(arg0 + 0x20) + 0x18) += 0xE00;
    *(u16 *)(*(s32 *)(arg0 + 0x20) + 0x1A) += 0xE00;
    p = &D_801F44C4;
    *p += 0xFFFBFBFC;
    if (*(s16 *)(*(s32 *)(arg0 + 0x20) + 0x18) >= 0x7001) {
        func_8012C218((void *)arg0);
    }
}
