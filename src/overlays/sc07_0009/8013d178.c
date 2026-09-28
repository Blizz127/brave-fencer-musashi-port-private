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

    extern u8 D_801A3C80;
    extern u8 D_801A3C81;
    extern u8 D_801A3C82;
    extern u8 D_801A3C83;
    extern u8 D_801A3C84;
    extern u8 D_801A3C85;
    extern u8 D_801A3C86;
    extern u8 D_801A3C87;
    extern u8 D_801A3C88;
    extern unsigned char D_801A3D20, D_801A3D21, D_801A3D22, D_801A3D23, D_801A3D24, D_801A3D25, D_801A3D26, D_801A3D27, D_801A3D28;
    extern unsigned char D_801A3D20, D_801A3D21, D_801A3D22, D_801A3D23, D_801A3D24, D_801A3D25, D_801A3D26, D_801A3D27, D_801A3D28;
    extern unsigned char D_801A3D20, D_801A3D21, D_801A3D22, D_801A3D23, D_801A3D24, D_801A3D25, D_801A3D26, D_801A3D27, D_801A3D28;
    extern unsigned char D_801A3D20, D_801A3D21, D_801A3D22, D_801A3D23, D_801A3D24, D_801A3D25, D_801A3D26, D_801A3D27, D_801A3D28;
    extern unsigned char D_801A3D20, D_801A3D21, D_801A3D22, D_801A3D23, D_801A3D24, D_801A3D25, D_801A3D26, D_801A3D27, D_801A3D28;
    extern unsigned char D_801A3D20, D_801A3D21, D_801A3D22, D_801A3D23, D_801A3D24, D_801A3D25, D_801A3D26, D_801A3D27, D_801A3D28;
    extern unsigned char D_801A3D20, D_801A3D21, D_801A3D22, D_801A3D23, D_801A3D24, D_801A3D25, D_801A3D26, D_801A3D27, D_801A3D28;
    extern unsigned char D_801A3D20, D_801A3D21, D_801A3D22, D_801A3D23, D_801A3D24, D_801A3D25, D_801A3D26, D_801A3D27, D_801A3D28;
    extern unsigned char D_801A3D20, D_801A3D21, D_801A3D22, D_801A3D23, D_801A3D24, D_801A3D25, D_801A3D26, D_801A3D27, D_801A3D28;
    unsigned char v, t;
    register unsigned char *p __asm__("$5");

    p = &D_801A3C80; v = *p; t = D_801A3D20;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_801A3C81; v = *p; t = D_801A3D21;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_801A3C82; v = *p; t = D_801A3D22;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_801A3C83; v = *p; t = D_801A3D23;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_801A3C84; v = *p; t = D_801A3D24;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_801A3C85; v = *p; t = D_801A3D25;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_801A3C86; v = *p; t = D_801A3D26;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_801A3C87; v = *p; t = D_801A3D27;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_801A3C88; v = *p; t = D_801A3D28;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
}
