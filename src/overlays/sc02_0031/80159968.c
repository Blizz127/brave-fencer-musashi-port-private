/* SC02 resident retail span [80159968,801599A4). Offset 0x31810 at base 80128158.
 * SHA256(span)=8e0cc23630f0529e24659e906ae32636cd753a9af2d7f81322964c2bcd3bef1b.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180A10->D_80187300.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80159968 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_80187300[])(void);

void func_80159968(void *a0) {
    D_80187300[*(u8 *)((s32)a0 + 0x4D)]();
}
