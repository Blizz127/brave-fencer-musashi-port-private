/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800D2A24 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_800EC9E8[4];
extern s32 func_800435CC(s32 mode, void *buf, void *param);
extern s32 func_8004657C(s32 count);

void func_800D2A24(s32 a0) {
    u8 *p;
    s32 r;
    register s32 v0 __asm__("$2");

retry:
    p = D_800EC9E8;
    for (;;) {
        r = func_800435CC(2, (void *)a0, p);
        if (*p & 0x10) {
            goto ret1;
        }
        if (r != 0) {
            break;
        }
    }
    if (func_8004657C(0x1C0) == 0) {
        goto retry;
    }
    v0 = 0;
    __asm__ __volatile__("" : : "r"(v0));
    return;

ret1:
    v0 = 1;
    __asm__ __volatile__("" : : "r"(v0));
    return;
}
