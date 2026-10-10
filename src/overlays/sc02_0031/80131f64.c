/* SC02 resident retail span [80131F64,80131FA0). Offset 0x9E0C at base 80128158.
 * SHA256(span)=9b33f64814e739994060c478b9a5c0038c182db7fdc3893f02b450ab8b6a0e80.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8017E8F8->D_801851E8.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80131F64 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void (*D_801851E8[])(void *);

void func_80131F64(void *a0) {
    D_801851E8[*(u16 *)((s32)a0 + 0x2)](a0);
}
