/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CCBC0 - byte-exact against retail at -O2 (tools/register_match.py). */
s32 aF800CCBC0(void) __asm__("func_800CCBC0");

s32 aF800CCBC0(void) {
    typedef struct { s16 vx, vy, vz, pad; } SVEC;
    typedef struct { u8 r, g, b, cd; } CVEC;
    typedef struct { SVEC v0, v1, v2, v3; CVEC c0, c1, c2, c3; s32 tag; } Prim;
    typedef struct { s32 w[8]; } Blk20;
    typedef struct { u16 f0, f1, f2, f3, f4, f5; } Rec;
    typedef struct { u8 flag, idx, cnt, tim; Rec e[16]; } Trail;

    extern Blk20 D_800AE620;
    extern u8 D_800CD6E0[];
    extern u8 D_800CD6E1;
    extern u8 D_800CD6E2;
    extern u8 D_800CD6E3;
    extern s32 func_80017758(void *a0, void *a1);

    Prim prim;
    Blk20 blk;
    Trail *p;
    Rec *e;
    Rec *q;
    short idx;
    short cnt;
    unsigned int tim;
    short half;
    short n;

    blk = D_800AE620;
    prim.tag = 0x50000000;
    p = (Trail *)D_800CD6E0;
    if (p->flag == 0) {
        return 0;
    }
    n = 0;
    e = p->e;
    idx = D_800CD6E1;
    tim = D_800CD6E3;
    cnt = D_800CD6E2;
    half = tim >> 1;
    cnt = cnt - 1;
    if (cnt != -1) {
        do {
            q = &e[idx];
            prim.v0.vx = q->f0;
            prim.v0.vy = q->f1;
            prim.v0.vz = q->f2;
            prim.v1.vx = q->f3;
            prim.v1.vy = q->f4;
            prim.v1.vz = q->f5;
            n = n + 1;
            idx = idx - 1;
            prim.c0.r = prim.c1.r = tim;
            prim.c0.g = prim.c1.g = prim.c0.b = prim.c1.b = half;
            if (idx < 0) {
                idx = 15;
            }
            q = &e[idx];
            prim.v2.vx = q->f0;
            prim.v2.vy = q->f1;
            prim.v2.vz = q->f2;
            prim.v3.vx = q->f3;
            prim.v3.vy = q->f4;
            prim.v3.vz = q->f5;
            tim = tim - 0x10;
            half = half - 0x10;
            if (half < 0) {
                half = 0;
            }
            prim.c2.r = prim.c3.r = tim;
            prim.c2.g = prim.c3.g = prim.c2.b = prim.c3.b = half;
            func_80017758(&prim, &blk);
            cnt = cnt - 1;
        } while (cnt != -1);
    }
    return n;
}
