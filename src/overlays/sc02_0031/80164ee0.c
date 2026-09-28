/* SC02 resident retail span [80164EE0,80164F44). Offset 0x3CD88 at base 80128158.
 * SHA256(span)=21f02329f57a805473fc5e634b8d3b8f8bb2d242bb674a88703f803092fecb11.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801843A4->D_801B655C.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80164EE0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { int f0; int f1; int f2; int f3; } DStruct;
extern DStruct D_801B655C[];
extern void func_80165124(void *a0);
extern void func_80146CA0(void *a0);

void func_80164EE0(int param_1)
{
    int i;

    for (i = 7; i >= 0; i--) {
        D_801B655C[i].f0 = 0;
    }
    *(short *)(param_1 + 0x2e) = 0x4000;
    *(short *)(param_1 + 0x2c) = 0x4000;
    *(short *)(param_1 + 0x60) = 0;
    *(short *)(param_1 + 0x62) = 0;
    ((void (*)(int))func_80165124)(param_1);
    *(short *)(param_1 + 0x66) = 0;
    ((void (*)(int))func_80146CA0)(param_1);
}
