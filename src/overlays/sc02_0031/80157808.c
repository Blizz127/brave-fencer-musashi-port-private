/* SC02 resident retail span [80157808,80157880). Offset 0x2F6B0 at base 80128158.
 * SHA256(span)=f0a2606eb8638a02e85293c76ec3eeea67ee714c54bf1e7ba19e3aed8956508b.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8018068C->D_80186F7C; D_80184280->D_801B6438.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80157808 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_80186F7C[])(void *);
extern int D_801B6438;
extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);

void func_80157808(void *param_1)
{
    D_80186F7C[*(unsigned short *)((char *)param_1 + 2)](param_1);
    D_801B6438 = D_801B6438 - 1;
    if (D_801B6438 == -1) {
        func_801599A4(param_1);
        func_80159B3C(param_1);
    }
}
