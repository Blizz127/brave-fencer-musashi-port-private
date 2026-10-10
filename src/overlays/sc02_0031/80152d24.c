/* SC02 resident retail span [80152D24,80152D60). Offset 0x2ABCC at base 80128158.
 * SHA256(span)=23b9ec40fc1c7c815da7e55da75a06c2380c3507dd05217b874d78d6cc1e7653.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8018013C->D_80186A2C.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80152D24 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_80186A2C[])(void *);

void func_80152D24(void *a0) {
    D_80186A2C[*(u16 *)((s32)a0 + 0x2)](a0);
}
