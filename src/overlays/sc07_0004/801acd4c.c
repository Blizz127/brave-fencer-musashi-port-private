/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801ACD4C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_800599B8(void *, void *);
extern u8 D_801F8B18;

void func_801ACD4C(void) {
    u16 sp10[4];
    u16 *base;
    u16 *p;
    s32 i;
    u16 first;
    u16 t;

    base = (u16 *) &D_801F8B18;
    first = base[0];
    i = 0;
    p = base;
    do {
        t = p[1];
        i++;
        p[0] = t;
        p++;
    } while (i < 0x5E);
    base[i] = first;
    sp10[0] = 0x100;
    sp10[1] = 0x1E0;
    sp10[2] = 0x100;
    sp10[3] = 1;
    func_800599B8(sp10, (void *) &D_801F8B18);
}
