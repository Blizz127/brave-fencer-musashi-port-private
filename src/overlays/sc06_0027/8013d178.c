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

    extern u8 D_8019D2D8;
    extern u8 D_8019D2D9;
    extern u8 D_8019D2DA;
    extern u8 D_8019D2DB;
    extern u8 D_8019D2DC;
    extern u8 D_8019D2DD;
    extern u8 D_8019D2DE;
    extern u8 D_8019D2DF;
    extern u8 D_8019D2E0;
    extern unsigned char D_8019D378, D_8019D379, D_8019D37A, D_8019D37B, D_8019D37C, D_8019D37D, D_8019D37E, D_8019D37F, D_8019D380;
    extern unsigned char D_8019D378, D_8019D379, D_8019D37A, D_8019D37B, D_8019D37C, D_8019D37D, D_8019D37E, D_8019D37F, D_8019D380;
    extern unsigned char D_8019D378, D_8019D379, D_8019D37A, D_8019D37B, D_8019D37C, D_8019D37D, D_8019D37E, D_8019D37F, D_8019D380;
    extern unsigned char D_8019D378, D_8019D379, D_8019D37A, D_8019D37B, D_8019D37C, D_8019D37D, D_8019D37E, D_8019D37F, D_8019D380;
    extern unsigned char D_8019D378, D_8019D379, D_8019D37A, D_8019D37B, D_8019D37C, D_8019D37D, D_8019D37E, D_8019D37F, D_8019D380;
    extern unsigned char D_8019D378, D_8019D379, D_8019D37A, D_8019D37B, D_8019D37C, D_8019D37D, D_8019D37E, D_8019D37F, D_8019D380;
    extern unsigned char D_8019D378, D_8019D379, D_8019D37A, D_8019D37B, D_8019D37C, D_8019D37D, D_8019D37E, D_8019D37F, D_8019D380;
    extern unsigned char D_8019D378, D_8019D379, D_8019D37A, D_8019D37B, D_8019D37C, D_8019D37D, D_8019D37E, D_8019D37F, D_8019D380;
    extern unsigned char D_8019D378, D_8019D379, D_8019D37A, D_8019D37B, D_8019D37C, D_8019D37D, D_8019D37E, D_8019D37F, D_8019D380;
    unsigned char v, t;
    register unsigned char *p __asm__("$5");

    p = &D_8019D2D8; v = *p; t = D_8019D378;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_8019D2D9; v = *p; t = D_8019D379;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_8019D2DA; v = *p; t = D_8019D37A;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_8019D2DB; v = *p; t = D_8019D37B;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_8019D2DC; v = *p; t = D_8019D37C;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_8019D2DD; v = *p; t = D_8019D37D;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_8019D2DE; v = *p; t = D_8019D37E;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_8019D2DF; v = *p; t = D_8019D37F;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_8019D2E0; v = *p; t = D_8019D380;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
}
