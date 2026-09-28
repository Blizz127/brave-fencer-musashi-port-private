/* SC02.CD FILE_031 / ov_SC02_031 retail span [80174584,801745AC).
 * Offset 0x4C42C at overlay base 80128158. SHA256(span)=f969941f8e96c13951c5298a4e520fe1281dbfb06e1759f9fc3f22427735bd51.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80174584.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80174584 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80174684(void *);
extern void func_801745AC();

void func_80174584(void) {
    func_80174684(func_801745AC);
}
