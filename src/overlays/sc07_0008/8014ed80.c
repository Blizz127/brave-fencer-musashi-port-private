/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014ED80 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

struct SubED80 {
    u8 pad0[6];
    u16 f6;
    u8 pad8[2];
    u16 fA;
    u8 padC[2];
    u16 fE;
    u8 pad10[0x34];
    s32 f44;
    u8 pad48[0x40];
    u16 f88;
    u16 f8A;
    u16 f8C;
    u8 pad8E[0x16A];
    s32 f1F8;
};
extern s32 func_8014EE14(s32 a0, s16 *a1, s16 *a2);

s32 func_8014ED80(struct SubED80 *a0) {
    s16 g1[3];
    s16 g2[3];
    if (a0->f44 & 0x80000) {
        return 0;
    }
    if (a0->f1F8 & 0x4000000) {
        return 0;
    }
    g1[0] = a0->f88;
    g1[1] = a0->f8A - 0x10;
    g1[2] = a0->f8C;
    g2[0] = a0->f6;
    g2[1] = a0->fA - 0x10;
    g2[2] = a0->fE;
    func_8014EE14((s32)a0, g1, g2);
}
