/* SC02.CD FILE_031 / ov_SC02_031 retail span [80170374,801703E0).
 * Offset 0x4821C at overlay base 80128158. SHA256(span)=4d086acf72f1c11bc6d394406424c9d0ab607248993a5c4dd9b8be3de1d78343.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80170374.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80170374 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_8014C168(s32 *a0, s32 a1);
extern s16 func_80171AB0(s32 a0, void *a1);
extern void func_80171928(void *a0);
extern void *D_8011F738;
extern void func_8012A568(void (*a0)(void));

void func_80170374(u8 * a0)
{
    s16 sp[4];
    s32 v0;
    v0 = func_8014C168(a0, (s32)D_8011F738);
    sp[0] = *(u16 *)(v0 + 0x6);
    sp[1] = *(u16 *)(v0 + 0xA);
    sp[2] = *(u16 *)(v0 + 0xE);
    if (func_80171AB0((s32)a0, sp) == 0) {
        func_80171928(a0);
    }
}
