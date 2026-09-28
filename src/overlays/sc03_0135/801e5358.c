/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801E5358 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_801E288C(void);
extern u8 *D_80126B10;
extern u8 D_801E672C[];
extern u8 D_801E6798[];
extern u8 D_801E67B0[];
extern s32 func_801789AC(u8 *a0);
extern void func_80178CBC(u8 *a0, u8 *a1);
extern s16 func_80185B78(void);
extern void func_80185B88(s32 a0);
extern void func_80174438(s32 a0);
extern void func_801E2864(void);

void func_801E5358(u8 *a0) {
    switch (*(u16 *)(a0 + 0x34)) {
    case 0:
        switch (func_801789AC(a0)) {
        case 2:
            func_80178CBC(a0, D_801E6798);
            *(u16 *)(a0 + 0x34) = 0;
            break;
        case 1:
            *(u16 *)(a0 + 0x34) = 2;
            func_80185B88(4);
            break;
        case 3:
            func_80178CBC(a0, D_801E67B0);
            *(u16 *)(a0 + 0x34) = 3;
            break;
        }
        break;
    case 1:
        break;
    case 2:
        if (func_80185B78() != 0) {
            func_801E2864();
            *(u16 *)(a0 + 0x34) = 4;
        } else {
            func_80178CBC(a0, D_801E672C);
            *(u16 *)(a0 + 0x34) = 0;
        }
        break;
    case 3:
        if (func_801789AC(a0) != 0) {
            func_80174438((*(s32 *)&D_80126B10));
            *(u16 *)(a0 + 0x34) = 1;
        }
        break;
    case 4:
        if (((s16 (*)(void))func_801E288C)() != 0) {
            *(u16 *)(a0 + 0x34) = 2;
            func_80185B88(4);
        }
        break;
    }
}
