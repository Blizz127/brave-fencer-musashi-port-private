/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A3788 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012C218(void *a0);
extern void func_801A38E4(void *a0, void *a1, s32 a2, s32 a3, s32 a4);
extern s32 func_801A419C(s32 a0);
extern s32 func_80153BD8(s32 a0);
typedef struct { s16 a, b, c, d; } V8x_801A3788;

void func_801A3788(void *arg0) {
    register s32 s0 __asm__("$16") = (s32)arg0;
    s32 s1;
    u16 v1;
    s32 v1s;
    s32 pad[8];

    s1 = *(s32 *)(s0 + 0x64);

    if (*(s16 *)(s1 + 0x36) != *(s32 *)(s0 + 0xF8)) {
        func_8012C218((void *)s0);
        return;
    }

    func_801A38E4((void *)s1, (void *)(s0 + 0xCC), 0x10, 6, 0);

    *(V8x_801A3788 *)(*(s32 *)(s0 + 0x20) + 0x10) = *(V8x_801A3788 *)(*(s32 *)(s1 + 0x20) + 0x10);

    *(s32 *)(s0 + 0x4) = *(s32 *)(s1 + 0x4);
    *(s32 *)(s0 + 0x8) = *(s32 *)(s1 + 0x8);
    *(s32 *)(s0 + 0xC) = *(s32 *)(s1 + 0xC);

    v1 = *(u16 *)(s0 + 0x34);

    switch (v1) {
    default:
        v1s = v1;
        if (v1s < 2) {
            if (v1 != 0) {
                break;
            }
            if (func_801A419C(s0) == 1) {
                (*(u16 *)(s0 + 0x34))++;
            }
        }
        break;
    case 1:
        if (func_80153BD8(s0) != 0) {
            *(s32 *)(s1 + 0xE0) |= 8;
        }
        (*(u16 *)(s0 + 0x34))++;
        break;
    }
}
