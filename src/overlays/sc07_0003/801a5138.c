/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A5138 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32  func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001C214(s32 a0, s32 a1);
extern void func_8012B2CC(s32 a0);
extern s32  func_8012C194(void);
extern void func_800233CC(void *a0, u16 a1);
extern void func_8001CD9C(s32 a0, void *a1);
extern s32  func_8005C49C(void);
extern u16 D_801A73D4[];
extern s32 D_801F4484;
extern s32 D_801F4488;
extern s32 D_801F448C;
extern s32 D_801F4490;

void func_801A5138(s32 a0) {
    s32 s2;
    s32 obj;
    s32 o1;
    s32 o2;
    s32 base;
    s32 off;
    s32 v;
    s32 s1;
    s32 p64;
    u16 tmp;
    s32 *p;

    s2 = a0;
    obj = func_8012C1B8();
    *(s32 *)(s2 + 0x20) = obj;
    if (obj == 0) {
        func_8012CAE4((void *)s2);
        return;
    }

    func_8001C214(obj, 0);

    o1 = *(s32 *)(s2 + 0x20);
    *(u16 *)(o1 + 0x10) = D_801A73D4[*(s16 *)(s2 + 0x70)];

    o2 = *(s32 *)(s2 + 0x20);
    off = func_8005C49C() % 0x100;
    base = *(s16 *)(s2 + 0xFC);
    if (func_8005C49C() & 1) {
        v = base + off;
    } else {
        v = base - off;
    }
    *(s16 *)(o2 + 0x12) = v;

    func_8012B2CC(s2);

    *(s16 *)(s2 + 0xFE) = (func_8005C49C() % 0x20) + 0x20;

    p64 = *(s32 *)(s2 + 0x64);
    tmp = *(u16 *)(p64 + 0x36);
    *(u16 *)(s2 + 0x2) = *(u16 *)(s2 + 0x2) + 1;
    *(s16 *)(s2 + 0x10A) = tmp;

    s1 = func_8012C194();
    if (s1 == 0) {
        return;
    }

    *(s32 *)(s2 + 0xCC) = s1;
    p = &D_801F4484;
    *p = 0xC0C0C0;
    D_801F4488 = 0;
    D_801F448C = 0;
    D_801F4490 = 0;
    func_800233CC((void *)p, 0x60);
    func_8001CD9C(s1, (void *)p);
    *(u16 *)(s1 + 0x2C) = 0xC010;
    *(s32 *)(s1 + 0x4) = *(s32 *)(s1 + 0x4) | 0x50800000;
    *(u16 *)(s1 + 0x8) = *(u16 *)(s2 + 0x6);
    *(u16 *)(s1 + 0xA) = *(u16 *)(s2 + 0xA);
    *(u16 *)(s1 + 0xC) = *(u16 *)(s2 + 0xE);
}
