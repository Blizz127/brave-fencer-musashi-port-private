/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A5698 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { s32 w[8]; } Mtx32_801A90D8;
typedef struct { s16 m[3][3]; s32 t[3]; } Mtx32_801A5698;
typedef struct { s16 vx, vy, vz, pad; } SVec_801A5698;
extern void func_8004A0DC(s32 a0, void *a1);
extern void func_8004914C(void *a0);
extern void func_800491AC(void *a0);
extern void func_8004945C(s32 a0, s32 a1, void *a2);
extern Mtx32_801A90D8 D_800AE620;
extern s16 D_80126B5E;
extern s16 D_80126B62;
extern s16 D_80126B66;

void func_801A5698(u8 *s2, s32 a1)
{
    Mtx32_801A5698 mtx;
    SVec_801A5698 sv;
    s32 flag;
    s32 angle;

    mtx = *(Mtx32_801A5698 *)&D_800AE620;
    mtx.t[0] = D_80126B5E;
    mtx.t[1] = D_80126B62;
    mtx.t[2] = D_80126B66;

    angle = (s16)a1 + *(s16 *)(*(s32 *)(s2 + 0x64) + 0x102);
    func_8004A0DC(angle, &mtx);

    sv.vy = 0;
    sv.vx = 0;
    sv.vz = 0x1A0;
    func_8004914C(&mtx);
    func_800491AC(&mtx);

    func_8004945C((s32)&sv, (s32)&sv, &flag);

    *(u16 *)(s2 + 0x6) = sv.vx;
    *(u16 *)(s2 + 0xE) = sv.vz;
}
