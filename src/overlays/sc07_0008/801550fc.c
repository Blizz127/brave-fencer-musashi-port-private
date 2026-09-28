/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801550FC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct {
    u8 b[8];
} ImgRect8;
extern void func_80059A80(void *a0, s32 a1, s32 a2);
extern void func_800183E0(s32 a0);
extern ImgRect8 D_8017F12C[];

void func_801550FC(s32 arg0)
{
    if (arg0 & 0x40000000) {
        func_80059A80(&D_8017F12C[arg0 & 0xFF], 0x200, 0x100);
    } else {
        ((void (*)(void))func_800183E0)();
    }
}
