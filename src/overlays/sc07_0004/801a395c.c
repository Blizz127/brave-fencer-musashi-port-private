/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A395C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_801A395C(s32 a0, s32 a1) {
    register s32 ret __asm__("$2");
    s16 cur;
    s16 t;
    s32 overshot;

    t = (s16)a1;
    cur = *(s16 *)(a0 + 0xA);
    if (cur == t) {
        __asm__ __volatile__("");
        ret = 1;
    } else {
        if (t < cur) {
            cur -= 2;
            *(s16 *)(a0 + 0xA) = cur;
            overshot = (t < cur);
        } else {
            cur += 2;
            *(s16 *)(a0 + 0xA) = cur;
            overshot = (cur < t);
        }
        if (overshot) {
            ret = 0;
        } else {
            *(s16 *)(a0 + 0xA) = t;
            ret = 1;
        }
    }
    __asm__ __volatile__("" :: "r"(ret));
}
