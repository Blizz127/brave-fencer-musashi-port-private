/* SC02 resident retail span [8014292C,80142978). Offset 0x1A7D4 at base 80128158.
 * SHA256(span)=4a1473f9f3de96c67f954501cfac7867d8fecc57522cbf055eb1bb6dbaf132f3.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8017F7E4->D_801860D4.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014292C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u16 D_801270C0;
extern void (*D_801860D4[])(int);

void func_8014292C(int param_1)
{
    if (*(s16 *)&D_801270C0 != 3) {
        D_801860D4[*(u16 *)(param_1 + 2)](param_1);
    }
}
