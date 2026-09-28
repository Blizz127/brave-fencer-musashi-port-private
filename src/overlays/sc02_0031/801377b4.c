/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801377B4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 D_80127524;
extern s32 D_80127528;
extern void func_80137840(s32 a0);

void func_801377B4(s32 a0, s32 a1, s32 a2) {
    s32 s1 = a0;
    s32 s0 = a1;
    s32 s2 = a2;
    s32 *p;
    s32 v1;
    func_80137840(s2);
    *(s16 *)(s2 + 0x4) = 1;
    *(s32 *)(s2 + 0x0) = s1;
    *(s32 *)(s2 + 0x8) = (s16)s0;
    if ((s0 & 0x2000) == 0) {
        p = &D_80127524;
        v1 = *p;
        if (v1 != 0) {
            D_80127528 = v1;
            *(s16 *)(v1 + 0x1A) = 2;
        }
        *p = s2;
    }
}
