/* SC02.CD FILE_031 / ov_SC02_031 retail span [8017041C,8017044C).
 * Offset 0x482C4 at overlay base 80128158. SHA256(span)=a7085beda4cb50662313d90fdbf00e1b6831384f68651148e238cb7153e97526.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8017041c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017041C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80171990(u8 *a0);
extern void func_8017044C(u8 *a0);
extern void func_8012A568(void (*a0)(void));

void func_8017041C(u8 *a0) {
    func_80171990(a0);
    func_8017044C(a0);
}
