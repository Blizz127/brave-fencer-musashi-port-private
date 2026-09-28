/* SC02.CD FILE_031 / ov_SC02_031 retail span [80170670,801706AC).
 * Offset 0x48518 at overlay base 80128158. SHA256(span)=f1233c5070c566fc20f9193f231155cfca78b4c4c9193b4c3d893da84a25dc91.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80170670.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80170670 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void *D_8011F738;
extern void func_8012A568(void (*a0)(void));
extern void func_80171928(void *a0);

void func_80170670(void *a0) {
    func_8012A568((void (*)(void))D_8011F738);
    func_80171928(a0);
}
