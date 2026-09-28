/* MAIN10 resident retail span [800D1BF8,800D1D24), offset 0x22E00 at base 800AEDF8. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800D1BF8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_800AE6B0;
extern s32 D_800AE6A8;
extern s16 D_800B9A0E;
extern void func_800D1D24(void);
extern s32  func_80011DF4(void);
extern void func_80011DCC(void);
extern void func_80011818(s32);
extern s32  func_8002AF08(void);
extern s32  func_800CFBE8(void);
extern void func_800CFBBC(void);
extern s32  func_80029264(void);
extern void func_80029254(void);
extern s32  func_800D1DB0(void);
extern void func_80011B7C(s32);

void func_800D1BF8(void) {
    u8 *p = (u8 *)&D_800AE6A8;
    void (*fp)(void);
    s32 a0val;

    fp = *(void (**)(void))((D_800AE6B0 & 0x80FFFFFF) + 0x1C);
    D_800B9A0E = 0;
    fp();
    func_800D1D24();

    if (func_80011DF4() != 0) {
        func_80011DCC();
        func_80011818(0x11);
    } else {
        if (func_8002AF08() != 0) {
            a0val = 0xD;
        } else if (func_800CFBE8() != 0) {
            func_800CFBBC();
            a0val = 0x13;
        } else if (func_80029264() != 0) {
            func_80029254();
            a0val = 0x12;
        } else {
            s32 n = func_800D1DB0();
            if (n != 1) {
                if (n < 2 && n == 0) {
                    a0val = 6;
                } else {
                    a0val = 0x10;
                }
            } else {
                a0val = 5;
            }
        }
        func_80011B7C(a0val);
    }

    if (*(s32 *)(p + 8) & 0x1000000) {
        p[0x17] = 1;
    } else {
        p[0x17] = 0;
    }
}
