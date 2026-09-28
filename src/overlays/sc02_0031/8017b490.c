/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017B490 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { s16 a, b, c, d; } SV4_8017B368;
typedef struct { SV4_8017B368 x, y; } Pair16;
extern void func_8012A568(void (*a0)(void));

s32 func_8017B490(s32 param)
{
    extern void func_8017BA3C(s32 param_1, s32 param_2);
    extern void func_8012F214(s32 a0, s32 a1, s32 a2);
    extern SV4_8017B368 D_801B7524;
    extern SV4_8017B368 D_801B752C;
    extern s16 D_801B757C;
    extern s16 D_801B7574;
    extern u16 D_801885B0;
    extern s16 D_801B7504;
    extern s16 D_801B7A98;
    extern s32 D_80126984;
    extern s32 D_80126988;
    extern s32 D_8012698C;
    extern s32 D_80126990;
    extern s32 D_80126994;
    extern s32 D_80126998;

    SV4_8017B368 loc0;
    SV4_8017B368 loc1;
    u32 n = (u32)&D_801B7524;

    ((void (*)(void))func_8017BA3C)();

    if (n >= 0xB) {
        loc0 = *(SV4_8017B368 *)n;
        loc1 = D_801B752C;
    } else {
        s32 ax = (s32)&((Pair16 *)&D_801885B0)[n].x;
        s32 ay = (s32)&((Pair16 *)&D_801885B0)[n].y;
        func_8012F214(param, ax, (s32)&loc0);
        func_8012F214(param, ay, (s32)&loc1);
    }

    (*(SV4_8017B368 *)&D_801B757C) = loc0;
    (*(SV4_8017B368 *)&D_801B7574) = loc1;
    D_801B7A98 = 1;
    D_801B7504 = 0x1E;
    D_80126990 = (*(SV4_8017B368 *)&D_801B757C).a;
    D_80126994 = (*(SV4_8017B368 *)&D_801B757C).b;
    D_80126998 = (*(SV4_8017B368 *)&D_801B757C).c;
    D_80126984 = (*(SV4_8017B368 *)&D_801B7574).a;
    D_80126988 = (*(SV4_8017B368 *)&D_801B7574).b;
    D_8012698C = (*(SV4_8017B368 *)&D_801B7574).c;
}
