/* SC02.CD FILE_031 / ov_SC02_031 retail span [80172644,80172658).
 * Offset 0x4A4EC at overlay base 80128158. SHA256(span)=c9ffd279194050b6c0d2cd3ae96e31ab5f5ec7c1f06e89b79a807196fa4a097a.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80172644.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80172644 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));

s32 func_80172644(u8 *a0) {
    s32 v0 = *(u32 *)((s32)a0 + 0x1F4) | 0x200;
    *(u32 *)((s32)a0 + 0x1F4) = v0;
    return v0;
}
