/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8013C360 - byte-exact against retail at -O0 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);

void func_8013C360(s32 a0) {
    s32 *p;
    u32 i;
    p = (s32 *)(a0 + 0x10);
    for (i = 0; i < *(u32 *)(a0 + 8); i++) {
        *(s32 *)(*(s32 *)p) = *(s32 *)((s32)p + 4);
        p = (s32 *)((s32)p + 0xC);
    }
}
