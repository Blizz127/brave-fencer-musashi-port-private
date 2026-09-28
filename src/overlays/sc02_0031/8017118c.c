/* SC02.CD FILE_031 / ov_SC02_031 retail span [8017118C,801711C0).
 * Offset 0x49034 at overlay base 80128158. SHA256(span)=77f836330b823041119bc3867a8032917add0a96bbd2855d32a0431580972957.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8017118c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017118C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_80142454(s32 a0);
extern void func_80171928(void *a0);

void func_8017118C(u8 * a0)
{
    func_80142454(-0x80);
    func_80171928(a0);
}
