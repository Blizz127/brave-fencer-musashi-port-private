/* SC02 resident retail span [80160920,801609B8). Offset 0x387C8 at base 80128158.
 * SHA256(span)=e8bcd2d41a6f802fa605515cf4cc37f6b6f56c6d31f122ae79e10fdbc8b21298.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180A1C->D_8018730C.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80160920 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef void (*code)(unsigned short *);
extern void (*D_8018730C[])(void*);
extern u16 func_801487F4(s32 *a0);
extern s32 func_80161208();
extern void func_80160A74(s32 *a0);
extern void func_80154150(s32 a0, s32 a1);
extern void func_80146CA0(void *a0);

void func_80160920(unsigned short *param_1)
{
    if ((((int (*)(void))func_801487F4)() & 8) == 0) {
        ((code *)D_8018730C)[*param_1](param_1);
        ((void (*)(unsigned short *))func_80160A74)(param_1);
    } else {
        if (((int (*)(unsigned short *))func_80161208)(param_1) == 0 && param_1[0x5c] == 0x8000) {
            ((void (*)(unsigned short *, int))func_80154150)(param_1, 0x25);
            ((void (*)(unsigned short *))func_80146CA0)(param_1);
        }
    }
    return;
}
