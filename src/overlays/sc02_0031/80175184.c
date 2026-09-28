/* SC02 resident retail span [80175184,801751D8). Offset 0x4D02C at base 80128158.
 * SHA256(span)=cde082c6151e1f38669d0062a33fe61b3b1b72f0df618ad5f5b86a542fa653d7.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80181A08->D_801882F8.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80175184 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_801882F8[])(void*);
extern s32 func_80175268(s32);

void func_80175184(s32* arg0) {
    u16 v1 = *(u16*)((u8*)arg0 + 2);
    if (v1 < 2) {
        D_801882F8[v1](arg0);
    } else {
        func_80175268((s32)arg0);
    }
}
