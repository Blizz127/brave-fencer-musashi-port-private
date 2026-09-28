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

extern u8 D_8019D16A;
extern u8 D_8019D1DE;
extern u8 D_8019D092;
extern u8 D_8019D14C;
extern u8 D_8019D070;
extern u8 D_8019D091;
extern s32 D_8019D150;

void func_8013D330(void) {
    if ((D_8019D16A & 0xff) != D_8019D1DE) {
        D_8019D16A = ((D_8019D16A & 0xff) < D_8019D1DE) ? (D_8019D16A + 1) : (D_8019D16A - 1);
    }
    if ((D_8019D092 & 0xff) != D_8019D14C) {
        D_8019D092 = ((D_8019D092 & 0xff) < D_8019D14C) ? (D_8019D092 + 1) : (D_8019D092 - 1);
    }
    if ((D_8019D070 & 0xff) != D_8019D091) {
        D_8019D070 = ((D_8019D070 & 0xff) < D_8019D091) ? (D_8019D070 + 1) : (D_8019D070 - 1);
    }
    D_8019D150 = 1;
}
