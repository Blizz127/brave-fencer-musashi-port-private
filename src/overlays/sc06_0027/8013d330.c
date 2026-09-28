/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8013D330 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_8019D3BA;
extern u8 D_8019D42E;
extern u8 D_8019D2E2;
extern u8 D_8019D39C;
extern u8 D_8019D2C0;
extern u8 D_8019D2E1;
extern s32 D_8019D3A0;

void func_8013D330(void) {
    if ((D_8019D3BA & 0xff) != D_8019D42E) {
        D_8019D3BA = ((D_8019D3BA & 0xff) < D_8019D42E) ? (D_8019D3BA + 1) : (D_8019D3BA - 1);
    }
    if ((D_8019D2E2 & 0xff) != D_8019D39C) {
        D_8019D2E2 = ((D_8019D2E2 & 0xff) < D_8019D39C) ? (D_8019D2E2 + 1) : (D_8019D2E2 - 1);
    }
    if ((D_8019D2C0 & 0xff) != D_8019D2E1) {
        D_8019D2C0 = ((D_8019D2C0 & 0xff) < D_8019D2E1) ? (D_8019D2C0 + 1) : (D_8019D2C0 - 1);
    }
    D_8019D3A0 = 1;
}
