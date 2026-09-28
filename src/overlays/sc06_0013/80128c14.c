/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80128C14 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80010AE0(s32 a0);
extern s16 D_800B9A08;

void func_80128C14(void) {
    s32 a0;
    switch (D_800B9A08) {
    case 0x3023:
        a0 = 0x4E0;
        break;
    case 0x3081:
        a0 = 0x420;
        break;
    case 0x3067:
        a0 = 0x480;
        break;
    case 0x3093:
        a0 = 0xFFB;
        break;
    case 0x30A5:
        a0 = 0xFFB;
        break;
    default:
        a0 = 0x3E0;
        break;
    }
    func_80010AE0(a0);
}
