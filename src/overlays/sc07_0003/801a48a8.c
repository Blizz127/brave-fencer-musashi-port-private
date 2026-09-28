/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A48A8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001CA1C(s32 a0, s32 a1);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012B2CC(s32 a0);
extern void func_8012B260(u8 *a0);
extern s32 func_8012C658(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_8005C49C(void);
extern void func_801A484C(s32 a0, s32 a1);
extern u8 D_801A6F08[];
extern u8 D_801A7148[];
extern u16 D_801A7314[];

void func_801A48A8(void *arg0) {
    register s32 s0 __asm__("$16") = (s32)arg0;
    register s32 s1 __asm__("$17");

    s1 = func_8012C1B8();
    if (s1 == 0) {
        func_8012CAE4((void *)s0);
        return;
    }

    *(s32 *)(s0 + 0x20) = s1;
    func_8001CA1C(s1, (s32)D_801A6F08);
    func_8012A828(s0, (void *)D_801A7148);

    {
        u16 t70 = *(u16 *)(s0 + 0x70);
        s16 val = 0x5000 - ((t70 & 0xF) << 11);
        *(s16 *)(s1 + 0x1C) = val;
        *(s16 *)(s1 + 0x1A) = val;
        *(s16 *)(s1 + 0x18) = val;
    }
    *(s32 *)(s1 + 0x4) = *(s32 *)(s1 + 0x4) | 0x50000000;
    *(s16 *)(s1 + 0x2C) = *(u16 *)(s1 + 0x2C) | 0x90;

    *(s16 *)(s0 + 0x10A) = *(u16 *)(*(s32 *)(s0 + 0x64) + 0x36);

    if ((*(u16 *)(s0 + 0x70) & 0xF) == 0) {
        s32 p = *(s32 *)(*(s32 *)(s0 + 0x64) + 0x20);
        u16 t = *(u16 *)(p + 0x12);
        s16 sum;
        s32 d;
        s32 v0;

        *(s16 *)(s1 + 0x14) = t;
        sum = t + D_801A7314[*(u16 *)(s0 + 0x70) >> 15];
        *(s16 *)(s1 + 0x14) = sum;
        func_8012B2CC(s0);

        d = func_8005C49C();
        s1 = s0 + 0xE4;
        *(s32 *)(s0 + 0x94) = d % 0x10;
        *(s32 *)(s0 + 0x1C) = 0xC;
        *(s32 *)(*(s32 *)(s0 + 0x20) + 0x80) = s1;
        *(s16 *)(s0 + 0xE8) = 0x80;
        *(s16 *)(s0 + 0xE6) = 0x80;
        *(s16 *)(s0 + 0xE4) = 0x80;
        v0 = func_8012C658(0x378, 1, s0);
        if (v0 != 0) {
            func_801A484C(v0, 2);
        }
        *(s16 *)(s0 + 0x2) = *(u16 *)(s0 + 0x2) + 1;
        return;
    }

    {
        s32 p = *(s32 *)(*(s32 *)(s0 + 0x64) + 0x20);
        s32 slot = *(s32 *)(s0 + 0x20);
        s32 d;
        *(s32 *)(slot + 0x80) = *(s32 *)(p + 0x80);
        d = func_8005C49C();
        *(s32 *)(s0 + 0x94) = d % 0x10;
        *(s16 *)(s0 + 0x2) = 2;
        func_8012B260((u8 *)s0);
    }
}
