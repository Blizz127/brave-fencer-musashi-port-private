/* SC02 resident retail span [8012F828,8012F87C). Offset 0x76D0 at base 80128158.
 * SHA256(span)=d25b6e9a02ea772dfad8faf61b1477a0c53a6de1a677d1e7abccbe8bb1347085.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8017E6F0->D_80184FE0.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012F828 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80131170();
extern void func_80131CA8();
extern unsigned char D_80184FE0[];

void func_8012F828(int param_1)
{
    *(unsigned char *)(param_1 + 0xC1) = 4;
    if (*(unsigned int *)(param_1 + 0xB4) & 8) {
        func_80131170(param_1, D_80184FE0, 0xB);
    }
    func_80131CA8(param_1, 9);
}
