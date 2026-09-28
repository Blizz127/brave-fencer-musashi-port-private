/* SC02.CD FILE_031 / ov_SC02_031 retail span [801751D8,80175218).
 * Offset 0x4D080 at overlay base 80128158. SHA256(span)=c7299c34290a64424211de5f31d3a0b936fb5c36b5cc50cc00c5359bc4b85e66.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801751d8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801751D8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern s32 func_80161104(void);
extern s32 func_80175218(void *a0);
extern void func_80146CA0(void *a0);

void func_801751D8(void *a0) {
    void *s = a0;
    if (func_80161104()) {
        func_80175218(s);
        func_80146CA0(s);
    }
}
