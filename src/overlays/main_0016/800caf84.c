/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CAF84 - byte-exact against retail at -O2 (tools/register_match.py). */
#define RotMatrixYXZ func_80049A1C
typedef struct { s16 vx, vy, vz, pad; } SVecX;
typedef struct { u8 r, g, b, cd; } CVecX;
typedef struct { SVecX v[4]; CVecX c[4]; s32 code; s32 pad2; } PrimX;
typedef struct { s16 m[3][3]; s32 t[3]; } MtxX;
extern void func_80017DC4(void *a0, void *a1);
extern void func_8012F14C(void *a0, void *a1, void *a2);
extern void func_800D20C0(void *a0, void *a1, s32 a2);
extern void func_800D23D0(void *a0);
extern void func_80017E68(void *a0, void *a1);
extern void RotMatrixYXZ(void *a0, void *a1);
extern void func_80048D9C(void *a0, void *a1);
extern void func_80017758(void *a0, void *a1);
extern u8 D_800CB528[];

void func_800CAF84(arg0) void *arg0; {
    SVecX sv;
    SVecX rot;
    PrimX prim;
    MtxX m1;
    MtxX m2;
    u8 *p;
    s16 i;

    sv.vx = sv.vy = sv.vz = *(u16 *)((u8 *)arg0 + 0x28);
    func_80017DC4(&sv, &m1);

    sv.vx = sv.vz = 0;
    sv.vy = -0x2C;
    func_8012F14C((u8 *)arg0 + 0x38, &sv, &sv);

    func_800D20C0(&sv, &rot, 5);
    func_800D23D0(&rot);

    prim.v[1].vx = prim.v[1].vy = prim.v[1].vz = 0;
    prim.v[0].vz = prim.v[2].vz = prim.v[3].vz = 0;
    prim.c[1].b = ((s16)*(u16 *)((u8 *)arg0 + 0x28) >> 6) + 0x70;
    prim.c[1].r = prim.c[1].g = 0;
    prim.c[0].r = prim.c[0].g = prim.c[0].b = 0;
    prim.c[2].r = prim.c[2].g = prim.c[2].b = 0;
    prim.c[3].r = prim.c[3].g = prim.c[3].b = 0;
    prim.code = 0x50000000;
    func_80017E68(&sv, &m1);

    RotMatrixYXZ(&rot, &m2);
    func_80048D9C(&m1, &m2);

    p = D_800CB528;
    for (i = 0; i < 4; i++) {
        prim.v[0].vx = (s8)*p++;
        prim.v[0].vy = (s8)*p++;
        prim.v[2].vx = (s8)*p++;
        prim.v[2].vy = (s8)*p++;
        prim.v[3].vx = (s8)*p++;
        prim.v[3].vy = (s8)*p++;
        p -= 2;
        func_80017758(&prim, &m1);
    }
}
