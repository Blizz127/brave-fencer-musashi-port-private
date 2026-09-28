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

extern u8 D_801A3D62;
extern u8 D_801A3DD6;
extern u8 D_801A3C8A;
extern u8 D_801A3D44;
extern u8 D_801A3C68;
extern u8 D_801A3C89;
extern s32 D_801A3D48;

void func_8013D330(void) {
    if ((D_801A3D62 & 0xff) != D_801A3DD6) {
        D_801A3D62 = ((D_801A3D62 & 0xff) < D_801A3DD6) ? (D_801A3D62 + 1) : (D_801A3D62 - 1);
    }
    if ((D_801A3C8A & 0xff) != D_801A3D44) {
        D_801A3C8A = ((D_801A3C8A & 0xff) < D_801A3D44) ? (D_801A3C8A + 1) : (D_801A3C8A - 1);
    }
    if ((D_801A3C68 & 0xff) != D_801A3C89) {
        D_801A3C68 = ((D_801A3C68 & 0xff) < D_801A3C89) ? (D_801A3C68 + 1) : (D_801A3C68 - 1);
    }
    D_801A3D48 = 1;
}
