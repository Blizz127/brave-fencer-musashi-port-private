/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016F764,8016F798).
 * Offset 0x4760C at overlay base 80128158. SHA256(span)=0ca32a1aae5a8dd28eb71a5f6c06477cb5f8728c27ac43fdb0d6c1de962cbfc1.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016f764.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016F764 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80171928(void *a0);
extern void func_8012A568(void (*a0)(void));

void func_8016F764(void *a0) {
    s32 v0 = *(s32 *)((u8 *)a0 + 0x200) - 1;
    *(s32 *)((u8 *)a0 + 0x200) = v0;
    if (v0 == -1) {
        func_80171928(a0);
    }
}
