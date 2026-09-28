/* SC02.CD FILE_031 / ov_SC02_031 retail span [80172C50,80172CA0).
 * Offset 0x4AAF8 at overlay base 80128158. SHA256(span)=08eeed6b49538162ba1611a029b5343d00b7dc317ff3c12de1362da6697767e9.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80172c50.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80172C50 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

struct S8_80172780 { s16 m[4]; };
extern void func_8012A568(void (*a0)(void));
extern void func_80174684(void *);
extern void func_80172CA0(void*);

void func_80172C50(void *a0) {
    extern s16 D_80126B30;
    *(struct S8_80172780 *)&D_80126B30 = *(struct S8_80172780 *)a0;
    func_80174684((void *)func_80172CA0);
}
