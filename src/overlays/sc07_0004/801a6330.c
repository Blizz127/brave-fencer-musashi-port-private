/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A6330 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u16 D_801202A0[];
extern void func_801A63A8(void *arg0);

void func_801A6330(void) {
    u16 *p;
    s32 i;

    p = D_801202A0;
    i = 0;
    do {
        if (*p == 0x31F) {
            if (*(s16 *)(p + 0x82) == 0) {
                func_801A63A8(p);
            }
        }
        i = i + 1;
        p = p + 0x86;
    } while (i < 0x60);
}
