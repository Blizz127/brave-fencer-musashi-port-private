/* SC02.CD FILE_031 / ov_SC02_031 retail span [80173C64,80173CB4).
 * Offset 0x4BB0C at overlay base 80128158. SHA256(span)=4498e7a665d7cadf0bb79bae95eba314124de38c9f68e8da8fbd198d8777a560.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80173c64.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80173C64 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern s32 func_80171CC4(void *a0, void *a1);
extern void func_80171A1C(u8 *a0);
extern s16 D_80126B36;

void func_80173C64(u8 *a0) {
    s16 *p = &D_80126B36;
    if (*p != 0) {
        if (func_80171CC4(a0, p - 3) == 0) {
            return;
        }
    }
    func_80171A1C(a0);
}
