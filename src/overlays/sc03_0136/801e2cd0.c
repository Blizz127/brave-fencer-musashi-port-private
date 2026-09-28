/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801E2CD0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 *D_80126B10;
extern s32 func_801789AC(s32 a0);
extern void func_80178CBC(s32 a0, s32 a1);
extern void func_80174438(s32 a0);
extern void func_80185B88(s32 a0);
extern s16 func_80185B78(void);

void func_801E2CD0(void *param_1) {

    extern s32 D_801E336C;
    extern s32 D_801E3384;
    extern s32 D_801E3308;
    extern s32 D_801E3580[];

    switch (*(u16 *)((s32)param_1 + 0x34)) {
    case 0: {
        s32 v1 = func_801789AC((s32)param_1);
        switch (v1) {
        case 1:
            *(u16 *)((s32)param_1 + 0x34) = 2;
            func_80185B88(2);
            break;
        case 2:
            func_80178CBC((s32)param_1, (s32)&D_801E336C);
            *(u16 *)((s32)param_1 + 0x34) = 0;
            break;
        case 3:
            func_80178CBC((s32)param_1, (s32)&D_801E3384);
            *(u16 *)((s32)param_1 + 0x34) = 3;
            break;
        }
        break;
    }
    case 1:
        break;
    case 2: {
        s32 v0 = func_80185B78();
        if (v0 != 0) {
            func_80178CBC((s32)param_1, (s32)D_801E3580[v0]);
            *(u16 *)((s32)param_1 + 0x34) = 4;
        } else {
            func_80178CBC((s32)param_1, (s32)&D_801E3308);
            *(u16 *)((s32)param_1 + 0x34) = 0;
        }
        break;
    }
    case 3:
        if (func_801789AC((s32)param_1) != 0) {
            func_80174438((s32)D_80126B10);
            *(u16 *)((s32)param_1 + 0x34) = 1;
        }
        break;
    case 4:
        if (func_801789AC((s32)param_1) != 0) {
            *(u16 *)((s32)param_1 + 0x34) = 2;
            func_80185B88(2);
        }
        break;
    }
}
