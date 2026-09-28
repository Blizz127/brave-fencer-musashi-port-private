/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016B6BC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct {
    int m0;
    int m1;
} M8_8016B6BC;
typedef struct {
    short x;
    short y;
} DVec_8016B6BC;
typedef struct {
    short x;   /* +0x0 */
    short y;   /* +0x2 */
    short c;   /* +0x4 */
    short pad; /* +0x6 */
} Vtx_8016B6BC;
typedef struct {
    Vtx_8016B6BC v[3];       /* +0x00 +0x08 +0x10 */
    unsigned long combined;  /* +0x18 */
    unsigned long z1c;       /* +0x1c */
    unsigned long z20;       /* +0x20 */
    unsigned long color;     /* +0x24 */
} Prim_8016B6BC;
extern void func_80013CFC(s32 a0, s32 a1, void *a2);
extern void func_80015978(s32 a0, s32 *a1);
extern void func_8001739C(void *a0);
extern void func_8012A568(void (*a0)(void));

void func_8016B6BC(s32 param_1, s32 param_2, s32 param_3, s32 param_4) {

    extern int D_80181DCC;
    int iVar1;
    M8_8016B6BC *q;
    Prim_8016B6BC prim;
    Prim_8016B6BC *p = &prim;
    DVec_8016B6BC off;
    unsigned int v;
    unsigned int c;

    q = (M8_8016B6BC *)*(int *)((int)&D_80181DCC + ((param_4 << 0x10) >> 0xe));
    p->color = 0x50000000;
    c = (unsigned int)param_2;
    v = 0x20;
    if (c < 0x20) {
        v = c;
    }
    if (*(int *)(param_1 + 0x2c) == 0) {
        c = c | (v << 0x10 | v << 8);
    } else {
        c = c << 8 | v << 0x10 | v;
    }
    p->combined = c;
    iVar1 = (int)(short)param_3;
    p->z1c = 0;
    p->z20 = 0;
    func_80013CFC(iVar1, (int)q++, &p->v[0]);
    func_80013CFC(iVar1, (int)q++, &p->v[1]);
    func_80013CFC(iVar1, (int)q, &p->v[2]);
    func_80015978(param_1 + 4, (s32 *)&off);
    p->v[0].x += off.x;
    p->v[0].y += off.y;
    p->v[1].x += off.x;
    p->v[1].y += off.y;
    p->v[2].x += off.x;
    p->v[2].y += off.y;
    p->v[0].c = 3;
    func_8001739C(p);
}
