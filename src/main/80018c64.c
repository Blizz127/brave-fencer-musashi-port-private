/* Exact retail word export for [80018C64,80018CE8); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80018C64 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80018F88(void*);

void func_80018C64(void *a0)
{
    s32 i;
    u8 *q;
    u8 *p = (u8 *)a0;

    if (p[8] != 0) {
        func_80018F88(a0);
        return;
    }
    p[0] = p[9];
    i = 0;
    q = &p[0x2B];
    while (i < 2) {
        *q = ~*(p + i + 10);
        i++;
        q--;
    }
    i = 2;
    while (i < 6) {
        *(p + i + 0x2A) = *(p + i + 10);
        i++;
    }
}
