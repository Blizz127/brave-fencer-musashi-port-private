/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012A908 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_801202A0[];
extern u16 D_801270C0;
extern void func_8012A988(u8 *a0);

void func_8012A908(void) {
    u8 *p = D_801202A0;
    s32 i;
    for (i = 0; i < 0x60; i++) {
        if (((s16)D_801270C0 == 1) || (*(u16 *)(p + 0x72) & 0x1000)) {
            func_8012A988(p);
        }
        p += 0x10C;
    }
}
