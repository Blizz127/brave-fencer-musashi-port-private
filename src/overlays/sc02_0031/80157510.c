/* SC02.CD FILE_031 / ov_SC02_031 retail span [80157510,80157544).
 * Offset 0x2F3B8 at overlay base 80128158. SHA256(span)=1f808587cc8970735d104df34d14c153298322c696437375e2ff76224b115130.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80157510.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80157510 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80147078(s32 *a0, s16 a1);
extern void func_80157544(void *a0);

void func_80157510(s32 *a0) {
    func_80147078(a0, 6);
    func_80157544(a0);
}
