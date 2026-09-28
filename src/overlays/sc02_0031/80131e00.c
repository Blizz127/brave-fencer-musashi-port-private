/* SC02 resident retail span [80131E00,80131E38). Offset 0x9CA8 at base 80128158.
 * SHA256(span)=7313a6190db8095c42ab7859430613c2c3d9839933fa0cb0e144e644e40bab50.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8017E850->D_80185140.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80131E00 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

struct S80131E00 {
    char pad[0xB0];
    s32 field_B0;
};
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void (*D_80185140[])(struct S80131E00 *a0);

void func_80131E00(struct S80131E00 *a0, s32 a1) {
    a0->field_B0 = a1;
    D_80185140[a1](a0);
}
