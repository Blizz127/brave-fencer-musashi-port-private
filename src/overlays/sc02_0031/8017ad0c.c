/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017AD0C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct {
    s16 x;
    s16 y;
    s16 w;
    s16 h;
} Rect;
extern void func_8012A568(void (*a0)(void));
extern void func_80059A80(void *a0, s32 a1, s32 a2);

s32 func_8017AD0C(s32 arg0)
{
    Rect rect;
    s32 var_v0;
    s32 var_v1;
    arg0 = arg0 - 1;
    rect.x = ((arg0 & 3) * 0x10) + 0x280;
    var_v0 = arg0;
    if (arg0 < 0) {
        var_v0 = arg0 + 3;
    }
    rect.y = (var_v0 >> 2) + 0x1F8;
    rect.w = 0x10;
    rect.h = 1;
    func_80059A80(&rect, 0x160, 0x1C9);
    if (arg0 == 0x18) {
        rect.x = 0x2C0;
        rect.y = 0x1D0;
    } else {
        rect.x = ((arg0 & 7) * 8) + 0x280;
        var_v1 = arg0;
        if (arg0 < 0) {
            var_v1 = arg0 + 7;
        }
        rect.y = (var_v1 >> 3) * 0x28 + 0x180;
    }
    rect.w = 0x20;
    rect.h = 0x28;
    __asm__ __volatile__("" ::: "memory");
    func_80059A80(&rect, 0x1C8, 0x190);
}
