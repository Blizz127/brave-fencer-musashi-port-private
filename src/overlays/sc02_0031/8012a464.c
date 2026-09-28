/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012A464,8012A4BC).
 * Offset 0x230C at overlay base 80128158. SHA256(span)=c710e557afc99982d1c6d9ff9769e5346005d9a9c23218ddc8e6ec0ae13bafb2.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012a464.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012A464 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { s32 w[8]; } Vec8;
extern s32 D_801151D4;
extern Vec8 D_80114F24;

void func_8012A464(void)
{
    D_80114F24 = *(Vec8 *)(*(s32 *)&D_801151D4 + 0x3C);
}
