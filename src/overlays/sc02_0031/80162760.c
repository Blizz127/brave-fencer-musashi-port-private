/* SC02 resident retail span [80162760,801627C0). Offset 0x3A608 at base 80128158.
 * SHA256(span)=8e788c975347171416fe68b960228397451b6564cd3efe9da2f80ccd419f8dd2.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801842F8->D_801B64B0.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80162760 - byte-exact against retail at -O2 (tools/register_match.py). */
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
extern int D_801B64B0[];

void func_80162760(void)
{
    int *p;
    int i;

    func_800291C8(0x12, 0);
    i = 0;
    p = D_801B64B0;
    do {
        int v = *p;
        ((void (*)(int, int))func_80016714)(v, 0x38);
        p = p + 1;
        i = i + 1;
    } while (i < 3);
}
