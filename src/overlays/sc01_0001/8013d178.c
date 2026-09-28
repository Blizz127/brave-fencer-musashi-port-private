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

    extern u8 D_801F3070;
    extern u8 D_801F3071;
    extern u8 D_801F3072;
    extern u8 D_801F3073;
    extern u8 D_801F3074;
    extern u8 D_801F3075;
    extern u8 D_801F3076;
    extern u8 D_801F3077;
    extern u8 D_801F3078;
    extern unsigned char D_801F3110, D_801F3111, D_801F3112, D_801F3113, D_801F3114, D_801F3115, D_801F3116, D_801F3117, D_801F3118;
    extern unsigned char D_801F3110, D_801F3111, D_801F3112, D_801F3113, D_801F3114, D_801F3115, D_801F3116, D_801F3117, D_801F3118;
    extern unsigned char D_801F3110, D_801F3111, D_801F3112, D_801F3113, D_801F3114, D_801F3115, D_801F3116, D_801F3117, D_801F3118;
    extern unsigned char D_801F3110, D_801F3111, D_801F3112, D_801F3113, D_801F3114, D_801F3115, D_801F3116, D_801F3117, D_801F3118;
    extern unsigned char D_801F3110, D_801F3111, D_801F3112, D_801F3113, D_801F3114, D_801F3115, D_801F3116, D_801F3117, D_801F3118;
    extern unsigned char D_801F3110, D_801F3111, D_801F3112, D_801F3113, D_801F3114, D_801F3115, D_801F3116, D_801F3117, D_801F3118;
    extern unsigned char D_801F3110, D_801F3111, D_801F3112, D_801F3113, D_801F3114, D_801F3115, D_801F3116, D_801F3117, D_801F3118;
    extern unsigned char D_801F3110, D_801F3111, D_801F3112, D_801F3113, D_801F3114, D_801F3115, D_801F3116, D_801F3117, D_801F3118;
    extern unsigned char D_801F3110, D_801F3111, D_801F3112, D_801F3113, D_801F3114, D_801F3115, D_801F3116, D_801F3117, D_801F3118;
    unsigned char v, t;
    register unsigned char *p __asm__("$5");

    p = &D_801F3070; v = *p; t = D_801F3110;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_801F3071; v = *p; t = D_801F3111;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_801F3072; v = *p; t = D_801F3112;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_801F3073; v = *p; t = D_801F3113;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_801F3074; v = *p; t = D_801F3114;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_801F3075; v = *p; t = D_801F3115;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_801F3076; v = *p; t = D_801F3116;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_801F3077; v = *p; t = D_801F3117;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_801F3078; v = *p; t = D_801F3118;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
}
