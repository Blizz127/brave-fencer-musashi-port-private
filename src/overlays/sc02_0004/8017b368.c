/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017B368 - byte-exact against retail at -O2 (tools/register_match.py). */
typedef struct { s16 a, b, c, d; } SV4_8017B368;
typedef struct { SV4_8017B368 x, y; } Pair16_8017B368;
extern s16 D_80196350;
extern s16 D_801961B4;

s32 func_8017B368(s32 param)
{
    extern void func_8017BA3C(s32 param_1, s32 param_2);
    extern void func_8012F214(s32 a0, s32 a1, s32 a2);
    extern SV4_8017B368 D_801961D4;
    extern SV4_8017B368 D_801961DC;
    extern s16 D_8019622C;
    extern s16 D_80196224;
    extern u16 D_8018161C;

    SV4_8017B368 loc0;
    SV4_8017B368 loc1;
    u32 n = (u32)&D_801961D4;

    ((void (*)(void))func_8017BA3C)();

    if (n >= 0xB) {
        loc0 = *(SV4_8017B368 *)n;
        loc1 = D_801961DC;
    } else {
        s32 ax = (s32)&((Pair16_8017B368 *)&D_8018161C)[n].x;
        s32 ay = (s32)&((Pair16_8017B368 *)&D_8018161C)[n].y;
        func_8012F214(param, ax, (s32)&loc0);
        func_8012F214(param, ay, (s32)&loc1);
    }

    (*(SV4_8017B368 *)&D_8019622C) = loc0;
    (*(SV4_8017B368 *)&D_80196224) = loc1;
    D_80196350 = 1;
    D_801961B4 = 0;
}
