/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017B490 - byte-exact against retail at -O2 (tools/register_match.py). */
typedef struct { s16 a, b, c, d; } SV4_8017B368;
typedef struct { SV4_8017B368 x, y; } Pair16;
extern s32 D_80126990;
extern s32 D_80126994;
extern s16 D_80190628;
extern s16 D_8019028C;

s32 func_8017B490(s32 param)
{
    extern void func_8017BA3C(s32 param_1, s32 param_2);
    extern void func_8012F214(s32 a0, s32 a1, s32 a2);
    extern SV4_8017B368 D_801902AC;
    extern SV4_8017B368 D_801902B4;
    extern s16 D_80190304;
    extern s16 D_801902FC;
    extern u16 D_80181B84;
    extern s16 D_8019028C;
    extern s16 D_80190628;
    extern s32 D_80126984;
    extern s32 D_80126988;
    extern s32 D_8012698C;
    extern s32 D_80126990;
    extern s32 D_80126994;
    extern s32 D_80126998;

    SV4_8017B368 loc0;
    SV4_8017B368 loc1;
    u32 n = (u32)&D_801902AC;

    ((void (*)(void))func_8017BA3C)();

    if (n >= 0xB) {
        loc0 = *(SV4_8017B368 *)n;
        loc1 = D_801902B4;
    } else {
        s32 ax = (s32)&((Pair16 *)&D_80181B84)[n].x;
        s32 ay = (s32)&((Pair16 *)&D_80181B84)[n].y;
        func_8012F214(param, ax, (s32)&loc0);
        func_8012F214(param, ay, (s32)&loc1);
    }

    (*(SV4_8017B368 *)&D_80190304) = loc0;
    (*(SV4_8017B368 *)&D_801902FC) = loc1;
    D_80190628 = 1;
    D_8019028C = 0x1E;
    D_80126990 = (*(SV4_8017B368 *)&D_80190304).a;
    D_80126994 = (*(SV4_8017B368 *)&D_80190304).b;
    D_80126998 = (*(SV4_8017B368 *)&D_80190304).c;
    D_80126984 = (*(SV4_8017B368 *)&D_801902FC).a;
    D_80126988 = (*(SV4_8017B368 *)&D_801902FC).b;
    D_8012698C = (*(SV4_8017B368 *)&D_801902FC).c;
}
