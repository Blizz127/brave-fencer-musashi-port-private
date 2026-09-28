/* SC02 resident retail span [801622C4,80162330). Offset 0x3A16C at base 80128158.
 * SHA256(span)=119ce6e7d998e0e562158da33630181f62989d549ba7ffff297bd786ae32d3d3.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801842A0->D_801B6458.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801622C4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80029124(s32, s32);
extern void func_800291C8(s32, s32);
extern void func_80016714(void *a0, s32 a1);
extern int D_801B6458[];

void func_801622C4(void)
{
    int *p;
    int i;

    ((int (*)(int, int))func_80029124)(0x141, 1);
    ((int (*)(int, int))func_800291C8)(8, 0);
    i = 0;
    p = &D_801B6458;
    do {
        ((int (*)(int, int))func_80016714)(*p, 0x38);
        p = p + 1;
        i = i + 1;
    } while (i < 3);
}
