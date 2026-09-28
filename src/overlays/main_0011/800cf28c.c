/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800CF28C - byte-exact against retail at -O0 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_800CF28C(void) {
    extern u8 D_800AF630[];
    extern u8 D_80078E78[];
    extern u8 D_800D31F8[];
    extern u8 D_800D3334[];
    typedef struct { s16 unk00; s16 unk02; s16 unk04; } S6;
    typedef struct { u8 pad00[0x1A]; u16 f1A; } SP18;
    extern S6 D_800D4A5C[];
    extern s16 D_800D4C80;
    extern u16 D_800D4C9C;
    extern s32 D_800D4C90;
    extern s32 D_800D4C94;
    extern s32 D_800D3344;
    extern s16 D_800D3348;
    extern s16 D_800D334A;
    extern void func_800D0858(void);
    extern void func_8001534C(int, void *, int, int, int, int);
    extern void func_80011928(s32);
    extern void func_800167B8(s32);
    extern void func_80029514(s32);
    extern s32 func_80029178(s32);
    extern void func_80029124(s32, s32);
    extern void func_800D04F4(void);
    extern void func_800CFBF0(void);
    extern void func_800CFB88(void);

    register u8 *v0 = D_800AF630;
    SP18 *sp18 = (SP18 *)D_80078E78;
    s32 sp1C;

    v0[0xA3E1] = 0;
    func_800D0858();
    if ((u16)(D_800D4C9C & 0x4000)) {
        D_800D4C80++;
        if (D_800D4C80 >= 13) {
            D_800D4C80 = 0;
        }
    } else if ((u16)(D_800D4C9C & 0x1000)) {
        D_800D4C80--;
        if (D_800D4C80 < 0) {
            D_800D4C80 = 12;
        }
    }
    func_8001534C(1, D_800D31F8, 0x34, (s16)D_800D3334[D_800D4C80], 0, 0);
    switch (D_800D4C80) {
    case 0:
        if ((u16)(D_800D4C9C & 0x820)) {
            func_80011928(4);
        }
        break;
    case 1:
    case 2:
    case 3:
    case 5:
        if ((u16)(D_800D4C9C & 0x820)) {
            func_80011928(2);
            func_800167B8(4);
        }
        break;
    case 4:
        if ((u16)(D_800D4C9C & 0x8000)) {
            D_800D4C90--;
            if (D_800D4C90 < 0) {
                D_800D4C90 = 6;
            }
        }
        if ((u16)(D_800D4C9C & 0x2000)) {
            D_800D4C90++;
            if (D_800D4C90++ >= 7) {
                D_800D4C90 = 0;
            }
        }
        break;
    case 6:
        if ((u16)(D_800D4C9C & 0x8000)) {
            D_800D4C94--;
            if (D_800D4C94 < 0) {
                D_800D4C94 = 7;
            }
        }
        if ((u16)(D_800D4C9C & 0x2000)) {
            D_800D4C94++;
            if (D_800D4C94 >= 8) {
                D_800D4C94 = 0;
            }
        }
        break;
    case 7:
        if ((u16)(D_800D4C9C & 0x8000)) {
            if ((D_800D3344 = D_800D3344 - 10) < 0) {
                D_800D3344 = 0;
            }
        }
        if ((u16)(D_800D4C9C & 0x2000)) {
            if ((D_800D3344 = D_800D3344 + 10) >= 0x6A5) {
                D_800D3344 = 0x6A4;
            }
        }
        if ((u16)(D_800D4C9C & 0x20)) {
            if ((D_800D3344 = D_800D3344 + 1) >= 0x6A5) {
                D_800D3344 = 0x6A4;
            }
        }
        if ((u16)(D_800D4C9C & 0x40)) {
            if ((D_800D3344 = D_800D3344 - 1) < 0) {
                D_800D3344 = 0;
            }
        }
        if ((u16)(D_800D4C9C & 0x10)) {
            if ((D_800D3344 = D_800D3344 + 100) >= 0x6A5) {
                D_800D3344 = 0x6A4;
            }
        }
        if ((u16)(D_800D4C9C & 0x80)) {
            if ((D_800D3344 = D_800D3344 - 100) < 0) {
                D_800D3344 = 0;
            }
        }
        func_80029514(D_800D3344);
        break;
    case 8:
        if ((u16)(D_800D4C9C & 0x8000)) {
            if ((D_800D3348 = D_800D3348 - 1) < 0) {
                D_800D3348 = 0x2B;
            }
        }
        if ((u16)(D_800D4C9C & 0x2000)) {
            if ((D_800D3348 = D_800D3348 + 1) >= 0x2C) {
                D_800D3348 = 0;
            }
        }
        if ((u16)(D_800D4C9C & 0x20)) {
            sp1C = D_800D4A5C[D_800D3348].unk04;
            func_80029124(sp1C, (u8)func_80029178(sp1C) == 0);
        }
        break;
    case 9:
        if ((u16)(D_800D4C9C & 0x2000)) {
            D_800D334A += 0x3C;
        }
        if ((u16)(D_800D4C9C & 0x8000)) {
            D_800D334A -= 0x3C;
        }
        if ((u16)(D_800D4C9C & 0xA0)) {
            D_800D334A += 0xF;
        }
        if ((u16)(D_800D4C9C & 0x40)) {
            D_800D334A -= 0xF;
        }
        if (D_800D334A < 0) {
            D_800D334A = 0x59F;
        }
        if (D_800D334A >= 0x5A0) {
            D_800D334A = 0;
        }
        sp18->f1A = D_800D334A;
        break;
    case 10:
        if ((u16)(D_800D4C9C & 0x2000)) {
            func_80029124(0, (u8)func_80029178(0) == 0);
        }
        break;
    case 11:
        if ((u16)(D_800D4C9C & 0x2000)) {
            func_80029124(1, (u8)func_80029178(1) == 0);
        }
        break;
    case 12:
        if ((u16)(D_800D4C9C & 0x2000)) {
            func_80029124(2, (u8)func_80029178(2) == 0);
        }
        break;
    }
    if (D_800D4C80 >= 6) {
        if ((u16)(D_800D4C9C & 0x800)) {
            D_800D4C80 = 0;
            func_80011928(4);
        }
    }
    sp18->f1A = D_800D334A;
    func_800D04F4();
    func_800CFBF0();
    func_800CFB88();
}
