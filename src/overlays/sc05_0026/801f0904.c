/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801F0904 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_801F0904(void) {

    extern s32 func_80029504(void);
    extern s32 func_80029178(s32);
    extern s32 D_801ED90C;
    extern u8 D_801F1BD8[];
    extern u8 D_801F1C18[];

    s32 r;
    s32 f;

    r = func_80029504();

    if ((u32)(r - 0xC8) < 0x64U) {
        f = 0;
    } else if (r < 0x12C || (func_80029178(0xFA) & 0xFF) == 0) {
        f = 1;
    } else {
        f = 0;
    }

    if (f != 0) {
        *(s32 *)(D_801ED90C + 4) = (s32)D_801F1BD8;
    } else {
        *(s32 *)(D_801ED90C + 4) = (s32)D_801F1C18;
    }
}
