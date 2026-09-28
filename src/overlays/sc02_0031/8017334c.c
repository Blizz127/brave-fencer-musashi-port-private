/* SC02.CD FILE_031 / ov_SC02_031 retail span [8017334C,80173374).
 * Offset 0x4B1F4 at overlay base 80128158. SHA256(span)=6c7606a71fbc3ca30010d6b29af31814bffc54e28a430270a3b9d074db1cdca4.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8017334c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017334C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80174684(void *);
extern void func_80173374();

void func_8017334C(void) {
    func_80174684(func_80173374);
}
