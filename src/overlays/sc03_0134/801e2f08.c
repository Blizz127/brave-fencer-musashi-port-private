/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801E2F08 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_801789AC(s32 a0);
extern void func_80185B88(s32 a0);
extern void func_80178CBC(s32 a0, s32 a1);
extern void func_80174438(s32 a0);

void func_801E2F08(void *param_1) {

    extern u8 *D_80126B10;

    extern s32 D_801E3768;
    extern s32 D_801E3780;
    extern s32 D_801E3704;

    switch (*(u16 *)((s32)param_1 + 0x34)) {
    case 0: {
        s32 v0 = func_801789AC((s32)param_1);
        switch (v0) {
        case 1:
            *(u16 *)((s32)param_1 + 0x34) = 2;
            func_80185B88(0);
            break;
        case 2:
            func_80178CBC((s32)param_1, (s32)&D_801E3768);
            *(u16 *)((s32)param_1 + 0x34) = 0;
            break;
        case 3:
            func_80178CBC((s32)param_1, (s32)&D_801E3780);
            *(u16 *)((s32)param_1 + 0x34) = 3;
            break;
        }
        break;
    }
    case 1:
        break;
    case 2:
        func_80178CBC((s32)param_1, (s32)&D_801E3704);
        *(u16 *)((s32)param_1 + 0x34) = 0;
        break;
    case 3:
        if (func_801789AC((s32)param_1) != 0) {
            func_80174438((s32)D_80126B10);
            *(u16 *)((s32)param_1 + 0x34) = 1;
        }
        break;
    }
}
