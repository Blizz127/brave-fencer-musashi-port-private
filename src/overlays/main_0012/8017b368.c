/* Overlay range [8017B368,8017B490) from MAIN.CD member 0012.
 * SHA256(span)=e1492b6030cb4922e05af5c114df0ea60fed240e00a6c6d17eeae33be41994fb.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017B368 - byte-exact against retail at -O2 (tools/register_match.py). */
typedef struct { s16 a, b, c, d; } SV4_8017B368;
typedef struct { SV4_8017B368 x, y; } Pair16;
extern void func_8012F214(s32 a0, s32 a1, s32 a2);

s32 func_8017B368(s32 param)
{

    extern s16 D_8018534C;
    extern s16 D_80185C08;
    extern void func_8017BA3C(s32 param_1, s32 param_2);
    extern void func_8012F214(s32 a0, s32 a1, s32 a2);
    extern SV4_8017B368 D_8018536C;
    extern SV4_8017B368 D_80185374;
    extern s16 D_801853C4;
    extern s16 D_801853BC;
    extern u16 D_80181CC0;

    SV4_8017B368 loc0;
    SV4_8017B368 loc1;
    u32 n = (u32)&D_8018536C;

    ((void (*)(void))func_8017BA3C)();

    if (n >= 0xB) {
        loc0 = *(SV4_8017B368 *)n;
        loc1 = D_80185374;
    } else {
        s32 ax = (s32)&((Pair16 *)&D_80181CC0)[n].x;
        s32 ay = (s32)&((Pair16 *)&D_80181CC0)[n].y;
        func_8012F214(param, ax, (s32)&loc0);
        func_8012F214(param, ay, (s32)&loc1);
    }

    (*(SV4_8017B368 *)&D_801853C4) = loc0;
    (*(SV4_8017B368 *)&D_801853BC) = loc1;
    D_80185C08 = 1;
    D_8018534C = 0;
}
