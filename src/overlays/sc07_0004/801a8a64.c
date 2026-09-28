/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A8A64 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_8012C658(s32 a0, s32 a1, s32 a2);
extern s16 D_801B03CC;
extern u8 D_801B03CE[];

void func_801A8A64(s32 a0) {
    s16 *s0;
    s32 s1;
    s32 s4;
    s32 s2 = 0;

    if (D_801B03CC == 0xFFF) {
        return;
    }
    s4 = 0xFFF;
    s0 = &D_801B03CC;
    s1 = 0;
    do {
        s32 ret = func_8012C658(0xC1, s2, a0);
        if (ret != 0) {
            *(s16 *)(*(s32 *)(ret + 0x20) + 0x12) = *(u16 *)(D_801B03CE + s1);
            *(s16 *)(*(s32 *)(ret + 0x20) + 0x14) = *(u16 *)s0;
        }
        s0 += 2;
        s1 += 4;
        s2 += 1;
    } while (*s0 != s4);
}
