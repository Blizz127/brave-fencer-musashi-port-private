/* SC02 resident retail span [80169B80,80169BBC). Offset 0x41A28 at base 80128158.
 * SHA256(span)=a8de6014407059a1214908a43b3c2f4fee1333232a42af8625cb0f26caf916b4.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80181458->D_80187D48.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80169B80 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_80187D48[])(void);

void func_80169B80(void *a0) {
    D_80187D48[*(u16 *)((s32)a0 + 0x2)]();
}
