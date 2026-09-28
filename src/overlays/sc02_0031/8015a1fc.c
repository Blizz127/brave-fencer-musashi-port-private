/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015A1FC,8015A230).
 * Offset 0x320A4 at overlay base 80128158. SHA256(span)=f4eeba17a88ef0a8b05962edfd4e1365ba3b2061c82a9d7a0831bfa74fdea02f.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015a1fc.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015A1FC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80147078(s32 *a0, s16 a1);
extern void func_8015A2D8(s32);

void func_8015A1FC(s32 *a0) {
    func_80147078(a0, 1);
    func_8015A2D8(a0);
}
