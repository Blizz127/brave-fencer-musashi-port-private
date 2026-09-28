/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80138D58 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_8013A9F8(s32 a0, s32 a1);

void func_80138D58(s32 a0, u16 a1) {
    if (*(s32 *)(a0 + 0x40) == 0) {
        return;
    }
    if ((u32)(*(u16 *)(a0 + 0x18) - 2) >= 5) {
        return;
    }
    if ((u32)(u16)(a1 - 2) >= 5) {
        return;
    }
    *(s16 *)(a0 + 0x18) = a1;
    func_8013A9F8(*(s32 *)(a0 + 0x40), a1);
}
