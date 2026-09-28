/* SC02 resident retail span [8013B7AC,8013B7F4). Offset 0x13654 at base 80128158.
 * SHA256(span)=ea815d176496ebb3654867125e57de1ba9da66747c52a324f0b69a33a1283d22.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80185B58->D_801B79E8.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8013B7AC - byte-exact against retail at -O0 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { s32 f0; u8 pad[0x18]; } E_3B7AC_8013B7AC;
extern void func_8012A5F8(void (*a0)(void), s32 a1);

void func_8013B7AC(int a0) {
    extern E_3B7AC_8013B7AC D_801B79E8[];
 D_801B79E8[a0].f0 = 0; }
