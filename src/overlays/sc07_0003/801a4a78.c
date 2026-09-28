/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A4A78 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801A4D58(s32 a0, s32 a1);
extern s32 func_801A4DFC(void *a0);
extern s32 func_8012BEE8(s32 a0);
extern s32 func_8012B744(void *a0, void *a1);
extern s32 func_8012B608(s32 a0, s32 a1, s32 a2);
extern void func_8012BE98(s32 a0, u16 *a1);
extern s32 func_8012B8A4(s16 *a0);
extern s32 func_80132EF4(s32 a0, s32 a1);
extern void func_8012CBCC(s32 a0);
extern void func_8012C218(void *a0);
extern u16 D_801F4310[];

void func_801A4A78(s32 arg0) {
    s32 t;
    s32 p;
    s32 q;

    switch (*(u16 *)(arg0 + 0x34)) {
    case 0:
        func_801A4D58(arg0, -0x100000);
        if (func_8012BEE8(arg0) == 0) {
            break;
        }
        *(s32 *)(arg0 + 0x1C) = 0xC;
        *(u16 *)(arg0 + 0x34) = *(u16 *)(arg0 + 0x34) + 1;
        break;

    case 1:
        t = func_8012B744((void *)(arg0 + 4), D_801F4310);
        t = func_8012B608(*(s16 *)(*(s32 *)(arg0 + 0x20) + 0x14), t, 8);
        *(u16 *)(*(s32 *)(arg0 + 0x20) + 0x14) += t;
        func_801A4D58(arg0, -0x100000);
        if (((s32 (*)(s32, u16 *))func_8012BE98)(arg0, D_801F4310) > 0x4000) {
            if (func_8012BEE8(arg0) == 0) {
                break;
            }
        }
        *(s32 *)(arg0 + 0x1C) = 0x50;
        *(u16 *)(arg0 + 0x34) = *(u16 *)(arg0 + 0x34) + 1;
        break;

    case 2:
        t = func_8012B8A4((s16 *)arg0);
        t = func_8012B608(*(s16 *)(*(s32 *)(arg0 + 0x20) + 0x14), t, 0x18);
        *(u16 *)(*(s32 *)(arg0 + 0x20) + 0x14) += t;
        func_801A4D58(arg0, -0x100000);
        if (*(s32 *)(arg0 + 0x1C) == 0x10) {
            *(u16 *)(*(s32 *)(arg0 + 0x20) + 0x2C) |= 0x80;
            p = *(s32 *)(*(s32 *)(arg0 + 0x20) + 0x80);
            *(s16 *)(p + 4) = 0x80;
            *(s16 *)(p + 2) = 0x80;
            *(s16 *)(p + 0) = 0x80;
            *(u16 *)(arg0 + 0x34) = *(u16 *)(arg0 + 0x34) + 1;
        }
        /* fallthrough */
    case 3:
        if (*(s32 *)(arg0 + 0x1C) < 0x11) {
            p = *(s32 *)(*(s32 *)(arg0 + 0x20) + 0x80);
            *(u16 *)(p + 0) -= 8;
            *(u16 *)(p + 2) -= 8;
            *(u16 *)(p + 4) -= 8;
        }
        if (func_8012BEE8(arg0) != 0) {
            func_8012C218((void *)arg0);
            return;
        }
        break;
    }

    if (*(u16 *)(arg0 + 0x72) & 0x4000) {
        q = func_80132EF4(arg0, 0x6F);
        if (q != 0) {
            *(s32 *)(q + 0x10) = -(*(s32 *)(arg0 + 0x10) * 2);
            *(s32 *)(q + 0x14) = *(s32 *)(arg0 + 0x14);
            *(s32 *)(q + 0x18) = -(*(s32 *)(arg0 + 0x18) * 2);
        }
    }
    func_801A4DFC((void *)arg0);
    if (((s32 (*)(s32))func_8012CBCC)(arg0) != 0) {
        func_8012C218((void *)arg0);
    }
}
