/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016E7C8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { short m[3][3]; short pad; s32 t[3]; } MATRIX_8016E7C8;
typedef struct { short vx, vy, vz, pad; } SVECTOR_8016E7C8;
extern s32  func_80017DC4(void *a0, void *a1);
typedef struct {
    SVECTOR_8016E7C8 v[4];               /* 0x00 */
    s32 f0, f1, f2, f3, f4, f5; /* 0x20..0x37 */
    u8  f6;                     /* 0x38 */
    u8  pad[7];                 /* -> 0x40 */
} Prim_8016E7C8;
extern void func_8012A568(void (*a0)(void));

void func_8016E7C8(int param_1, short *param_2, unsigned int *param_3)
{
    extern void func_8004914C(void *a0);
    extern void func_800491AC(void *a0);
    extern void func_8004945C(void *a0, void *a1, void *a2);
    extern void func_80016ED4(void *a0);
    extern SVECTOR_8016E7C8 D_80181F54[4];
    extern s32 D_80181F74;
    extern s32 D_80181F7C;
    extern s32 D_80181F84;
    extern s32 D_80181F8C;

    Prim_8016E7C8 prim;
    MATRIX_8016E7C8 m;
    SVECTOR_8016E7C8 tmp;
    register Prim_8016E7C8 *pp __asm__("$18");   /* $s2 — force &prim into a saved reg */

    ((void (*)(void *, void *))func_80017DC4)(param_2, &m);
    m.t[0] = *(short *)(param_1 + 6);
    m.t[1] = *(short *)(param_1 + 10);
    m.t[2] = *(short *)(param_1 + 14);
    func_8004914C(&m);
    func_800491AC(&m);
    pp = &prim;
    func_8004945C(&D_80181F54[0], pp, &tmp);
    func_8004945C(&D_80181F54[1], &prim.v[1], &tmp);
    func_8004945C(&D_80181F54[2], &prim.v[2], &tmp);
    func_8004945C(&D_80181F54[3], &prim.v[3], &tmp);
    prim.v[0].vz = 3;
    prim.f5 = 0x50000000;
    prim.f0 = D_80181F74;
    prim.f1 = D_80181F7C;
    prim.f2 = D_80181F84;
    prim.f3 = D_80181F8C;
    prim.f4 = *param_3;
    prim.f6 = 0x27;
    func_80016ED4(pp);
}
