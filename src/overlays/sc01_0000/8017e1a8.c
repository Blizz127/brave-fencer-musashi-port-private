/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017E1A8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct {
    s16 x;      /* 0x00 — source point */
    s16 y;      /* 0x02 */
    s16 sx;     /* 0x04 — scaled result */
    s16 sy;     /* 0x06 */
} Pt_8017E1A8;

void func_8017E1A8(Pt_8017E1A8 *p, s32 arg1, s32 arg2, s32 arg3) {
    s32 i;
    s32 ax;
    s32 ay;

    for (i = 0; i < 9; i++) {
        ax = p[i].x - 0xA0;
        ay = p[i].y - 0x78;
        ax = (ax * arg3) / 0x1000;
        ay = (ay * arg3) / 0x1000;
        p[i].sx = ax + arg1;
        p[i].sy = ay + arg2;
    }
}
