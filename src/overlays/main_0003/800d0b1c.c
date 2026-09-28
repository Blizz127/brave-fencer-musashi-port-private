/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800D0B1C - byte-exact against retail at -O0 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_800AF630[];
extern s32 D_800D4E6C;
extern s16 D_800EC894;
extern void func_800183E0(s32 a0);

void func_800D0B1C(void) {
    register u8 *s0 = D_800AF630;
    func_800183E0((s32)&D_800D4E6C);
    switch (D_800EC894) {
    case 0:
        *(u16 *)(s0 + 0xA3B6) = 1;
        *(u16 *)(s0 + 0xA3B8) = 2;
        break;
    case 1:
        *(u16 *)(s0 + 0xA3B6) = 1;
        *(u16 *)(s0 + 0xA3B8) = 0;
        break;
    case 2:
        *(u16 *)(s0 + 0xA3B6) = 1;
        *(u16 *)(s0 + 0xA3B8) = 1;
        break;
    case 4:
        *(u16 *)(s0 + 0xA3B6) = 1;
        *(u16 *)(s0 + 0xA3B8) = 4;
        break;
    }
}
