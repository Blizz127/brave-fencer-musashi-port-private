/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012A4BC,8012A568).
 * Offset 0x2364 at overlay base 80128158. SHA256(span)=5821f68588540ee0c6c267894fb9d2103ceb3e67124b206b2e34e4e006e35a83.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012a4bc.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012A4BC - byte-exact against retail at -O2 (tools/register_match.py). */
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
extern struct BigCopy D_80114EE8;
extern u8 D_80127504;

void func_8012A4BC(void) {
    D_80126DB8 = *(struct BigCopy *)D_801151D4;
    *(struct BigCopy *)D_801151D4 = D_80114EE8;
    D_80127504 = 0x30;
}
