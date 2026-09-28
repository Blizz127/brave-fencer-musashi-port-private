/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015BF04,8015BF48).
 * Offset 0x33DAC at overlay base 80128158. SHA256(span)=4ebabc071ea817185d3c396cefde9a13df1978a54c9fcb1b670a3bd7a7897107.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015bf04.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015BF04 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801553A8(s32 *a0);
extern void func_80154A74(s32 a0, s32 a1);

void func_8015BF04(s32 *a0)
{
    func_801553A8(a0);
    func_80154A74((s32)a0, 0x11);
    *(s32 *)((u8 *)a0 + 0x44) &= ~2;
}
