/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A4328 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_801F8744[];
extern u8 D_801AFEF8[];
extern u8 D_801AFEF9[];
extern u8 D_801AFEFA[];
extern s16 D_801F8870;
extern s16 D_801F8872;
extern s16 D_801F8874;
extern s16 D_801F8878;
extern s16 D_801F887A;
extern s16 D_801F887C;
extern s16 D_801F8880;
extern s16 D_801F8882;
extern s16 D_801F8884;

void func_801A4328(s32 a0) {
    s32 idx;
    s32 b0;
    s32 b1;
    s32 b2;
    s32 p;
    s32 q;
    s32 r;

    idx = a0 * 4;
    b0 = D_801F8744[0];
    b1 = D_801F8744[1];
    b2 = D_801F8744[2];
    D_801F8870 = b0 << 7;
    D_801F8872 = b1 << 7;
    D_801F8874 = b2 << 7;
    p = D_801AFEF8[idx];
    D_801F8878 = p << 7;
    q = D_801AFEF9[idx];
    D_801F887A = q << 7;
    r = D_801AFEFA[idx];
    D_801F8880 = (p - b0) << 4;
    D_801F8882 = (q - b1) << 4;
    D_801F887C = r << 7;
    D_801F8884 = (r - b2) << 4;
}
