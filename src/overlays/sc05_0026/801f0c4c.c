/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801F0C4C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801F0E6C(void);
extern s32 func_80029504(void);
extern void func_80029124(s32, s32);
extern s32 func_801F0E0C(s32, s32, s32);
extern void func_801F0E24(s32, s32, s32);
extern void func_801F0EEC(void);
extern void func_801F0F2C(void);
extern void func_801F0E9C(void);

void func_801F0C4C(void) {
    extern u8 D_80078EB1;
    extern u8 D_80078E78[];
    extern u8 D_801F2058[];
    extern u8 D_801F217C[];
    extern s32 D_801F84AC;
    extern s32 D_801F832C;
    register u8 *p __asm__("$17");
    register s32 v __asm__("$16");
    register s32 t2 __asm__("$2");
    register s32 flg __asm__("$3");
    register s32 *res __asm__("$2");

    func_801F0E6C();
    p = D_80078E78;
    v = func_80029504();

    if (v < 200) goto Lzero;
    if (v >= 600) goto Lzero;

    if (func_801F0E0C(D_80078EB1, 13, 24)) {
        t2 = (u32)(v - 310) < 70;
        if (t2) {
            func_801F0E24(10, (s32)D_801F2058, (s32)func_801F0EEC);
            func_80029124(274, 1);
        } else {
            func_801F0E24(10, 0, 0);
        }
    } else {
        func_801F0E24(10, 0, 0);
    }

    if (func_801F0E0C(p[57], 13, 24)) {
        t2 = (u32)(v - 310) < 70;
        if (t2) {
            func_801F0E24(11, (s32)D_801F217C, (s32)func_801F0F2C);
            goto Lcont;
        }
    }
    goto Lshared;

Lzero:
    func_801F0E24(10, 0, 0);

Lshared:
    func_801F0E24(11, 0, 0);

Lcont:
    func_801F0E9C();

    res = 0;
    flg = D_801F84AC;
    if (flg != 0) {
        res = (s32 *)&D_801F832C;
    }
    __asm__ __volatile__("" : : "r"(res));
}
