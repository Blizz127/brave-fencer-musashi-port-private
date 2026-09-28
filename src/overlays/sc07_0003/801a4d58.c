/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A4D58 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { s16 m[3][3]; s32 t[3]; } Mtx32_801A4D58;
extern void func_8004A0DC(s32 a0, void *a1);
extern void func_800484EC(s32 a0, s32 a1, s32 a2);

void func_801A4D58(s32 a0, s32 a1)
{
    extern u8 D_800AE620[];

    Mtx32_801A4D58 m;
    s32 vel[3];

    m = *(Mtx32_801A4D58 *)&D_800AE620;
    vel[1] = 0;
    vel[0] = 0;
    vel[2] = a1;
    func_8004A0DC(*(s16 *)(*(s32 *)((s32)a0 + 0x20) + 0x14), &m);
    func_800484EC((s32)&m, (s32)&vel[0], a0 + 0x10);
}
