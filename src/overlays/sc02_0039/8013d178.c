/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8013D178 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_8013D178(void) {

    extern u8 D_801A0CA8;
    extern u8 D_801A0CA9;
    extern u8 D_801A0CAA;
    extern u8 D_801A0CAB;
    extern u8 D_801A0CAC;
    extern u8 D_801A0CAD;
    extern u8 D_801A0CAE;
    extern u8 D_801A0CAF;
    extern u8 D_801A0CB0;
    extern unsigned char D_801A0D48, D_801A0D49, D_801A0D4A, D_801A0D4B, D_801A0D4C, D_801A0D4D, D_801A0D4E, D_801A0D4F, D_801A0D50;
    extern unsigned char D_801A0D48, D_801A0D49, D_801A0D4A, D_801A0D4B, D_801A0D4C, D_801A0D4D, D_801A0D4E, D_801A0D4F, D_801A0D50;
    extern unsigned char D_801A0D48, D_801A0D49, D_801A0D4A, D_801A0D4B, D_801A0D4C, D_801A0D4D, D_801A0D4E, D_801A0D4F, D_801A0D50;
    extern unsigned char D_801A0D48, D_801A0D49, D_801A0D4A, D_801A0D4B, D_801A0D4C, D_801A0D4D, D_801A0D4E, D_801A0D4F, D_801A0D50;
    extern unsigned char D_801A0D48, D_801A0D49, D_801A0D4A, D_801A0D4B, D_801A0D4C, D_801A0D4D, D_801A0D4E, D_801A0D4F, D_801A0D50;
    extern unsigned char D_801A0D48, D_801A0D49, D_801A0D4A, D_801A0D4B, D_801A0D4C, D_801A0D4D, D_801A0D4E, D_801A0D4F, D_801A0D50;
    extern unsigned char D_801A0D48, D_801A0D49, D_801A0D4A, D_801A0D4B, D_801A0D4C, D_801A0D4D, D_801A0D4E, D_801A0D4F, D_801A0D50;
    extern unsigned char D_801A0D48, D_801A0D49, D_801A0D4A, D_801A0D4B, D_801A0D4C, D_801A0D4D, D_801A0D4E, D_801A0D4F, D_801A0D50;
    extern unsigned char D_801A0D48, D_801A0D49, D_801A0D4A, D_801A0D4B, D_801A0D4C, D_801A0D4D, D_801A0D4E, D_801A0D4F, D_801A0D50;
    unsigned char v, t;
    register unsigned char *p __asm__("$5");

    p = &D_801A0CA8; v = *p; t = D_801A0D48;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_801A0CA9; v = *p; t = D_801A0D49;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_801A0CAA; v = *p; t = D_801A0D4A;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_801A0CAB; v = *p; t = D_801A0D4B;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_801A0CAC; v = *p; t = D_801A0D4C;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_801A0CAD; v = *p; t = D_801A0D4D;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_801A0CAE; v = *p; t = D_801A0D4E;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_801A0CAF; v = *p; t = D_801A0D4F;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
    p = &D_801A0CB0; v = *p; t = D_801A0D50;
    if (v != t) { if (v < t) *p = v + 8; else *p = v - 8; }
}
