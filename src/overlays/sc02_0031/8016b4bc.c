/* SC02 resident retail span [8016B4BC,8016B4F8). Offset 0x43364 at base 80128158.
 * SHA256(span)=ef0b6c265708103f5d5c1a18017d83d84415c56f48b17eb3f5f09d240f1056e4.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80181568->D_80187E58.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016B4BC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_80187E58[])(void);
extern void func_8012A568(void (*a0)(void));

void func_8016B4BC(void *a0) {
    D_80187E58[*(u16 *)((s32)a0 + 0x2)]();
}
