/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012A598,8012A5F8).
 * Offset 0x2440 at overlay base 80128158. SHA256(span)=3befcdb3e9cd74f3aba4cc0895b0ddcf532a2da9ba2ffdb4bf3edb4c3f082e3f.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012a598.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012A598 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

struct BigCopy { s32 words[41]; };
extern s32 D_801151D4;
extern struct BigCopy D_80126DB8;
extern u8 D_80127504;

void func_8012A598(void *a0)
{
    D_80126DB8 = *(struct BigCopy *)D_801151D4;
    D_80127504 = 0x30;
}
