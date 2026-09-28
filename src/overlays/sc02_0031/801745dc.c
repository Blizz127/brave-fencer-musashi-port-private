/* SC02.CD FILE_031 / ov_SC02_031 retail span [801745DC,80174604).
 * Offset 0x4C484 at overlay base 80128158. SHA256(span)=128d97a1712824f4c95ee0a90db921a51de83a29a5cf42ecafea48acb7a70566.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801745dc.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801745DC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80174604(void);
extern void func_80174684(void *);

void func_801745DC(void) {
    func_80174684(func_80174604);
}
