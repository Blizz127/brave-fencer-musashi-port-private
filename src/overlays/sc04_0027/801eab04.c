/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801EAB04 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80029504(void);
extern s32 func_80029178(s32 arg);

void func_801EAB04(void) {
    extern s32 D_801E7AAC;
    extern s32 D_801EBE24;
    extern s32 D_801EBE58;
    s32 r;
    s32 v;

    r = func_80029504();
    v = ((u32)(r - 0xC8) < 0x64) ? 0 :
        ((r < 0x12C) ? 1 :
         (((func_80029178(0xFA) & 0xFF) == 0) ? ({ __asm__ __volatile__("" ::: "memory"); 1; }) : 0));
    if (v) {
        *(s32 *)(D_801E7AAC + 4) = (s32)&D_801EBE24;
    } else {
        *(s32 *)(D_801E7AAC + 4) = (s32)&D_801EBE58;
    }
}
