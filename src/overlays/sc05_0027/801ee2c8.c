/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801EE2C8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80029504(void);
extern s32 func_80184AD0(void);
extern s32 func_80184B44(void);
extern void func_80184BA0(void);

void func_801EE2C8(s32 a0) {

    extern s32 D_801EE718[];
    extern s32 D_801EE72C[];
    extern s32 D_801EE748[];

    s32 v1 = func_80029504();

    if (v1 < 0xC8) {
        extern s32 D_801F5994;
        s32 t = D_801F5994;
        s32 idx;

        if (t < 0x14) {
            idx = 0;
        } else if (t < 0x46) {
            idx = 1;
        } else if (t < 0x64) {
            idx = 2;
        } else if (t < 0x82) {
            idx = 3;
        } else {
            idx = 4;
        }
        *(s32 *)(a0 + 0xE4) = D_801EE718[idx];
    } else if (v1 < 0x384) {
        s32 v0 = func_80184AD0();
        *(s32 *)(a0 + 0xE4) = D_801EE72C[v0];
    } else {
        s32 v0 = func_80184B44();
        *(s32 *)(a0 + 0xE4) = D_801EE748[v0];
        func_80184BA0();
    }
}
