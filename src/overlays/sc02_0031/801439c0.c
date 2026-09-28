/* SC02.CD FILE_031 / ov_SC02_031 retail span [801439C0,801439FC).
 * Offset 0x1B868 at overlay base 80128158. SHA256(span)=802b1fa1507fda1a69bb775b9e41bbc371cadb2d00d9611a13ecbb93085ca106.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801439c0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801439C0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_80016714(void *a0, s32 a1);
extern void func_8012C218(void *a0);

void func_801439C0(u8 *a0) {
    if (a0 != 0) {
        func_80016714(*(void **)(a0 + 0xCC), 0x38);
        func_8012C218(a0);
    }
}
