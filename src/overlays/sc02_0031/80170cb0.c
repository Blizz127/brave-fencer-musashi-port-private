/* SC02.CD FILE_031 / ov_SC02_031 retail span [80170CB0,80170CF0).
 * Offset 0x48B58 at overlay base 80128158. SHA256(span)=7696632a837de359506f4302ae6c56d360fd678cd9b1c23cae99690e14f648a8.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80170cb0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80170CB0 - byte-exact against retail at -O2 (tools/register_match.py). */
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
extern s32 func_8017197C(u8 *a0);
extern void func_80170CF0(void *a0);

void func_80170CB0(u8 *a0) {
    func_801719A4((int)a0, 3);
    a0[0x217] = 0;
    func_8017197C(a0);
    func_80170CF0(a0);
}
