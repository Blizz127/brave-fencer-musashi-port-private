/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801EDC70 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80029504(void);
extern void func_801EDD20(s32 a0, s32 a1);

void func_801EDC70(void) {
    extern s16 D_801F7C18;
    extern u16 D_801F7C10;
    s32 id = func_80029504();

    if ((u32)(id - 5) >= 0x4B5) {
        if (id != 0x6A4) {
            D_801F7C18 = 1;
        } else {
            D_801F7C18 = 2;
        }
    } else {
        D_801F7C18 = 0;
    }
    func_801EDD20(1, D_801F7C18);
    {
        u16 *p = &D_801F7C10;
        (*p)++;
    }
}
