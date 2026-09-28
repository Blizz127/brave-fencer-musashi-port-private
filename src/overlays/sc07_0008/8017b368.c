/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017B368 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { s16 a, b, c, d; } SV4_8017B368;
typedef struct { SV4_8017B368 x, y; } Pair16_8017B368;
extern void func_8012A568(void (*a0)(void));
extern s16 D_80196534;
extern s16 D_801966D0;

s32 func_8017B368(s32 param)
{
    extern void func_8017BA3C(s32 param_1, s32 param_2);
    extern void func_8012F214(s32 a0, s32 a1, s32 a2);
    extern SV4_8017B368 D_80196554;
    extern SV4_8017B368 D_8019655C;
    extern s16 D_801965AC;
    extern s16 D_801965A4;
    extern u16 D_80180C40;

    SV4_8017B368 loc0;
    SV4_8017B368 loc1;
    u32 n = (u32)&D_80196554;

    ((void (*)(void))func_8017BA3C)();

    if (n >= 0xB) {
        loc0 = *(SV4_8017B368 *)n;
        loc1 = D_8019655C;
    } else {
        s32 ax = (s32)&((Pair16_8017B368 *)&D_80180C40)[n].x;
        s32 ay = (s32)&((Pair16_8017B368 *)&D_80180C40)[n].y;
        func_8012F214(param, ax, (s32)&loc0);
        func_8012F214(param, ay, (s32)&loc1);
    }

    (*(SV4_8017B368 *)&D_801965AC) = loc0;
    (*(SV4_8017B368 *)&D_801965A4) = loc1;
    D_801966D0 = 1;
    D_80196534 = 0;
}
