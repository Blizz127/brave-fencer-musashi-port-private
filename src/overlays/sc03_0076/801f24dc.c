/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801F24DC - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80029504(void);
extern s32 func_80029178(s32);

void func_801F24DC(s32 a0) {
    extern s32 func_80029504(void);
    extern s32 func_80029178(s32 arg);
    extern s32 func_801877C0(void);
    extern s32 func_80187890(void);
    extern s32 func_80187904(void);
    extern void func_80187960(void);
    extern s32 D_801F35EC[];
    extern s32 D_801F3600[];
    extern s32 D_801F361C[];
    extern s32 D_801F3D68;
    extern s32 D_801F3DB4;

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
            *(s32 *)(a0 + 0xE4) = D_801F35EC[func_801877C0()];
        } else {
            if (func_80029504() < 0x12CU) {
                *(s32 *)(a0 + 0xE4) = (s32)&D_801F3D68;
            } else {
                *(s32 *)(a0 + 0xE4) = (s32)&D_801F3DB4;
            }
        }
    } else if (v1 < 0x384) {
        *(s32 *)(a0 + 0xE4) = D_801F3600[func_80187890()];
    } else {
        *(s32 *)(a0 + 0xE4) = D_801F361C[func_80187904()];
        func_80187960();
    }
}
