/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801EAC10 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80029504(void);
extern s32 func_80029178(s32);
extern s32 func_80184D00(void);
extern s32 func_80184DD0(void);
extern s32 func_80184E44(void);
extern void func_80184EA0(void);
extern s32 D_801EBCBC[];
extern s32 D_801EBCD0[];
extern s32 D_801EBCEC[];
extern s32 D_801EC35C;
extern s32 D_801EC3A8;

void func_801EAC10(s32 a0) {
    s32 v0, v1 = func_80029504();
    if (v1 < 0x258) {
        v1 = func_80029504();
        if ((u32)(v1 - 0xC8) < 0x64) {
            v0 = 0;
        } else if (v1 < 0x12C) {
            v0 = 1;
        } else {
            v0 = func_80029178(0xFA) & 0xFF;
            if (v0 != 0) {
                v0 = 0;
            } else {
                v0 = 1;
            }
        }
        if (v0 != 0) {
            *(s32 *)(a0 + 0xE4) = D_801EBCBC[func_80184D00()];
        } else if ((u32)func_80029504() < 0x12C) {
            *(s32 *)(a0 + 0xE4) = (s32)&D_801EC35C;
        } else {
            *(s32 *)(a0 + 0xE4) = (s32)&D_801EC3A8;
        }
    } else if (v1 < 0x384) {
        *(s32 *)(a0 + 0xE4) = D_801EBCD0[func_80184DD0()];
    } else {
        *(s32 *)(a0 + 0xE4) = D_801EBCEC[func_80184E44()];
        func_80184EA0();
    }
}
