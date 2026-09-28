/* SC02 resident retail span [8016216C,801621CC). Offset 0x3A014 at base 80128158.
 * SHA256(span)=4aa18526913a022b8e9c4d9f3654ce88564e4f909d0067f27e8dc75d8e113b7d.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801842A0->D_801B6458.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016216C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_800291C8(s32, s32);
extern void func_80016714(void *a0, s32 a1);
extern int D_801B6458[];

void func_8016216C(void)
{
    int *p;
    int i;

    func_800291C8(8, 0);
    i = 0;
    p = D_801B6458;
    do {
        int v = *p;
        ((void (*)(int, int))func_80016714)(v, 0x38);
        p = p + 1;
        i = i + 1;
    } while (i < 3);
}
