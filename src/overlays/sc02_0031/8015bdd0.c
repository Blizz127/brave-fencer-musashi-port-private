/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015BDD0,8015BE04).
 * Offset 0x33C78 at overlay base 80128158. SHA256(span)=6a265b17862a26e83ea45f43ef0643832d23a4b680d2a731a87493e61499927a.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015bdd0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015BDD0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80147078(s32 *a0, s16 a1);
extern s32 func_8015BE94();

void func_8015BDD0(s32 *a0) {
    func_80147078(a0, 3);
    ((s32 (*)(void *))func_8015BE94)(a0);
}
