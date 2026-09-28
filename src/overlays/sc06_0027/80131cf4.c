/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80131CF4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
s32 aF80131CF4(s32 *a0, s32 a1) __asm__("func_80131CF4");

s32 aF80131CF4(s32 *a0, s32 a1) {
    s32 v0;
    s32 k;
    if (a0 == 0) {
        return 0;
    }
    goto enter;
found:
    return a0[1];
enter:
    if (a0[0] == 0) {
        return 0;
    }
    __asm__ __volatile__("" : "=r"(k) : "0"(0xD) : "memory");
    v0 = a0[0];
    do {
        if (v0 == k) {
            a0 = (s32 *)a0[1];
        } else {
            if (v0 == a1) {
                goto found;
            }
            a0 = (s32 *)((u8 *)a0 + 8);
        }
        v0 = a0[0];
    } while (v0 != 0);
    return 0;
}
