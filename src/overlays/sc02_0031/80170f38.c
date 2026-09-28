/* SC02.CD FILE_031 / ov_SC02_031 retail span [80170F38,80170F74).
 * Offset 0x48DE0 at overlay base 80128158. SHA256(span)=0acb4616ada454d4fd8001ca17d9c846438cdcf2831451da779864854da897e2.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80170f38.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80170F38 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_801719A4(int a0, int a1);
extern s32 func_80171990(u8 *a0);
extern void func_80170F74(void *a0);

void func_80170F38(u8 *a0) {
    func_801719A4((int)a0, 1);
    func_80171990(a0);
    func_80170F74(a0);
}
