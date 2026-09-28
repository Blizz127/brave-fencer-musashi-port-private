/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016E26C,8016E2E8).
 * Offset 0x46114 at overlay base 80128158. SHA256(span)=b093ceb5b4fc658124bda579c01aa73c71ccda264676ce7928ea721b0c1a1db8.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016e26c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016E26C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8016E3CC(s32 a0);
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern void func_8012A568(void (*a0)(void));

void func_8016E26C(s32 *a0) {
    func_8016E3CC((s32)a0);
    if (--a0[0x1C / 4] != 0) {
        func_80146A6C(0x48, a0, 0, 0, 0, 0x8000, 0);
    } else {
        a0[0x1C / 4] = 0x10;
        *(u16 *)((char *)a0 + 2) += 1;
    }
}
