/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017EB54 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern s16 D_800AF7CE;
extern void func_80016224(s32 a0, s32 a1);

s32 func_8017EB54(void) {
    D_800AF7CE = (u16)D_800AF7CE + 4;
    if ((u16)D_800AF7CE > 0xFF) {
        D_800AF7CE = 0xFF;
    }
    func_80016224((u8)D_800AF7CE, 0);
    return (u16)D_800AF7CE >= 0xFF;
}
