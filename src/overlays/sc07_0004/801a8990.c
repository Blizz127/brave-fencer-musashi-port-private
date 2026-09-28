/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A8990 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { u16 vx, vy, vz, pad; } SV_801A8990;
typedef struct { s16 m[3][3]; s32 t[3]; } MTX_801A8990;

void func_801A8990(void *a0)
{
    extern void func_80049CAC(s32 a0, s32 a1);
    extern void func_8004914C(void *a0);
    extern void func_800491AC(void *a0);
    extern s32 func_8004787C(s32 a0);
    extern void func_8004945C(s32 a0, s32 a1, void *a2);

    SV_801A8990 vec;   /* sp+0x10 */
    MTX_801A8990 mtx;  /* sp+0x18 */
    MTX_801A8990 *mp;
    s32 flag[3];       /* sp+0x38 */
    s32 v1;
    s32 prod;

    mp = &mtx;
    func_80049CAC(*(s32 *)((s32)a0 + 0x20) + 0x10, (s32)mp);

    mtx.t[0] = *(s16 *)((s32)a0 + 0x104);
    mtx.t[1] = *(s16 *)((s32)a0 + 0x106);
    mtx.t[2] = *(s16 *)((s32)a0 + 0x108);

    func_8004914C(mp);
    func_800491AC(mp);

    vec.vy = 0;
    vec.vx = 0;

    prod = func_8004787C(*(s16 *)((s32)a0 + 0x100));
    v1 = *(s16 *)((s32)a0 + 0xFE);
    vec.vz = v1 + ((v1 * prod) >> 15);

    func_8004945C((s32)&vec, (s32)&vec, &flag[0]);

    *(s16 *)((s32)a0 + 0x6) = vec.vx;
    *(s16 *)((s32)a0 + 0xA) = vec.vy;
    *(s16 *)((s32)a0 + 0xE) = vec.vz;
}
