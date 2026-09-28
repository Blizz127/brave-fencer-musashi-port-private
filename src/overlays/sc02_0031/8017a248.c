/* SC02.CD FILE_031 / ov_SC02_031 retail span [8017A248,8017A270).
 * Offset 0x520F0 at overlay base 80128158. SHA256(span)=cf721b14aeac360d4d6b8cbc2d1aaa79fda38719639ac608436e27844204700e.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8017a248.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017A248 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80179B74(u16 *p);

void func_8017A248(void) {
    s16 v = 0x22;
    func_80179B74(&v);
}
