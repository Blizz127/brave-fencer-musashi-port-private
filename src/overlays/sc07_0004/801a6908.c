/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A6908 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_801A3798(s32 a0, s32 a1);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012B200(u8 *a0);
extern void func_8012AD44(s32 *a0, s16 a1);
extern void func_801A4328(s32 a0);
extern void func_800183E0(s32);
extern void func_8017F418(void);
extern void func_801A46D4(s32 a0);
extern s32 D_801EEAC8;
extern s16 D_801F8714;
extern s32 D_801C65E4;
extern s32 D_801AFBC4;
extern u16 D_8019FF8A;
extern s32 D_801C6644;

void func_801A6908(s32 s0) {
    register s32 *p __asm__("$4");
    register u16 t5c __asm__("$2");
    u16 f9;
    if (func_801A3798(s0, 1) != 0) {
        func_8012A828(s0, &D_801EEAC8);
        *(s32 *)(s0 + 0x1C) = (s16)(D_801F8714 / 79) + 0x18;
        func_8012B200((u8 *)s0);
        func_8012AD44((s32 *)s0, 1);
        *(s32 *)(s0 + 0x1C) = 1;
        func_801A4328(0);
        p = &D_801C65E4;
        __asm__ __volatile__("" : : "r"(p));
        t5c = *(u16 *)(s0 + 0x5C) | 0x2000;
        *(s32 *)(s0 + 0x58) = (s32)&D_801AFBC4 | 0x40000000 | 0x20000000;
        f9 = D_8019FF8A & 0xF9FF;
        *(u16 *)(s0 + 0x5C) = t5c;
        D_8019FF8A = f9;
        ((s32 (*)(s32 *))func_800183E0)(p);
        ((s32 (*)(s32 *))func_800183E0)(&D_801C6644);
        func_8017F418();
        func_801A46D4(s0);
    }
}
