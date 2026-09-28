/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017B940 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u16 D_80126B5E;
extern u16 D_80126B66;
extern u16 D_801B7584;
extern u16 D_801B7586;
extern u16 D_801B7588;
extern s32 D_80114F30;
extern s32 D_80114F34;
extern s32 D_80114F38;
extern s32 D_80114F24;
extern s32 D_80114F28;
extern s32 D_80114F2C;
extern u8  D_8012694C;
extern s16 D_801B7504;
extern short D_801B758C;
extern short D_801B758E;
extern short D_801B7590;
extern s16 D_801B757C;
extern s16 D_801B757E;
extern s16 D_801B7580;
extern s16 D_801B7574;
extern s16 D_801B7576;
extern s16 D_801B7578;

void func_8017B940(void)
{
    /* [T51] scoped in from file scope: a file-scope decl of these symbols constrains every
       LATER function in this TU, which blocks a byte-true decl of a different type.
       Declaration-only move (cookbook §103); the whole-binary byte-gate is the arbiter. */
    extern u16 D_80126B62;
    s32 buf[3];

    D_8012694C = 2;
    buf[0] = (*(s16 *)&D_80126B5E) - (*(s16 *)&D_801B7584);
    buf[1] = (*(s16 *)&D_80126B62) - (*(s16 *)&D_801B7586);
    buf[2] = (*(s16 *)&D_80126B66) - (*(s16 *)&D_801B7588);
    (*(s16 *)&D_801B758C) = buf[0];
    (*(s16 *)&D_801B758E) = buf[1];
    (*(s16 *)&D_801B7590) = buf[2];
    D_801B757C = D_80114F30 + buf[0];
    D_801B7504 = 0;
    D_801B757E = D_80114F34 + buf[1];
    D_801B7580 = D_80114F38 + buf[2];
    D_801B7574 = D_80114F24 + buf[0];
    D_801B7576 = D_80114F28 + buf[1];
    D_801B7578 = D_80114F2C + buf[2];
}
