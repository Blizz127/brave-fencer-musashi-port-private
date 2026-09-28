/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012DE2C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern u8 D_801202A0[];

s32 func_8012DE2C(s32 a0) {
    extern u8 * D_8019BD4C;
    extern u8 * D_8019BD48;

    u8 *base;
    u8 *end;
    u8 *p;

    base = D_801202A0;
    end = base + 0x6480;
    D_8019BD4C = base;
    D_8019BD48 = ((u8 *)a0);

    while (D_8019BD4C != end) {
        p = D_8019BD4C;
        if (*(u16 *)p != 0 && p != ((u8 *)a0)) {
            D_8019BD4C = p + 0x10C;
            return p;
        }
        D_8019BD4C += 0x10C;
    }
    D_8019BD4C = 0;
    return 0;
}
