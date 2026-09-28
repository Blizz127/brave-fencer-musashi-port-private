/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012DEB8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_8012F214(s32 a0, s32 a1, s32 a2);
extern s32 func_8012DF34(s32 a0, s32 a1, s32 a2);
extern s16 D_80126B9A;

s32 func_8012DEB8(s32 a0, s32 a1, s32 a2) {
    s32 sp10[2];
    s32 sp18[2];
    func_8012F214(a0, a1, (s32)sp10);
    func_8012F214(a0, a2, (s32)sp18);
    if (func_8012DF34(a0, (s32)sp10, (s32)sp18) != 0) {
        D_80126B9A = *(u16 *)(*(s32 *)(a0 + 0x20) + 0x12);
        return 1;
    }
    return 0;
}
