/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A64DC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s16 D_801AFBC8;
extern s16 D_801AFBCA;
extern s16 D_801AFBCC;
extern s16 D_801AFBCE;
extern s16 D_801AFBD0;
extern s16 D_801AFBD2;
extern s32 D_801F871C;

void func_801A64DC(s32 arg0) {
    s32 var = D_801F871C;

    *(u16 *)(arg0 + 0) = *(u16 *)(var + 6) + ((D_801AFBC8 + D_801AFBCA) >> 1);
    *(u16 *)(arg0 + 2) = *(u16 *)(var + 0x52) + (*(u16 *)(var + 0xA) + ((D_801AFBCC + D_801AFBCE) >> 1));
    *(u16 *)(arg0 + 4) = *(u16 *)(var + 0xE) + ((D_801AFBD0 + D_801AFBD2) >> 1);
}
