/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A1C7C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801A395C(s32 a0, s32 a1);
extern void func_8013240C(s32 a0);
extern void func_8001C924(s32 a0, void *a1);
extern void func_8012A860(void *a0, int a1);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012B200(u8 *a0);
extern void func_8012AD44(s32 *a0, s16 a1);
extern void func_801A4328(s32 a0);
extern void func_800183E0(s32 a0);
extern s32 D_801B6E94[0x11];
extern u8 D_801EF9A8;
extern s32 D_801EEAC8;
extern s16 D_801F8714;
extern s16 D_801F872A;
extern s32 D_801F8730;
extern s32 D_801AFBC4;
extern s32 D_801C65E4;
extern s32 D_801C6644;
extern u16 D_8019FF8A;

void func_801A1C7C(s32 s0) {
    register s32 *p __asm__("$4");
    register u16 t5c __asm__("$2");
    s32 v0;
    s32 *q;
    u16 f9;

    v0 = ((s32 (*)(s32, s32))func_801A395C)(s0, -0x240);
    switch (*(u16 *)(s0 + 0x34)) {
    case 0:
        q = &D_801F8730;
        *q &= ~0x4000;
        D_801F872A -= 4;
        if (D_801F872A < -1) {
            D_801F872A = -1;
        }
        func_8013240C((s32)q - 0xC);
        if (D_801F872A <= 0) {
            *(u16 *)(s0 + 0x34) += 1;
        }
        break;
    case 1:
        func_8001C924(*(s32 *)(s0 + 0x20), D_801B6E94);
        func_8012A860((void *)s0, (int)&D_801EF9A8);
        *(u16 *)(s0 + 0x34) += 1;
        break;
    case 2:
        if (*(s16 *)(s0 + 0x98) == 0 && v0 != 0) {
            func_8012A828(s0, &D_801EEAC8);
            *(s32 *)(s0 + 0x1C) = (s16)(D_801F8714 / 79) + 0x18;
            func_8012B200((u8 *)s0);
            func_8012AD44((s32 *)s0, 1);
            *(s32 *)(s0 + 0x1C) = 0x10;
            func_801A4328(0);
            p = &D_801C65E4;
            __asm__ __volatile__("" : : "r"(p));
            *(s16 *)(s0 + 0xAE) = -1;
            *(s32 *)(s0 + 0x58) = (s32)&D_801AFBC4 | 0x40000000 | 0x20000000;
            t5c = *(u16 *)(s0 + 0x5C) | 0x2000;
            f9 = D_8019FF8A & 0xF9F7;
            *(u16 *)(s0 + 0x5C) = t5c;
            D_8019FF8A = f9;
            ((s32 (*)(s32 *))func_800183E0)(p);
            ((s32 (*)(s32 *))func_800183E0)(&D_801C6644);
        }
        break;
    }
}
