/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801EADC4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801EAFE4(void);
extern s32 func_80029504(void);
extern s32 func_801EAF84(s32, s32, s32);
extern void func_801EAF9C(s32, s32, s32);
extern void func_80029124(s32, s32);
extern void func_801EB064(void);
extern void func_801EB0A4(void);
extern void func_801EB014(void);

s32 func_801EADC4(void) {

    extern u8 D_80078EB1;
    extern u8 D_80078E78[];
    extern u8 D_801EC1D0[];
    extern u8 D_801EC2F4[];
    extern s32 D_801F2624;
    extern s32 D_801F24A4;

    u8 *p;
    s32 var;

    func_801EAFE4();
    p = D_80078E78;
    var = func_80029504();

    if (var < 200)
        goto L;
    if (var >= 600)
        goto L;

    if (func_801EAF84(D_80078EB1, 13, 24) && (u32)(var - 0x136) < 0x46) {
        ((void (*)(s32, void *, void *))func_801EAF9C)(10, D_801EC1D0, func_801EB064);
        func_80029124(0x112, 1);
    } else {
        ((void (*)(s32, void *, void *))func_801EAF9C)(10, 0, 0);
    }

    if (func_801EAF84(p[0x39], 13, 24) && (u32)(var - 0x136) < 0x46) {
        ((void (*)(s32, void *, void *))func_801EAF9C)(11, D_801EC2F4, func_801EB0A4);
    } else {
        ((void (*)(s32, void *, void *))func_801EAF9C)(11, 0, 0);
    }
    goto M;

L:
    ((void (*)(s32, void *, void *))func_801EAF9C)(10, 0, 0);
    ((void (*)(s32, void *, void *))func_801EAF9C)(11, 0, 0);

M:
    func_801EB014();
    if (!D_801F2624) {
        return 0;
    }
    return (s32)((u8 *)&D_801F24A4);
}
