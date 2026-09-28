/* SC02 resident retail span [8015E698,8015E714). Offset 0x36540 at base 80128158.
 * SHA256(span)=06304da1ad29476aea511783a54cb2a8f15d3717740fbd7926e701f5e456b809.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180A1C->D_8018730C.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015E698 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80161208();
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80159BE4(s32 arg0);
extern void (*D_8018730C[])(void*);

void func_8015E698(u16 *param_1)
{
    if (func_80161208() == 0 && (param_1[0x5c] & 0x8000) != 0) {
        ((void (**)(u16*))D_8018730C)[param_1[0]](param_1);
        ((void (*)(u16 *, s32))func_80147078)(param_1, 0);
        ((void (*)(u16 *))func_80159BE4)(param_1);
    }
}
