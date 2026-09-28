/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015A230,8015A264).
 * Offset 0x320D8 at overlay base 80128158. SHA256(span)=2f12ef24419cdef40c1c0f8804a076be450d6d2b520feefd2dd7090c39023423.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015a230.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015A230 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80147078(s32 *a0, s16 a1);
extern void func_8015A264(void *a0);

void func_8015A230(s32 *a0) {
    func_80147078(a0, 0x1);
    func_8015A264(a0);
}
