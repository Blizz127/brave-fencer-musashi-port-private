/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017BEBC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_8012F14C(s32 a0, s32 a1, s32 a2);
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);

void func_8017BEBC(s32 a0, s16 *a1, s16 a2) {
    s16 v[3];
    short i;
    v[0] = a1[0];
    v[1] = a1[1] - 0x14;
    v[2] = a1[2];
    ((void (*)(s32, void *, void *))func_8012F14C)(*(s32 *)(a0 + 0x20) + 0x34, v, v);
    i = 0;
    do {
        short t;
        if (a2 == 0) {
            t = i;
        } else {
            t = 1;
        }
        func_80146A6C(0x25, (void *)a0, v[0], v[1], v[2], t, 0);
        i = i + 1;
    } while (i < 2);
}
