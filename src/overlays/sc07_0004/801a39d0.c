/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A39D0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8004914C(void *a0);
extern void func_800491AC(void *a0);
extern void func_8004945C(s32 a0, s32 a1, void *a2);
typedef struct { s16 vx, vy, vz, pad; } SVec_801A39D0;

void func_801A39D0(s32 param_1)
{
    SVec_801A39D0 sv;
    s32 flag;

    func_8004914C((void *)(*(s32 *)(param_1 + 0x20) + 0x34));
    func_800491AC((void *)(*(s32 *)(param_1 + 0x20) + 0x34));

    sv.vx = 0;
    sv.vy = -0x40;
    sv.vz = 0x30;
    func_8004945C((s32)&sv, (s32)&sv, &flag);

    *(s16 *)(param_1 + 0x06) = *(s32 *)(*(s32 *)(param_1 + 0x20) + 0x48) = sv.vx;
    *(s16 *)(param_1 + 0x0A) = *(s32 *)(*(s32 *)(param_1 + 0x20) + 0x4C) = sv.vy;
    *(s16 *)(param_1 + 0x0E) = *(s32 *)(*(s32 *)(param_1 + 0x20) + 0x50) = sv.vz;
}
