/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016D464 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_800D22E4(s32 a0);
extern short func_8016CF04();
extern void func_8012A568(void (*a0)(void));

void func_8016D464(u8 *a0) {
    u8 *s1 = *(u8 **)(a0 + 0x34);
    s32 v0;
    func_800D22E4((s32)a0);
    func_8016CF04((s32)a0, 1);
    v0 = *(s32 *)(a0 + 0x1C) - 1;
    *(s32 *)(a0 + 0x1C) = v0;
    if (v0 == -1 || *(u16 *)s1 != 1) {
        *(u16 *)(a0 + 0x2) = *(u16 *)(a0 + 0x2) + 1;
    }
}
