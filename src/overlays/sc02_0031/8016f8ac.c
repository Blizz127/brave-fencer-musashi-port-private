/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016F8AC,8016F8E4).
 * Offset 0x47754 at overlay base 80128158. SHA256(span)=77126bb2f33eb31edfa94eccc5edf80b48af6b64638a4dd30f61a618de834e92.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016f8ac.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016F8AC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void *D_8011F738;
extern void func_80172358(u8 *a0, u8 *a1);
extern void func_80171928(void *a0);
extern void func_8012A568(void (*a0)(void));

void func_8016F8AC(u8 *a0) {
    func_80172358(a0, (u8 *)&D_8011F738);
    func_80171928(a0);
}
