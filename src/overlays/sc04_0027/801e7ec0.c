/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801E7EC0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_801E7EC0(s32 a0, s32 a1) {
    extern u8 D_800B9A15;
    extern unsigned char D_800B9A13;
    extern u16 D_80115110;
    extern void func_801E7F38(void);
    extern s16 D_80115126;
    extern s16 D_801F218C;
    extern s16 D_801F2188;
    extern u16 D_80115112;
    extern void *D_8011DB24;
    extern s32 func_8002D4C8(s32, s32);

    D_800B9A15 = 1;
    D_800B9A13 = 5;
    D_80115110 = 4;
    D_80115126 = (s16)a0;
    D_801F218C = (s16)a1;
    D_801F2188 = (s16)a1;
    D_80115112 = 0;
    D_8011DB24 = func_801E7F38;
    func_8002D4C8(0x1E, 0);
}
