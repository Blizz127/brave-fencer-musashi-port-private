/* SC02.CD FILE_031 / ov_SC02_031 retail span [8017329C,801732C4).
 * Offset 0x4B144 at overlay base 80128158. SHA256(span)=7cf072b11c2c5860a46e8b58c236bee0dcffb886465a281f4e9484b519eb16a2.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8017329c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017329C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80174684(void *);
extern void func_801732C4();

void func_8017329C(void) {
    func_80174684(func_801732C4);
}
