/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801F0A98 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80029504(void);
extern s32 func_80029178(s32 arg);
extern s32 func_80184A00(void);
extern s32 func_80184AD0(void);
extern s32 func_80184B44(void);
extern void func_80184BA0(void);

void func_801F0A98(s32 a0) {
    extern s32 D_801F1B44[];
    extern s32 D_801F1B58[];
    extern s32 D_801F1B74[];
    extern s32 D_801F21E4;
    extern s32 D_801F2230;

    s32 v1 = func_80029504();
    if (v1 < 0x258) {
        s32 flag;
        v1 = func_80029504();
        if ((u32)(v1 - 0xC8) >= 0x64U) {
            if (v1 < 0x12C || (func_80029178(0xFA) & 0xFF) == 0) {
                flag = 1;
            } else {
                flag = 0;
            }
        } else {
            flag = 0;
        }
        if (flag) {
            *(s32 *)(a0 + 0xE4) = D_801F1B44[func_80184A00()];
        } else {
            if (func_80029504() < 0x12CU) {
                *(s32 *)(a0 + 0xE4) = (s32)&D_801F21E4;
            } else {
                *(s32 *)(a0 + 0xE4) = (s32)&D_801F2230;
            }
        }
    } else if (v1 < 0x384) {
        *(s32 *)(a0 + 0xE4) = D_801F1B58[func_80184AD0()];
    } else {
        *(s32 *)(a0 + 0xE4) = D_801F1B74[func_80184B44()];
        func_80184BA0();
    }
}
