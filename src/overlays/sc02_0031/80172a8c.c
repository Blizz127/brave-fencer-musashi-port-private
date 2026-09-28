/* SC02.CD FILE_031 / ov_SC02_031 retail span [80172A8C,80172ACC).
 * Offset 0x4A934 at overlay base 80128158. SHA256(span)=220ac249dce22575b48100df5135e92f63e4307622481aa699cb3436a11e9c76.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80172a8c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80172A8C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern s16 D_80126B30;
extern s32 func_80171CC4(void *a0, void *a1);
extern void func_80171A1C(u8 *a0);

void func_80172A8C(void *a0) {
    if (func_80171CC4(a0, &D_80126B30)) {
        func_80171A1C((u8 *)a0);
    }
}
