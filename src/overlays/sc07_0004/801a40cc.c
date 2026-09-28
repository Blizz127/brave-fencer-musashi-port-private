/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A40CC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { char c[4]; } Blk4_801A40CC;
extern void func_800233CC(void *a0, unsigned short a1);
extern void func_801A417C(s32 arg0);
extern u8 D_801F8744[];
extern u8 D_801AFEF8[];
extern s32 D_801A01B4[];

void func_801A40CC(s32 a0) {
    u8 *base;
    u8 *p;
    u8 *q;
    s32 i;

    i = 0;
    base = D_801F8744;
    q = base + 4;
    p = base;

    for (; i < 4; i++) {
        func_800233CC((void *)p, 0x40);
        *(Blk4_801A40CC *)p = *(Blk4_801A40CC *)&D_801AFEF8;
        *(Blk4_801A40CC *)q = *(Blk4_801A40CC *)&D_801A01B4;
        q += 0x40;
        p += 0x40;
    }

    func_801A417C(a0);
}
