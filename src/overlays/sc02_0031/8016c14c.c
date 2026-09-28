/* SC02 resident retail span [8016C14C,8016C188). Offset 0x43FF4 at base 80128158.
 * SHA256(span)=e90483c13b7338cdb881303162ffe87298f23e84af51da785b63e835d277041f.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801815E8->D_80187ED8.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016C14C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_80187ED8[])(void);
extern void func_8012A568(void (*a0)(void));

void func_8016C14C(void *a0) {
    D_80187ED8[*(u16 *)((s32)a0 + 0x2)]();
}
