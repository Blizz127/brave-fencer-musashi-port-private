/* SC02 resident retail span [8016FFDC,80170018). Offset 0x47E84 at base 80128158.
 * SHA256(span)=1df6d9e9a35445e73e7003365665da7b434504020b369230437b51b53c958e15.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80181840->D_80188130.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016FFDC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_80188130[])(void *);
extern void func_8012A568(void (*a0)(void));

void func_8016FFDC(void *a0) {
    D_80188130[*(u8 *)((s32)a0 + 0x216)](a0);
}
