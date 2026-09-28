/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801E56A8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80029504(void);
extern s32 func_80029178(s32);
extern s32 func_80029178(s32 arg);
extern s32 func_80184428(void);
extern s32 func_801844F8(void);
extern s32 func_8018456C(void);
extern void func_801845C8(void);

void func_801E56A8(s32 a0) {
    extern s32 D_801E6754[];
    extern s32 D_801E6768[];
    extern s32 D_801E6784[];
    extern s32 D_801E6DF4;
    extern s32 D_801E6E40;

    register s32 flag __asm__("$2");

    s32 v1 = func_80029504();

    if (v1 < 0x258) {
        s32 u = func_80029504();

        if ((u32)(u - 0xC8) >= 0x64) {
            if (u >= 0x12C) {
                if (func_80029178(0xFA) & 0xFF) {
                    goto zero;
                }
            } else {
                goto one;
            }
        } else {
            goto zero;
        }
        flag = 1;
        goto eval;
    zero:
        flag = 0;
        goto eval;
    one:
        flag = 1;
    eval:
        if (flag != 0) {
            s32 v0 = func_80184428();
            *(s32 *)(a0 + 0xE4) = D_801E6754[v0];
        } else {
            s32 w = func_80029504();
            if ((u32)w < 0x12C) {
                *(s32 *)(a0 + 0xE4) = (s32)&D_801E6DF4;
            } else {
                *(s32 *)(a0 + 0xE4) = (s32)&D_801E6E40;
            }
        }
    } else if (v1 < 0x384) {
        s32 v0 = func_801844F8();
        *(s32 *)(a0 + 0xE4) = D_801E6768[v0];
    } else {
        s32 v0 = func_8018456C();
        *(s32 *)(a0 + 0xE4) = D_801E6784[v0];
        func_801845C8();
    }
}
