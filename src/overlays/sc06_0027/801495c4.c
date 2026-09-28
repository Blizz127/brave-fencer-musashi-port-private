/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801495C4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012F14C(s32 a0, s32 a1, s32 a2);
extern void func_8012EF70(s32, s32);

void func_801495C4(s32 a0, s32 a1) {
    s16 in[4];
    s16 result[4];
    s16 buf[4];
    s16 *pin;
    s16 *m1;
    s16 *m2;
    s32 mtx;
    in[0] = *(u16 *)(a1 + 0x2);
    in[1] = *(u16 *)(a1 + 0x6);
    in[2] = *(u16 *)(a1 + 0xA);
    pin = in;                  __asm__ __volatile__("" : "=r"(pin) : "0"(pin));
    mtx = *(s32 *)(a0 + 0x20); __asm__ __volatile__("" : "=r"(mtx) : "0"(mtx));
    m1 = buf;                  __asm__ __volatile__("" : "=r"(m1) : "0"(m1));
    ((void (*)(s32, void *, void *))func_8012F14C)(mtx + 0x34, pin, m1);
    m2 = buf;                  __asm__ __volatile__("" : "=r"(m2) : "0"(m2));
    ((void (*)(void *, void *))func_8012EF70)(m2, result);
    *(s16 *)(a1 + 0x2) = result[0];
    *(s16 *)(a1 + 0x6) = result[1];
    *(s16 *)(a1 + 0xA) = result[2];
}
