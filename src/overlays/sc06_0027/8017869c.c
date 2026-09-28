/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017869C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_80178744(s32 a0, s32 a1);

void func_8017869C(s32 a0) {
    s32 v1;
    s32 a1;
    if (*(s16 *)(a0 + 0xAA) == 0) {
        return;
    }
    *(s16 *)(a0 + 0xAA) = *(s16 *)(a0 + 0xAA) - 1;
    v1 = *(s16 *)(a0 + 0xAA);
    if (v1 == 0) {
        a1 = 0x1000;
        if (*(u16 *)(a0 + 0x5E) == 0x1E) {
            *(s16 *)(a0 + 0x5E) = 0;
        }
    } else if (v1 >= 0xF1) {
        a1 = 0x1000 - (0x100 - v1) * 0x90;
    } else {
        if (v1 < 0x10) {
            a1 = 0x1000 - v1 * 0x90;
        } else {
            a1 = 0x700;
        }
    }
    func_80178744(a0, a1);
}
