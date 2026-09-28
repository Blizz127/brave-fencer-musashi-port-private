/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016FC64 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80171928(void *a0);
extern void func_8012A568(void (*a0)(void));

void func_8016FC64(void *a0) {
    s32 v1 = *(s32 *)((s32)a0 + 0x20);
    u16 v0 = *(u16 *)((s32)a0 + 0x132);
    *(s16 *)((s32)a0 + 0x136) = 0;
    *(s16 *)(v1 + 0x12) = v0;
    func_80171928(a0);
}
