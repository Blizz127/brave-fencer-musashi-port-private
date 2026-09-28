/* Complete SC02 retail span [8014964C,801496D4).
 * PAC0 member31 words.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014964C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct {
    /* 0x00 */ s16 f0;
    /* 0x02 */ s16 f2;
    /* 0x04 */ s16 f4;
    /* 0x06 */ s16 pad6;
} Vec3;
extern void func_8012F14C(s32 a0, s32 a1, s32 a2);
extern void func_8012EFB8(s32 a0);

void func_8014964C(s32 param_1, s32 param_2) {
    Vec3 in;
    Vec3 out;
    s32 mid[2];
    register s32 p2 __asm__("$16");
    Vec3 *pin;
    s32 *m1;
    s32 *m2;
    s32 mtx;
    p2 = param_2;
    in.f0 = *(s16 *)(p2 + 2);
    in.f2 = *(s16 *)(p2 + 6);
    in.f4 = *(s16 *)(p2 + 0xA);
    pin = &in;
    __asm__ __volatile__("" : "=r"(pin) : "0"(pin));
    mtx = *(s32 *)(param_1 + 0x20);
    __asm__ __volatile__("" : "=r"(mtx) : "0"(mtx));
    m1 = mid;
    __asm__ __volatile__("" : "=r"(m1) : "0"(m1));
    ((void (*)(s32, Vec3 *, s32 *))func_8012F14C)(mtx + 0x34, pin, m1);
    m2 = mid;
    __asm__ __volatile__("" : "=r"(m2) : "0"(m2));
    ((void (*)(s32 *, Vec3 *))func_8012EFB8)(m2, &out);
    *(s16 *)(p2 + 2) = out.f0;
    *(s16 *)(p2 + 6) = out.f2;
    *(s16 *)(p2 + 0xA) = out.f4;
}
