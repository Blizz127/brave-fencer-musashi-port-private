/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016FED0,8016FF30).
 * Offset 0x47D78 at overlay base 80128158. SHA256(span)=52651b0e1c1b44e692e2875b53e21c8ea8d007eaa431934f0aaed0ea72517c4d.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016fed0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016FED0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80172664(s32 *a0);
extern s32 func_80171CC4(void *a0, void *a1);
extern void func_80171928(void *a0);
extern void *D_8011F738;
extern void func_8012A568(void (*a0)(void));

void func_8016FED0(s32 *a0) {
    if (func_80172664(a0) != 0) {
        *(u16 *)((u8 *)a0 + 0xAA) |= 0x40;
    }
    if (func_80171CC4(a0, &D_8011F738) != 0) {
        func_80171928(a0);
    }
}
