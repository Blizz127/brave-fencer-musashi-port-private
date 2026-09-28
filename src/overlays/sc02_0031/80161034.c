/* SC02 resident retail span [80161034,80161094). Offset 0x38EDC at base 80128158.
 * SHA256(span)=ca03ce17e957cad8acc6a256becd7637d286aa0d8026b8bb31257cca7093f44f.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180A1C->D_8018730C.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80161034 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80149020(s32 *a0);
extern void (*D_8018730C[])(void *);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80159B70(void *a0);

void func_80161034(void *a0)
{
    func_80149020(a0);
    D_8018730C[*(u16 *)a0](a0);
    func_80147078(a0, 0);
    func_80159B70(a0);
}
