/* SC02.CD member31 [8014E6F8,8014E790); exact word export. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014E6F8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

struct SubE6F8 {
    u8 pad0[6];
    u16 f6;
    u8 pad8[2];
    u16 fA;
    u8 padC[2];
    u16 fE;
    u8 pad10[0x78];
    u16 f88;
    u16 f8A;
    u16 f8C;
    u8 pad8E[0xF2];
    s32 f180;
};
extern s32 func_8014E83C(s32 a0, s16 *a1, s16 *a2);
extern s32 func_8014E790(s32 a0, s16 *a1, s16 *a2);

void func_8014E6F8(struct SubE6F8 *a0) {
    s16 g1[3];
    s16 g2[3];
    u16 t8A;
    u16 tA;
    g1[0] = a0->f88;
    t8A = a0->f8A;
    g1[1] = t8A;
    g1[2] = a0->f8C;
    g2[0] = a0->f6;
    tA = a0->fA;
    g2[1] = tA;
    g2[2] = a0->fE;
    if (a0->f180 == 0) {
        g1[1] = t8A - 0x54;
        g2[1] = tA - 0x54;
        func_8014E83C((s32)a0, g1, g2);
    } else {
        func_8014E790((s32)a0, g1, g2);
    }
}
