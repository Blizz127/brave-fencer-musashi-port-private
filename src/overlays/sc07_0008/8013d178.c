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

    extern u8 D_801965F0;
    extern u8 D_801965F1;
    extern u8 D_801965F2;
    extern u8 D_801965F3;
    extern u8 D_801965F4;
    extern u8 D_801965F5;
    extern u8 D_801965F6;
    extern u8 D_801965F7;
    extern u8 D_801965F8;
    extern unsigned char D_80196690, D_80196691, D_80196692, D_80196693, D_80196694, D_80196695, D_80196696, D_80196697, D_80196698;
    extern unsigned char D_80196690, D_80196691, D_80196692, D_80196693, D_80196694, D_80196695, D_80196696, D_80196697, D_80196698;
    extern unsigned char D_80196690, D_80196691, D_80196692, D_80196693, D_80196694, D_80196695, D_80196696, D_80196697, D_80196698;
    extern unsigned char D_80196690, D_80196691, D_80196692, D_80196693, D_80196694, D_80196695, D_80196696, D_80196697, D_80196698;
    extern unsigned char D_80196690, D_80196691, D_80196692, D_80196693, D_80196694, D_80196695, D_80196696, D_80196697, D_80196698;
    extern unsigned char D_80196690, D_80196691, D_80196692, D_80196693, D_80196694, D_80196695, D_80196696, D_80196697, D_80196698;
    extern unsigned char D_80196690, D_80196691, D_80196692, D_80196693, D_80196694, D_80196695, D_80196696, D_80196697, D_80196698;
    extern unsigned char D_80196690, D_80196691, D_80196692, D_80196693, D_80196694, D_80196695, D_80196696, D_80196697, D_80196698;
    extern unsigned char D_80196690, D_80196691, D_80196692, D_80196693, D_80196694, D_80196695, D_80196696, D_80196697, D_80196698;
    unsigned char v, t;
    register unsigned char *p __asm__("$5");

    p = &D_801965F0; v = *p; t = D_80196690;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_801965F1; v = *p; t = D_80196691;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_801965F2; v = *p; t = D_80196692;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_801965F3; v = *p; t = D_80196693;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_801965F4; v = *p; t = D_80196694;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_801965F5; v = *p; t = D_80196695;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_801965F6; v = *p; t = D_80196696;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_801965F7; v = *p; t = D_80196697;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_801965F8; v = *p; t = D_80196698;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
}
