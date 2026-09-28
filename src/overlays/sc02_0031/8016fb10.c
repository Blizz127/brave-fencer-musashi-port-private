/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016FB10,8016FB50).
 * Offset 0x479B8 at overlay base 80128158. SHA256(span)=38b94c950d357223e635c333631e1ff69874404115d0da1f08495016c404d6bb.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016fb10.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016FB10 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void *D_8011F738;
extern s32 func_80171CC4(void *a0, void *a1);
extern s32 func_80171990(u8 *a0);
extern void func_8012A568(void (*a0)(void));

void func_8016FB10(void *a0) {
    if (func_80171CC4(a0, &D_8011F738)) {
        func_80171990((u8 *)a0);
    }
}
