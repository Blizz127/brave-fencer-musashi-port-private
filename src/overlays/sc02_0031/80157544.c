/* SC02 resident retail span [80157544,80157580). Offset 0x2F3EC at base 80128158.
 * SHA256(span)=4d27a62002f4e8c9d69ebfa77f966eb772bdb0f1fd67910076b7fc3fa860f4fc.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180664->D_80186F54.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80157544 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_80186F54[])(void *);

void func_80157544(void *a0) {
    D_80186F54[*(u16 *)((s32)a0 + 0x2)](a0);
}
