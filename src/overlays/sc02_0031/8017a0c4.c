/* SC02 resident retail span [8017A0C4,8017A0F4). Offset 0x51F6C at base 80128158.
 * SHA256(span)=e83892cf3e66a0b77917ec1d7830ff25a813df08414cf1107be31a881609ecbd.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80185364->D_801B751C.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017A0C4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80179B74(u16 *p);
extern s32 D_801B751C;

void func_8017A0C4(s32 arg0) {
    s16 sp10;

    D_801B751C = arg0;
    sp10 = 0x16;
    func_80179B74(&sp10);
}
