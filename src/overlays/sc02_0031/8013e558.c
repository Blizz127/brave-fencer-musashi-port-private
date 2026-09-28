/* SC02.CD FILE_031 / ov_SC02_031 retail span [8013E558,8013E588).
 * Offset 0x16400 at overlay base 80128158. SHA256(span)=d28a3284efc8f47ce717962f75d073e0cc8d17b07285599354313dd82f884459.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8013e558.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8013E558 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_800D24A0(s32 a0);
extern void func_80141788(void);
extern void *D_8011DB24;

void func_8013E558(void) {
    func_800D24A0(2);
    D_8011DB24 = (void *)func_80141788;
}
