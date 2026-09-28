/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801AACD4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8004945C(s32 a0, s32 a1, void *a2);
extern void func_800491AC(void *a0);
extern void func_8004914C(void *a0);
typedef struct { s16 vx, vy, vz, pad; } SV_801AACD4;
typedef struct { s16 m[3][3]; s32 t[3]; } MTX_801AACD4;

void func_801AACD4(void *a0, void *a1, u32 a2, s32 a3)
{
    extern void func_80049CAC(s32 a0, s32 a1);
    extern void func_801AADA8(s32 a0, s32 a1, s32 a2);

    MTX_801AACD4 mtx;    /* sp+0x10 */
    SV_801AACD4 sv;      /* sp+0x30 */
    s32 flag;            /* sp+0x38 */

    func_80049CAC((s32)a1, (s32)&mtx);
    mtx.t[0] = *(s16 *)((u8 *)a0 + 0);
    mtx.t[1] = *(s16 *)((u8 *)a0 + 2);
    mtx.t[2] = *(s16 *)((u8 *)a0 + 4);
    func_8004914C(&mtx);
    func_800491AC(&mtx);
    sv.vy = 0;
    sv.vx = 0;
    sv.vz = -a2;
    func_8004945C((s32)&sv, (s32)&sv, &flag);
    func_801AADA8((s32)a0, (s32)&sv, a3);
    *(SV_801AACD4 *)a0 = sv;
}
