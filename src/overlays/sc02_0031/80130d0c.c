/* SC02 resident retail span [80130D0C,80130D48). Offset 0x8BB4 at base 80128158.
 * SHA256(span)=6b945002f7550b7b2b93e750b56b292636aa116d21c0ae456aa608e8da6ca503.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8017E710->D_80185000.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80130D0C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void (*D_80185000[])(void *);

void func_80130D0C(void *a0) {
    D_80185000[*(u8 *)((s32)a0 + 0xC1)](a0);
}
