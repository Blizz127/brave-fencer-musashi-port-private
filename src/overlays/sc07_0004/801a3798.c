/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A3798 - byte-exact against retail at -O2 (tools/register_match.py). */
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
extern void func_801A3A6C(u8 *s0);
extern void func_8012B2CC(s32 a0);
extern void func_801A7D18(s32 arg0);
extern s32 func_801A8564(s32 a0);
extern void func_80132288(s32 *a0, s32 *a1, s32 a2);
extern void func_801292C8(u8 *a0);
extern s32 D_801B6E94[0x11];
extern u8 D_801EF9A8;
extern s32 D_801F8724;
extern s32 D_801F8730;
extern s32 D_801BC9EC;
extern s32 *D_801AFB7C[];
extern u16 D_8019FF8A;

s32 func_801A3798(s32 s0, s32 arg1) {
    s32 v0;
    s32 v1;
    s32 y;
    s32 t;
    s32 p;
    u16 f9;
    register s32 zr __asm__("$0");

    v0 = ((s32 (*)(s32, s32))func_801A395C)(s0, (s16)(*(u16 *)(s0 + 0x100) - 0x240));
    y = arg1 + zr;
    __asm__ ("" : "=r" (y) : "0" (y));
    v1 = *(s16 *)(s0 + 0xE6);
    if (v1 >= 0) {
        func_8013240C((s32)&D_801F8724);
        if (D_801F8730 & 0x4000) {
            t = *(u16 *)(s0 + 0xE6) - 1;
            *(u16 *)(s0 + 0xE6) = t;
            t <<= 16;
            v1 = t >> 16;
            if (v1 >= 0) {
                if (v1 >= 3) {
                    if (v1 != 3) {
                        goto other;
                    }
                    func_8001C924(*(s32 *)(s0 + 0x20), &D_801BC9EC);
                    if (*(s32 *)(s0 + 0xD4) != 0) {
                        func_801A7D18(*(s32 *)(s0 + 0xD4));
                        *(s32 *)(s0 + 0xD4) = 0;
                    }
                    func_801A3A6C((u8 *)s0);
                    *(u16 *)(s0 + 0x100) = 0;
                    func_8012B2CC(s0);
                    if ((arg1 << 16) != 0) {
                        *(s32 *)(s0 + 0xD4) = func_801A8564(s0);
                    }
                }
                func_80132288(&D_801F8724, D_801AFB7C[*(s16 *)(s0 + 0xE6)], D_801BC9EC);
                goto ret0;
            }
        other:
            func_8001C924(*(s32 *)(s0 + 0x20), D_801B6E94);
            func_8012A860((void *)s0, (int)&D_801EF9A8);
            if ((y << 16) != 0) {
                f9 = D_8019FF8A & 0xFFF7;
                p = *(s32 *)(s0 + 0xD4);
                D_8019FF8A = f9;
                if (p != 0) {
                    func_801292C8((u8 *)p);
                }
            }
        }
    ret0:
        return 0;
    }
    return (*(s16 *)(s0 + 0x98) == 0) && (v0 != 0);
}
