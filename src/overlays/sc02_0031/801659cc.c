/* SC02.CD FILE_031 / ov_SC02_031 retail span [801659CC,801659DC).
 * Offset 0x3D874 at overlay base 80128158. SHA256(span)=bc4ed949a158cf5e0808d87441d563e2abf9cea27c97713ee95bb2e8e63f114a.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801659cc.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801659CC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_80126B08;

s32 func_801659CC(void) {
    return D_80126B08;
}
