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

    extern u8 D_8019AAB0;
    extern u8 D_8019AAB1;
    extern u8 D_8019AAB2;
    extern u8 D_8019AAB3;
    extern u8 D_8019AAB4;
    extern u8 D_8019AAB5;
    extern u8 D_8019AAB6;
    extern u8 D_8019AAB7;
    extern u8 D_8019AAB8;
    extern unsigned char D_8019AB50, D_8019AB51, D_8019AB52, D_8019AB53, D_8019AB54, D_8019AB55, D_8019AB56, D_8019AB57, D_8019AB58;
    extern unsigned char D_8019AB50, D_8019AB51, D_8019AB52, D_8019AB53, D_8019AB54, D_8019AB55, D_8019AB56, D_8019AB57, D_8019AB58;
    extern unsigned char D_8019AB50, D_8019AB51, D_8019AB52, D_8019AB53, D_8019AB54, D_8019AB55, D_8019AB56, D_8019AB57, D_8019AB58;
    extern unsigned char D_8019AB50, D_8019AB51, D_8019AB52, D_8019AB53, D_8019AB54, D_8019AB55, D_8019AB56, D_8019AB57, D_8019AB58;
    extern unsigned char D_8019AB50, D_8019AB51, D_8019AB52, D_8019AB53, D_8019AB54, D_8019AB55, D_8019AB56, D_8019AB57, D_8019AB58;
    extern unsigned char D_8019AB50, D_8019AB51, D_8019AB52, D_8019AB53, D_8019AB54, D_8019AB55, D_8019AB56, D_8019AB57, D_8019AB58;
    extern unsigned char D_8019AB50, D_8019AB51, D_8019AB52, D_8019AB53, D_8019AB54, D_8019AB55, D_8019AB56, D_8019AB57, D_8019AB58;
    extern unsigned char D_8019AB50, D_8019AB51, D_8019AB52, D_8019AB53, D_8019AB54, D_8019AB55, D_8019AB56, D_8019AB57, D_8019AB58;
    extern unsigned char D_8019AB50, D_8019AB51, D_8019AB52, D_8019AB53, D_8019AB54, D_8019AB55, D_8019AB56, D_8019AB57, D_8019AB58;
    unsigned char v, t;
    register unsigned char *p __asm__("$5");

    p = &D_8019AAB0; v = *p; t = D_8019AB50;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_8019AAB1; v = *p; t = D_8019AB51;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_8019AAB2; v = *p; t = D_8019AB52;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_8019AAB3; v = *p; t = D_8019AB53;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_8019AAB4; v = *p; t = D_8019AB54;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_8019AAB5; v = *p; t = D_8019AB55;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_8019AAB6; v = *p; t = D_8019AB56;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_8019AAB7; v = *p; t = D_8019AB57;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_8019AAB8; v = *p; t = D_8019AB58;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
}
