/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801EFB94 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_800D1724(void *);
extern s32 func_801789AC(s32 arg0);
extern void func_80188F20(s32 a0);
extern void func_80178CBC(s32 a0, s32 a1);
extern void func_80174438(s32 a0);
extern s32 func_80188F10(void);
extern u8 *D_80126B10;

void func_801EFB94(void *a0) {

    extern s32 D_801F00AC;
    extern s32 D_801F00C4;
    extern s32 D_801F0048;
    extern s32 D_800D39CC;

    switch (*(u16 *)((s32)a0 + 0x34)) {
    case 0: {
        s32 v0 = func_801789AC((s32)a0);
        switch (v0) {
        case 1:
            *(u16 *)((s32)a0 + 0x34) = 2;
            func_80188F20(5);
            break;
        case 2:
            func_80178CBC((s32)a0, (s32)&D_801F00AC);
            *(u16 *)((s32)a0 + 0x34) = 0;
            break;
        case 3:
            func_80178CBC((s32)a0, (s32)&D_801F00C4);
            *(u16 *)((s32)a0 + 0x34) = 3;
            break;
        }
        break;
    }
    case 1:
        break;
    case 2:
        if ((func_80188F10() << 16) != 0) {
            func_800D1724(&D_800D39CC);
            *(u16 *)((s32)a0 + 0x34) = 1;
        } else {
            func_80178CBC((s32)a0, (s32)&D_801F0048);
            *(u16 *)((s32)a0 + 0x34) = 0;
        }
        break;
    case 3:
        if (func_801789AC((s32)a0) != 0) {
            func_80174438((s32)D_80126B10);
            *(u16 *)((s32)a0 + 0x34) = 1;
        }
        break;
    }
}
