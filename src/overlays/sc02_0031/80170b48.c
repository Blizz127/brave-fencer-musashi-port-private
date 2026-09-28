/* SC02.CD FILE_031 / ov_SC02_031 retail span [80170B48,80170B90).
 * Offset 0x489F0 at overlay base 80128158. SHA256(span)=2e3e6913015c2277aa2c3a68eb40f79c820b57929a0c9600a3c4ac1637549e10.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80170b48.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80170B48 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_80170B90(u8 *a0);

void func_80170B48(int a0)
{
    extern void *D_8011F738;
    extern void func_8014706C(void *a0);
    extern void func_80154274(s32 *a0, s32 a1);
    extern s32 func_80171990(u8 *a0);
    func_8014706C(a0);
    func_80154274((s32 *)a0, (s32)D_8011F738);
    func_80171990((u8 *)a0);
    func_80170B90((u8 *)a0);
}
