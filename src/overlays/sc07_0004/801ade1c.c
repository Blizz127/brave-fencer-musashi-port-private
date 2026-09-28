/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801ADE1C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { u16 a, b, c, d; } Rec8_801A57E8;
extern void func_800599B8(void *rect, void *data);

void func_801ADE1C(void *a0, u16 *a1, s8 *a2, u8 *a3) {
    Rec8_801A57E8 rect;
    s32 i;
    register void *pos __asm__("$10") = a0;
    register u16 *data __asm__("$11") = a1;
    register u16 *out __asm__("$8");

    __asm__ __volatile__("" : "=r"(pos) : "0"(pos) : "memory");
    __asm__ __volatile__("" : "=r"(data) : "0"(data) : "memory");
    i = 0;
    out = data;
    for (; i < 16; i++) {
        register u32 c0 __asm__("$5");
        register u32 c2 __asm__("$4");
        register u32 c1 __asm__("$3");
        s32 k = i * 3;

        if (a2[k + 0] > 0) {
            a2[k + 0] -= a3[k + 0];
        }
        if (a2[k + 0] < 0) {
            a2[k + 0] = 0;
        }

        if (a2[k + 1] > 0) {
            a2[k + 1] -= a3[k + 1];
        }
        if (a2[k + 1] < 0) {
            a2[k + 1] = 0;
        }

        if (a2[k + 2] > 0) {
            a2[k + 2] -= a3[k + 2];
        }
        if (a2[k + 2] < 0) {
            a2[k + 2] = 0;
        }

        c0 = (u8)a2[k + 0] & 0x7C;
        c1 = (u8)a2[k + 1] & 0x7C;
        c2 = (u8)a2[k + 2] & 0x7C;

        c2 >>= 2;
        c0 <<= 8;
        c1 <<= 3;
        c1 |= 0xFFFF8000u;
        c0 |= c1;
        *out = c2 | c0;

        out++;
    }

    rect.a = *(u16 *)pos;
    rect.b = *(u16 *)((u8 *)pos + 2);
    rect.c = 16;
    rect.d = 1;

    func_800599B8(&rect, data);
}
