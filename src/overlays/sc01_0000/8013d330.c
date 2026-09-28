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

extern u8 D_801A5872;
extern u8 D_801A58E6;
extern u8 D_801A579A;
extern u8 D_801A5854;
extern u8 D_801A5778;
extern u8 D_801A5799;
extern s32 D_801A5858;

void func_8013D330(void) {
    if ((D_801A5872 & 0xff) != D_801A58E6) {
        D_801A5872 = ((D_801A5872 & 0xff) < D_801A58E6) ? (D_801A5872 + 1) : (D_801A5872 - 1);
    }
    if ((D_801A579A & 0xff) != D_801A5854) {
        D_801A579A = ((D_801A579A & 0xff) < D_801A5854) ? (D_801A579A + 1) : (D_801A579A - 1);
    }
    if ((D_801A5778 & 0xff) != D_801A5799) {
        D_801A5778 = ((D_801A5778 & 0xff) < D_801A5799) ? (D_801A5778 + 1) : (D_801A5778 - 1);
    }
    D_801A5858 = 1;
}
