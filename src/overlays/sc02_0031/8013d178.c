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

    extern u8 D_801B79B8;
    extern u8 D_801B79B9;
    extern u8 D_801B79BA;
    extern u8 D_801B79BB;
    extern u8 D_801B79BC;
    extern u8 D_801B79BD;
    extern u8 D_801B79BE;
    extern u8 D_801B79BF;
    extern u8 D_801B79C0;
    extern unsigned char D_801B7A58, D_801B7A59, D_801B7A5A, D_801B7A5B, D_801B7A5C, D_801B7A5D, D_801B7A5E, D_801B7A5F, D_801B7A60;
    extern unsigned char D_801B7A58, D_801B7A59, D_801B7A5A, D_801B7A5B, D_801B7A5C, D_801B7A5D, D_801B7A5E, D_801B7A5F, D_801B7A60;
    extern unsigned char D_801B7A58, D_801B7A59, D_801B7A5A, D_801B7A5B, D_801B7A5C, D_801B7A5D, D_801B7A5E, D_801B7A5F, D_801B7A60;
    extern unsigned char D_801B7A58, D_801B7A59, D_801B7A5A, D_801B7A5B, D_801B7A5C, D_801B7A5D, D_801B7A5E, D_801B7A5F, D_801B7A60;
    extern unsigned char D_801B7A58, D_801B7A59, D_801B7A5A, D_801B7A5B, D_801B7A5C, D_801B7A5D, D_801B7A5E, D_801B7A5F, D_801B7A60;
    extern unsigned char D_801B7A58, D_801B7A59, D_801B7A5A, D_801B7A5B, D_801B7A5C, D_801B7A5D, D_801B7A5E, D_801B7A5F, D_801B7A60;
    extern unsigned char D_801B7A58, D_801B7A59, D_801B7A5A, D_801B7A5B, D_801B7A5C, D_801B7A5D, D_801B7A5E, D_801B7A5F, D_801B7A60;
    extern unsigned char D_801B7A58, D_801B7A59, D_801B7A5A, D_801B7A5B, D_801B7A5C, D_801B7A5D, D_801B7A5E, D_801B7A5F, D_801B7A60;
    extern unsigned char D_801B7A58, D_801B7A59, D_801B7A5A, D_801B7A5B, D_801B7A5C, D_801B7A5D, D_801B7A5E, D_801B7A5F, D_801B7A60;
    unsigned char v, t;
    register unsigned char *p __asm__("$5");

    p = &D_801B79B8; v = *p; t = D_801B7A58;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_801B79B9; v = *p; t = D_801B7A59;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_801B79BA; v = *p; t = D_801B7A5A;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_801B79BB; v = *p; t = D_801B7A5B;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_801B79BC; v = *p; t = D_801B7A5C;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_801B79BD; v = *p; t = D_801B7A5D;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_801B79BE; v = *p; t = D_801B7A5E;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_801B79BF; v = *p; t = D_801B7A5F;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_801B79C0; v = *p; t = D_801B7A60;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
}
