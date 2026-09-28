/* SC02 resident retail span [80141C0C,80141C50). Offset 0x19AB4 at base 80128158.
 * SHA256(span)=7ba0dec8adbc0348a5630ee7fafc24fcc9fa30bd7b793982339a24a9fd64db05.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8017F6D4->D_80185FC4.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80141C0C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern u16 D_80115110;
extern u8 D_80185FC4;
extern void func_8002D4C8(s32 a0, s32 a1);

void func_80141C0C(s32 param_1)
{
    func_8002D4C8(*(u16 *)(&D_80185FC4 + (((param_1 << 16) >> 15) + (u32)D_80115110) * 2), 0);
}
