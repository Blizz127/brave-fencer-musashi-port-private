/* SC02.CD FILE_031 / ov_SC02_031 retail span [801725B8,801725CC).
 * Offset 0x4A460 at overlay base 80128158. SHA256(span)=9479659232f692b14fa6b176917f7646ec03074d70ef3706a5e2edbbc7b86745.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801725b8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801725B8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));

s32 func_801725B8(u8 *a0) {
    s32 v0 = *(u32 *)((s32)a0 + 0x1F4) | 0x4;
    *(u32 *)((s32)a0 + 0x1F4) = v0;
    return v0;
}
