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

extern u8 D_801F3152;
extern u8 D_801F31C6;
extern u8 D_801F307A;
extern u8 D_801F3134;
extern u8 D_801F3058;
extern u8 D_801F3079;
extern s32 D_801F3138;

void func_8013D330(void) {
    if ((D_801F3152 & 0xff) != D_801F31C6) {
        D_801F3152 = ((D_801F3152 & 0xff) < D_801F31C6) ? (D_801F3152 + 1) : (D_801F3152 - 1);
    }
    if ((D_801F307A & 0xff) != D_801F3134) {
        D_801F307A = ((D_801F307A & 0xff) < D_801F3134) ? (D_801F307A + 1) : (D_801F307A - 1);
    }
    if ((D_801F3058 & 0xff) != D_801F3079) {
        D_801F3058 = ((D_801F3058 & 0xff) < D_801F3079) ? (D_801F3058 + 1) : (D_801F3058 - 1);
    }
    D_801F3138 = 1;
}
