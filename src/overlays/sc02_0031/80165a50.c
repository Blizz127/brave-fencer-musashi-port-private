/* SC02.CD FILE_031 / ov_SC02_031 retail span [80165A50,80165A78).
 * Offset 0x3D8F8 at overlay base 80128158. SHA256(span)=1d3276210f727b7466af9fca6da90d9f982462623dc5f378850f3ca78b68eb7c.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80165a50.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80165A50 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_80078EC1;
extern u8 D_80078EC2;
extern u8 D_80078EC3;
extern s8 D_80078EC4;

s32 func_80165A50(s32 _arg0)
{
    D_80078EC1 = 0;
    D_80078EC2 = 0;
    D_80078EC3 = 0;
    D_80078EC4 = 0;
}
