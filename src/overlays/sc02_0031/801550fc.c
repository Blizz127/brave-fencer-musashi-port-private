/* SC02 resident retail span [801550FC,80155150). Offset 0x2CFA4 at base 80128158.
 * SHA256(span)=d36ad38f16d983c326d8aa1e9506d9c8299a172e7822bcb7f59c727c369077cb.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801801AC->D_80186A9C.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801550FC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct {
    u8 b[8];
} ImgRect8;
extern void func_80059A80(void *a0, s32 a1, s32 a2);
extern void func_800183E0(s32 a0);
extern ImgRect8 D_80186A9C[];

void func_801550FC(s32 arg0)
{
    if (arg0 & 0x40000000) {
        func_80059A80(&D_80186A9C[arg0 & 0xFF], 0x200, 0x100);
    } else {
        ((void (*)(void))func_800183E0)();
    }
}
