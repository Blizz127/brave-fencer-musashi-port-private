/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801343C4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_8019BFE8;

s32 func_801343C4(s32 angle, s32 p1, s32 p2)
{
    extern s32 func_80133AB0(s16 flag, s16 x, s16 y, s32 arg3);
    extern s16 * D_8017E564;
    extern s16 * D_8017E568;
    extern u16 D_8019BFF8;
    extern u16 D_8019BFF4;

    s16 *pac;
    s16 *pb0;
    s16 *pacs, *pb0s;
    u16 *pb0u;
    int a1v, a2v, d94, b0;
    int sangle = ((s16)angle);

    pac = D_8017E564;
    d94 = D_8019BFE8;
    pb0 = D_8017E568;
    pac[0] = ((u16 *)p1)[0];
    pac[1] = ((u16 *)p1)[1];
    pac[2] = ((u16 *)p1)[2];
    pb0[0] = ((u16 *)p2)[0];
    pb0[1] = ((u16 *)p2)[1];
    pb0[2] = ((u16 *)p2)[2];

    a1v = pac[0]; a2v = pac[2];
    __asm__ __volatile__("" ::: "memory");
    D_8019BFF8 = 0;
    D_8019BFF4 = 0;
    if (((int (*)(int, s16, s16, int))func_80133AB0)(sangle, a1v, a2v, d94)) {
    setdst:
        pb0u = (u16 *)D_8017E568;
        ((u16 *)p2)[0] = pb0u[0];
        ((u16 *)p2)[1] = pb0u[1];
        ((u16 *)p2)[2] = pb0u[2];
        ((u16 *)p2)[3] = D_8019BFF8;
        return 1;
    }

    pacs = D_8017E564;
    pb0s = D_8017E568;
    b0 = pb0s[0];
    if ((pacs[0] & 0xFF80) == (b0 & 0xFF80) &&
        (pacs[2] & 0xFF80) == (pb0s[2] & 0xFF80)) {
        return 0;
    }
    if (((int (*)(int, s16, s16, int))func_80133AB0)(sangle, b0, pb0s[2], D_8019BFE8)) {
        goto setdst;
    }
    return 0;
}
