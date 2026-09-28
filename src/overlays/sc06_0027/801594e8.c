/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801594E8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_80078E78[];
extern void func_80175454(void);
extern s32 func_80029178(s32);
extern s32 func_800291B4(s32);
extern void func_80029274(void);
extern void func_80029044(void);
extern void func_8002906C(void);
extern void func_80029094(void);
extern void func_8002941C(void);
extern void func_80029124(s32, s32);
extern void func_800291A0(s32, s32);
extern void func_8014BEC0(void);
extern void func_8002AB64(void);
extern void func_80029514(s32);
extern void func_800D185C(u8 *);
extern void func_800CF804(void);
extern void func_800D1F90(void);

void func_801594E8(s32 param_1, s32 param_2)
{

    extern s32 D_80128150;
    extern u8 D_800D3A44[];
    extern u8 D_800D39FC[];
    extern u8 D_800D3A20[];
    u8 *p = D_80078E78;

    func_80175454();
    switch (param_2) {
    case -1: {
        struct { u8 a, b, c; u8 pad[5]; u8 d, e; } t;
        s32 saved;
        t.a = func_80029178(0xB);
        t.b = func_80029178(0xC);
        t.c = func_80029178(0xD);
        t.d = func_800291B4(0x2C);
        t.e = func_800291B4(0x2D);
        saved = *(s32 *)(p + 0x4);
        func_80029274();
        func_80029044();
        func_8002906C();
        func_80029094();
        func_8002941C();
        func_80029124(0xB, t.a);
        func_80029124(0xC, t.b);
        func_80029124(0xD, t.c);
        func_800291A0(0x2C, t.d);
        func_800291A0(0x2D, t.e);
        *(s32 *)(p + 0x4) = saved;
        ((void (*)(s32))func_8014BEC0)(param_1);
        func_8002AB64();
        func_80029514(2);
        func_800D185C(D_800D3A44);
        func_800CF804();
        break;
    }
    case 1:
        *(s16 *)(p + 0x3C) = 0x96;
        *(s16 *)(p + 0x40) = 0x96;
        *(s32 *)(p + 0x14) = D_80128150;
        break;
    case 2:
    case 3:
    case 4:
        func_800D1F90();
        break;
    case 5:
        func_800D1F90();
        func_800D185C(D_800D39FC);
        func_80029514(0x636);
        break;
    case 6:
        func_800D1F90();
        func_800D185C(D_800D3A20);
        func_80029514(0x636);
        break;
    }
}
