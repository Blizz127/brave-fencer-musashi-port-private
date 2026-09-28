/* Complete SC02 retail span [80143CD4,80143D28).
 * Live STOP 43970 before 44054; PAC0 member31.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80143CD4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 func_8012C658(s32 a0, s32 a1, s32 a2);

void func_80143CD4(s32 a0) {
    func_8012C658(0x39, 0, a0);
    func_8012C658(0x39, 1, a0);
    func_8012C658(0x39, 2, a0);
}
