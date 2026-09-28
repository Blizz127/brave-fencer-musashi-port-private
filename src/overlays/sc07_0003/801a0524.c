/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A0524 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32  func_801789AC(void);
extern void func_80178D18();
extern void func_8017BF08(void *, void *, s32, s32);
extern void func_8012C218(void *);
extern s32  func_8012C194(void);
extern void func_800233CC(void *, u16);
extern void func_8001CD9C(s32, void *);
extern void func_8012A568(void *);
extern void func_8017F004(void);
extern s32 D_801F4358;
extern s32 D_801F4318;
extern s32 D_801F431C;
extern s32 D_801F4320;
extern s32 D_801F4324;

void func_801A0524(s32 a0) {
    s32 s0;
    s32 *p;

    s0 = a0;
    if (func_801789AC() == 1) {
        func_80178D18(s0);
        func_8017BF08((void *)(s0 + 0x76), (void *)*(s32 *)(s0 + 0x78), 0xA, 0x120);
        *(s16 *)(s0 + 2) = 3;
        func_8012C218(*(void **)(s0 + 0xD8));
        *(s32 *)(s0 + 0xD8) = 0;
        D_801F4358 = func_8012C194();
        if (D_801F4358 != 0) {
            p = &D_801F4318;
            *p = 0;
            D_801F431C = 0;
            D_801F4320 = 0;
            D_801F4324 = 0;
            func_800233CC(p, 0x60);
            func_8001CD9C(D_801F4358, p);
            *(u16 *)(D_801F4358 + 0x2C) = 0xC010;
            *(s32 *)(D_801F4358 + 4) |= 0x50000000;
        }
        func_8012A568(func_8017F004);
    }
}
