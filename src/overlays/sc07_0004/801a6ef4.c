/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A6EF4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_8012B8A4(s16 *a0);
extern void func_801A5698(u8 *s2, s32 a1);
extern void func_801A54AC(s32 a0);

void func_801A6EF4(void *arg0) {
    s32 s0;

    s0 = (s32)arg0;
    *(u16 *)(*(s32 *)((u8 *)s0 + 0x20) + 0x12) = func_8012B8A4((s16 *)s0);
    func_801A5698((u8 *)s0, *(s16 *)((u8 *)s0 + 0xFE));
    func_801A54AC(s0);
}
