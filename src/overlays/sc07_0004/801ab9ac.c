/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801AB9AC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u16 D_8019FF8A;
extern void func_801A8884(s32 *a0);
extern void func_801A88AC();
extern void func_801A8990();

void func_801AB9AC(s32 arg0) {
    s32 v1;

    v1 = D_8019FF8A;
    if (!(v1 & 1)) {
        func_801A8884(arg0);
    } else if (v1 & 0x400) {
        func_801A88AC(arg0);
    }

    *(u16 *)(arg0 + 0x104) = *(u16 *)(*(s32 *)(arg0 + 0x64) + 6);
    *(u16 *)(arg0 + 0x106) = *(u16 *)(*(s32 *)(arg0 + 0x64) + 0xA);
    *(u16 *)(arg0 + 0x108) = *(u16 *)(*(s32 *)(arg0 + 0x64) + 0xE);
    func_801A8990(arg0);

    if (*(s16 *)(arg0 + 0xFE) < 0x28) {
        *(s16 *)(arg0 + 0xFE) = *(s16 *)(arg0 + 0xFE) + 2;
    }
    *(u16 *)(arg0 + 0x100) += 0x28;
    *(u16 *)(*(s32 *)(arg0 + 0x20) + 0x10) += *(u16 *)(arg0 + 0x102);
}
