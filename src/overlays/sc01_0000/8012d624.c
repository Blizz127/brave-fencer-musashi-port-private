/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012D624 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern int func_8012D664();

void func_8012D624(s32 a0) {
    u16 sp[3];
    sp[0] = *(u16 *)(a0 + 0x6);
    sp[1] = *(u16 *)(a0 + 0xA);
    sp[2] = *(u16 *)(a0 + 0xE);
    func_8012D664((void *)sp);
}
