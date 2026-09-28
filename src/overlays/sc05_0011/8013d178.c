/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8013D178 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_8013D178(void) {

    extern u8 D_8019D088;
    extern u8 D_8019D089;
    extern u8 D_8019D08A;
    extern u8 D_8019D08B;
    extern u8 D_8019D08C;
    extern u8 D_8019D08D;
    extern u8 D_8019D08E;
    extern u8 D_8019D08F;
    extern u8 D_8019D090;
    extern unsigned char D_8019D128, D_8019D129, D_8019D12A, D_8019D12B, D_8019D12C, D_8019D12D, D_8019D12E, D_8019D12F, D_8019D130;
    extern unsigned char D_8019D128, D_8019D129, D_8019D12A, D_8019D12B, D_8019D12C, D_8019D12D, D_8019D12E, D_8019D12F, D_8019D130;
    extern unsigned char D_8019D128, D_8019D129, D_8019D12A, D_8019D12B, D_8019D12C, D_8019D12D, D_8019D12E, D_8019D12F, D_8019D130;
    extern unsigned char D_8019D128, D_8019D129, D_8019D12A, D_8019D12B, D_8019D12C, D_8019D12D, D_8019D12E, D_8019D12F, D_8019D130;
    extern unsigned char D_8019D128, D_8019D129, D_8019D12A, D_8019D12B, D_8019D12C, D_8019D12D, D_8019D12E, D_8019D12F, D_8019D130;
    extern unsigned char D_8019D128, D_8019D129, D_8019D12A, D_8019D12B, D_8019D12C, D_8019D12D, D_8019D12E, D_8019D12F, D_8019D130;
    extern unsigned char D_8019D128, D_8019D129, D_8019D12A, D_8019D12B, D_8019D12C, D_8019D12D, D_8019D12E, D_8019D12F, D_8019D130;
    extern unsigned char D_8019D128, D_8019D129, D_8019D12A, D_8019D12B, D_8019D12C, D_8019D12D, D_8019D12E, D_8019D12F, D_8019D130;
    extern unsigned char D_8019D128, D_8019D129, D_8019D12A, D_8019D12B, D_8019D12C, D_8019D12D, D_8019D12E, D_8019D12F, D_8019D130;
    unsigned char v, t;
    register unsigned char *p __asm__("$5");

    p = &D_8019D088; v = *p; t = D_8019D128;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_8019D089; v = *p; t = D_8019D129;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_8019D08A; v = *p; t = D_8019D12A;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_8019D08B; v = *p; t = D_8019D12B;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_8019D08C; v = *p; t = D_8019D12C;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_8019D08D; v = *p; t = D_8019D12D;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_8019D08E; v = *p; t = D_8019D12E;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_8019D08F; v = *p; t = D_8019D12F;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_8019D090; v = *p; t = D_8019D130;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
}
