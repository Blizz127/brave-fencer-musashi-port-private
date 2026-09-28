/* SC02.CD FILE_031 / ov_SC02_031 retail span [80157A8C,80157AC8).
 * Offset 0x2F934 at overlay base 80128158. SHA256(span)=91fdc82b3d341ac21d4ccbd56cf91870ba5a928647ceb131737c46dfacd4754a.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80157a8c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80157A8C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80161D20();
extern void func_8014C010(s32 a0, s32 a1);

void func_80157A8C(s32 a0) {
    func_80161D20(a0, *(u16 *)(a0 + 0x16E));
    func_8014C010(a0, 1);
}
