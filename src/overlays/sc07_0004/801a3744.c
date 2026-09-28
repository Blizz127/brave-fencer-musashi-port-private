/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A3744 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80132288(s32 *a0, s32 *a1, s32 a2);
extern s32 *D_801AFB8C;
extern s32 D_801BF01C;
extern s32 D_801F8724;

void func_801A3744(s32 a0) {
    *(s16 *)(a0 + 0xE6) = 4;
    func_80132288(&D_801F8724, D_801AFB8C, D_801BF01C);
    *(s16 *)(a0 + 0x100) = -0x40;
}
