/* SC02.CD FILE_031 / ov_SC02_031 retail span [80170B90,80170BD8).
 * Offset 0x48A38 at overlay base 80128158. SHA256(span)=f83674abf18c6a355957f8a34019629d8d79fc405486cee899e5256df185e923.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80170b90.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80170B90 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_80147060(u8 *a0);
extern void func_80171928(void *a0);

void func_80170B90(u8 *a0) {
    if (*(u16 *)(a0 + 0xB8) & 0x8000) {
        func_80147060(a0);
        func_80171928(a0);
    }
}
