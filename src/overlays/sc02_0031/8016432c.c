/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016432C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80164418();
extern s32 func_80146E98(s32 a0);
extern void func_801553C0(s32 a0);
extern void func_80147364();
extern void func_80147324(s32 arg0);
extern void func_80162CCC();

void func_8016432C(s32 a0) {
    s32 s1 = a0;
    s32 s0 = *(s32 *)(s1 + 0x4C);
    func_80164418();
    if (func_80146E98(s1) != 0) {
        u32 v44;
        *(u16 *)(s0 + 0x18A) = 0;
        if (*(s32 *)(s0 + 0x184) != 0 &&
            ((v44 = *(u32 *)(s0 + 0x44)) & 0x400) == 0 &&
            (*(u32 *)(s0 + 0x1F8) & 0x80FFFFFF) == 0) {
            *(u32 *)(s0 + 0x44) = v44 | 0x10;
            if (*(s16 *)(s0 + 0x188) < 0x80) {
                *(u32 *)(s0 + 0x184) = *(u32 *)(s0 + 0x184) | 0x80000000;
            }
        } else {
            *(s32 *)(s0 + 0x184) = 0;
        }
        *(u16 *)(s0 + 0x188) = 0;
        __asm__ __volatile__("" : : "r"(s0));
        *(u32 *)(s0 + 0x44) = *(u32 *)(s0 + 0x44) & 0xFFFFFFFB;
        func_801553C0(s0);
        func_80147364(4, 0x449);
        func_80147324(0x44B);
        ((void (*)(s32))func_80162CCC)(s1);
    }
}
