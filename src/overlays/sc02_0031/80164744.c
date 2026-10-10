/* SC02 resident retail span [80164744,801647A4). Offset 0x3C5EC at base 80128158.
 * SHA256(span)=47f9f72f2dbf2e4ceddfea2520c3335e7592c64ac119bf816410a050ea6e8ff1.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180F84->D_80187874.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80164744 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_80187874[])(s32);
extern void func_80162D28(s32 *a0);

void func_80164744(s32 param_1)
{
    s32 iVar1;

    iVar1 = *(s32 *)(param_1 + 0x20);
    D_80187874[*(u16 *)(param_1 + 2)](param_1);
    if (iVar1 != 0) {
        ((void (*)(s32))func_80162D28)(param_1);
    }
}
