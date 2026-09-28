/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801F0D88 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801F0C4C();
extern s32 D_801F84AC;
extern s32 D_801F8334[][4];
extern s32 D_801F8330[][4];

s32 func_801F0D88(s32 a0) {
    s32 s0;
    s32 cnt;
    s32 off;
    s0 = a0;
    func_801F0C4C();
    cnt = D_801F84AC;
    if (cnt > 0) {
        off = 0;
        do {
            if (*(s32 *)((s32)((s32 *)D_801F8334) + off) == s0) {
                return *(s32 *)((s32)((s32 *)D_801F8330) + off);
            }
            off += 16;
        } while (off < cnt * 16);
    }
    return 0;
}
