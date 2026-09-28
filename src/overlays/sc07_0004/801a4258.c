/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A4258 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_801F8744[];
extern s16 D_801F8870;
extern s16 D_801F8872;
extern s16 D_801F8874;
extern s16 D_801F8878;
extern s16 D_801F887A;
extern s16 D_801F887C;
extern s16 D_801F8880;
extern s16 D_801F8882;
extern s16 D_801F8884;

void func_801A4258(void) {
    s32 pad[6];
    register s16 *p __asm__("$5");
    register s32 t __asm__("$3");
    register s32 u __asm__("$4");
    register s32 sum __asm__("$2");
    register s32 zr __asm__("$0");
    s32 q;

    (void)&pad;
    __asm__ __volatile__("" ::: "memory");
    p = &D_801F8870;

    t = *p;
    if (t != D_801F8878) {
        u = t + zr;
        sum = u + (u16)D_801F8880;
        q = (u32)sum >> 7;
        *p = (s16)sum;
        D_801F8744[0] = (u8)q;
    }

    t = D_801F8872;
    if (t != D_801F887A) {
        u = t + zr;
        sum = u + (u16)D_801F8882;
        q = (u32)sum >> 7;
        D_801F8872 = (s16)sum;
        D_801F8744[1] = (u8)q;
    }

    t = D_801F8874;
    if (t != D_801F887C) {
        u = t + zr;
        sum = u + (u16)D_801F8884;
        q = (u32)sum >> 7;
        D_801F8874 = (s16)sum;
        D_801F8744[2] = (u8)q;
    }
}
