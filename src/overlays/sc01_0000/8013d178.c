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

    extern u8 D_801A5790;
    extern u8 D_801A5791;
    extern u8 D_801A5792;
    extern u8 D_801A5793;
    extern u8 D_801A5794;
    extern u8 D_801A5795;
    extern u8 D_801A5796;
    extern u8 D_801A5797;
    extern u8 D_801A5798;
    extern unsigned char D_801A5830, D_801A5831, D_801A5832, D_801A5833, D_801A5834, D_801A5835, D_801A5836, D_801A5837, D_801A5838;
    extern unsigned char D_801A5830, D_801A5831, D_801A5832, D_801A5833, D_801A5834, D_801A5835, D_801A5836, D_801A5837, D_801A5838;
    extern unsigned char D_801A5830, D_801A5831, D_801A5832, D_801A5833, D_801A5834, D_801A5835, D_801A5836, D_801A5837, D_801A5838;
    extern unsigned char D_801A5830, D_801A5831, D_801A5832, D_801A5833, D_801A5834, D_801A5835, D_801A5836, D_801A5837, D_801A5838;
    extern unsigned char D_801A5830, D_801A5831, D_801A5832, D_801A5833, D_801A5834, D_801A5835, D_801A5836, D_801A5837, D_801A5838;
    extern unsigned char D_801A5830, D_801A5831, D_801A5832, D_801A5833, D_801A5834, D_801A5835, D_801A5836, D_801A5837, D_801A5838;
    extern unsigned char D_801A5830, D_801A5831, D_801A5832, D_801A5833, D_801A5834, D_801A5835, D_801A5836, D_801A5837, D_801A5838;
    extern unsigned char D_801A5830, D_801A5831, D_801A5832, D_801A5833, D_801A5834, D_801A5835, D_801A5836, D_801A5837, D_801A5838;
    extern unsigned char D_801A5830, D_801A5831, D_801A5832, D_801A5833, D_801A5834, D_801A5835, D_801A5836, D_801A5837, D_801A5838;
    unsigned char v, t;
    register unsigned char *p __asm__("$5");

    p = &D_801A5790; v = *p; t = D_801A5830;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_801A5791; v = *p; t = D_801A5831;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_801A5792; v = *p; t = D_801A5832;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_801A5793; v = *p; t = D_801A5833;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_801A5794; v = *p; t = D_801A5834;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_801A5795; v = *p; t = D_801A5835;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_801A5796; v = *p; t = D_801A5836;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_801A5797; v = *p; t = D_801A5837;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_801A5798; v = *p; t = D_801A5838;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
}
