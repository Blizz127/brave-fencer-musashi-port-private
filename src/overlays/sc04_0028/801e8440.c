/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801E8440 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80029504(void);

void func_801E8440(s32 a0) {

    extern s32 D_801E8890[];
    extern s32 D_801E88A4[];
    extern s32 D_801E88C0[];
    extern s32 D_801EFB0C;
    extern s32 func_80184DD0(void);
    extern s32 func_80184E44(void);
    extern void func_80184EA0(void);

    s32 v1 = func_80029504();

    if (v1 < 0xC8) {
        s32 idx;

        if (D_801EFB0C < 20) {
            idx = 0;
        } else if (D_801EFB0C < 70) {
            idx = 1;
        } else if (D_801EFB0C < 100) {
            idx = 2;
        } else if (D_801EFB0C < 130) {
            idx = 3;
        } else {
            idx = 4;
        }
        *(s32 *)(a0 + 0xE4) = D_801E8890[idx];
    } else if (v1 < 0x384) {
        *(s32 *)(a0 + 0xE4) = D_801E88A4[func_80184DD0()];
    } else {
        *(s32 *)(a0 + 0xE4) = D_801E88C0[func_80184E44()];
        func_80184EA0();
    }
}
