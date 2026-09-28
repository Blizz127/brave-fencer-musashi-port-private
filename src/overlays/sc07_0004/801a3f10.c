/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A3F10 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u16 D_8019FF8A;
extern s16 D_801F8860;
extern s32 func_8013D13C(s16 a0);
extern s32 func_8018184C(s16 a0);

void func_801A3F10(void) {
    if (D_8019FF8A & 0x20) {
        if (func_8013D13C(D_801F8860) == 0) {
            D_8019FF8A &= 0xFFDF;
        }
    }
    if (D_8019FF8A & 0x800) {
        if (func_8018184C(D_801F8860) == 0) {
            D_8019FF8A &= 0xF7FF;
        }
    }
}
