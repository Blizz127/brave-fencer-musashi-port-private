/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A5CE8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { s16 vx, vy, vz, pad; } SVec_801A5CE8;
extern void func_8004914C(void *a0);
extern void func_800491AC(void *a0);
extern void func_8004945C(s32 a0, s32 a1, void *a2);
extern u16 D_801F885C;
extern u8 D_801F88A8[];
extern u8 D_801F88B0[];

void func_801A5CE8(void *a0)
{
    SVec_801A5CE8 in;
    SVec_801A5CE8 out;

    func_8004914C((void *)(*(s32 *)((u8 *)a0 + 0x20) + 0x34));
    func_800491AC((void *)(*(s32 *)((u8 *)a0 + 0x20) + 0x34));

    in.vz = 0;
    in.vy = 0;
    in.vx = 0;
    func_8004945C((s32)&in, (s32)D_801F88A8, &out);

    in.vy = D_801F885C;
    func_8004945C((s32)&in, (s32)D_801F88B0, &out);
}
