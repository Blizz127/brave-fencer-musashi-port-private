/* SC02.CD FILE_031 / ov_SC02_031 retail span [80170018,80170068).
 * Offset 0x47EC0 at overlay base 80128158. SHA256(span)=ba1962a1ac766aa761fbe0a2b9a2bdbfb75f20ee9b305965e8cf033c624ccba7.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80170018.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80170018 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801719A4(int a0, int a1);
extern s32 func_8013767C(s32 a0);
extern s32 func_80171990(u8 *a0);
extern void func_80170068(u8 *a0);
extern void *D_8011F738;
extern void func_8012A568(void (*a0)(void));

void func_80170018(u8 *a0) {
    func_801719A4((int)a0, 1);
    *(s32 *)(a0 + 0x198) = func_8013767C((s32)D_8011F738);
    func_80171990(a0);
    func_80170068(a0);
}
