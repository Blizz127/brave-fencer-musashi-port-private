/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012C724 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 func_8012C890(s32 a0, s32 a1, s32 a2);

void func_8012C724(s32 a0, s32 a1) {
    *(u16 *)((s32)a0 + 0xA) |= 0x8000;
    func_8012C890(a0, a1, 0);
}
