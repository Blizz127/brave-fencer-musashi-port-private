/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016E2E8,8016E358).
 * Offset 0x46190 at overlay base 80128158. SHA256(span)=9cf1ecf73699eb8d35160b98901bbb97999c2c59b5798965ee52e7cbd272ff0f.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016e2e8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016E2E8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8016E3CC(s32 a0);
extern void func_80146C3C();
extern void func_8012A568(void (*a0)(void));

void func_8016E2E8(void *a0) {
    s32 *s1 = *(s32 **)((s32)a0 + 0x20);
    func_8016E3CC((s32)a0);
    if (--*(s32 *)((s32)a0 + 0x1C) != 0) {
        *(u16 *)((s32)s1 + 0x18) -= 0x100;
        *(u16 *)((s32)s1 + 0x1A) -= 0x120;
    } else {
        ((void (*)(s32))func_80146C3C)((s32)a0);
    }
}
