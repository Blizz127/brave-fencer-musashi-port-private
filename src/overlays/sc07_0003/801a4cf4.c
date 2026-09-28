/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A4CF4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012C218(void *a0);
extern void func_8012B260(u8 *a0);

void func_801A4CF4(s32 a0) {
    s32 a1 = *(s32 *)(a0 + 0x64);

    if (*(s16 *)(a1 + 0x36) != *(s16 *)(a0 + 0x10A)) {
        func_8012C218((void *)a0);
        return;
    }

    *(s32 *)(a0 + 0x4) = *(s32 *)(a1 + 0x38);
    *(s32 *)(a0 + 0x8) = *(s32 *)(a1 + 0x3C);
    *(s32 *)(a0 + 0xC) = *(s32 *)(a1 + 0x40);
    func_8012B260((u8 *)a0);
}
