/* SC02 resident retail span [8013CB20,8013CB5C). Offset 0x149C8 at base 80128158.
 * SHA256(span)=b664efb4f5b8642970e7a6a9a549aa0367bb988d03d15ce4ae7771d820a308da.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801841BC->D_801B6374; D_801841C0->D_801B6378; D_801841E8->D_801B63A0; D_801841EC->D_801B63A4.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8013CB20 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_801B6374;
extern s32 D_801B6378;
extern s32 D_801B63A0;
extern s32 D_801B63A4;

void func_8013CB20(void)
{
    D_801B63A0 = D_801B6378;
    D_801B63A4 = D_801B6374;
    D_801B6378 = 1;
    D_801B6374 = 0;
}
