/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801752BC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_801553A8(s32 *a0);
extern void func_80154A74(s32 a0, s32 a1);

void func_801752BC(s32 *a0) {
    *(s16 *)((u8 *)a0 + 0xF6) = 0x1000;
    func_801553A8(a0);
    func_80154A74((s32)a0, 0x11);
    *(s32 *)((u8 *)a0 + 0x44) &= ~2;
}
