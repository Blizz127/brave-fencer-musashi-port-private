/* SC02.CD member31 [8014E284,8014E434); exact word export. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014E284 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct EntSC01077 {
    u16 f00;
    u8  pad02[4];
    u16 f06;
    u8  pad08[2];
    u16 f0A;
    u8  pad0C[2];
    u16 f0E;
    u8  pad10[0x10];
    s32 f20;
    u8  pad24[0x34];
    s32 f58;
    u16 f5C;
    u8  pad5E[0xAE];
} EntSC01077;
extern u8 D_801202A0[];
extern s32 func_80135A4C(s32 a0, s32 a1, s32 *a2, s32 a3);
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern s32 func_80012A60(s32 a0, s32 a1);

s32 func_8014E284(s32 a0, s16 *arg1, s16 *arg2) {
    u16 *a1 = (u16 *)arg1;
    u16 *a2 = (u16 *)arg2;
    EntSC01077 *p;
    s16 dx;
    s16 dz;
    s16 ax;
    s16 az;
    s32 r1;
    s32 r2;
    dx = a2[0] - a1[0];
    dz = a2[2] - a1[2];
    if ((s16)(dx | dz) != 0) {
        for (p = (EntSC01077 *)D_801202A0; p < (EntSC01077 *)D_801202A0 + 96; p++) {
            if (p->f00 == 0) continue;
            if (p->f58 == 0) continue;
            if ((p->f5C & 0x1000) == 0) continue;
            /* §17a-1 fn-ptr cast: keep the canonical extern, call with the intended sig. */
            if (((s32 (*)(s32, s32, u16 *, u16 *))func_80135A4C)(p->f20, p->f58, a1, a2) == 0) continue;
            ax = p->f06 - *(u16 *)(a0 + 6);
            az = p->f0E - *(u16 *)(a0 + 0xE);
            r1 = (s16)func_8004CFEC(dz, dx);
            r2 = (s16)func_8004CFEC(az, ax);
            if ((s16)func_80012A60(r1, r2) < 0x400) {
                *(s32 *)(a0 + 0x170) = (s32)p;
                *(u16 *)(a0 + 6) = a2[0];
                *(u16 *)(a0 + 0xA) = a2[1] + 0x10;
                *(u16 *)(a0 + 0xE) = a2[2];
                return 1;
            }
        }
    }
    return 0;
}
