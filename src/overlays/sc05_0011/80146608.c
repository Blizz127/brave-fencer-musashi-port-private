/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80146608 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801466F0(s32 a0, s32 a1, s32 a2, s32 a3, s32 sp5, s32 sp6, s32 sp7, s32 sp8);
extern s32 D_8011F9D0;

s32 func_80146608(s32 a0, s32 a1, s32 a2, s32 a3, s16 arg9, s32 arg10, s32 arg11, s32 arg12, s32 arg13) {
    u8 *p;
    u8 *end;
    s32 cnt;
    cnt = 0;
    p = (u8 *)&D_8011F9D0;
    end = p + 0x820;
    while (p < end) {
        if (*(u16 *)p == (a0 & 0xFFFF)) {
            cnt++;
        }
        p += 0x68;
    }
    if ((u32)cnt >= (u32)arg12) {
        return 0;
    }
    func_801466F0(a0 & 0xFFFF, a1, (s16)a2, (s16)a3, arg9, arg10, arg11, arg13);
}
