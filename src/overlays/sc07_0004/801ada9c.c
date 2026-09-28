/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801ADA9C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801AE990(void *a0);
extern void func_801ADBB0(s32 a0, s32 a1, s32 a2);

void func_801ADA9C(s32 arg0) {
    s16 sp10[3];
    register s16 *p __asm__("$3") = (s16 *)arg0;
    s32 i;
    s32 j;

    sp10[0] = p[3];
    sp10[1] = p[5] - 0x40;
    sp10[2] = p[7] + 0x20;
    func_801AE990(sp10);

    j = 2;
    i = 0;
    func_801ADBB0(0x400, 0, 0);
    func_801ADBB0(-0x400, 0, 1);

    for (; i < 8; i++) {
        func_801ADBB0(0, (i << 25) >> 16, (j << 16) >> 16);
        j++;
    }

    for (i = 0; i < 8; i++) {
        func_801ADBB0(0x200, (0x1000000 + i * 0x2000000) >> 16, (j << 16) >> 16);
        j++;
    }

    for (i = 0; i < 8; i++) {
        func_801ADBB0(-0x200, (0x1000000 + i * 0x2000000) >> 16, (j << 16) >> 16);
        j++;
    }
}
