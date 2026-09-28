/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8013A1E8 - byte-exact against retail at -O2 (tools/register_match.py). */
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
extern s16 func_80138DB8(s32 a0, u8 a1, s32 a2);
extern void func_80138B88(s32 a0);

void func_8013A1E8(s32 a0) {
    s32 v = D_80127524;
    if (v == a0) {
        if (func_80138DB8(v, 0, 0x70) != 0 || (*(s32 *)(v + 8) & 0x800)) {
            func_80138B88(v);
        }
    }
}
