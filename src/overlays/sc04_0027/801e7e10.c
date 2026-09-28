/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801E7E10 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80029504(void);

void func_801E7E10(void) {

    extern s16 D_801F1D90;
    extern u16 D_801F1D88;
    extern void func_801E7EC0(s32, s32);
    s32 v1;
    u16 *p;

    v1 = func_80029504();
    if ((u32)(v1 - 5) >= 0x4B5) {
        if (v1 != 0x6A4) {
            D_801F1D90 = 1;
        } else {
            D_801F1D90 = 2;
        }
    } else {
        D_801F1D90 = 0;
    }
    func_801E7EC0(1, D_801F1D90);
    p = &D_801F1D88;
    *p = *p + 1;
}
