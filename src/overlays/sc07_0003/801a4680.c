/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A4680 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { s16 vx, vy, vz, pad; } SVec_801A4680;
typedef struct {
    SVec_801A4680 v[4];                  /* 0x00 */
    s16 u0, t0, u1, t1, u2, t2, u3, t3;  /* 0x20 */
    u32 bcast;                           /* 0x30 */
    s32 tag;                             /* 0x34 */
    u8  code;                            /* 0x38 */
    u8  pad39[7];                        /* -> 0x40 */
} Prim_801A4680;
extern void func_80016EF8(void *a0, void *a1);

void func_801A4680(void *a0) {
    Prim_801A4680 prim;
    s32 i, j;

    prim.bcast = 0x808080;
    prim.tag = 0x50000000;
    prim.code = 0x8F;

    prim.v[3].vy = -0x40;
    prim.v[2].vy = -0x40;
    prim.v[1].vy = -0x40;
    prim.v[0].vy = -0x40;

    prim.v[3].vz = 0;
    prim.v[2].vz = 0;
    prim.v[1].vz = 0;
    prim.v[0].vz = 0;

    prim.t3 = 0x80;
    prim.t2 = 0x80;
    prim.t1 = 0x80;
    prim.t0 = 0x80;

    for (i = 0; i < 8; i++) {
        prim.v[3].vx = -0x40;
        prim.v[2].vx = -0x40;
        prim.v[1].vx = -0x40;
        prim.v[0].vx = -0x40;

        prim.u3 = 0xB80;
        prim.u2 = 0xB80;
        prim.u1 = 0xB80;
        prim.u0 = 0xB80;

        prim.v[2].vy += 0x10;
        prim.v[3].vy += 0x10;
        prim.t2 += 0xF;
        prim.t3 += 0xF;

        for (j = 0; j < 8; j++) {
            prim.v[1].vx += 0x10;
            prim.v[3].vx += 0x10;
            prim.u1 += 0xF;
            prim.u3 += 0xF;

            func_80016EF8(&prim, (void *)(*(s32 *)((u8 *)a0 + 0x20) + 0x34));

            prim.v[0].vx = prim.v[1].vx;
            prim.v[2].vx = prim.v[3].vx;
            prim.u0 = prim.u1;
            prim.u2 = prim.u3;
        }

        prim.v[0].vy = prim.v[2].vy;
        prim.v[1].vy = prim.v[3].vy;
        prim.t0 = prim.t2;
        prim.t1 = prim.t3;
    }
}
