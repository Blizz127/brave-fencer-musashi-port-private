/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A1470 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801A3FB0(void *arg0);
extern void func_801A4008(s32 a0);
extern void func_801A41CC(void);
extern void func_801A417C(s32 arg0);
extern void func_801A4328(s32 a0);
extern void func_801A5414(s32 param_1);
extern void func_801A5654(s32 param_1, s16 param_2, s32 param_3);
extern void func_801A5698(u8 *s2, s32 a1);
extern void func_801A6330(void);
extern s32 func_8012B8A4(s16 *a0);
extern s32 func_8012BEE8(s32 a0);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012AD44(s32 *a0, s16 a1);
extern void func_8012B200(u8 *a0);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8017F418(void);
extern s32 D_801F8844[];
extern s32 D_801F8858;
extern s16 D_801F8714;
extern s32 D_801EF928;
extern s32 D_801EEAC8;
typedef struct { u8 pad0[0x34]; u16 f34; } S34_801A1470;

void func_801A1470(s32 s0) {
    s32 v0;
    s32 v1;

    switch (*(u16 *)(s0 + 0x34)) {
    case 0:
        *(u16 *)(s0 + 0xA) = *(u16 *)(s0 + 0xA) + 2;
        if (*(s32 *)(s0 + 0x94) == 0xA) {
            *(u16 *)(s0 + 0x34) = *(u16 *)(s0 + 0x34) + 1;
        }
        break;
    case 1:
        *(u16 *)(s0 + 0xA) = *(u16 *)(s0 + 0xA) - 0x10;
        if (*(s16 *)(*(s32 *)(s0 + 0x20) + 0x18) > 0) {
            *(s16 *)(*(s32 *)(s0 + 0x20) + 0x18) = *(s16 *)(*(s32 *)(s0 + 0x20) + 0x18) - 0x200;
            if (*(s16 *)(*(s32 *)(s0 + 0x20) + 0x18) <= 0) {
                *(s16 *)(*(s32 *)(s0 + 0x20) + 0x18) = -1;
            }
            *(s16 *)(*(s32 *)(s0 + 0x20) + 0x1C) = *(u16 *)(*(s32 *)(s0 + 0x20) + 0x18);
        }
        if (*(s16 *)(s0 + 0x98) != 0) {
            break;
        }
        if (*(s16 *)(*(s32 *)(s0 + 0x20) + 0x18) >= 0) {
            break;
        }
        func_801A3FB0((void *)s0);
        *(s32 *)(s0 + 0x1C) = 0x20;
        *(u16 *)(s0 + 0x34) = *(u16 *)(s0 + 0x34) + 1;
        break;
    case 2:
        if (func_8012BEE8(s0) == 0) {
            break;
        }
        *(u16 *)(s0 + 0x100) = 0;
        func_801A5698((u8 *)s0, 0);
        *(s16 *)(s0 + 0xA) = -0x200;
        func_801A4008(s0);
        func_8012A828(s0, &D_801EF928);
        *(u16 *)(s0 + 0x34) = *(u16 *)(s0 + 0x34) + 1;
        break;
    case 3:
        *(s16 *)(*(s32 *)(s0 + 0x20) + 0x12) = func_8012B8A4((s16 *)s0);
        func_801A5698((u8 *)s0, *(s16 *)(s0 + 0x100));
        if (*(s16 *)(*(s32 *)(s0 + 0x20) + 0x18) < 0x1000) {
            *(s16 *)(*(s32 *)(s0 + 0x20) + 0x18) = *(s16 *)(*(s32 *)(s0 + 0x20) + 0x18) + 0x200;
            *(s16 *)(*(s32 *)(s0 + 0x20) + 0x1C) = *(u16 *)(*(s32 *)(s0 + 0x20) + 0x18);
            if (*(s16 *)(*(s32 *)(s0 + 0x20) + 0x18) < 0x1000) {
                break;
            }
        }
        *(s16 *)(*(s32 *)(s0 + 0x20) + 0x18) = 0x1000;
        *(s16 *)(*(s32 *)(s0 + 0x20) + 0x1C) = 0x1000;
        D_801F8858 = 0;
        *(s32 *)(s0 + 0x1C) = 0;
        ((S34_801A1470 *)s0)->f34 = ((S34_801A1470 *)s0)->f34 + 1;
        break;
    case 4:
        if (*(s32 *)(s0 + 0x1C) != 0) {
            *(s32 *)(s0 + 0x1C) = *(s32 *)(s0 + 0x1C) - 1;
        } else {
            v1 = D_801F8858;
            *(s32 *)(s0 + 0x1C) = 5;
            if (v1 < 5) {
                v0 = ((s32 (*)(s32, s16, s32))func_801A5654)(s0, *(s16 *)(s0 + 0x100), v1);
                D_801F8844[D_801F8858] = v0;
                D_801F8858 = D_801F8858 + 1;
                func_8002D4C8(0xABA, 0);
            }
        }
        *(u16 *)(s0 + 0x100) = *(u16 *)(s0 + 0x100) + 0x88;
        *(s16 *)(*(s32 *)(s0 + 0x20) + 0x12) = func_8012B8A4((s16 *)s0);
        func_801A5698((u8 *)s0, *(s16 *)(s0 + 0x100));
        if (*(s16 *)(s0 + 0x100) >= 0x1000) {
            func_801A41CC();
            func_801A3FB0((void *)s0);
            *(u16 *)(s0 + 0x6) = 0;
            *(u16 *)(s0 + 0xE) = 0;
            func_801A6330();
            *(u16 *)(s0 + 0x100) = 0;
            *(s32 *)(s0 + 0x1C) = 0x30;
            *(u16 *)(s0 + 0x34) = *(u16 *)(s0 + 0x34) + 1;
        }
        break;
    case 5:
        *(u16 *)(s0 + 0x102) = *(u16 *)(s0 + 0x102) + 0x10;
        if (func_8012BEE8(s0) != 0) {
            *(u16 *)(s0 + 0x34) = *(u16 *)(s0 + 0x34) + 1;
        }
        break;
    case 6:
        if (func_8012BEE8(s0) == 0) {
            break;
        }
        v0 = D_801F8844[*(s16 *)(s0 + 0x100)];
        if (v0 == 0) {
            break;
        }
        func_801A5414(v0);
        *(u16 *)(s0 + 0x100) = *(u16 *)(s0 + 0x100) + 1;
        if (*(s16 *)(s0 + 0x100) >= 5) {
            *(s32 *)(s0 + 0x1C) = 0x40;
            *(u16 *)(s0 + 0x34) = *(u16 *)(s0 + 0x34) + 1;
        } else {
            *(s32 *)(s0 + 0x1C) = 0xC;
        }
        break;
    case 7:
        if (func_8012BEE8(s0) == 0) {
            break;
        }
        *(s16 *)(s0 + 0xA) = -0x240;
        *(s16 *)(*(s32 *)(s0 + 0x20) + 0x18) = 0x200;
        *(s16 *)(*(s32 *)(s0 + 0x20) + 0x1C) = 0x200;
        func_801A417C(s0);
        func_801A4008(s0);
        *(u16 *)(s0 + 0x34) = *(u16 *)(s0 + 0x34) + 1;
        break;
    case 8:
        *(u16 *)(*(s32 *)(s0 + 0x20) + 0x18) = *(u16 *)(*(s32 *)(s0 + 0x20) + 0x18) + 0x200;
        *(s16 *)(*(s32 *)(s0 + 0x20) + 0x1C) = *(u16 *)(*(s32 *)(s0 + 0x20) + 0x18);
        if (*(s16 *)(*(s32 *)(s0 + 0x20) + 0x18) < 0x1000) {
            break;
        }
        func_8012A828(s0, &D_801EEAC8);
        *(s32 *)(s0 + 0x1C) = (s16)(D_801F8714 / 79) + 0x18;
        func_8012B200((u8 *)s0);
        func_8012AD44((s32 *)s0, 1);
        func_801A4328(0);
        func_8017F418();
        *(u16 *)(s0 + 0x5C) = *(u16 *)(s0 + 0x5C) | 0x2000;
        break;
    }
}
