/* SC02 resident retail span [80132144,801321B0). Offset 0x9FEC at base 80128158.
 * SHA256(span)=9f497492b1a3f1eb412e16012e0b730e10dedd13e334356746c3245001b41fc0.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8017E8C0->D_801851B0.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80132144 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001C214(int, int);

s32 func_80132144(s32 param_1)
{
    extern int D_801851B0;

    int v0;

    v0 = ((int (*)(void))func_8012C1B8)();
    *(int *)(((int)param_1) + 0x20) = v0;
    if (v0 == 0) {
        ((void (*)(int))func_8012CAE4)(((int)param_1));
    } else {
        ((void(*)(int, int))func_8001C214)(v0, 0);
        *(int *)(((int)param_1) + 0x58) = (int)&D_801851B0;
        *(short *)(((int)param_1) + 0x5c) = 0x80;
        *(unsigned short *)(((int)param_1) + 2) += 1;
    }
}
