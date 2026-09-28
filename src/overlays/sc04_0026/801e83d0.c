/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801E83D0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80029504(void);
extern s32 func_80184D00(s32);
extern s32 func_80184DD0(void);
extern s32 func_80184E44(void);
extern void func_80184EA0(void);

void func_801E83D0(s32 a0) {

    extern s32 D_801E8C64[];
    extern s32 D_801E8C78[];
    extern s32 D_801E8C94[];

    s32 v1 = func_80029504();

    if (v1 < 0xC8) {
        s32 v0 = ((s32 (*)(void))func_80184D00)();
        *(s32 *)(a0 + 0xE4) = D_801E8C64[v0];
    } else if (v1 < 0x384) {
        s32 v0 = func_80184DD0();
        *(s32 *)(a0 + 0xE4) = D_801E8C78[v0];
    } else {
        s32 v0 = func_80184E44();
        *(s32 *)(a0 + 0xE4) = D_801E8C94[v0];
        func_80184EA0();
    }
}
