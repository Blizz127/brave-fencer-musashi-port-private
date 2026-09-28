/* SC02.CD FILE_031 / ov_SC02_031 retail span [801707D4,80170810).
 * Offset 0x4867C at overlay base 80128158. SHA256(span)=1f1d720ece058a54d8dacbf45f973e6c22729b895cbc5b4765fb37af6e13fbd8.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801707d4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801707D4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern s32 func_80174ED4(void);
extern void func_80171928(void *a0);

void func_801707D4(void *a0) {
    if ((s16)func_80174ED4() != 0) {
        func_80171928(a0);
    }
}
