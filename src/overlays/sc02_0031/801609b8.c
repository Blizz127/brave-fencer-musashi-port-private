/* SC02 resident retail span [801609B8,80160A28). Offset 0x38860 at base 80128158.
 * SHA256(span)=59cbcb8247fbfad10a3ed46d2fbb6a39752b44f0c88fa15165dc924a4222e7c0.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180A1C->D_8018730C.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801609B8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u16 func_801487F4(s32 *a0);
extern void func_80160A74(s32 *a0);
extern s32 func_80161208();
extern void (*D_8018730C[])(void*);

void func_801609B8(u16 *param_1) {
    if ((((u32 (*)(void))func_801487F4)() & 8) == 0) {
        ((void (**)(u16*))D_8018730C)[*param_1](param_1);
        ((void (*)(u16 *))func_80160A74)(param_1);
    } else {
        ((void (*)(u16 *))func_80161208)(param_1);
    }
}
