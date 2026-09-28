/* SC02 resident retail span [80157D20,80157D74). Offset 0x2FBC8 at base 80128158.
 * SHA256(span)=1998ffaf33f9b3b8116f48f6cafd991e2a49d74b15d5937234081b2b0f0604b3.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801806BC->D_80186FAC.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80157D20 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80156648(s32 *a0);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80157D74(u16 *a0);

void func_80157D20(void)
{

    extern u16 D_80186FAC[];
    register void *a0v __asm__("$4");
    register s32 a1v __asm__("$5");
    void *param_1 = a0v;
    s32 param_2 = a1v;

    ((void (*)(void))func_80156648)();
    ((void (*)(void *, s32))func_80147078)(param_1, D_80186FAC[param_2]);
    ((void (*)(void *))func_80157D74)(param_1);
}
