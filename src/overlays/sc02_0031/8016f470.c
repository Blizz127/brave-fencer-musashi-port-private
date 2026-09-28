/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016F470,8016F494).
 * Offset 0x47318 at overlay base 80128158. SHA256(span)=03b4143203f5efafc56d0136e8c3e641e12c768a533a36f0818a9d6a41d4ba92.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016f470.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016F470 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80029124(s32 a0, s32 a1);
extern void func_8012A568(void (*a0)(void));

void func_8016F470(s32 a0) {
    func_80029124(a0 + 0x125, 0);
}
