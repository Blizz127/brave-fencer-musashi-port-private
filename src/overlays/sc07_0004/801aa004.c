/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801AA004 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { s32 w[8]; } Mtx32_801A90D8;
typedef struct { s32 vx, vy, vz; } Vec32_801AA004;
extern Mtx32_801A90D8 D_800AE620;
extern void func_8004A0DC(s32 a0, void *a1);
extern void func_800484EC(s32 a0, s32 a1, s32 a2);

void func_801AA004(void *arg0, void *arg1)
{
    Vec32_801AA004 off;

    *(Mtx32_801A90D8 *)arg1 = D_800AE620;
    func_8004A0DC(-*(s16 *)(*(s32 *)((s32)arg0 + 0x20) + 0x14), arg1);
    off.vy = 0;
    off.vx = 0;
    off.vz = 0xFFE40000;
    func_800484EC((s32)arg1, (s32)&off, (s32)arg0 + 0x10);
}
