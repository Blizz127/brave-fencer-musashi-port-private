/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016F804,8016F834).
 * Offset 0x476AC at overlay base 80128158. SHA256(span)=48aef0f674a686eb7514633d3ba817dbdb696d806685a7d94d1f348080516f80.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016f804.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016F804 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80171928(void *);
extern void func_8012A568(void (*a0)(void));

void func_8016F804(void *a0) {
    if (*(u8 *)((s32)a0 + 0x1C2) != 0) {
        *(u8 *)((s32)a0 + 0x1C2) = 0;
        func_80171928(a0);
    }
}
