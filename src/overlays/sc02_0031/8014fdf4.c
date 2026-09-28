/* SC02.CD member31 [8014FDF4,8014FE60); exact word export. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014FDF4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

struct S8014FDF4 {
    s16 pad0[3];   /* 0x0,0x2,0x4 */
    s16 f6;        /* 0x6 */
    s16 pad8;      /* 0x8 */
    s16 fA;        /* 0xA */
    s16 padC;      /* 0xC */
    s16 fE;        /* 0xE */
    s16 pad[0x3C]; /* up to 0x88 */
    s16 f88;       /* 0x88 */
    s16 f8A;       /* 0x8A */
    s16 f8C;       /* 0x8C */
};
extern s32 func_80150170(void *a0);
extern s32 func_8014FE60();

void func_8014FDF4(struct S8014FDF4 *a0) {
    if (a0->f6 != a0->f88 || a0->fA != a0->f8A || a0->fE != a0->f8C) {
        func_80150170(a0);
    } else {
        func_8014FE60(a0);
    }
}
