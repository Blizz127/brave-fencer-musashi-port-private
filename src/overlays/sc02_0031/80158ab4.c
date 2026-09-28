/* SC02.CD FILE_031 / ov_SC02_031 retail span [80158AB4,80158AE4).
 * Offset 0x3095C at overlay base 80128158. SHA256(span)=e7850668379adc3d42d121244c8d4df8585279d0c32ab9699b83602a3d9f4643.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80158ab4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80158AB4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80158AE4(void *a0);
extern void func_80146CA0(void *a0);

void func_80158AB4(void *a0) {
    func_80158AE4(a0);
    func_80146CA0(a0);
}
