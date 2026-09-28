/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014CD0C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_8014CF04(s32 a0, s32 a1, void *a2);
extern int func_8014CD80(s32 a0, u16 *a1, u16 *a2);

void func_8014CD0C(u8 *a0) {
    u16 sp10[3];
    u16 sp18[3];
    u16 b;
    u16 c;
    u16 d;
    b = *(u16 *)(a0 + 0x6);
    sp18[0] = b;
    sp10[0] = b;
    c = *(u16 *)(a0 + 0xA);
    sp10[1] = c - 3;
    d = *(u16 *)(a0 + 0xE);
    sp18[1] = c + 5;
    sp18[2] = d;
    sp10[2] = d;
    if (*(s32 *)(a0 + 0x174) == 0) {
        func_8014CF04((s32)a0, sp10, sp18);
    } else {
        func_8014CD80((s32)a0, sp10, sp18);
    }
}
