/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012BB3C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 func_8004CFEC(s32 a0, s32 a1);

s32 func_8012BB3C(s32 arg0, s32 arg1, u32 arg2, s32 arg3) {
    register s32 a __asm__("$17");   /* $s1 */
    register s32 div __asm__("$16"); /* $s0 */
    register s32 q __asm__("$3");    /* $v1 */
    register s32 d __asm__("$2");    /* $v0 */
    s32 ang;
    s32 diff;
    u32 cur;
    a = arg2;
    div = arg3;
    ang = func_8004CFEC(*(s16 *)(arg0 + 0xA) - *(s16 *)(arg1 + 0xA),
                 *(s16 *)(arg1 + 0x2) - *(s16 *)(arg0 + 0x2));
    ang = ang - 0x400;
    __asm__ __volatile__("" : : "r"(ang));
    div = (s16)div;
    a = a & 0xFFF;
    cur = ang & 0xFFF;
    if (a == cur) {
        d = 0;
    } else {
        s32 t;
        diff = cur - a;
        if (0x800 < diff) {
            t = a + 0x1000;
            diff = cur - t;
        }
        if (diff < -0x800) {
            t = a - 0x1000;
            diff = cur - t;
        }
        if (diff >= 0) {
            q = diff / div;
            if (q == 0) {
                q = 1;
            }
        } else {
            q = diff / div;
            if (q == 0) {
                q = -1;
            }
        }
        d = q;
    }
    return (s16)d;
}
